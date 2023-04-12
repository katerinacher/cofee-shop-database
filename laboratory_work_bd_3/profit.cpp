#include "profit.h"
#include "ui_profit.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
Profit::Profit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Profit)
{
    ui->setupUi(this);
    this->setWindowTitle("Выручка");
}

Profit::~Profit()
{
    delete ui;
}

void Profit::on_result_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel;
    QSqlQuery query;
    QDate date1=ui->beginDate->date();
    QDate date2=ui->endDate->date();
    query.prepare("SELECT profitofcofixlast(?,?) AS Прибыль ");
    query.addBindValue(date1);
    query.addBindValue(date2);
    query.exec();
    model->setQuery(query);
    ui->profit->setModel(model);
}
