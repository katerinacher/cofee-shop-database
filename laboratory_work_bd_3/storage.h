#ifndef STORAGE_H
#define STORAGE_H

#include <QDialog>
#include <QSqlDatabase>

namespace Ui {
class Storage;
}

class Storage : public QDialog
{
    Q_OBJECT

public:
    explicit Storage(QWidget *parent = nullptr);
    ~Storage();

private slots:

    void on_Ingreds_clicked();

    void on_Check_clicked();

    void on_addIngr_clicked();

    void on_delIngr_clicked();

private:
    Ui::Storage *ui;

 };

#endif // STORAGE_H
