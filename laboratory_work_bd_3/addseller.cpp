#include "addseller.h"
#include <QGridLayout>
#include <QSqlQuery>
#include <QSqlQueryModel>

addSeller::addSeller(QWidget *parent): QDialog(parent)
{
    setWindowTitle(tr("Добавление продавца"));
    nameLabel = new QLabel("Имя", this);
    name = new QLineEdit(this);
    numberLabel = new QLabel("Номер", this);
    number = new QLineEdit(this);
    addButton = new QPushButton("Добавить", this);
    closeButton = new QPushButton("Назад", this);

    QGridLayout *layout = new QGridLayout(this);
    layout->addWidget(nameLabel, 0, 0);
    layout->addWidget(name, 0, 1);
    layout->addWidget(numberLabel, 1, 0);
    layout->addWidget(number, 1, 1);
    layout->addWidget(addButton, 2, 0, 1, -1);
    layout->addWidget(closeButton, 3, 0, 1, -1);

    QObject::connect(addButton, SIGNAL(clicked()), this, SLOT(addSel()));
    QObject::connect(closeButton, SIGNAL(clicked()), this, SLOT(reject()));
}

void addSeller::addSel()
{
    accept();
    QString nameString = name->text();
    QString numberString = number->text();
    QSqlQuery query;
    query.prepare("INSERT INTO Sellers (имя, номер) VALUES ('" + nameString + "', " +numberString + ")");
    query.exec();
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery(query);
    query.exec();
}
