// main.cpp
#include "mainwindow.h"
#include <QApplication>
#include <QtCore>
#include <QtSql>
#include <QtGui>
#include <QMessageBox>

// main.cpp
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    // 使用相对路径
    db.setDatabaseName("shop.db3");

    if (!db.open()) {
        QMessageBox::information(0, "失败", QString("连接到数据库失败，请检查数据库文件后重试启动。错误信息: %1").arg(db.lastError().text()));
        return 0;
    }

    qDebug() << db.tables();

    MainWindow w;  // 将连接名传递给主窗口
    w.show();

    return a.exec();
}
