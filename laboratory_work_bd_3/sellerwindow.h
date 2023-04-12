#ifndef SELLERWINDOW_H
#define SELLERWINDOW_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSettings>
#include "order.h"

namespace Ui {
class SellerWindow;
}

class SellerWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SellerWindow(QWidget *parent = nullptr);
    ~SellerWindow();

private slots:
    void on_Checkout_clicked();
    void on_Menu_clicked();

private:
    Ui::SellerWindow *ui;
    //Order*order_window;

};

#endif // SELLERWINDOW_H
