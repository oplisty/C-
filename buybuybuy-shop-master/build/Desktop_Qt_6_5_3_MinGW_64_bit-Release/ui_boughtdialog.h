/********************************************************************************
** Form generated from reading UI file 'boughtdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOUGHTDIALOG_H
#define UI_BOUGHTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_BoughtDialog
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;

    void setupUi(QDialog *BoughtDialog)
    {
        if (BoughtDialog->objectName().isEmpty())
            BoughtDialog->setObjectName("BoughtDialog");
        BoughtDialog->resize(400, 300);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/icons/box.png"), QSize(), QIcon::Normal, QIcon::Off);
        BoughtDialog->setWindowIcon(icon);
        BoughtDialog->setStyleSheet(QString::fromUtf8("QDialog{\n"
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
        verticalLayout = new QVBoxLayout(BoughtDialog);
        verticalLayout->setObjectName("verticalLayout");
        tableWidget = new QTableWidget(BoughtDialog);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setStyleSheet(QString::fromUtf8("QTableWidget{\n"
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
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setTabKeyNavigation(false);
        tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
        tableWidget->setGridStyle(Qt::SolidLine);

        verticalLayout->addWidget(tableWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(BoughtDialog);
        pushButton->setObjectName("pushButton");
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(BoughtDialog);
        QObject::connect(pushButton, &QPushButton::clicked, BoughtDialog, qOverload<>(&QDialog::accept));

        QMetaObject::connectSlotsByName(BoughtDialog);
    } // setupUi

    void retranslateUi(QDialog *BoughtDialog)
    {
        BoughtDialog->setWindowTitle(QCoreApplication::translate("BoughtDialog", "\345\267\262\344\271\260\345\210\260\347\232\204\345\256\235\350\264\235", nullptr));
        pushButton->setText(QCoreApplication::translate("BoughtDialog", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BoughtDialog: public Ui_BoughtDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOUGHTDIALOG_H
