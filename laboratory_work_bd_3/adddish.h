#ifndef ADDDISH_H
#define ADDDISH_H

#include <QDialog>
#include "dialog.h"

namespace Ui {
class addDish;
}

class addDish : public QDialog
{
    Q_OBJECT

public:
    explicit addDish(QWidget *parent = nullptr);
    ~addDish();

private:
    Ui::addDish *ui;

private slots:
    void on_addButton_clicked();
    void on_cancelButton_clicked();
};

#endif // ADDDISH_H
