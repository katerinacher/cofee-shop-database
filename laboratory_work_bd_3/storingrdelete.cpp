#include "storingrdelete.h"

#include <QGridLayout>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>

storIngrDelete::storIngrDelete(QDialog *parent): QDialog(parent)
{
    setWindowTitle(tr("Удаление ингредиента"));
    ingrLabel = new QLabel("ингредиент", this);
    ingr = new QComboBox(this);
    delButton = new QPushButton("Удалить", this);
    closeButton = new QPushButton("Назад", this);

    QSqlQuery query;
    query.exec("SELECT ингредиент FROM Storage");
    while (query.next()) {
        ingr->addItem(query.value(0).toString());
    }

    QGridLayout *layout = new QGridLayout(this);
    layout->addWidget(ingrLabel, 0, 0);
    layout->addWidget(ingr, 0, 1);
    layout->addWidget(delButton, 1, 0, 1, -1);
    layout->addWidget(closeButton, 2, 0, 1, -1);

    QObject::connect(delButton, SIGNAL(clicked()), this, SLOT(deleteIngredient()));
    QObject::connect(closeButton, SIGNAL(clicked()), this, SLOT(reject()));
}

void storIngrDelete::deleteIngredient()
{
    accept();
    QString ingrCur = ingr->currentText();
    QSqlQuery query;
    query.prepare("DELETE FROM Storage WHERE ингредиент=?");
    query.addBindValue(ingrCur);
    query.exec();
    query.prepare("DELETE FROM Storage_prices WHERE ингредиент=?");
    query.addBindValue(ingrCur);

    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery(query);
    query.exec();
}
