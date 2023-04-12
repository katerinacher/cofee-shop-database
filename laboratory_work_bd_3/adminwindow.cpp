#include "adminwindow.h"
#include "ui_adminwindow.h"
#include "dialog.h"
#include <QtSql/QSqlQuery>
#include <QSqlQueryModel>
#include <QErrorMessage>
#include <QMessageBox>
#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlField>
#include <QVariant>
#include <QString>
#include <QStringList>
#include <QKeyEvent>
#include "QStringListModel"
#include <QAbstractItemView>
#include <QSqlRelationalTableModel>
#include "storage.h"
#include "sellersalary.h"
#include "addrecipes.h"
#include "pricesmin.h"
#include "addseller.h"
#include "deleteseller.h"
#include "deleterec.h"

AdminWindow::AdminWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Администратор");
}

AdminWindow::~AdminWindow()
{
    delete ui;
}

void AdminWindow::on_addDish_triggered()
{
    addDish*addDish_window=new addDish(this);
    addDish_window->exec();
}

void AdminWindow::on_deleteDish_triggered()
{
    deleteDish*deleteDish_window;
    deleteDish_window=new deleteDish(this);
    deleteDish_window->exec();
}

void AdminWindow::on_profit_triggered()
{
    Profit*profit_window=new Profit(this);
    profit_window->exec();
}

void AdminWindow::on_sellerSalary_triggered()
{
    SellerSalary * salary_window=new SellerSalary(this) ;
    salary_window->exec();
}

void AdminWindow::on_Menu_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel;
    QSqlQuery query;
    query.exec("SELECT блюдо, цена FROM Menu");
    model->setQuery(query);
    ui->tableView->setModel(model);
}

void AdminWindow::on_Storage_clicked()
{
   ui->tableView->setModel(0);
    ui->recView->setModel(0);
   storage_window=new Storage(this);
   storage_window->exec();
}

void AdminWindow::on_ordersHistory_clicked()
{
    ui->tableView->setModel(0);
    ui->recView->setModel(0);
    QSqlQueryModel *model = new QSqlQueryModel;
    QSqlQuery query;
    query.exec("SELECT номер_заказа,дата,блюдо,цена,количество,продавец FROM orders ORDER BY номер_заказа");
    model->setQuery(query);
    ui->tableView->setModel(model);
}

void AdminWindow::on_sellersTable_clicked()
{
    ui->tableView->setModel(0);
     ui->recView->setModel(0);
    QSqlQueryModel *model = new QSqlQueryModel;
    QSqlQuery query;
    query.exec("SELECT имя, номер FROM sellers");
    model->setQuery(query);
    ui->tableView->setModel(model);
}

void AdminWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    QString namedish=index.data().toString();
    QSqlRelationalTableModel *modelTab = new QSqlRelationalTableModel;
    modelTab->setTable("recipes");
    modelTab->setEditStrategy(QSqlRelationalTableModel::OnFieldChange);
    modelTab->QSqlQueryModel::setQuery("SELECT блюдо, ингредиент, количество FROM Recipes WHERE блюдо= '" + namedish + "'");
    ui->recView->setModel(modelTab);
    ui->recView->setColumnHidden(0, true);
    modelTab->submitAll();
}

void AdminWindow::on_addRecipe_triggered()
{
    QString dishname=ui->tableView->model()->index(ui->tableView->currentIndex().row(),0).data().toString();
    addRecipes*addRecipe_window=new addRecipes(this);
    addRecipe_window->exec(dishname);

    QSqlRelationalTableModel *modelTab = new QSqlRelationalTableModel;
    modelTab->setTable("recipes");
    modelTab->setEditStrategy(QSqlRelationalTableModel::OnFieldChange);
    modelTab->QSqlQueryModel::setQuery("SELECT блюдо, ингредиент, количество FROM Recipes WHERE блюдо= '" + dishname + "'");
    ui->recView->setModel(modelTab);
    ui->recView->setColumnHidden(0, true);
    modelTab->submitAll();
}

void AdminWindow::on_prices_and_min_triggered()
{
    PricesMin*prices_min_window=new PricesMin(this);
    prices_min_window->exec();
}


void AdminWindow::on_addSel_triggered()
{
    addSeller*addSel_window=new addSeller(this);
    addSel_window->exec();
}


void AdminWindow::on_deleteSel_triggered()
{
    deleteSeller*delSel_window=new deleteSeller(this);
    delSel_window->exec();
}


void AdminWindow::on_delRecipe_triggered()
{
    QString ingrname=ui->recView->model()->index(ui->recView->currentIndex().row(),1).data().toString();
    QString dishname=ui->tableView->model()->index(ui->tableView->currentIndex().row(),0).data().toString();
    deleteRec*delRecipe_window=new deleteRec(this);
    delRecipe_window->exec(ingrname, dishname);

    QSqlRelationalTableModel *modelTab = new QSqlRelationalTableModel;
    modelTab->setTable("recipes");
    modelTab->setEditStrategy(QSqlRelationalTableModel::OnFieldChange);
    modelTab->QSqlQueryModel::setQuery("SELECT блюдо, ингредиент, количество FROM Recipes WHERE блюдо= '" + dishname + "'");
    ui->recView->setModel(modelTab);
    ui->recView->setColumnHidden(0, true);
    modelTab->submitAll();
}

void AdminWindow::on_nazenka_triggered()
{
    QString dishname=ui->tableView->model()->index(ui->tableView->currentIndex().row(),0).data().toString();
    nazenka*nazenka_window=new nazenka(this);
    nazenka_window->exec(dishname);
}
