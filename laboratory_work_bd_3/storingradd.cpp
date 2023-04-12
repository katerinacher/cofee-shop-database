#include "storingradd.h"

#include <QGridLayout>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QMessageBox>

storIngrAdd::storIngrAdd(QDialog *parent): QDialog(parent)
{
    setWindowTitle(tr("Добавление ингредиента"));
    ingrLabel = new QLabel("ингредиент", this);
    ingr = new QLineEdit(this);
    addButton = new QPushButton("Добавить", this);
    closeButton = new QPushButton("Назад", this);

    QGridLayout *layout = new QGridLayout(this);
    layout->addWidget(ingrLabel, 0, 0);
    layout->addWidget(ingr, 0, 1);
    layout->addWidget(addButton, 1, 0, 1, -1);
    layout->addWidget(closeButton, 2, 0, 1, -1);

    QObject::connect(addButton, SIGNAL(clicked()), this, SLOT(addIngredient()));
    QObject::connect(closeButton, SIGNAL(clicked()), this, SLOT(reject()));
}

void storIngrAdd::addIngredient()
{
    QString ingrString = ingr->text();
    QSqlQuery query;
    query.prepare("INSERT INTO Storage (ингредиент) VALUES ('" + ingrString + "')");
    query.exec();
    query.prepare("INSERT INTO Storage_prices (ингредиент) VALUES ('" + ingrString + "')");
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery(query);

    if (!query.exec()) {
        QMessageBox::warning(this,"Отклонено","Вы пытаетесь добавить ингредиент, который уже есть на складе");
    }
    accept();
}
