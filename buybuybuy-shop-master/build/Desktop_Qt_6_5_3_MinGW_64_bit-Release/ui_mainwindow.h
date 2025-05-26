/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *userLabel;
    QPushButton *userB;
    QLineEdit *lineEdit;
    QPushButton *searchButton;
    QPushButton *bankB;
    QPushButton *boughtB;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *widget;
    QTabWidget *tabWidget;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *addB;
    QPushButton *cartB;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(727, 499);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/icons/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"	border-image: url(:/new/icons/UI.jpg);\n"
"    background-position: center;\n"
"    background-repeat: no-repeat;\n"
"    background-attachment: fixed;\n"
"	background-size:cover;\n"
"}\n"
"\n"
"/* \345\274\272\345\210\266\346\211\200\346\234\211\345\255\220\346\216\247\344\273\266\351\200\217\346\230\216 */\n"
"QMainWindow * {\n"
"    background-color: transparent !important;\n"
"}"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        userLabel = new QLabel(centralWidget);
        userLabel->setObjectName("userLabel");
        userLabel->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QLabel{\n"
"		font-family:\"Microsoft YaHei\";\n"
"		font-size:12px;\n"
"		font-weight:bold;\n"
"		color:black;\n"
"		border:none;\n"
"}"));

        horizontalLayout->addWidget(userLabel);

        userB = new QPushButton(centralWidget);
        userB->setObjectName("userB");
        userB->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"		border:0.5px solid white;\n"
"		border-radius:6px;\n"
"		background-color:rgb(90,194,198);\n"
"		min-width:80px;\n"
"		font-family:\"Microsoft YaHei\";\n"
"		font-size:11pt;\n"
"		font-weight:bold;\n"
"		color:white;\n"
"}\n"
"QPushButton:hover{\n"
"		border:0.5px solid white;\n"
"		border-radius:6px;\n"
"		background-color:#1fab89;\n"
"		min-width:80px;\n"
"		font-family:\"Microsoft YaHei\";\n"
"		font-size:10pt;\n"
"		font-weight:bold;\n"
"		color:white;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/icons/user.png"), QSize(), QIcon::Normal, QIcon::Off);
        userB->setIcon(icon1);

        horizontalLayout->addWidget(userB);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setStyleSheet(QString::fromUtf8("	*{\n"
"		background-color: rgb(196, 239, 255);\n"
"}"));

        horizontalLayout->addWidget(lineEdit);

        searchButton = new QPushButton(centralWidget);
        searchButton->setObjectName("searchButton");
        searchButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"		border:0.5px solid white;\n"
"		border-radius:6px;\n"
"		background-color:rgb(90,194,198);\n"
"		min-width:80px;\n"
"		font-family:\"Microsoft YaHei\";\n"
"		font-size:11pt;\n"
"		font-weight:bold;\n"
"		color:white;\n"
"}\n"
"QPushButton:hover{\n"
"		border:0.5px solid white;\n"
"		border-radius:6px;\n"
"		background-color:#1fab89;\n"
"		min-width:80px;\n"
"		font-family:\"Microsoft YaHei\";\n"
"		font-size:10pt;\n"
"		font-weight:bold;\n"
"		color:white;\n"
"}"));

        horizontalLayout->addWidget(searchButton);

        bankB = new QPushButton(centralWidget);
        bankB->setObjectName("bankB");
        bankB->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"		border:0.5px solid white;\n"
"		border-radius:6px;\n"
"		background-color:rgb(90,194,198);\n"
"		min-width:80px;\n"
"		font-family:\"Microsoft YaHei\";\n"
"		font-size:11pt;\n"
"		font-weight:bold;\n"
"		color:white;\n"
"}\n"
"QPushButton:hover{\n"
"		border:0.5px solid white;\n"
"		border-radius:6px;\n"
"		background-color:#1fab89;\n"
"		min-width:80px;\n"
"		font-family:\"Microsoft YaHei\";\n"
"		font-size:10pt;\n"
"		font-weight:bold;\n"
"		color:white;\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/icons/wallet.png"), QSize(), QIcon::Normal, QIcon::Off);
        bankB->setIcon(icon2);

        horizontalLayout->addWidget(bankB);

        boughtB = new QPushButton(centralWidget);
        boughtB->setObjectName("boughtB");
        boughtB->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"		border:0.5px solid white;\n"
"		border-radius:6px;\n"
"		background-color:rgb(90,194,198);\n"
"		min-width:80px;\n"
"		font-family:\"Microsoft YaHei\";\n"
"		font-size:11pt;\n"
"		font-weight:bold;\n"
"		color:white;\n"
"}\n"
"QPushButton:hover{\n"
"		border:0.5px solid white;\n"
"		border-radius:6px;\n"
"		background-color:#1fab89;\n"
"		min-width:80px;\n"
"		font-family:\"Microsoft YaHei\";\n"
"		font-size:10pt;\n"
"		font-weight:bold;\n"
"		color:white;\n"
"}"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/icons/box.png"), QSize(), QIcon::Normal, QIcon::Off);
        boughtB->setIcon(icon3);

        horizontalLayout->addWidget(boughtB);


        verticalLayout->addLayout(horizontalLayout);

        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setEnabled(true);
        scrollArea->setMinimumSize(QSize(702, 102));
        scrollArea->setStyleSheet(QString::fromUtf8("QScrollArea {\n"
"    border: 0.5px solid rgba(255, 255, 255, 0.5);  /* \345\215\212\351\200\217\346\230\216\347\231\275\350\211\262\350\276\271\346\241\206 */\n"
"    border-radius: 6px;\n"
"    background-color: transparent;                 /* \344\270\273\350\203\214\346\231\257\351\200\217\346\230\216 */\n"
"    color: white;                                  /* \346\226\207\345\255\227\351\242\234\350\211\262\357\274\210\346\240\271\346\215\256\350\203\214\346\231\257\350\260\203\346\225\264\357\274\211 */\n"
"    font-family: \"Microsoft YaHei\";\n"
"    font-size: 11pt;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* \350\256\276\347\275\256\350\247\206\345\217\243\357\274\210\345\206\205\345\256\271\345\214\272\345\237\237\357\274\211\351\200\217\346\230\216 */\n"
"QScrollArea::viewport {\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"/* \350\241\250\345\244\264\351\200\217\346\230\216 */\n"
"QScrollArea::section {\n"
"    background-color: transparent;\n"
"    border: none;                  /* \345"
                        "\217\257\351\200\211\357\274\232\347\247\273\351\231\244\350\241\250\345\244\264\350\276\271\346\241\206 */\n"
"}\n"
"\n"
"\n"
"QScrollArea {\n"
"    min-width: 700px;\n"
"    max-width: 70000px;\n"
"    min-height: 100px;\n"
"    max-height: 100px;\n"
"}\n"
"\n"
"\n"
"/* \351\200\211\344\270\255\347\212\266\346\200\201\346\225\210\346\236\234 */\n"
"QScrollArea::item:selected {\n"
"    background-color: rgba(255, 255, 255, 0.2);  /* \345\215\212\351\200\217\346\230\216\351\200\211\344\270\255\351\253\230\344\272\256 */\n"
"}"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 713, 100));
        widget = new QWidget(scrollAreaWidgetContents);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 771, 101));
        widget->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    border: 0.5px solid rgba(255, 255, 255, 0.5);  /* \345\215\212\351\200\217\346\230\216\347\231\275\350\211\262\350\276\271\346\241\206 */\n"
"    border-radius: 6px;\n"
"    background-color: transparent;                 /* \344\270\273\350\203\214\346\231\257\351\200\217\346\230\216 */\n"
"    color: black;                                  /* \346\226\207\345\255\227\351\242\234\350\211\262\357\274\210\346\240\271\346\215\256\350\203\214\346\231\257\350\260\203\346\225\264\357\274\211 */\n"
"    font-family: \"Microsoft YaHei\";\n"
"    font-size: 11pt;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* \350\256\276\347\275\256\350\247\206\345\217\243\357\274\210\345\206\205\345\256\271\345\214\272\345\237\237\357\274\211\351\200\217\346\230\216 */\n"
"QWidget::viewport {\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"/* \350\241\250\345\244\264\351\200\217\346\230\216 */\n"
"QWidget::section {\n"
"    background-color: transparent;\n"
"    border: none;                  /* \345\217\257\351"
                        "\200\211\357\274\232\347\247\273\351\231\244\350\241\250\345\244\264\350\276\271\346\241\206 */\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"/* \351\200\211\344\270\255\347\212\266\346\200\201\346\225\210\346\236\234 */\n"
"QScrollArea::item:selected {\n"
"    background-color: rgba(255, 255, 255, 0.2);  /* \345\215\212\351\200\217\346\230\216\351\200\211\344\270\255\351\253\230\344\272\256 */\n"
"}"));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setStyleSheet(QString::fromUtf8("/* ---------------------- QTabWidget \346\225\264\344\275\223\350\256\276\347\275\256 ---------------------- */\n"
"QTabWidget {\n"
"    background-color: transparent;  /* \344\270\273\346\216\247\344\273\266\351\200\217\346\230\216 */\n"
"    border: none !important;        /* \347\247\273\351\231\244\351\273\230\350\256\244\350\276\271\346\241\206 */\n"
"}\n"
"\n"
"/* ---------------------- \346\240\207\347\255\276\351\241\265\345\256\271\345\231\250\357\274\210\345\206\205\345\256\271\345\214\272\345\237\237\357\274\211 ---------------------- */\n"
"QTabWidget::pane {\n"
"    border: 1px solid rgba(255, 255, 255, 0.3);  /* \345\215\212\351\200\217\346\230\216\347\231\275\350\211\262\350\276\271\346\241\206 */\n"
"    border-top: none;               /* \344\270\216\346\240\207\347\255\276\346\240\217\350\241\224\346\216\245\345\244\204\345\216\273\350\276\271\346\241\206 */\n"
"    border-radius: 0 4px 4px 4px;   /* \345\217\263\344\270\213\350\247\222\345\234\206\350\247\222\345\214\271\351\205\215\346\240\207"
                        "\347\255\276\346\240\217 */\n"
"    background-color: rgba(0, 0, 0, 0.1);  /* \345\215\212\351\200\217\346\230\216\351\273\221\350\211\262\350\203\214\346\231\257\357\274\210\345\217\257\351\200\211\357\274\211 */\n"
"    margin-top: -1px;               /* \346\266\210\351\231\244\344\270\216\346\240\207\347\255\276\346\240\217\347\232\204\351\227\264\351\232\231 */\n"
"    padding: 5px;\n"
"}\n"
"\n"
"/* ---------------------- \346\240\207\347\255\276\346\240\217\357\274\210QTabBar\357\274\211 ---------------------- */\n"
"QTabBar {\n"
"    background: transparent;        /* \346\240\207\347\255\276\346\240\217\350\203\214\346\231\257\351\200\217\346\230\216 */\n"
"    spacing: 3px;                   /* \346\240\207\347\255\276\344\271\213\351\227\264\347\232\204\351\227\264\350\267\235 */\n"
"}\n"
"\n"
"/* ---------------------- \345\215\225\344\270\252\346\240\207\347\255\276\351\241\265\357\274\210\346\234\252\351\200\211\344\270\255\357\274\211 ---------------------- */\n"
"QTabBar::tab {\n"
"    backgrou"
                        "nd-color: rgba(255, 255, 255, 0.2);  /* \345\215\212\351\200\217\346\230\216\347\231\275\350\211\262\350\203\214\346\231\257 */\n"
"    border: 1px solid rgba(255, 255, 255, 0.3);  /* \345\215\212\351\200\217\346\230\216\350\276\271\346\241\206 */\n"
"    border-bottom: none;            /* \345\272\225\351\203\250\344\270\216\345\206\205\345\256\271\345\214\272\345\237\237\350\241\224\346\216\245 */\n"
"    border-radius: 4px 4px 0 0;     /* \344\270\212\344\276\247\345\234\206\350\247\222 */\n"
"    padding: 8px 15px;              /* \345\206\205\350\276\271\350\267\235 */\n"
"    color: white;                   /* \346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"    font-weight: bold;\n"
"    margin-right: 2px;              /* \346\240\207\347\255\276\351\227\264\345\217\263\344\276\247\351\227\264\350\267\235 */\n"
"}\n"
"\n"
"/* ---------------------- \346\240\207\347\255\276\351\241\265\357\274\210\346\202\254\345\201\234\346\225\210\346\236\234\357\274\211 ---------------------- */\n"
"QTabBar::ta"
                        "b:hover {\n"
"    background-color: rgba(255, 255, 255, 0.3);  /* \346\233\264\351\253\230\351\200\217\346\230\216\345\272\246 */\n"
"    border-color: rgba(255, 255, 255, 0.5);\n"
"}\n"
"\n"
"/* ---------------------- \346\240\207\347\255\276\351\241\265\357\274\210\351\200\211\344\270\255\347\212\266\346\200\201\357\274\211 ---------------------- */\n"
"QTabBar::tab:selected {\n"
"    background-color: rgba(255, 255, 255, 0.4);  /* \351\253\230\344\272\256\351\200\211\344\270\255\346\240\207\347\255\276 */\n"
"    border-color: rgba(255, 255, 255, 0.6);\n"
"    border-bottom: 1px solid transparent;  /* \351\232\220\350\227\217\345\272\225\351\203\250\350\276\271\346\241\206 */\n"
"}\n"
"\n"
"/* ---------------------- \346\240\207\347\255\276\351\241\265\357\274\210\347\246\201\347\224\250\347\212\266\346\200\201\357\274\211 ---------------------- */\n"
"QTabBar::tab:disabled {\n"
"    background-color: rgba(128, 128, 128, 0.2);\n"
"    color: rgba(255, 255, 255, 0.5);\n"
"}"));

        verticalLayout->addWidget(tabWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        addB = new QPushButton(centralWidget);
        addB->setObjectName("addB");
        addB->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/icons/addCart.png"), QSize(), QIcon::Normal, QIcon::Off);
        addB->setIcon(icon4);

        horizontalLayout_2->addWidget(addB);

        cartB = new QPushButton(centralWidget);
        cartB->setObjectName("cartB");
        cartB->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/icons/cart.png"), QSize(), QIcon::Normal, QIcon::Off);
        cartB->setIcon(icon5);

        horizontalLayout_2->addWidget(cartB);


        verticalLayout->addLayout(horizontalLayout_2);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\350\264\255\347\211\251\345\225\206\345\237\216", nullptr));
        userLabel->setText(QCoreApplication::translate("MainWindow", "User", nullptr));
        userB->setText(QCoreApplication::translate("MainWindow", "login/out", nullptr));
        lineEdit->setText(QString());
        lineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "\346\220\234\347\264\242", nullptr));
        searchButton->setText(QCoreApplication::translate("MainWindow", "\346\220\234\347\264\242", nullptr));
        bankB->setText(QCoreApplication::translate("MainWindow", "\346\210\221\347\232\204\351\222\261\345\214\205", nullptr));
        boughtB->setText(QCoreApplication::translate("MainWindow", "\345\267\262\344\271\260\345\210\260\347\232\204\345\256\235\350\264\235", nullptr));
        addB->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\345\210\260\350\264\255\347\211\251\350\275\246", nullptr));
        cartB->setText(QCoreApplication::translate("MainWindow", "\346\210\221\347\232\204\350\264\255\347\211\251\350\275\246(0)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
