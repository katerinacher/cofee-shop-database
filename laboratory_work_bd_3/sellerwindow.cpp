#include "sellerwindow.h"
#include "ui_sellerwindow.h"
#include "dialog.h"
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlQuery>

SellerWindow::SellerWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SellerWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Продавец");
}

SellerWindow::~SellerWindow()
{
    delete ui;
}


void SellerWindow::on_Checkout_clicked()
{
    Order*order_window;
    order_window=new Order(this);
    order_window->exec();
}


void SellerWindow::on_Menu_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel;
    QSqlQuery query;
    query.exec("SELECT * FROM Menu");
    model->setQuery(query);
    ui->tableView->setModel(model);
}
