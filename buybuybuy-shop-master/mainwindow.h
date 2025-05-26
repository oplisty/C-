#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QtGui>
#include <QMessageBox>
#include <QTableWidget>
#include <QButtonGroup>

#include "product.h"
#include "user.h"
#include "cart.h"
#include "bankcard.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_userB_clicked();
    void on_addB_clicked();
    void on_cartB_clicked();
    void removeFromCart(int index);
    void on_bankB_clicked();
    void readCards();
    void payCart();
    void payOK();
    void payAbort();
    void on_boughtB_clicked();
    void on_categoryButtonClicked(int id);
    void setupMainCategoryButtons();
    void on_subcategoryButtonClicked(int id);
    void on_searchButton_clicked();
private:
    void showGoods();
    bool readL();
    bool saveL();
    void readAndShowGoods();
    bool saveCart();
    void readCart();
    void saveBought();
    void readBought();

    void SearchBooksByName(const QString& searchName);

    template <typename T>
    bool saveL(const QVector<T>&, QString tableName);
    template <typename T>
    T* find(QVector<T>&, int id);

    Ui::MainWindow *ui;
    QTableWidget bookT;
    QTableWidget elecT;
    QTableWidget clothesT;
    QTableWidget foodT;

    QTabWidget bookSubTabWidget;
    QTabWidget elecSubTabWidget;
    QTabWidget clothesSubTabWidget;
    QTabWidget foodSubTabWidget;

    QVector<Book> bookL;
    QVector<Elec> elecL;
    QVector<Clothes> clothesL;
    QVector<Food> foodL;

    User u;
    Cart c;
    Cart bought;
    QVector<BankCard> cards;
    bool login;

    QButtonGroup *categoryButtonGroup;
    QButtonGroup *subcategoryButtonGroup;
    int currentCategory;

};

#endif // MAINWINDOW_H
