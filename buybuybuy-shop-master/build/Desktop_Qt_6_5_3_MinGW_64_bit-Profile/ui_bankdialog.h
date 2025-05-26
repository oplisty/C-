/********************************************************************************
** Form generated from reading UI file 'bankdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BANKDIALOG_H
#define UI_BANKDIALOG_H

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

class Ui_BankDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *addB;
    QPushButton *removeB;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_3;

    void setupUi(QDialog *BankDialog)
    {
        if (BankDialog->objectName().isEmpty())
            BankDialog->setObjectName("BankDialog");
        BankDialog->resize(440, 300);
        BankDialog->setMinimumSize(QSize(82, 300));
        BankDialog->setMaximumSize(QSize(600, 600));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/icons/wallet.png"), QSize(), QIcon::Normal, QIcon::Off);
        BankDialog->setWindowIcon(icon);
        BankDialog->setStyleSheet(QString::fromUtf8("QDialog{\n"
"	border:0.5px solid white;\n"
"	border-radius:6px;\n"
"	\n"
"	background-color: rgb(222, 255, 241);\n"
"	min-width:80px;\n"
"	font-family:\"Microsoft YaHei\";\n"
"	font-size:11pt;\n"
"	font-weight:bold;\n"
"	color:white;\n"
"}\n"
"\n"
""));
        verticalLayout = new QVBoxLayout(BankDialog);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(BankDialog);
        label->setObjectName("label");
        QFont font;
        font.setFamilies({QString::fromUtf8("Microsoft YaHei")});
        font.setPointSize(11);
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border:0.5px solid white;\n"
"	border-radius:6px;\n"
"	background-color:rgb(90,194,198);\n"
"	min-width:80px;\n"
"	font-family:\"Microsoft YaHei\";\n"
"	font-size:11pt;\n"
"	font-weight:bold;\n"
"	color:white;\n"
"}\n"
"\n"
""));

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        addB = new QPushButton(BankDialog);
        addB->setObjectName("addB");
        addB->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border:0.5px solid white;\n"
"	border-radius:6px;\n"
"	background-color:rgb(90,194,198);\n"
"	min-width:80px;\n"
"	font-family:\"Microsoft YaHei\";\n"
"	font-size:11pt;\n"
"	font-weight:bold;\n"
"	color:white;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	border:0.5px solid white;\n"
"	border-radius:6px;\n"
"	background:\"Microsoft YaHei\";\n"
"	font-size:10pt;\n"
"	font-weight:bold;\n"
"	color:white;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/icons/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        addB->setIcon(icon1);

        horizontalLayout->addWidget(addB);

        removeB = new QPushButton(BankDialog);
        removeB->setObjectName("removeB");
        removeB->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border:0.5px solid white;\n"
"	border-radius:6px;\n"
"	background-color:rgb(90,194,198);\n"
"	min-width:80px;\n"
"	font-family:\"Microsoft YaHei\";\n"
"	font-size:11pt;\n"
"	font-weight:bold;\n"
"	color:white;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	border:0.5px solid white;\n"
"	border-radius:6px;\n"
"	background:\"Microsoft YaHei\";\n"
"	font-size:10pt;\n"
"	font-weight:bold;\n"
"	color:white;\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/icons/remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        removeB->setIcon(icon2);

        horizontalLayout->addWidget(removeB);


        verticalLayout->addLayout(horizontalLayout);

        tableWidget = new QTableWidget(BankDialog);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setStyleSheet(QString::fromUtf8("QTableWidget{\n"
"	border:0.5px solid white;\n"
"	border-radius:6px;\n"
"	\n"
"	background-color: rgb(222, 255, 241);\n"
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

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton_3 = new QPushButton(BankDialog);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        horizontalLayout_2->addWidget(pushButton_3);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(BankDialog);
        QObject::connect(pushButton_3, &QPushButton::clicked, BankDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(BankDialog);
    } // setupUi

    void retranslateUi(QDialog *BankDialog)
    {
        BankDialog->setWindowTitle(QCoreApplication::translate("BankDialog", "\346\210\221\347\232\204\351\222\261\345\214\205", nullptr));
        label->setText(QCoreApplication::translate("BankDialog", "\346\210\221\347\273\221\345\256\232\347\232\204\351\223\266\350\241\214\345\215\241", nullptr));
        addB->setText(QCoreApplication::translate("BankDialog", "\347\273\221\345\256\232\346\226\260\351\223\266\350\241\214\345\215\241", nullptr));
        removeB->setText(QCoreApplication::translate("BankDialog", "\345\210\240\351\231\244\350\277\231\345\274\240\351\223\266\350\241\214\345\215\241", nullptr));
        pushButton_3->setText(QCoreApplication::translate("BankDialog", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BankDialog: public Ui_BankDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BANKDIALOG_H
