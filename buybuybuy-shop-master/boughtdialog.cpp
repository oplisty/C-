#include "boughtdialog.h"
#include "ui_boughtdialog.h"

BoughtDialog::BoughtDialog(Cart* bought, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BoughtDialog),
    bought(bought),
    titleLabel(new QLabel(this))
{
    ui->setupUi(this);

    // 删除UI文件中默认的布局和控件
    delete ui->verticalLayout;  // 删除Qt Designer生成的布局

    // 创建新的布局
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(20, 15, 20, 15);
    mainLayout->setSpacing(15);

    // 设置对话框样式
    this->setStyleSheet(R"(
        QDialog {
            background-color: #f5f5f5;
            font-family: 微软雅黑;
        }
        QLabel#titleLabel {
            color: #333;
            font-size: 24px;
            font-weight: bold;
            qproperty-alignment: AlignCenter;
        }
        QTableWidget {
            background-color: white;
            border: 1px solid #e0e0e0;
            border-radius: 4px;
        }
        QHeaderView::section {
            background-color: #1890ff;
            color: white;
            padding: 8px;
            border: none;
        }
        QTableWidget::item {
            padding: 6px;
        }
    )");

    // 配置标题标签
    titleLabel->setObjectName("titleLabel");
    mainLayout->addWidget(titleLabel);

    // 配置表格控件
    ui->tableWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    mainLayout->addWidget(ui->tableWidget);

    // 根据数据更新界面
    if (bought->getSize() == 0) {
        titleLabel->setText("📭 当前没有已购买的商品");
        ui->tableWidget->hide();
        // 添加空状态图标
        QLabel *emptyIcon = new QLabel(this);
        emptyIcon->setPixmap(QPixmap(":/icons/empty-cart.png").scaled(100, 100, Qt::KeepAspectRatio));
        emptyIcon->setAlignment(Qt::AlignCenter);
        mainLayout->addWidget(emptyIcon);
    } else {
        titleLabel->setText("📦 以下是您已购买的商品");
        showCart();
        // 美化表格样式
        ui->tableWidget->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
        ui->tableWidget->verticalHeader()->setVisible(false);
        ui->tableWidget->setShowGrid(false);
        ui->tableWidget->setAlternatingRowColors(true);
        ui->tableWidget->setStyleSheet(R"(
            QTableWidget {
                alternate-background-color: #f8f9fa;
            }
            QTableWidget::item:selected {
                background-color: #e6f7ff;
            }
        )");
    }

    this->adjustSize();
}

void BoughtDialog::showCart()
{
    // 表格列配置
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "商品名称" << "商品描述" << "单价" << "数量");
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents);

    // 填充数据
    vector<Product*> products = bought->getListCopy();
    ui->tableWidget->setRowCount(products.size());

    for (size_t i = 0; i < products.size(); ++i) {
        Product* p = products[i];
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(p->getName()));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(p->getDesc()));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString("¥%1").arg(p->getPrice(), 0, 'f', 2)));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(p->getAmount())));

        // 设置数据对齐方式
        ui->tableWidget->item(i, 2)->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
        ui->tableWidget->item(i, 3)->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
    }
}

BoughtDialog::~BoughtDialog()
{
    delete ui;
}
