#include "sellersalary.h"
#include "ui_sellersalary.h"
#include <QSqlQueryModel>
#include <QSqlQuery>

SellerSalary::SellerSalary(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SellerSalary)
{
    ui->setupUi(this);
}

SellerSalary::~SellerSalary()
{
    delete ui;
}

void SellerSalary::on_result_clicked()
{
    QDate date1=ui->dateBegin->date();
    QDate date2=ui->dateEnd->date();
    QSqlQueryModel *model = new QSqlQueryModel;
    QSqlQuery query;
    query.prepare("SELECT * FROM zarplatakakproz (?, ?)");
    query.addBindValue(date1);
    query.addBindValue(date2);
    query.exec();
    model->setQuery(query);
    ui->tableView->setModel(model);
}
