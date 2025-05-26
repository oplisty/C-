/********************************************************************************
** Form generated from reading UI file 'binddialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BINDDIALOG_H
#define UI_BINDDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_BindDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QComboBox *bankSelect;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *accountIDIn;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *pwIn;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *applyB;
    QPushButton *cancelB;

    void setupUi(QDialog *BindDialog)
    {
        if (BindDialog->objectName().isEmpty())
            BindDialog->setObjectName("BindDialog");
        BindDialog->resize(400, 240);
        BindDialog->setMinimumSize(QSize(82, 233));
        BindDialog->setMaximumSize(QSize(400, 240));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/icons/wallet.png"), QSize(), QIcon::Normal, QIcon::Off);
        BindDialog->setWindowIcon(icon);
        BindDialog->setStyleSheet(QString::fromUtf8("QDialog{\n"
"	border:0.5px solid white;\n"
"	border-radius:6px;\n"
"	background-color:rgb(222,255,241);\n"
"	min-width:80px;\n"
"	font-family:\"Microsoft YaHei\";\n"
"	font-size:11pt;\n"
"	font-weight:bold;\n"
"	color:white;\n"
"}\n"
""));
        verticalLayout = new QVBoxLayout(BindDialog);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(BindDialog);
        label->setObjectName("label");
        QFont font;
        font.setFamilies({QString::fromUtf8("Microsoft YaHei")});
        font.setPointSize(20);
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border:1px solid white;\n"
"	border-radius:10px;\n"
"	\n"
"	\n"
"	background-color: rgb(101, 229, 255);\n"
"	min-width:80px;\n"
"	font-family:\"Microsoft YaHei\";\n"
"	font-size:20pt;\n"
"	font-weight:bold;\n"
"	color:white;\n"
"}\n"
"\n"
""));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        bankSelect = new QComboBox(BindDialog);
        bankSelect->setObjectName("bankSelect");
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(bankSelect->sizePolicy().hasHeightForWidth());
        bankSelect->setSizePolicy(sizePolicy);
        bankSelect->setMaximumSize(QSize(250, 16777215));
        bankSelect->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"	border:0.5px solid white;\n"
"	border-radius:6px;\n"
"	\n"
"	background-color: rgb(158, 232, 255);\n"
"	min-width:80px;\n"
"	font-family:\"Microsoft YaHei\";\n"
"	font-size:11pt;\n"
"	font-weight:bold;\n"
"	color:white;\n"
"}\n"
"\n"
""));

        horizontalLayout->addWidget(bankSelect);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        accountIDIn = new QLineEdit(BindDialog);
        accountIDIn->setObjectName("accountIDIn");
        accountIDIn->setMaximumSize(QSize(250, 16777215));
        accountIDIn->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	border:0.5px solid white;\n"
"	border-radius:6px;\n"
"	\n"
"	background-color: rgb(158, 232, 255);\n"
"	min-width:80px;\n"
"	font-family:\"Microsoft YaHei\";\n"
"	font-size:11pt;\n"
"	font-weight:bold;\n"
"	color:white;\n"
"}\n"
"\n"
""));

        horizontalLayout_2->addWidget(accountIDIn);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        pwIn = new QLineEdit(BindDialog);
        pwIn->setObjectName("pwIn");
        pwIn->setMaximumSize(QSize(250, 16777215));
        pwIn->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	border:0.5px solid white;\n"
"	border-radius:6px;\n"
"	\n"
"	background-color: rgb(158, 232, 255);\n"
"	min-width:80px;\n"
"	font-family:\"Microsoft YaHei\";\n"
"	font-size:11pt;\n"
"	font-weight:bold;\n"
"	color:white;\n"
"}\n"
"\n"
""));
        pwIn->setEchoMode(QLineEdit::Password);

        horizontalLayout_3->addWidget(pwIn);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        applyB = new QPushButton(BindDialog);
        applyB->setObjectName("applyB");
        applyB->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        horizontalLayout_4->addWidget(applyB);

        cancelB = new QPushButton(BindDialog);
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

        horizontalLayout_4->addWidget(cancelB);


        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(BindDialog);

        QMetaObject::connectSlotsByName(BindDialog);
    } // setupUi

    void retranslateUi(QDialog *BindDialog)
    {
        BindDialog->setWindowTitle(QCoreApplication::translate("BindDialog", "\347\273\221\345\256\232\351\223\266\350\241\214\345\215\241", nullptr));
        label->setText(QCoreApplication::translate("BindDialog", "<html><head/><body><p><span style=\" font-weight:700;\">\347\273\221\345\256\232\351\223\266\350\241\214\345\215\241</span></p></body></html>", nullptr));
        bankSelect->setPlaceholderText(QCoreApplication::translate("BindDialog", "\351\223\266\350\241\214\345\215\241", nullptr));
        accountIDIn->setPlaceholderText(QCoreApplication::translate("BindDialog", "\350\264\246\346\210\267", nullptr));
        pwIn->setPlaceholderText(QCoreApplication::translate("BindDialog", "\345\257\206\347\240\201", nullptr));
        applyB->setText(QCoreApplication::translate("BindDialog", "\346\217\220\344\272\244", nullptr));
        cancelB->setText(QCoreApplication::translate("BindDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BindDialog: public Ui_BindDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BINDDIALOG_H
