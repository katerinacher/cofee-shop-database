#include "pricesmin.h"
#include "ui_pricesmin.h"
#include <QSqlQuery>
#include <QSqlQueryModel>

PricesMin::PricesMin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PricesMin)
{
    ui->setupUi(this);
    this->setWindowTitle("Установление цен и минимума");
    QSqlQuery query;
    query.exec("SELECT ингредиент FROM Storage");
    while (query.next()) {
        ui->ingrSelect->addItem(query.value(0).toString());
    }
}

PricesMin::~PricesMin()
{
    delete ui;
}

void PricesMin::on_cancelButton_clicked()
{
    reject();
}

void PricesMin::on_addButton_clicked()
{
    accept();
    QString ingr=ui->ingrSelect->currentText();
    QString costPriceIngr=ui->priceCostSelect->cleanText();
    QString min=ui->minimum->text();

    QSqlQuery query;
    query.prepare("UPDATE Storage_prices SET себестоимость=?, минимум=? WHERE ингредиент=?");
    query.addBindValue(costPriceIngr.toDouble());
    query.addBindValue(min.toInt());
    query.addBindValue(ingr);

    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery(query);
    query.exec();
}
