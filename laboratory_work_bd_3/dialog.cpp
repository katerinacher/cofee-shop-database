#include "dialog.h"
#include "ui_dialog.h"
#include <QString>
#include <QSettings>
#include <adminwindow.h>
#include <QSqlError>
#include <QMessageBox>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    QSettings::setDefaultFormat(QSettings::IniFormat);
    QApplication::setOrganizationName("Dream Team");
    QApplication::setApplicationName("lab3");
    settings=new QSettings("file.ini",QSettings::IniFormat);
    ui->setupUi(this);
    this->setWindowTitle("Вход");
    loadsettingsD();
    ui->PasswordEdit->setEchoMode(QLineEdit::Password);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::savesettingsD()
{
    settings->setValue("name",name);
    settings->setValue("IP",IP);
    settings->setValue("password",password);
    settings->setValue("login",login);
    settings->setValue("port",port);
}

void Dialog::loadsettingsD()
{
    name=(settings->value("name",QString("upgradedcofix"))).toString();
    IP=(settings->value("IP",QString("34.133.1.26"))).toString();
    password=(settings->value("password",QString("elinaandkate"))).toString();
    login=(settings->value("login",QString(""))).toString();
    port=(settings->value("port",5432)).toInt();
    ui->NameEdit->setText(name);
    ui->IPEdit->setText(IP);
    ui->LoginEdit->setText(login);
    ui->PasswordEdit->setText(password);
    QString str;
    str.setNum(port);
    ui->PortEdit->setText(str);
}

void Dialog::on_PushButton_clicked()
{
    name=ui->NameEdit->text();
    IP=ui->IPEdit->text();
    login=ui->LoginEdit->text();
    password=ui->PasswordEdit->text();
    port=ui->PortEdit->text().toInt();
    accept();
    db=QSqlDatabase::addDatabase("QPSQL");
    db.setDatabaseName("fn1133_2021");
    db.setPassword("");
    db.setHostName("195.19.32.74");
    db.setUserName("student");
    db.setPort(5432);
    if (db.open())
    {
        qDebug()<<1;
        savesettingsD();

         if (login == "admin")
         {
             AdminWindow*adm_window;
             adm_window=new AdminWindow(this);
             adm_window->show();

          }
         else
         {  if (login == "seller")
             {

                   SellerWindow*sel_window;
                   sel_window=new SellerWindow;
                   sel_window->show();
             }
             else
             {
                 if (login == "supplier")
                 {
                 SupplierWindow*sup_window;
                 sup_window=new SupplierWindow;
                 sup_window->show();
                  }
             }
          }

     }
    else
    {
      QMessageBox::information(this, "Error", db.lastError().text());
    }
}

void Dialog::on_cancelButton_clicked()
{
    reject();
}
