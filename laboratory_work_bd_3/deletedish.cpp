#include "deletedish.h"
#include "ui_deletedish.h"
#include "adminwindow.h"
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QComboBox>
#include <QSqlError>

deleteDish::deleteDish(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::deleteDish)
{
    ui->setupUi(this);
    this->setWindowTitle("Удаление блюда");
    QSqlQuery query;
    query.exec("SELECT блюдо FROM Menu");
    while (query.next()) {
        ui->dishName->addItem(query.value(0).toString());
    }
}

deleteDish::~deleteDish()
{
    delete ui;
}

void deleteDish::on_deleteButton_clicked()
{
    accept();
    QString nameDish=ui->dishName->currentText();
    QSqlQuery query;
    query.prepare("DELETE FROM Menu WHERE блюдо=?");
    query.addBindValue(nameDish);

    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery(query);
    if (!query.exec()) {
        qDebug() << query.lastError().text();
    }
}

void deleteDish::on_cancelButton_clicked()
{
    ui->dishName->clear();
    reject();
}
