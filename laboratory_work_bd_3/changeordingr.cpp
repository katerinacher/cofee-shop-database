#include "changeordingr.h"
#include <QGridLayout>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QSizePolicy>
#include <QWidget>

void changeOrdIngr::changeIngr()
{
    accept();
    QString ingrCur = ingr->currentText();
    QString ingr = m_ingrName;
    QString dishName = m_dishName;
    QSqlQuery query;
    query.prepare("UPDATE Recipes SET ингредиент = '" + ingrCur + "' WHERE ингредиент=? AND блюдо=?");
    query.addBindValue(ingr);
    query.addBindValue(dishName);
    query.exec();

    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery(query);
}

int changeOrdIngr::exec(QString ingrName, QString dishName)
{
    m_ingrName=ingrName;
    m_dishName=dishName;
    setWindowTitle("Изменение ингредиента " + ingrName + " для блюда " + dishName);
    return QDialog::exec();
}

changeOrdIngr::changeOrdIngr(QDialog *parent): QDialog(parent)
{
    setWindowTitle(tr("Изменение ингредиента в рецепте"));
    stringLabel = new QLabel("                 Выберите ингредиент, на который вы хотите поменять                 ", this);
    ingr = new QComboBox(this);
    changeButton = new QPushButton("Изменить", this);
    closeButton = new QPushButton("Назад", this);

    QSqlQuery query;
    query.exec("SELECT ингредиент FROM Storage");
    while (query.next()) {
        ingr->addItem(query.value(0).toString());
    }

    QGridLayout *layout = new QGridLayout(this);
    layout->addWidget(stringLabel, 0, 0);
    layout->addWidget(ingr, 1, 0);
    layout->addWidget(changeButton, 2, 0);
    layout->addWidget(closeButton, 3, 0);

    QObject::connect(changeButton, SIGNAL(clicked()), this, SLOT(changeIngr()));
    QObject::connect(closeButton, SIGNAL(clicked()), this, SLOT(reject()));
}
