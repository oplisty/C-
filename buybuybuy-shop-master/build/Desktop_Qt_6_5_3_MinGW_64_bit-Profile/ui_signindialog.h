/********************************************************************************
** Form generated from reading UI file 'signindialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNINDIALOG_H
#define UI_SIGNINDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SignInDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *nameIn;  // 修改为 QLineEdit
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *pwIn;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *loginB;
    QPushButton *signupB;

    void setupUi(QDialog *SignInDialog)
    {
        if (SignInDialog->objectName().isEmpty())
            SignInDialog->setObjectName("SignInDialog");
        SignInDialog->resize(300, 220);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SignInDialog->sizePolicy().hasHeightForWidth());
        SignInDialog->setSizePolicy(sizePolicy);
        SignInDialog->setMinimumSize(QSize(300, 220));
        SignInDialog->setMaximumSize(QSize(300, 220));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/icons/user.png"), QSize(), QIcon::Normal, QIcon::Off);
        SignInDialog->setWindowIcon(icon);
        SignInDialog->setStyleSheet(QString::fromUtf8("QDialog {\n"
                                                      "    background-color: rgb(203, 231, 255);\n"
                                                      "}\n"
                                                      "QDialog*{\n"
                                                      "    background-color: transparent !important;\n"
                                                      "}"));
        verticalLayout = new QVBoxLayout(SignInDialog);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_2 = new QLabel(SignInDialog);
        label_2->setObjectName("label_2");
        QFont font;
        font.setFamilies({QString::fromUtf8("Microsoft YaHei")});
        font.setBold(true);
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("QLabel{\n"
                                                 "    font-family:\"Microsoft YaHei\";\n"
                                                 "    font-size:30px;\n"
                                                 "    font-weight:bold;\n"
                                                 "    color:black;\n"
                                                 "    border:none;\n"
                                                 "}"));
        label_2->setAlignment(Qt::AlignCenter);
        horizontalLayout->addWidget(label_2);
        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(-1, -1, 0, -1);
        nameIn = new QLineEdit(SignInDialog);  // 替换为 QLineEdit
        nameIn->setObjectName("nameIn");
        nameIn->setMaximumSize(QSize(200, 16777215));
        nameIn->setStyleSheet(QString::fromUtf8("*{\n"
                                                "    background-color: rgb(222, 241, 255);\n"
                                                "}"));
        horizontalLayout_2->addWidget(nameIn);
        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(-1, -1, 0, -1);
        pwIn = new QLineEdit(SignInDialog);
        pwIn->setObjectName("pwIn");
        pwIn->setMaximumSize(QSize(200, 16777215));
        pwIn->setStyleSheet(QString::fromUtf8("*{\n"
                                              "    background-color: rgb(222, 241, 255);\n"
                                              "}"));
        pwIn->setEchoMode(QLineEdit::Password);
        horizontalLayout_3->addWidget(pwIn);
        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        loginB = new QPushButton(SignInDialog);
        loginB->setObjectName("loginB");
        loginB->setStyleSheet(QString::fromUtf8("QPushButton{\n"
                                                "    border:0.5px solid white;\n"
                                                "    border-radius:6px;\n"
                                                "    background-color:rgb(90,194,198);\n"
                                                "    min-width:80px;\n"
                                                "    font-family:\"Microsoft YaHei\";\n"
                                                "    font-size:11pt;\n"
                                                "    font-weight:bold;\n"
                                                "    color:white;\n"
                                                "}\n"
                                                "QPushButton:hover{\n"
                                                "    background-color:#1fab89;\n"
                                                "}"));
        horizontalLayout_4->addWidget(loginB);

        signupB = new QPushButton(SignInDialog);
        signupB->setObjectName("signupB");
        signupB->setStyleSheet(QString::fromUtf8("QPushButton{\n"
                                                 "    border:0.5px solid white;\n"
                                                 "    border-radius:6px;\n"
                                                 "    background-color:rgb(90,194,198);\n"
                                                 "    min-width:80px;\n"
                                                 "    font-family:\"Microsoft YaHei\";\n"
                                                 "    font-size:11pt;\n"
                                                 "    font-weight:bold;\n"
                                                 "    color:white;\n"
                                                 "}\n"
                                                 "QPushButton:hover{\n"
                                                 "    background-color:#1fab89;\n"
                                                 "}"));
        horizontalLayout_4->addWidget(signupB);
        verticalLayout->addLayout(horizontalLayout_4);

        retranslateUi(SignInDialog);
        QMetaObject::connectSlotsByName(SignInDialog);
    } // setupUi

    void retranslateUi(QDialog *SignInDialog)
    {
        SignInDialog->setWindowTitle(QCoreApplication::translate("SignInDialog", "登录/注册", nullptr));
        label_2->setText(QCoreApplication::translate("SignInDialog", "登录或注册", nullptr));
        nameIn->setPlaceholderText(QCoreApplication::translate("SignInDialog", "用户名", nullptr));  // 合法，因为 nameIn 是 QLineEdit
        pwIn->setPlaceholderText(QCoreApplication::translate("SignInDialog", "密码", nullptr));
        loginB->setText(QCoreApplication::translate("SignInDialog", "登录", nullptr));
        signupB->setText(QCoreApplication::translate("SignInDialog", "注册", nullptr));
    } // retranslateUi
};

namespace Ui {
class SignInDialog: public Ui_SignInDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNINDIALOG_H
