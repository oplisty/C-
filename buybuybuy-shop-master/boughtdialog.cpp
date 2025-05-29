#include "boughtdialog.h"
#include "ui_boughtdialog.h"

BoughtDialog::BoughtDialog(Cart* bought, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BoughtDialog),
    bought(bought)
{
    ui->setupUi(this);

    // ==== 第一步：配置已有UI组件 ====
    // 1. 标签样式强化（初始样式）
    ui->label->setStyleSheet(R"(
        QLabel {
            color: #333;
            font-size: 20px;
            font-weight: 500;
            qproperty-alignment: AlignLeft|AlignTop;
        }
    )");
    ui->label->setContentsMargins(0, 0, 0, 15); // 下边距15px

    // 2. 返回按钮定位到右下角
    QHBoxLayout *btnLayout = new QHBoxLayout();
    btnLayout->addStretch();
    btnLayout->addWidget(ui->pushButton);
    ui->verticalLayout->addLayout(btnLayout); // 使用原有垂直布局

    // 3. 表格样式优化
    ui->tableWidget->setStyleSheet(R"(
        QTableWidget {
            background-color: white;
            border: 1px solid #e0e0e0;
            alternate-background-color: #f8f9fa;
        }
        QHeaderView::section {
            background-color: #1890ff;
            color: white;
            padding: 10px;
        }
    )");

    // ==== 第二步：动态内容控制 ====
    if (bought->getSize() == 0) {
        // 空状态处理
        ui->label->setText("购物车为空");  // 设置提示文本

        // 空状态样式
        ui->label->setStyleSheet(R"(
            QLabel {
                color: #666;
                font-size: 16px;
                qproperty-alignment: AlignCenter;
            }
        )");

        // 隐藏表格
        ui->tableWidget->setVisible(false);
    } else {
        // 非空状态
        ui->label->setText("已购买商品");  // 设置标题文本
        ui->tableWidget->setVisible(false); // 先隐藏，填充数据后显示
        showCart();
    }

    // ==== 第三步：窗口尺寸优化 ====
    this->setMinimumSize(600, 400);
}

void BoughtDialog::showCart()
{
    // 配置表格
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels(
        QStringList() << "商品名称" << "描述" << "单价" << "数量");

    // 列宽配置
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents);

    // 填充数据
    vector<Product*> products = bought->getListCopy();
    ui->tableWidget->setRowCount(products.size());
    for (int i = 0; i < products.size(); ++i) {
        Product* p = products[i];
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(p->getName()));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(p->getDesc()));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString("¥%1").arg(p->getPrice(), 0, 'f', 2)));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(p->getAmount())));
    }

    // 关键：显示填充后的表格
    ui->tableWidget->setVisible(true);
}

BoughtDialog::~BoughtDialog()
{
    delete ui;
}
