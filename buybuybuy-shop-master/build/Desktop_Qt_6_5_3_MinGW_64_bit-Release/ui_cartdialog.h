/********************************************************************************
** Form generated from reading UI file 'cartdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARTDIALOG_H
#define UI_CARTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CartDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *delB;
    QTableWidget *tableWidget;
    QLabel *saleL;
    QLabel *countL;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *payB;
    QPushButton *cancelB;

    void setupUi(QDialog *CartDialog)
    {
        if (CartDialog->objectName().isEmpty())
            CartDialog->setObjectName("CartDialog");
        CartDialog->resize(632, 551);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/icons/cart.png"), QSize(), QIcon::Normal, QIcon::Off);
        CartDialog->setWindowIcon(icon);
        CartDialog->setStyleSheet(QString::fromUtf8("QDialog\n"
"{\n"
"	border:0.5px solid white;\n"
"	border-radius:6px;\n"
"	\n"
"	background-color: rgb(233, 255, 224);\n"
"	min-width:80px;\n"
"	font-family:\"Microsoft YaHei\";\n"
"	font-size:11pt;\n"
"	font-weight:bold;\n"
"	color:white;\n"
"}\n"
"\n"
""));
        verticalLayout = new QVBoxLayout(CartDialog);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_2 = new QLabel(CartDialog);
        label_2->setObjectName("label_2");
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMinimumSize(QSize(30, 30));
        label_2->setMaximumSize(QSize(30, 30));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/new/icons/icon.png")));
        label_2->setScaledContents(true);

        horizontalLayout->addWidget(label_2);

        label = new QLabel(CartDialog);
        label->setObjectName("label");
        QFont font;
        font.setFamilies({QString::fromUtf8("Microsoft YaHei")});
        font.setPointSize(15);
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	\n"
"	background-color:rgb(233, 255, 224);\n"
"	min-width:80px;\n"
"	font-family:\"Microsoft YaHei\";\n"
"	font-size:15pt;\n"
"	font-weight:bold;\n"
"	color:blue;\n"
"}\n"
"\n"
""));

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        delB = new QPushButton(CartDialog);
        delB->setObjectName("delB");
        delB->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 0.5px solid white;\n"
"	border-radius: 6px;\n"
"	background-color: rgb(90, 194, 198);\n"
"	min-width: 80px;\n"
"	font-family: \"Microsoft YaHei\";\n"
"	font-size: 11pt;\n"
"	font-weight: bold;\n"
"	color: white;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #1fab89;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #178f75;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"	background-color: gray;\n"
"	color: lightgray;\n"
"}\n"
""));

        horizontalLayout->addWidget(delB);


        verticalLayout->addLayout(horizontalLayout);

        tableWidget = new QTableWidget(CartDialog);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setStyleSheet(QString::fromUtf8("QTableWidget{\n"
"	border:0.5px solid black;\n"
"	border-radius:6px;\n"
"	\n"
"	background-color: rgb(233, 255, 224);\n"
"	min-width:80px;\n"
"	font-family:\"Microsoft YaHei\";\n"
"	font-size:11pt;\n"
"	font-weight:bold;\n"
"	color:white;\n"
"}\n"
"\n"
""));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout->addWidget(tableWidget);

        saleL = new QLabel(CartDialog);
        saleL->setObjectName("saleL");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221 Light")});
        font1.setPointSize(11);
        saleL->setFont(font1);
        saleL->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(saleL);

        countL = new QLabel(CartDialog);
        countL->setObjectName("countL");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font2.setPointSize(14);
        font2.setBold(true);
        countL->setFont(font2);
        countL->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(countL);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        payB = new QPushButton(CartDialog);
        payB->setObjectName("payB");

        horizontalLayout_2->addWidget(payB);

        cancelB = new QPushButton(CartDialog);
        cancelB->setObjectName("cancelB");

        horizontalLayout_2->addWidget(cancelB);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(CartDialog);

        QMetaObject::connectSlotsByName(CartDialog);
    } // setupUi

    void retranslateUi(QDialog *CartDialog)
    {
        CartDialog->setWindowTitle(QCoreApplication::translate("CartDialog", "\346\210\221\347\232\204\350\264\255\347\211\251\350\275\246", nullptr));
        label_2->setText(QString());
        label->setText(QCoreApplication::translate("CartDialog", "\346\210\221\347\232\204\350\264\255\347\211\251\350\275\246", nullptr));
        delB->setText(QCoreApplication::translate("CartDialog", "\345\210\240\351\231\244\350\277\231\344\270\200\351\241\271", nullptr));
        saleL->setText(QString());
        countL->setText(QCoreApplication::translate("CartDialog", "\345\205\261\351\234\200\346\224\257\344\273\230: \344\270\215\345\217\257\347\224\250", nullptr));
        payB->setText(QCoreApplication::translate("CartDialog", "\347\273\223\347\256\227", nullptr));
        cancelB->setText(QCoreApplication::translate("CartDialog", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CartDialog: public Ui_CartDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARTDIALOG_H
