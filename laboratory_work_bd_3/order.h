#ifndef ORDER_H
#define ORDER_H

#include <QDialog>
#include <QListWidgetItem>
#include <QSettings>
#include <QShortcut>

namespace Ui {
class Order;
}

class Order : public QDialog
{
    Q_OBJECT

public:
    explicit Order(QWidget *parent = nullptr);
    ~Order();
     Ui::Order *ui;
     void savesettings();
     void loadsettings();
     QSettings *settings;
     int n;
     QString namedish;

private slots:
    void on_addDish_clicked();

    void on_confirmOrder_clicked();

    void on_revokeButton_clicked();

    void slotShortcutDELETE();

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_tableView_clicked(const QModelIndex &index);

    void on_delButton_clicked();

    void menuCall(QPoint pos);

    void changeIngr();

private:
    QShortcut *keyDELETE;
    QString nameingr;
};

#endif // ORDER_H
