#include "boughtdialog.h"
#include "ui_boughtdialog.h"

BoughtDialog::BoughtDialog(Cart* bought, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BoughtDialog),
    bought(bought)
{
    ui->setupUi(this);

    // ==== 第一步：配置已有UI组件 ====
    // 1. 标签样式强化（你在UI文件中放置的QLabel）
    ui->label->setStyleSheet(R"(
        QLabel {
            color: #333;
            font-size: 20px;
            font-weight: 500;
            qproperty-alignment: AlignLeft|AlignTop;
        }
    )");
    ui->label->setContentsMargins(0, 0, 0, 15); // 下边距15px

    // 2. 返回按钮定位到右下角（你在UI文件中放置的QPushButton）
    QHBoxLayout *btnLayout = new QHBoxLayout();
    btnLayout->addStretch();
    btnLayout->addWidget(ui->pushButton);
    ui->verticalLayout->addLayout(btnLayout); // 使用你原有的垂直布局

    // 3. 表格样式优化（你在UI文件中放置的QTableWidget）
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
        // 保留你原有的widget容器（用于空状态显示）
        ui->tableWidget->setVisible(true);
        ui->tableWidget->setVisible(false);

        // 调整空状态标签样式
        ui->label->setStyleSheet(R"(
            QLabel {
                color: #666;
                font-size: 16px;
                qproperty-alignment: AlignCenter;
            }
        )");
    } else {
        ui->tableWidget->setVisible(false);
        showCart();
    }

    // ==== 第三步：窗口尺寸优化 ====
    this->setMinimumSize(600, 400); // 保持你UI文件中设计的控件比例
}

void BoughtDialog::showCart()
{
    // 使用你在UI文件中设计的表格列
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels(
        QStringList() << "商品名称" << "描述" << "单价" << "数量");

    // 列宽配置（兼容你的UI设计）
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents);

    // 数据填充（保持你原有的数据结构）
    vector<Product*> products = bought->getListCopy();
    ui->tableWidget->setRowCount(products.size());
    for (int i = 0; i < products.size(); ++i) {
        Product* p = products[i];
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(p->getName()));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(p->getDesc()));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString("¥%1").arg(p->getPrice(), 0, 'f', 2)));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(p->getAmount())));
    }
}

BoughtDialog::~BoughtDialog()
{
    delete ui;
}
