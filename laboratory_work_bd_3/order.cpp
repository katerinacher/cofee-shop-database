#include "order.h"
#include "ui_order.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QComboBox>
#include <QTableView>
#include <QSqlError>
#include <QMessageBox>
#include <QDate>
#include <QSettings>
#include <QSqlRelationalTableModel>
#include <QItemSelectionModel>
#include <QModelIndex>
#include <QSqlError>
#include "changeordingr.h"
#include <QMenu>

Order::Order(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Order)
{
    QSettings::setDefaultFormat(QSettings::IniFormat);
    QApplication::setOrganizationName("Dream Team");
    QApplication::setApplicationName("lab3");
    QString d = QDate::currentDate().toString();
    settings=new QSettings("file1.ini",QSettings::IniFormat);
    ui->setupUi(this);
    this->setWindowTitle("Оформление заказа");
    loadsettings();
    ui->orderDate->setText(d);

    QSqlQuery query;
    query.exec("SELECT блюдо FROM Menu");
    while (query.next()) {
        ui->dishEdit->addItem(query.value(0).toString());
    }

    query.exec("SELECT имя FROM Sellers");
    while (query.next()) {
        ui->sellerEdit->addItem(query.value(0).toString());
    }

    keyDELETE = new QShortcut(this);   // Initialize the object
    keyDELETE->setKey(Qt::Key_Delete);    // Set the key code
    connect(keyDELETE, SIGNAL(activated()), this, SLOT(slotShortcutDELETE()));   // connect handler to keypress

    ui->recipeView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->recipeView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(menuCall(QPoint)));
}

Order::~Order()
{
    delete ui;
}

void Order::on_addDish_clicked()
{
    QString orderID=ui->orderCode->text();
    QDate orderD = QDate::currentDate();
    QString seller=ui->sellerEdit->currentText();
    QString dishCount=ui->countSelect->cleanText();
    QString dishName=ui->dishEdit->currentText();
    QSqlQuery query ;
    query.prepare("INSERT INTO Orders (номер_заказа,дата,блюдо,номер_блюда,цена,количество,продавец,корректность) VALUES (?, ? , ? , nomerdishforui(?), priceforuiint(?), ?, ?,proverka(nomerdishforui(?),?))");
    query.addBindValue(orderID.toInt());
    query.addBindValue(orderD);
    query.addBindValue(dishName);
    query.addBindValue(dishName);//номер блюда
    query.addBindValue(dishName);
    query.addBindValue(dishCount.toInt());
    query.addBindValue(seller);
    query.addBindValue(dishName);
    query.addBindValue(dishCount.toInt());
    if (!query.exec()) {
        QMessageBox::warning(this,"Предупреждение","Недостаточно продуктов на складе для совершения заказа");
    } else {
        query.prepare("SELECT updatestorage(nomerdishforui(?),?)");
        query.addBindValue(dishName);
        query.addBindValue(dishCount.toInt());
        query.exec();
        query.prepare("SELECT блюдо,количество,цена FROM orders WHERE номер_заказа=?");
        query.addBindValue(orderID.toInt());
        query.exec();
        QSqlRelationalTableModel *modelTab = new QSqlRelationalTableModel;
        modelTab->setTable("orders");
        modelTab->setEditStrategy(QSqlRelationalTableModel::OnFieldChange);
        modelTab->QSqlQueryModel::setQuery(query);
        ui->tableView->setModel(modelTab);
    }
}

void Order::on_confirmOrder_clicked()
{
    savesettings();
    accept();
}

void Order::on_revokeButton_clicked()
{
    n=ui->orderCode->text().toInt();
    QSqlQuery query;
    query.prepare("DELETE FROM orders WHERE номер_заказа=?");
    query.addBindValue(n);
    query.exec();
    settings->setValue("n",n);
    accept();
}

void Order::savesettings()
{
    n=ui->orderCode->text().toInt();
    n=n+1;
    settings->setValue("n",n);
}

void Order::loadsettings()
{
    n=(settings->value("n",1)).toInt();
    QString str;
    str.setNum(n);
    ui->orderCode->setText(str);
}

void Order::slotShortcutDELETE()
{
    QSqlRelationalTableModel *modelTab = new QSqlRelationalTableModel;
    modelTab->setTable("orders");
    ui->tableView->setModel(modelTab);
    QSqlQuery query;
    QString orderID=ui->orderCode->text();
    modelTab->QSqlQueryModel::setQuery("DELETE FROM orders WHERE блюдо='" + namedish + "' AND номер_заказа =" +orderID);
    query.prepare("SELECT блюдо,количество,цена FROM orders WHERE номер_заказа=?");
    query.addBindValue(orderID.toInt());
    query.exec();
    modelTab->QSqlQueryModel::setQuery(query);
    ui->tableView->setModel(modelTab);
}

void Order::on_delButton_clicked()
{
    QSqlRelationalTableModel *modelTab = new QSqlRelationalTableModel;
    modelTab->setTable("orders");
    ui->tableView->setModel(modelTab);
    QSqlQuery query;
    QString orderID=ui->orderCode->text();
    modelTab->QSqlQueryModel::setQuery("DELETE FROM orders WHERE блюдо='" + namedish + "' AND номер_заказа =" +orderID);
    modelTab->QSqlQueryModel::setQuery("SELECT блюдо,количество,цена FROM orders WHERE номер_заказа="+orderID);
    ui->tableView->setModel(modelTab);
}

void Order::menuCall(QPoint pos)
{
    QMenu *menu = new QMenu(this);
    QAction *changeIngr = new QAction("Изменить", this);
    connect(changeIngr, SIGNAL(triggered()), this, SLOT(changeIngr()));
    menu->addAction(changeIngr);
    menu->popup(ui->recipeView->viewport()->mapToGlobal(pos));
}

void Order::changeIngr()
{
    QString ingrname=ui->recipeView->model()->index(ui->recipeView->currentIndex().row(),0).data().toString();
    QString dishname=ui->tableView->model()->index(ui->tableView->currentIndex().row(),0).data().toString();
    changeOrdIngr*change_window=new changeOrdIngr(this);
    change_window->exec(ingrname, dishname);

    QSqlRelationalTableModel *modelTab = new QSqlRelationalTableModel;
    modelTab->setTable("recipes");
    modelTab->setEditStrategy(QSqlRelationalTableModel::OnFieldChange);
    modelTab->QSqlQueryModel::setQuery("SELECT ингредиент, количество FROM Recipes WHERE блюдо= '" + dishname + "'");
    ui->recipeView->setModel(modelTab);
    modelTab->submitAll();
}

void Order::on_tableView_doubleClicked(const QModelIndex &index)
{
    QString namedish=index.data().toString();
    QSqlRelationalTableModel *modelTab = new QSqlRelationalTableModel;
    modelTab->setTable("recipes");
    modelTab->setEditStrategy(QSqlRelationalTableModel::OnFieldChange);
    modelTab->QSqlQueryModel::setQuery("SELECT ингредиент, количество FROM Recipes WHERE блюдо= '" + namedish + "'");
    ui->recipeView->setModel(modelTab);
    modelTab->submitAll();
}

void Order::on_tableView_clicked(const QModelIndex &index)
{
    namedish=index.data().toString();
}
