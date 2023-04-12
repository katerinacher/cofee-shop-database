#include "deleteseller.h"
#include <QGridLayout>
#include <QSqlQuery>
#include <QSqlQueryModel>

deleteSeller::deleteSeller(QWidget *parent): QDialog(parent)
{
    setWindowTitle(tr("Удаление продавца"));
    nameLabel = new QLabel("Имя", this);
    name = new QComboBox(this);
    deleteButton = new QPushButton("Удалить", this);
    closeButton = new QPushButton("Назад", this);

    QSqlQuery query;
    query.exec("SELECT имя FROM Sellers");
    while (query.next()) {
        name->addItem(query.value(0).toString());
    }

    QGridLayout *layout = new QGridLayout(this);
    layout->addWidget(nameLabel, 0, 0);
    layout->addWidget(name, 0, 1);
    layout->addWidget(deleteButton, 2, 0, 1, -1);
    layout->addWidget(closeButton, 3, 0, 1, -1);

    QObject::connect(deleteButton, SIGNAL(clicked()), this, SLOT(deleteSel()));
    QObject::connect(closeButton, SIGNAL(clicked()), this, SLOT(reject()));
}

void deleteSeller::deleteSel()
{
    accept();
    QString nameCur = name->currentText();
    QSqlQuery query;
    query.prepare("DELETE FROM Sellers WHERE имя=?");
    query.addBindValue(nameCur);

    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery(query);
    query.exec();
}
