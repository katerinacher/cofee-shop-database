#include "nazenka.h"
#include "ui_nazenka.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
nazenka::nazenka(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::nazenka)
{
    ui->setupUi(this);
}

nazenka::~nazenka()
{
    delete ui;
}

int nazenka::exec(QString dishName)
{
    m_dishName=dishName;
    setWindowTitle("Установление наценки на блюдо " + dishName);
    return QDialog::exec();
}


void nazenka::on_addButton_clicked()
{
    int naz=ui->lineEdit->text().toInt();
    QSqlQuery query;
    query.prepare("UPDATE menu SET цена=(cost_of_dish(nomerdishforui(?))*(100+?)/100) WHERE блюдо=?");
    query.addBindValue(m_dishName);
    query.addBindValue(naz);
    query.addBindValue(m_dishName);

    query.exec();
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery(query);
    qDebug()<<model->lastError();
    accept();
}


void nazenka::on_closeButton_clicked()
{
    reject();
}
