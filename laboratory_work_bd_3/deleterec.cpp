#include "deleterec.h"
#include <QGridLayout>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QWidget>

deleteRec::deleteRec(QWidget *parent): QDialog(parent)
{
    stringLabel = new QLabel("               Вы точно хотите удалить этот ингредиент из рецепта?               ", this);
    yesButton = new QPushButton("Да", this);
    noButton = new QPushButton("Нет", this);

    QGridLayout *layout = new QGridLayout(this);
    layout->addWidget(stringLabel, 0, 0, 1, -1);
    layout->addWidget(yesButton, 1, 0);
    layout->addWidget(noButton, 1, 1);

    QObject::connect(yesButton, SIGNAL(clicked()), this, SLOT(deleteRecipe()));
    QObject::connect(noButton, SIGNAL(clicked()), this, SLOT(reject()));
}

void deleteRec::deleteRecipe()
{
    accept();
    QString ingr = m_ingrName;
    QString dishName = m_dishName;
    QSqlQuery query;
    query.prepare("DELETE FROM Recipes WHERE ингредиент=? AND блюдо=?");
    query.addBindValue(ingr);
    query.addBindValue(dishName);
    query.exec();
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery(query);
}

int deleteRec::exec(QString ingrName, QString dishName)
{
    m_ingrName=ingrName;
    m_dishName=dishName;
    setWindowTitle("Удаление ингредиента " + ingrName + " из рецепта " + dishName);
    return QDialog::exec();
}
