/********************************************************************************
** Form generated from reading UI file 'paydialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAYDIALOG_H
#define UI_PAYDIALOG_H

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

class Ui_PayDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *waitGifL;
    QLabel *waitL;
    QSpacerItem *horizontalSpacer;
    QLabel *moneyL;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *payB;
    QPushButton *cancelB;

    void setupUi(QDialog *PayDialog)
    {
        if (PayDialog->objectName().isEmpty())
            PayDialog->setObjectName("PayDialog");
        PayDialog->resize(518, 355);
        PayDialog->setMaximumSize(QSize(518, 740));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/icons/wallet.png"), QSize(), QIcon::Normal, QIcon::Off);
        PayDialog->setWindowIcon(icon);
        PayDialog->setStyleSheet(QString::fromUtf8("QDialog{\n"
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
        verticalLayout = new QVBoxLayout(PayDialog);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(PayDialog);
        label->setObjectName("label");
        QFont font;
        font.setFamilies({QString::fromUtf8("Microsoft YaHei")});
        font.setPointSize(11);
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border: 0.5px solid white;\n"
"	border-radius: 6px;\n"
"	background-color: rgb(130, 205, 255);\n"
"	min-width: 80px;\n"
"	font-family: \"Microsoft YaHei\";\n"
"	font-size: 11pt;\n"
"	font-weight: bold;\n"
"	color: white;\n"
"}\n"
"\n"
""));

        verticalLayout->addWidget(label);

        tableWidget = new QTableWidget(PayDialog);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setMinimumSize(QSize(82, 200));
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

        verticalLayout->addWidget(tableWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        waitGifL = new QLabel(PayDialog);
        waitGifL->setObjectName("waitGifL");
        waitGifL->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border: 0.5px solid white;\n"
"	border-radius: 6px;\n"
"	background-color: rgb(130, 205, 255);\n"
"	min-width: 80px;\n"
"	font-family: \"Microsoft YaHei\";\n"
"	font-size: 11pt;\n"
"	font-weight: bold;\n"
"	color: white;\n"
"}\n"
"\n"
""));

        horizontalLayout->addWidget(waitGifL);

        waitL = new QLabel(PayDialog);
        waitL->setObjectName("waitL");
        waitL->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border: 0.5px solid white;\n"
"	border-radius: 6px;\n"
"	background-color: rgb(130, 205, 255);\n"
"	min-width: 80px;\n"
"	font-family: \"Microsoft YaHei\";\n"
"	font-size: 11pt;\n"
"	font-weight: bold;\n"
"	color: white;\n"
"}\n"
"\n"
""));

        horizontalLayout->addWidget(waitL);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        moneyL = new QLabel(PayDialog);
        moneyL->setObjectName("moneyL");
        moneyL->setFont(font);
        moneyL->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border: 0.5px solid white;\n"
"	border-radius: 6px;\n"
"	background-color: rgb(130, 205, 255);\n"
"	min-width: 80px;\n"
"	font-family: \"Microsoft YaHei\";\n"
"	font-size: 11pt;\n"
"	font-weight: bold;\n"
"	color: white;\n"
"}\n"
"\n"
""));
        moneyL->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(moneyL);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        payB = new QPushButton(PayDialog);
        payB->setObjectName("payB");
        payB->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        horizontalLayout_2->addWidget(payB);

        cancelB = new QPushButton(PayDialog);
        cancelB->setObjectName("cancelB");
        cancelB->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        horizontalLayout_2->addWidget(cancelB);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(PayDialog);

        QMetaObject::connectSlotsByName(PayDialog);
    } // setupUi

    void retranslateUi(QDialog *PayDialog)
    {
        PayDialog->setWindowTitle(QCoreApplication::translate("PayDialog", "\346\224\257\344\273\230", nullptr));
        label->setText(QCoreApplication::translate("PayDialog", "\351\200\211\346\213\251\344\270\200\345\274\240\351\223\266\350\241\214\345\215\241\346\224\257\344\273\230", nullptr));
        waitGifL->setText(QCoreApplication::translate("PayDialog", "TextLabel", nullptr));
        waitL->setText(QCoreApplication::translate("PayDialog", "TextLabel", nullptr));
        moneyL->setText(QCoreApplication::translate("PayDialog", "\345\205\261\351\234\200\346\224\257\344\273\230\357\274\232", nullptr));
        payB->setText(QCoreApplication::translate("PayDialog", "\346\224\257\344\273\230", nullptr));
        cancelB->setText(QCoreApplication::translate("PayDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PayDialog: public Ui_PayDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAYDIALOG_H
