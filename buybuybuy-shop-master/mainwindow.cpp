#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "signindialog.h"
#include "cartdialog.h"
#include "bankdialog.h"
#include "paydialog.h"
#include "boughtdialog.h"
#include <QInputDialog>
#include<QButtonGroup>
#include<QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    login = false;
    ui->userLabel->setText("用户未登录");
    ui->userB->setText("登录/注册");
    ui->bankB->hide();
    ui->boughtB->hide();
    ui->addB->hide();
    ui->cartB->hide();

    bookT.setEditTriggers(QTableWidget::NoEditTriggers);
    elecT.setEditTriggers(QTableWidget::NoEditTriggers);
    clothesT.setEditTriggers(QTableWidget::NoEditTriggers);
    foodT.setEditTriggers(QTableWidget::NoEditTriggers);
    bookT.setSelectionBehavior(QAbstractItemView::SelectRows);
    elecT.setSelectionBehavior(QAbstractItemView::SelectRows);
    clothesT.setSelectionBehavior(QAbstractItemView::SelectRows);
    foodT.setSelectionBehavior(QAbstractItemView::SelectRows);

    readAndShowGoods();

    // === 初始化子分类按钮组 ===
    subcategoryButtonGroup = new QButtonGroup(this);
    connect(subcategoryButtonGroup, SIGNAL(idClicked(int)), this, SLOT(on_subcategoryButtonClicked(int)));

    // === 初始化主分类按钮 ===
    setupMainCategoryButtons();


}




void MainWindow::setupMainCategoryButtons()
{
    // 动态创建分类按钮
    QHBoxLayout *categoryButtonLayout = new QHBoxLayout;

    QPushButton *categoryButton0 = new QPushButton("书籍", this);
    QPushButton *categoryButton1 = new QPushButton("电子", this);
    QPushButton *categoryButton2 = new QPushButton("服装", this);
    QPushButton *categoryButton3 = new QPushButton("食品", this);

    categoryButtonLayout->addWidget(categoryButton0);
    categoryButtonLayout->addWidget(categoryButton1);
    categoryButtonLayout->addWidget(categoryButton2);
    categoryButtonLayout->addWidget(categoryButton3);

    // 将布局添加到名为 widget 的容器控件中
    QWidget *categoryButtonContainer = ui->widget;
    if (categoryButtonContainer) {
        // 清空旧布局
        if (categoryButtonContainer->layout()) {
            QLayoutItem *item;
            while ((item = categoryButtonContainer->layout()->takeAt(0))) {
                delete item->widget();
                delete item;
            }
            delete categoryButtonContainer->layout();
        }
        // 设置新布局
        categoryButtonContainer->setLayout(categoryButtonLayout);
    }

    // 连接分类按钮信号和槽
    connect(categoryButton0, &QPushButton::clicked, [this]() { on_categoryButtonClicked(0); });
    connect(categoryButton1, &QPushButton::clicked, [this]() { on_categoryButtonClicked(1); });
    connect(categoryButton2, &QPushButton::clicked, [this]() { on_categoryButtonClicked(2); });
    connect(categoryButton3, &QPushButton::clicked, [this]() { on_categoryButtonClicked(3); });
}



MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::readL() {
    bookL.clear();
    elecL.clear();
    clothesL.clear();
    foodL.clear();
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.open()) {
        QMessageBox::information(this, "获取商品列表失败", "无法连接到数据库，请重试");
        qDebug() << "Database open error:" << db.lastError().text();
        return false;
    }
    QSqlQuery q;
    q.prepare("SELECT ID, name, [desc], amount, author, price FROM Book");
    if (!q.exec()) {
        QString errorMsg = QString("书籍表查询失败！\n"
                                   "SQL: %1\n"
                                   "错误: %2\n"
                                   "表是否存在: %3")
                               .arg(q.lastQuery())
                               .arg(q.lastError().text())
                               .arg(db.tables().contains("Book") ? "是" : "否");

        QMessageBox::critical(this, "查询失败", errorMsg);
        qDebug() << "Book query error:" << errorMsg;
        return false;
    }
    while (q.next()) {
        try {
            Book *bk = new Book(
                q.value("ID").toInt(),
                q.value("name").toString(),
                q.value("desc").toString(),
                q.value("price").toDouble(),
                q.value("amount").toInt(),
                q.value("author").toString()
                );
            bookL.push_back(*bk);
        } catch (...) {
            QMessageBox::warning(this, "警告", "创建书籍对象时发生错误");
            continue;
        }
    }

    q.prepare("select ID,name,desc,amount,brand,price from Elec");
    if (!q.exec()) {
        QMessageBox::information(this, "获取电子类商品列表失败", "无法查询数据库，请重试");
        qDebug() << "Elec query error:" << q.lastError().text();
        return false;
    }
    while (q.next()) {
        int id = q.value(0).toInt();
        QString name = q.value(1).toString();
        QString desc = q.value(2).toString();
        int amount = q.value(3).toInt();
        QString brand = q.value(4).toString();
        double price = q.value(5).toDouble();
        // 创建非常量对象并添加到QVector
        Elec *elec = new Elec(id, name, desc, price, amount, brand);
        elecL.push_back(*elec);
        delete elec;
    }

    q.prepare("select ID,name,desc,amount,sex,price from Clothes");
    if (!q.exec()) {
        QMessageBox::information(this, "获取服装类商品列表失败", "无法查询数据库，请重试");
        qDebug() << "Clothes query error:" << q.lastError().text();
        return false;
    }
    while (q.next()) {
        int id = q.value(0).toInt();
        QString name = q.value(1).toString();
        QString desc = q.value(2).toString();
        int amount = q.value(3).toInt();
        int sexi = q.value(4).toInt();
        Clothes::Sex sex = sexi == 0? Clothes::General : (sexi == 1? Clothes::Male : Clothes::Female);
        double price = q.value(5).toDouble();
        // 创建非常量对象并添加到QVector
        Clothes *c = new Clothes(id, name, desc, price, amount, sex);
        clothesL.push_back(*c);
        delete c;
    }

    q.prepare("select ID,name,desc,amount,date,price from Food");
    if (!q.exec()) {
        QMessageBox::information(this, "获取食品类商品列表失败", "无法查询数据库，请重试");
        qDebug() << "Food query error:" << q.lastError().text();
        return false;
    }
    while (q.next()) {
        int id = q.value(0).toInt();
        QString name = q.value(1).toString();
        QString desc = q.value(2).toString();
        int amount = q.value(3).toInt();
        QDate date = QDate::fromString(q.value(4).toString());
        double price = q.value(5).toDouble();
        // 创建非常量对象并添加到QVector
        Food *f = new Food(id, name, desc, price, amount, date);
        foodL.push_back(*f);
        delete f;
    }
    return true;
}



void MainWindow::readAndShowGoods() {
    if (readL()) {
        showGoods();
    }
}












template <typename T>
bool MainWindow::saveL(const QVector<T>& L, QString tableName){
    QSqlDatabase db=QSqlDatabase::database();
    if(!db.open()){
        QMessageBox::information(this,"保存商品列表失败","无法连接到数据库，请重试");
        return false;
    }
    QSqlQuery q;
    for(auto it=L.begin();it!=L.end();it++){
        q.prepare(QString("update %1 set amount=? where ID=?").arg(tableName));
        //q.addBindValue(tableName);
        q.addBindValue(it->getAmount());
        q.addBindValue(it->getID());
        //QMessageBox::information(0,"update",QString("update \'%1\' set amount=%2 where ID=%3")
        //              .arg(tableName).arg(it->getAmount()).arg(it->getID()));
        if(!q.exec()){
            QMessageBox::information(this,"保存书籍商品列表失败",
                                     QString("%1品类的一项保存失败").arg(tableName));
            return false;
        }
    }
    return true;
}








void MainWindow::SearchBooksByName(const QString& searchName)
{
    int currentIndex = ui->tabWidget->currentIndex();
    if(currentIndex==0)
    {
        // 先清空表格
        bookT.clearContents();
        int row = 0;

        for (auto it=bookL.begin();it!=bookL.end();it++)
        {
            if (it->getName().contains(searchName, Qt::CaseInsensitive))
            {
                // 设置行数（如果还未设置行数，先设置行数）
                if (row >= bookT.rowCount())
                    bookT.insertRow(row);

                // 在第0列放书名
                QTableWidgetItem* nameItem = new QTableWidgetItem(it->getName());
                bookT.setItem(row, 0, nameItem);

                // 在第1列放作者（假设有）
                QTableWidgetItem* authorItem = new QTableWidgetItem(it->getAuthor());
                bookT.setItem(row, 1, authorItem);

                bookT.setItem(row,2,new QTableWidgetItem(it->getDesc()));
                bookT.setItem(row,3,new QTableWidgetItem(QString("%1 元").arg(it->getPrice())));
                bookT.setItem(row,4,new QTableWidgetItem(QString("%1 本").arg(it->getAmount())));
                bookT.item(row,3)->setData(Qt::UserRole,it->getPrice());
                bookT.item(row,4)->setData(Qt::UserRole,it->getAmount());
                bookT.item(row,0)->setData(Qt::UserRole,it->getID());

                row++;
            }
        }
    }
    else if(currentIndex==1)
    {
        // 先清空表格
        elecT.clearContents();
        int row = 0;

        for (auto it=elecL.begin();it!=elecL.end();it++)
        {
            if (it->getName().contains(searchName, Qt::CaseInsensitive))
            {
                // 设置行数（如果还未设置行数，先设置行数）
                if (row >= elecT.rowCount())
                    elecT.insertRow(row);

                QTableWidgetItem* nameItem = new QTableWidgetItem(it->getName());
                elecT.setItem(row, 0, nameItem);

                QTableWidgetItem* authorItem = new QTableWidgetItem(it->getBrand());
                elecT.setItem(row, 1, authorItem);

                elecT.setItem(row,2,new QTableWidgetItem(it->getDesc()));
                elecT.setItem(row,3,new QTableWidgetItem(QString("%1 元").arg(it->getPrice())));
                elecT.setItem(row,4,new QTableWidgetItem(QString("%1 个").arg(it->getAmount())));
                elecT.item(row,3)->setData(Qt::UserRole,it->getPrice());
                elecT.item(row,4)->setData(Qt::UserRole,it->getAmount());
                elecT.item(row,0)->setData(Qt::UserRole,it->getID());

                row++;
            }
        }

    }
    else if(currentIndex==2)
    {
        // 先清空表格
        clothesT.clearContents();
        int row = 0;
        QStringList sexL=QStringList()<<"通用"<<"男装"<<"女装";
        for (auto it=clothesL.begin();it!=clothesL.end();it++)
        {
            if (it->getName().contains(searchName, Qt::CaseInsensitive))
            {
                // 设置行数（如果还未设置行数，先设置行数）
                if (row >= clothesT.rowCount())
                    clothesT.insertRow(row);

                QTableWidgetItem* nameItem = new QTableWidgetItem(it->getName());
                clothesT.setItem(row, 0, nameItem);

                QTableWidgetItem* authorItem = new QTableWidgetItem(sexL[it->getSexi()]);
                clothesT.setItem(row, 1, authorItem);

                clothesT.setItem(row,2,new QTableWidgetItem(it->getDesc()));
                clothesT.setItem(row,3,new QTableWidgetItem(QString("%1 元").arg(it->getPrice())));
                clothesT.setItem(row,4,new QTableWidgetItem(QString("%1 件").arg(it->getAmount())));
                clothesT.item(row,3)->setData(Qt::UserRole,it->getPrice());
                clothesT.item(row,4)->setData(Qt::UserRole,it->getAmount());
                clothesT.item(row,0)->setData(Qt::UserRole,it->getID());

                row++;
            }
        }
    }
    else if(currentIndex==3)
    {
        // 先清空表格
        foodT.clearContents();
        int row = 0;

        for (auto it=foodL.begin();it!=foodL.end();it++)
        {
            if (it->getName().contains(searchName, Qt::CaseInsensitive))
            {
                // 设置行数（如果还未设置行数，先设置行数）
                if (row >= foodT.rowCount())
                    foodT.insertRow(row);

                QTableWidgetItem* nameItem = new QTableWidgetItem(it->getName());
                foodT.setItem(row, 0, nameItem);

                QTableWidgetItem* authorItem = new QTableWidgetItem(it->getDesc());
                foodT.setItem(row, 1, authorItem);

                foodT.setItem(row,2,new QTableWidgetItem(QString("%1 元").arg(it->getPrice())));
                foodT.setItem(row,3,new QTableWidgetItem(it->getDate().toString()));
                foodT.setItem(row,4,new QTableWidgetItem(QString("%1 个").arg(it->getAmount())));
                foodT.item(row,2)->setData(Qt::UserRole,it->getPrice());
                foodT.item(row,4)->setData(Qt::UserRole,it->getAmount());
                foodT.item(row,0)->setData(Qt::UserRole,it->getID());

                row++;
            }
        }

    }


}


bool MainWindow::saveL(){
    if(saveL<Book>(bookL,"Book")&&saveL<Elec>(elecL,"Elec")
        &&saveL<Clothes>(clothesL,"Clothes")&&saveL<Food>(foodL,"Food"))
        return true;
    else return false;
}

void MainWindow::showGoods(){
    ui->tabWidget->clear();

    bookSubTabWidget.clear();
    bookSubTabWidget.addTab(&bookT,"全部");
    bookSubTabWidget.addTab(&bookT,"政治与哲学");
    bookSubTabWidget.addTab(&bookT,"教科书");
    bookSubTabWidget.addTab(&bookT,"小说");
    bookSubTabWidget.addTab(&bookT,"漫画");

    bookT.clear();
    bookT.setColumnCount(7);
    bookT.setRowCount(bookL.size());
    bookT.setHorizontalHeaderLabels(QStringList()
                                    <<"书名"
                                    <<"作者"
                                    <<"分类"
                                    <<"价格"
                                    <<"库存量"
                                    ); // 如果需要
    for(auto it=bookL.begin();it!=bookL.end();it++){
        int i=it-bookL.begin();
        bookT.setItem(i,0,new QTableWidgetItem(it->getName()));
        bookT.setItem(i,1,new QTableWidgetItem(it->getAuthor()));
        bookT.setItem(i,2,new QTableWidgetItem(it->getDesc()));
        bookT.setItem(i,3,new QTableWidgetItem(QString("%1 元").arg(it->getPrice())));
        bookT.setItem(i,4,new QTableWidgetItem(QString("%1 本").arg(it->getAmount())));
        bookT.item(i,3)->setData(Qt::UserRole,it->getPrice());
        bookT.item(i,4)->setData(Qt::UserRole,it->getAmount());
        bookT.item(i,0)->setData(Qt::UserRole,it->getID());
    }

    elecT.clear();
    elecT.setColumnCount(5);
    elecT.setRowCount(elecL.size());
    elecT.setHorizontalHeaderLabels(QStringList()
                                    <<"品名"
                                    <<"品牌"
                                    <<"分类"
                                    <<"价格"
                                    <<"库存量"
                                    );
    for(auto it=elecL.begin();it!=elecL.end();it++){
        int i=it-elecL.begin();
        elecT.setItem(i,0,new QTableWidgetItem(it->getName()));
        elecT.setItem(i,1,new QTableWidgetItem(it->getBrand()));
        elecT.setItem(i,2,new QTableWidgetItem(it->getDesc()));
        elecT.setItem(i,3,new QTableWidgetItem(QString("%1 元").arg(it->getPrice())));
        elecT.setItem(i,4,new QTableWidgetItem(QString("%1 个").arg(it->getAmount())));
        elecT.item(i,3)->setData(Qt::UserRole,it->getPrice());
        elecT.item(i,4)->setData(Qt::UserRole,it->getAmount());
        elecT.item(i,0)->setData(Qt::UserRole,it->getID());
    }

    clothesT.clear();
    clothesT.setColumnCount(5);
    clothesT.setRowCount(clothesL.size());
    clothesT.setHorizontalHeaderLabels(QStringList()
                                       <<"品名"
                                       <<"性别"
                                       <<"分类"
                                       <<"价格"
                                       <<"库存量"
                                       );
    QStringList sexL=QStringList()<<"通用"<<"男装"<<"女装";
    for(auto it=clothesL.begin();it!=clothesL.end();it++){
        int i=it-clothesL.begin();
        clothesT.setItem(i,0,new QTableWidgetItem(it->getName()));
        clothesT.setItem(i,1,new QTableWidgetItem(sexL[it->getSexi()]));
        clothesT.setItem(i,2,new QTableWidgetItem(it->getDesc()));
        clothesT.setItem(i,3,new QTableWidgetItem(QString("%1 元").arg(it->getPrice())));
        clothesT.setItem(i,4,new QTableWidgetItem(QString("%1 件").arg(it->getAmount())));
        clothesT.item(i,3)->setData(Qt::UserRole,it->getPrice());
        clothesT.item(i,4)->setData(Qt::UserRole,it->getAmount());
        clothesT.item(i,0)->setData(Qt::UserRole,it->getID());
    }

    foodT.clear();
    foodT.setColumnCount(5);
    foodT.setRowCount(foodL.size());
    foodT.setHorizontalHeaderLabels(QStringList()
                                    <<"名称"
                                    <<"分类"
                                    <<"价格"
                                    <<"生产日期"
                                    <<"库存量"
                                    );
    for(auto it=foodL.begin();it!=foodL.end();it++){
        int i=it-foodL.begin();
        foodT.setItem(i,0,new QTableWidgetItem(it->getName()));
        foodT.setItem(i,1,new QTableWidgetItem(it->getDesc()));
        foodT.setItem(i,2,new QTableWidgetItem(QString("%1 元").arg(it->getPrice())));
        foodT.setItem(i,3,new QTableWidgetItem(it->getDate().toString()));
        foodT.setItem(i,4,new QTableWidgetItem(QString("%1 个").arg(it->getAmount())));
        foodT.item(i,2)->setData(Qt::UserRole,it->getPrice());
        foodT.item(i,4)->setData(Qt::UserRole,it->getAmount());
        foodT.item(i,0)->setData(Qt::UserRole,it->getID());
    }

    bookT.setSelectionBehavior(QAbstractItemView::SelectRows);
    elecT.setSelectionBehavior(QAbstractItemView::SelectRows);
    clothesT.setSelectionBehavior(QAbstractItemView::SelectRows);
    foodT.setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tabWidget->addTab(&bookT,QIcon(),"书籍");
    ui->tabWidget->addTab(&elecT,QIcon(),"电子");
    ui->tabWidget->addTab(&clothesT,QIcon(),"服装");
    ui->tabWidget->addTab(&foodT,QIcon(),"食品");
}

template <typename T>
T* MainWindow::find(QVector<T>& L, int id) {
    for (auto it = L.begin(); it != L.end(); it++) {
        if (it->getID() == id)
            return &(*it);
    }
    return nullptr;
}

void MainWindow::on_userB_clicked()
{
    if(login){
        int comf=QMessageBox::question(this,"登出","确定退出登录吗？"
                                         ,QMessageBox::Ok,QMessageBox::Cancel);
        if(comf!=QMessageBox::Ok){
            readAndShowGoods();
            return;
        }
        u=User();
        c=Cart();
        login=false;
        ui->userLabel->setText("用户未登录");
        ui->userB->setText("登录/注册");
        ui->bankB->hide();
        ui->boughtB->hide();
        ui->addB->hide();
        ui->cartB->setText("我的购物车(0)");
        ui->cartB->hide();
        readAndShowGoods();
        return;
    }

    SignInDialog dia(&u,this);
    dia.setWindowModality(Qt::ApplicationModal);
    dia.exec();
    if(dia.result()==QDialog::Accepted){
        login=true;
        ui->userLabel->setText(QString("欢迎光临，%1").arg(u.getName()));
        ui->userB->setText("退出登录");
        ui->bankB->show();
        ui->boughtB->show();
        ui->addB->show();
        ui->cartB->show();
        readAndShowGoods();
        readCart();
        readCards();
        return;
    }
    else{
        u=User();
        c=Cart();
        login=false;
        ui->userLabel->setText("用户未登录");
        ui->userB->setText("登录/注册");
        readAndShowGoods();
        return;
    }

}

void MainWindow::on_addB_clicked()
{
    QTableWidget* t = dynamic_cast<QTableWidget*>(ui->tabWidget->currentWidget());
    if (t == nullptr) {
        QMessageBox::information(this, "FATAL ERROR",
                                 "mainwindow.cpp:on_addB_clicked():获取tabWidget当前页QTableWidget*转换失败");
        return;
    }

    // 保存当前分类索引和选中行
    int currentIndex = ui->tabWidget->currentIndex();
    int r = t->currentRow();

    // 检查是否选中商品
    if (r == -1) {
        QMessageBox::information(this, "未选择商品", "未选择商品，请重试");
        return;
    }

    // 保存原始商品ID
    int chooseid = t->item(r, 0)->data(Qt::UserRole).toInt();

    // 刷新商品列表（可能导致行号变化）
    readAndShowGoods();

    // 重新获取当前分类的表格控件
    ui->tabWidget->setCurrentIndex(currentIndex);
    t = dynamic_cast<QTableWidget*>(ui->tabWidget->currentWidget());
    if (!t) {
        QMessageBox::critical(this, "错误", "无法加载商品列表");
        return;
    }

    // 根据商品ID重新定位行号
    int newRow = -1;
    for (int i = 0; i < t->rowCount(); ++i) {
        if (t->item(i, 0)->data(Qt::UserRole).toInt() == chooseid) {
            newRow = i;
            break;
        }
    }

    // 处理商品不存在的情况
    if (newRow == -1) {
        QMessageBox::information(this, "错误", "商品已不存在，请重新选择");
        return;
    }

    // 设置新的选中行并验证ID
    t->setCurrentCell(newRow, 0);
    int id = t->item(newRow, 0)->data(Qt::UserRole).toInt();
    if (id != chooseid) {
        QMessageBox::information(this, "错误", "商品发生意外变动");
        return;
    }

    // 获取最新库存数据
    QString name = t->item(newRow, 0)->text();
    int restAmount = t->item(newRow, 4)->data(Qt::UserRole).toInt();

    // 检查库存
    if (restAmount <= 0) {
        QMessageBox::information(this, "库存不足！", "抱歉，您选择的商品库存不足");
        return;
    }

    // 根据分类处理商品添加逻辑
    int categoryIndex = ui->tabWidget->currentIndex();
    switch (categoryIndex) {
    case 0: { // Book
        QString author = t->item(newRow, 1)->text();
        QString desc = t->item(newRow, 2)->text();
        double price = t->item(newRow, 3)->data(Qt::UserRole).toDouble();
        bool ask = false;
        int amount = QInputDialog::getInt(this, "输入购买数量", "请输入购买数量：", 0, 0, restAmount, 1, &ask);
        if (amount == 0 || !ask) return;
        Book* b = new Book(id, name, desc, price, amount, author);
        c.addProduct(b);
        break;
    }
    case 1: { // Elec
        QString brand = t->item(newRow, 1)->text();
        QString desc = t->item(newRow, 2)->text();
        double price = t->item(newRow, 3)->data(Qt::UserRole).toDouble();
        bool ask = false;
        int amount = QInputDialog::getInt(this, "输入购买数量", "请输入购买数量：", 0, 0, restAmount, 1, &ask);
        if (amount == 0 || !ask) return;
        Elec* e = new Elec(id, name, desc, price, amount, brand);
        c.addProduct(e);
        break;
    }
    case 2: { // Clothes
        QString sexs = t->item(newRow, 1)->text();
        Clothes::Sex sex = Clothes::General;
        if (sexs == "男装") sex = Clothes::Male;
        else if (sexs == "女装") sex = Clothes::Female;
        QString desc = t->item(newRow, 2)->text();
        double price = t->item(newRow, 3)->data(Qt::UserRole).toDouble();
        bool ask = false;
        int amount = QInputDialog::getInt(this, "输入购买数量", "请输入购买数量：", 0, 0, restAmount, 1, &ask);
        if (amount == 0 || !ask) return;
        Clothes* clo = new Clothes(id, name, desc, price, amount, sex);
        c.addProduct(clo);
        break;
    }
    case 3: { // Food
        QString desc = t->item(newRow, 1)->text();
        double price = t->item(newRow, 2)->data(Qt::UserRole).toDouble();
        QDate date = QDate::fromString(t->item(newRow, 3)->text());
        bool ask = false;
        int amount = QInputDialog::getInt(this, "输入购买数量", "请输入购买数量：", 0, 0, restAmount, 1, &ask);
        if (amount == 0 || !ask) return;
        Food* f = new Food(id, name, desc, price, amount, date);
        c.addProduct(f);
        break;
    }
    }

    // 更新购物车显示
    ui->cartB->setText(QString("我的购物车(%1)").arg(c.getSize()));
    saveCart();
    readCart();
}

void MainWindow::on_cartB_clicked()
{
    CartDialog dia(&c,&u,this);
    connect(&dia,SIGNAL(delFromCart(int)),this,SLOT(removeFromCart(int)));
    connect(&dia,SIGNAL(pay()),this,SLOT(payCart()));
    dia.setWindowModality(Qt::ApplicationModal);
    dia.exec();
}

void MainWindow::removeFromCart(int index){
    c.delProduct(index);
    ui->cartB->setText(QString("我的购物车(%1)").arg(c.getSize()));
    saveCart();
    readCart();
}

bool MainWindow::saveCart(){
    QSqlDatabase db=QSqlDatabase::database();
    if(!db.open()){
        QMessageBox::information(this,"无法保存购物车","无法连接到数据库");
        return false;
    }
    QString tableName=QString("%1_cart").arg(u.getName());
    QSqlQuery q;
    q.prepare(QString("delete from %1").arg(tableName));
    if(!q.exec()){
        QMessageBox::information(this,"保存购物车失败"
                                 ,"保存购物车失败:无法清空表");
        return false;
    }

    vector<Product*> p=c.getListCopy();
    for(auto it=p.begin();it!=p.end();it++){
        Product* &itp=*it;
        if(itp->type()==0)continue;
        int typeCode=itp->type();
        int id=itp->getID();
        id=id*1000+typeCode;
        q.prepare(QString("select amount from %1 "
                          "where id =?").arg(tableName));
        q.addBindValue(id);
        q.exec();
        if(q.next()){//重复商品
            int amount=q.value(0).toInt();
            q.prepare(QString("update %1 set amount=? "
                              "where id=?").arg(tableName));
            q.addBindValue(amount+itp->getAmount());
            q.addBindValue(id);
            if(!q.exec()){
                QMessageBox::information(this,"保存购物车"
                                         ,QString("一项商品添加失败:%1").arg(itp->getName()));
            }
        }
        else{
            q.prepare(QString("insert into %1(id,amount,name) "
                              "values(?,?,?)").arg(tableName));
            q.addBindValue(id);
            q.addBindValue(itp->getAmount());
            q.addBindValue(itp->getName());
            if(!q.exec()){
                QMessageBox::information(this,"保存购物车"
                                         ,QString("一项商品保存失败:%1").arg(itp->getName()));
            }
        }
    }
    return true;
}

void MainWindow::readCart(){
    QSqlDatabase db=QSqlDatabase::database();
    if(!db.open()){
        return;
    }
    QString tableName=QString("%1_cart").arg(u.getName());
    QSqlQuery q;
    q.prepare(QString("select id,amount from %1").arg(tableName));
    if(!q.exec()){
        return;
    }
    c.clear();
    while(q.next()){
        int id=q.value(0).toInt();
        int type=id%1000;
        id=id/1000;
        int amount=q.value(1).toInt();

        if(type==0)continue;
        else if(type==1){//Book
            Book* b=find<Book>(bookL,id);
            Book* b_=new Book(b->getID(),b->getName()
                                ,b->getDesc(),b->getPrice()
                                ,amount,b->getAuthor());
            c.addProduct(b_);
        }
        else if(type==2){//Elec
            Elec* b=find<Elec>(elecL,id);
            Elec* b_=new Elec(b->getID(),b->getName()
                                ,b->getDesc(),b->getPrice()
                                ,amount,b->getBrand());
            c.addProduct(b_);
        }
        else if(type==3){//Clothes
            Clothes* b=find<Clothes>(clothesL,id);
            Clothes* b_=new Clothes(b->getID(),b->getName()
                                      ,b->getDesc(),b->getPrice()
                                      ,amount,b->getSex());
            c.addProduct(b_);
        }
        else if(type==4){//Food
            Food* b=find<Food>(foodL,id);
            Food* b_=new Food(b->getID(),b->getName()
                                ,b->getDesc(),b->getPrice()
                                ,amount,b->getDate());
            c.addProduct(b_);
        }
    }
    ui->cartB->setText(QString("我的购物车(%1)").arg(c.getSize()));
}

void MainWindow::readCards(){
    QSqlDatabase db=QSqlDatabase::database();
    if(!db.open()){
        QMessageBox::information(this,"获取绑定银行卡失败"
                                 ,"获取绑定银行卡失败：无法连接到数据库，请重试。");
        return;
    }
    QSqlQuery q;
    q.prepare("select bankID, accountID from bankCard where name=?");
    q.addBindValue(u.getName());
    if(!q.exec()){
        QMessageBox::information(this,"获取绑定银行卡失败"
                                 ,"获取绑定银行卡失败：无法查询数据库，请重试。");
        return;
    }
    cards.clear();
    while(q.next()){
        int bankID=q.value(0).toInt();
        QString accountID=q.value(1).toString();
        BankCard bc(bankID,accountID);
        cards.push_back(bc);
    }
}

void MainWindow::on_bankB_clicked()
{
    BankDialog dia(&u,&cards,this);
    if(!dia.initSuccess())
        return;
    connect(&dia,SIGNAL(updateCards()),this,SLOT(readCards()));
    dia.exec();
}

void MainWindow::payCart(){
    readAndShowGoods();
    vector<Product*> p=c.getListCopy();
    for(auto it=p.begin();it!=p.end();it++){//检查库存
        if(dynamic_cast<Book*>(*it)){
            Book* b=dynamic_cast<Book*>(*it);//in cart
            Book* s=find<Book>(bookL,b->getID());//stock
            if(!s||s->getAmount() < b->getAmount()){
                QMessageBox::information(this,"库存不足"
                                         ,QString("商品 %1 的库存不足了，请调整购物车")
                                             .arg(b->getName()));
                return;
            }
        }
        else if(dynamic_cast<Elec*>(*it)){
            Elec* b=dynamic_cast<Elec*>(*it);//in cart
            Elec* s=find<Elec>(elecL,b->getID());//stock
            if(!s||s->getAmount() < b->getAmount()){
                QMessageBox::information(this,"库存不足"
                                         ,QString("商品 %1 的库存不足了，请调整购物车")
                                             .arg(b->getName()));
                return;
            }
        }
        else if(dynamic_cast<Clothes*>(*it)){
            Clothes* b=dynamic_cast<Clothes*>(*it);//in cart
            Clothes* s=find<Clothes>(clothesL,b->getID());//stock
            if(!s||s->getAmount() < b->getAmount()){
                QMessageBox::information(this,"库存不足"
                                         ,QString("商品 %1 的库存不足了，请调整购物车")
                                             .arg(b->getName()));
                return;
            }
        }
        else if(dynamic_cast<Food*>(*it)){
            Food* b=dynamic_cast<Food*>(*it);//in cart
            Food* s=find<Food>(foodL,b->getID());//stock
            if(!s||s->getAmount() < b->getAmount()){
                QMessageBox::information(this,"库存不足"
                                         ,QString("商品 %1 的库存不足了，请调整购物车")
                                             .arg(b->getName()));
                return;
            }
        }
    }

    PayDialog dia(c.countPrice(),&cards,this);
    dia.setWindowModality(Qt::ApplicationModal);
    connect(&dia,SIGNAL(payOK()),this,SLOT(payOK()));
    connect(&dia,SIGNAL(payAbort()),this,SLOT(payAbort()));
    dia.exec();
}

void MainWindow::payOK(){
    QMessageBox::information(this,"支付成功"
                             ,"去\"已买到的宝贝\"看看吧！");
    bought=c;
    saveBought();
    c.clear();
    bought.clearP();
    saveCart();
    readCart();
}

void MainWindow::payAbort(){
    QMessageBox::information(this,"支付操作中止"
                             ,"支付操作被用户中止，但是支付请求已经向银行发出。\n"
                             "这意味着如果银行卡密码正确，余额充足，银行端非常可能已经完成了这一笔扣款。\n"
                             "请务必检查您的银行卡账户，如果对订单有疑问，请联系客服。");
    return;
}

void MainWindow::saveBought(){
    QSqlDatabase db=QSqlDatabase::database();
    if(!db.open()){
        QMessageBox::information(this,"无法保存已买到的宝贝","无法连接到数据库");
        return;
    }
    QString tableName=QString("%1_bought").arg(u.getName());
    QSqlQuery q;

    vector<Product*> p=bought.getListCopy();
    for(auto it=p.begin();it!=p.end();it++){
        Product* &itp=*it;
        if(itp->type()==0)continue;
        int typeCode=itp->type();
        int id=itp->getID();
        id=id*1000+typeCode;
        q.prepare(QString("select amount from %1 "
                          "where id=?").arg(tableName));
        q.addBindValue(id);
        q.exec();
        if(q.next()){//重复商品
            int amount=q.value(0).toInt();
            q.prepare(QString("update %1 set amount=? "
                              "where id=?").arg(tableName));
            q.addBindValue(amount+itp->getAmount());
            q.addBindValue(id);
            if(!q.exec()){
                QMessageBox::information(this,"保存已买到的宝贝"
                                         ,QString("一项商品增加失败:%1").arg(itp->getName()));
            }
        }
        else{
            q.prepare(QString("insert into %1(id,amount,name) "
                              "values(?,?,?)").arg(tableName));
            q.addBindValue(id);
            q.addBindValue(itp->getAmount());
            q.addBindValue(itp->getName());
            if(!q.exec()){
                QMessageBox::information(this,"保存已买到的宝贝"
                                         ,QString("一项商品保存失败:%1").arg(itp->getName()));
            }
        }
    }
}



void MainWindow::on_categoryButtonClicked(int id)
{
    currentCategory = id;

    // 清除旧的子分类按钮
    QList<QAbstractButton*> subcategoryButtons = subcategoryButtonGroup->buttons();
    for (QAbstractButton* button : subcategoryButtons) {
        subcategoryButtonGroup->removeButton(button);
        delete button;
    }

    // 生成新的子分类按钮布局，包含返回按钮
    QVBoxLayout *subcategoryLayout = new QVBoxLayout; // 使用垂直布局，方便上下排列按钮

    // 创建返回按钮
    QPushButton *backButton = new QPushButton("返回主分类", this);
    subcategoryLayout->addWidget(backButton);
    connect(backButton, &QPushButton::clicked, this, &MainWindow::setupMainCategoryButtons);

    // 创建子分类按钮的水平布局
    QHBoxLayout *subcategoryButtonLayout = new QHBoxLayout;

    switch (currentCategory) {
    case 0: // 书籍
    {
        QPushButton *allButton = new QPushButton("全部", this);
        QPushButton *novelButton = new QPushButton("小说", this);
        QPushButton *artButton = new QPushButton("政治与哲学", this);
        QPushButton *textbookButton = new QPushButton("教科书", this);
        QPushButton *comicButton = new QPushButton("漫画", this);

        subcategoryButtonGroup->addButton(allButton, 0);
        subcategoryButtonGroup->addButton(novelButton, 1);
        subcategoryButtonGroup->addButton(artButton, 2);
        subcategoryButtonGroup->addButton(textbookButton, 3);
        subcategoryButtonGroup->addButton(comicButton, 4);

        subcategoryButtonLayout->addWidget(allButton);
        subcategoryButtonLayout->addWidget(novelButton);
        subcategoryButtonLayout->addWidget(artButton);
        subcategoryButtonLayout->addWidget(textbookButton);
        subcategoryButtonLayout->addWidget(comicButton);
        break;
    }
    case 1: // 电子
    {
        QPushButton *allButton = new QPushButton("全部", this);
        QPushButton *gpuButton = new QPushButton("显卡", this);
        QPushButton *cpuButton = new QPushButton("CPU", this);
        QPushButton *peripheralButton = new QPushButton("外设", this);
        QPushButton *networkButton = new QPushButton("网络设备", this);
        QPushButton *audioButton = new QPushButton("音频设备", this);

        subcategoryButtonGroup->addButton(allButton, 0);
        subcategoryButtonGroup->addButton(gpuButton, 1);
        subcategoryButtonGroup->addButton(cpuButton, 2);
        subcategoryButtonGroup->addButton(peripheralButton, 3);
        subcategoryButtonGroup->addButton(networkButton, 4);
        subcategoryButtonGroup->addButton(audioButton, 5);

        subcategoryButtonLayout->addWidget(allButton);
        subcategoryButtonLayout->addWidget(gpuButton);
        subcategoryButtonLayout->addWidget(cpuButton);
        subcategoryButtonLayout->addWidget(peripheralButton);
        subcategoryButtonLayout->addWidget(networkButton);
        subcategoryButtonLayout->addWidget(audioButton);
        break;
    }
    case 2: // 服装
    {
        QPushButton *allButton = new QPushButton("全部", this);
        QPushButton *pantsButton = new QPushButton("裤子", this);
        QPushButton *skirtButton = new QPushButton("裙子", this);
        QPushButton *coatButton = new QPushButton("羽绒服", this);
        QPushButton *sweatshirtButton = new QPushButton("卫衣", this);

        subcategoryButtonGroup->addButton(allButton, 0);
        subcategoryButtonGroup->addButton(pantsButton, 1);
        subcategoryButtonGroup->addButton(skirtButton, 2);
        subcategoryButtonGroup->addButton(coatButton, 3);
        subcategoryButtonGroup->addButton(sweatshirtButton, 4);

        subcategoryButtonLayout->addWidget(allButton);
        subcategoryButtonLayout->addWidget(pantsButton);
        subcategoryButtonLayout->addWidget(skirtButton);
        subcategoryButtonLayout->addWidget(coatButton);
        subcategoryButtonLayout->addWidget(sweatshirtButton);
        break;
    }
    case 3: // 食品
    {
        QPushButton *allButton = new QPushButton("全部", this);
        QPushButton *snackButton = new QPushButton("零食", this);
        QPushButton *drinkButton = new QPushButton("酒水", this);
        QPushButton *bakeryButton = new QPushButton("烘培", this);
        QPushButton *stapleButton = new QPushButton("口粮", this);

        subcategoryButtonGroup->addButton(allButton, 0);
        subcategoryButtonGroup->addButton(snackButton, 1);
        subcategoryButtonGroup->addButton(drinkButton, 2);
        subcategoryButtonGroup->addButton(bakeryButton, 3);
        subcategoryButtonGroup->addButton(stapleButton, 4);

        subcategoryButtonLayout->addWidget(allButton);
        subcategoryButtonLayout->addWidget(snackButton);
        subcategoryButtonLayout->addWidget(drinkButton);
        subcategoryButtonLayout->addWidget(bakeryButton);
        subcategoryButtonLayout->addWidget(stapleButton);
        break;
    }
    }

    // 将子分类按钮的水平布局添加到垂直布局中
    subcategoryLayout->addLayout(subcategoryButtonLayout);

    // 设置到容器控件
    QWidget *subcategoryContainer = ui->widget;
    if (subcategoryContainer) {
        // 清空旧布局
        if (subcategoryContainer->layout()) {
            QLayoutItem *item;
            while ((item = subcategoryContainer->layout()->takeAt(0))){
                delete item->widget();
                delete item;
            }
            delete subcategoryContainer->layout();
        }
        // 设置新布局
        subcategoryContainer->setLayout(subcategoryLayout);
    }
}

void MainWindow::on_subcategoryButtonClicked(int id)
{
    QVector<Product*> filteredGoods;

    switch (currentCategory) {
    case 0: // 书籍
    {
        switch (id) {
        case 0: // 全部
            for (auto& book : bookL) {
                filteredGoods.push_back(&book);
            }
            break;
        case 1: // 小说
            for (auto& book : bookL) {
                if (book.type() == 1 && book.getDesc().contains("小说")) {
                    filteredGoods.push_back(&book);
                }
            }
            break;
        case 2: // 政治与哲学
            for (auto& book : bookL) {
                if (book.type() == 1 && book.getDesc().contains("政治与哲学")) {
                    filteredGoods.push_back(&book);
                }
            }
            break;
        case 3: // 教科书
            for (auto& book : bookL) {
                if (book.type() == 1 && book.getDesc().contains("教科书")) {
                    filteredGoods.push_back(&book);
                }
            }
            break;
        case 4: // 政治与哲学
            for (auto& book : bookL) {
                if (book.type() == 1 && book.getDesc().contains("漫画")) {
                    filteredGoods.push_back(&book);
                }
            }
        }
        break;
    }
    case 1: // 电子
    {
        switch (id) {
        case 0: // 全部
            for (auto& elec : elecL) {
                filteredGoods.push_back(&elec);
            }
            break;
        case 1: // 显卡
            for (auto& elec : elecL) {
                if (elec.type() == 2 && elec.getDesc().contains("显卡")) {
                    filteredGoods.push_back(&elec);
                }
            }
            break;
        case 2: // 工业电子
            for (auto& elec : elecL) {
                if (elec.type() == 2 && elec.getDesc().contains("CPU")) {
                    filteredGoods.push_back(&elec);
                }
            }
            break;
        case 3: // 工业电子
            for (auto& elec : elecL) {
                if (elec.type() == 2 && elec.getDesc().contains("外设")) {
                    filteredGoods.push_back(&elec);
                }
            }
            break;
        case 4: // 工业电子
            for (auto& elec : elecL) {
                if (elec.type() == 2 && elec.getDesc().contains("网络设备")) {
                    filteredGoods.push_back(&elec);
                }
            }
            break;
        case 5: // 工业电子
            for (auto& elec : elecL) {
                if (elec.type() == 2 && elec.getDesc().contains("音频设备")) {
                    filteredGoods.push_back(&elec);
                }
            }
            break;
        }
        break;
    }
    case 2: // 服装
    {
        switch (id) {
        case 0: // 全部
            for (auto& clothes : clothesL) {
                filteredGoods.push_back(&clothes);
            }
            break;
        case 1: // 裤子
            for (auto& clothes : clothesL) {
                if (clothes.type() == 3 && clothes.getDesc().contains("裤子")) {
                    filteredGoods.push_back(&clothes);
                }
            }
            break;
        case 2: // 裙子
            for (auto& clothes : clothesL) {
                if (clothes.type() == 3 && clothes.getDesc().contains("裙子")) {
                    filteredGoods.push_back(&clothes);
                }
            }
            break;
        case 3: // 羽绒服
            for (auto& clothes : clothesL) {
                if (clothes.type() == 3 && clothes.getDesc().contains("羽绒服")) {
                    filteredGoods.push_back(&clothes);
                }
            }
            break;
        case 4: // 卫衣
            for (auto& clothes : clothesL) {
                if (clothes.type() == 3 && clothes.getDesc().contains("卫衣")) {
                    filteredGoods.push_back(&clothes);
                }
            }
            break;
        }
        break;
    }
    case 3: // 食品
    {
        switch (id) {
        case 0: // 全部
            for (auto& food : foodL) {
                filteredGoods.push_back(&food);
            }
            break;
        case 1: // 零食
            for (auto& food : foodL) {
                if (food.type() == 4 && food.getDesc().contains("零食")) {
                    filteredGoods.push_back(&food);
                }
            }
            break;
        case 2: // 饮料
            for (auto& food : foodL) {
                if (food.type() == 4 && food.getDesc().contains("酒水")) {
                    filteredGoods.push_back(&food);
                }
            }
            break;
        case 3: // 蔬菜
            for (auto& food : foodL) {
                if (food.type() == 4 && food.getDesc().contains("烘培")) {
                    filteredGoods.push_back(&food);
                }
            }
            break;
        case 4: // 肉类
            for (auto& food : foodL) {
                if (food.type() == 4 && food.getDesc().contains("口粮")) {
                    filteredGoods.push_back(&food);
                }
            }
            break;
        }
        break;
    }
    }

    // 显示过滤后的商品列表
    QTableWidget *currentTable;
    switch (currentCategory) {
    case 0:
        currentTable = &bookT;
        break;
    case 1:
        currentTable = &elecT;
        break;
    case 2:
        currentTable = &clothesT;
        break;
    case 3:
        currentTable = &foodT;
        break;
    default:
        return;
    }

    currentTable->clear();
    currentTable->setColumnCount(4);
    currentTable->setRowCount(filteredGoods.size());
    currentTable->setHorizontalHeaderLabels(QStringList()
                                            << "名称"
                                            << "类型"
                                            << "价格"
                                            << "库存量");
    for (auto it = filteredGoods.begin(); it != filteredGoods.end(); it++) {
        int i = it - filteredGoods.begin();
        currentTable->setItem(i, 0, new QTableWidgetItem((*it)->getName()));
        currentTable->setItem(i, 1, new QTableWidgetItem((*it)->getDesc()));
        currentTable->setItem(i, 2, new QTableWidgetItem(QString("%1 元").arg((*it)->getPrice())));
        currentTable->setItem(i, 3, new QTableWidgetItem(QString("%1 件").arg((*it)->getAmount())));
        currentTable->setItem(i, 4, new QTableWidgetItem(QString::number((*it)->type())));
        currentTable->item(i, 2)->setData(Qt::UserRole, (*it)->getPrice());
        currentTable->item(i, 3)->setData(Qt::UserRole, (*it)->getAmount());
        currentTable->item(i, 0)->setData(Qt::UserRole, (*it)->getID());
    }
}







void MainWindow::readBought(){
    QSqlDatabase db=QSqlDatabase::database();
    if(!db.open()){
        QMessageBox::information(this,"无法获取已买到的宝贝"
                                 ,"无法获取已买到的宝贝:无法连接到数据库");
        return;
    }
    QString tableName=QString("%1_bought").arg(u.getName());
    QSqlQuery q;
    q.prepare(QString("select id,amount from %1").arg(tableName));
    if(!q.exec()){
        QMessageBox::information(this,"无法获取已买到的宝贝"
                                 ,"无法获取已买到的宝贝:无法查询数据库");
        return;
    }
    bought=Cart();
    while(q.next()){
        int id=q.value(0).toInt();
        int type=id%1000;
        id=id/1000;
        int amount=q.value(1).toInt();

        if(type==0)continue;
        else if(type==1){//Book
            Book* b=find<Book>(bookL,id);
            Book* b_=new Book(b->getID(),b->getName()
                                ,b->getDesc(),b->getPrice()
                                ,amount,b->getAuthor());
            bought.addProduct(b_);
        }
        else if(type==2){//Elec
            Elec* b=find<Elec>(elecL,id);
            Elec* b_=new Elec(b->getID(),b->getName()
                                ,b->getDesc(),b->getPrice()
                                ,amount,b->getBrand());
            bought.addProduct(b_);
        }
        else if(type==3){//Clothes
            Clothes* b=find<Clothes>(clothesL,id);
            Clothes* b_=new Clothes(b->getID(),b->getName()
                                      ,b->getDesc(),b->getPrice()
                                      ,amount,b->getSex());
            bought.addProduct(b_);
        }
        else if(type==4){//Food
            Food* b=find<Food>(foodL,id);
            Food* b_=new Food(b->getID(),b->getName()
                                ,b->getDesc(),b->getPrice()
                                ,amount,b->getDate());
            bought.addProduct(b_);
        }
    }
}

void MainWindow::on_boughtB_clicked()
{
    readBought();
    if(bought.getSize()==0){
        QMessageBox::information(this,
                                 "还没有买到的宝贝",
                                 "还没有买到的宝贝");
        return;
    }
    BoughtDialog dia(&bought);
    dia.exec();
}
void MainWindow::on_searchButton_clicked()
{
    QString searchText = ui->lineEdit->text(); // 获取用户输入
    SearchBooksByName(searchText);
}
