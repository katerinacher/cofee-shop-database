#include "supplierwindow.h"
#include "ui_supplierwindow.h"
#include "dialog.h"
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QtSql/QSqlError>
#include <QMessageBox>
#include <QSqlRelationalTableModel>
#include <QSqlRecord>

SupplierWindow::SupplierWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SupplierWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Поставщик");
    keyENTER = new QShortcut(this);
    keyENTER->setKey(Qt::Key_Return);
    connect(keyENTER, SIGNAL(activated()), this, SLOT(slotShortcutENTER()));
    QSqlRelationalTableModel *modelTab = new QSqlRelationalTableModel;
    modelTab->setTable("storage");
    modelTab->setEditStrategy(QSqlRelationalTableModel::OnFieldChange);
    modelTab->QSqlQueryModel::setQuery("(SELECT Storage.ингредиент, Storage.количество, Storage_prices.минимум-Storage.количество AS Количество_недостающего "
                                       "FROM Storage, Storage_prices WHERE Storage_prices.ингредиент = Storage.ингредиент AND Storage.количество-Storage_prices.минимум<0) "
                                       "UNION (SELECT Storage.ингредиент, Storage.количество, 0 AS Количество_недостающего FROM Storage, Storage_prices "
                                       "WHERE Storage_prices.ингредиент = Storage.ингредиент AND Storage.количество-Storage_prices.минимум>0)");
    ui->storageTab->setModel(modelTab);
}

SupplierWindow::~SupplierWindow()
{
    delete ui;
}

void SupplierWindow::slotShortcutENTER()
{
    QSqlRelationalTableModel *modelTab = new QSqlRelationalTableModel;
    modelTab->setTable("storage");
    modelTab->setEditStrategy(QSqlRelationalTableModel::OnFieldChange);
    modelTab->QSqlQueryModel::setQuery("(SELECT Storage.ингредиент, Storage.количество, Storage_prices.минимум-Storage.количество AS Количество_недостающего FROM Storage, Storage_prices WHERE Storage_prices.ингредиент = Storage.ингредиент AND Storage.количество-Storage_prices.минимум<0) UNION (SELECT Storage.ингредиент, Storage.количество, 0 AS Количество_недостающего FROM Storage, Storage_prices WHERE Storage_prices.ингредиент = Storage.ингредиент AND Storage.количество-Storage_prices.минимум>0)");
    ui->storageTab->setModel(modelTab);
}
