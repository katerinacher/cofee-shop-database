#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QSettings>
#include <QSqlDatabase>
#include "adminwindow.h"
#include "sellerwindow.h"
#include "supplierwindow.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    void savesettingsD();
    void loadsettingsD();
    QSettings *settings;
    QString name;
    QString IP;
    QString login;
    QString password;
    int port;
    QSqlDatabase db;

private slots:
    void on_PushButton_clicked();
    void on_cancelButton_clicked();

private:
    Ui::Dialog *ui;

};

#endif // DIALOG_H
