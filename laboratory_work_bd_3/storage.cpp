#include "storage.h"
#include "ui_storage.h"
#include "storingradd.h"
#include "storingrdelete.h"
#include "adminwindow.h"
#include <QtSql/QSqlQuery>
#include <QSqlQueryModel>
#include <QLabel>
#include <QPushButton>
#include <QWidget>
#include <QLineEdit>
#include <QGridLayout>
#include <QAccessibleTableCellInterface>

Storage::Storage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Storage)
{
    ui->setupUi(this);
    this->setWindowTitle("Склад");
}

Storage::~Storage()
{
    delete ui;
}

void Storage::on_Ingreds_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel;
    QSqlQuery query;
    query.exec("SELECT * FROM Storage");
    model->setQuery(query);
    ui->tableView->setModel(model);
}

void Storage::on_Check_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel;
    QSqlQuery query;
    query.exec("SELECT Storage.ингредиент, Storage.количество, Storage_prices.минимум, 'Недостаточно:' AS Статус, Storage_prices.минимум-Storage.количество AS Количество_недостающего FROM Storage,Storage_prices WHERE Storage.количество<Storage_prices.минимум AND Storage_prices.ингредиент=Storage.ингредиент;");
    model->setQuery(query);
    ui->tableView->setModel(model);
}


void Storage::on_addIngr_clicked()
{
    storIngrAdd*addIngr_window=new storIngrAdd(this);
    addIngr_window->exec();
}


void Storage::on_delIngr_clicked()
{
    storIngrDelete*delIngr_window=new storIngrDelete(this);
    delIngr_window->exec();
}
