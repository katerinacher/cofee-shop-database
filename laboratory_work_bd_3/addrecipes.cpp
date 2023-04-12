#include "addrecipes.h"
#include "ui_addrecipes.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>

addRecipes::addRecipes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addRecipes)
{
    ui->setupUi(this);
    QSqlQuery query;
    query.exec("SELECT ингредиент FROM Storage");
    while (query.next()) {
        ui->ingr->addItem(query.value(0).toString());
    }
}

addRecipes::~addRecipes()
{
    delete ui;
}

int addRecipes::exec(QString dishname)
{
    m_dishname=dishname;
    setWindowTitle("Добавление рецепта для " + dishname);
    return QDialog::exec();
}

void addRecipes::on_addBut_clicked()
{
    QString newIngr=ui->ingr->currentText();
    QString dishName = m_dishname;
    QSqlQuery query;

    query.prepare("INSERT INTO Recipes (номер_блюда, блюдо,ингредиент) VALUES (nomerdishforui(?), ?, ?)");
    query.addBindValue(dishName);
    query.addBindValue(dishName);
    query.addBindValue(newIngr);
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery(query);
    if (!query.exec()) {
        QMessageBox::warning(this,"Отклонено","Вы пытаетесь добавить ингредиент, который уже есть в рецепте");
    }
    accept();
}

void addRecipes::on_exitBut_clicked()
{
    reject();
}
