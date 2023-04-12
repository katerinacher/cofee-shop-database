#include "adddish.h"
#include "ui_adddish.h"
#include <QSqlQuery>
#include <QComboBox>
#include "adminwindow.h"
#include "ui_adminwindow.h"
#include <QSqlQueryModel>
#include <QSqlError>

addDish::addDish(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addDish)
{
    ui->setupUi(this);
    this->setWindowTitle("Добавление блюда");
}

addDish::~addDish()
{
    delete ui;
}

void addDish::on_addButton_clicked()
{
    accept();
    QString NameDish=ui->dishName->text();

    QSqlQuery query;
    query.prepare("INSERT INTO Menu (блюдо, цена) VALUES (?,0)");
    query.addBindValue(NameDish);
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery(query);
    query.exec();
    qDebug() << model->lastError();
}

void addDish::on_cancelButton_clicked()
{
    ui->dishName->clear();
    reject();
}
