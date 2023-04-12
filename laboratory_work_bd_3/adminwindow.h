#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSettings>
#include "adddish.h"
#include "deletedish.h"
#include "storage.h"
#include "profit.h"
#include "nazenka.h"
#include <QSqlRelationalTableModel>
namespace Ui {
class AdminWindow;
}

class AdminWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminWindow(QWidget *parent = nullptr);
    ~AdminWindow();

private slots:
    void on_addDish_triggered();

    void on_deleteDish_triggered();

    void on_profit_triggered();

    void on_Menu_clicked();

    void on_Storage_clicked();

    void on_ordersHistory_clicked();

    void on_sellersTable_clicked();

    void on_sellerSalary_triggered();

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_addRecipe_triggered();

    void on_prices_and_min_triggered();

    void on_addSel_triggered();

    void on_deleteSel_triggered();

    void on_delRecipe_triggered();

    void on_nazenka_triggered();

private:
    Ui::AdminWindow *ui;
    Storage*storage_window;

};

#endif // ADMINWINDOW_H
