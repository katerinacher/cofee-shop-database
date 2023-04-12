#ifndef PRICESMIN_H
#define PRICESMIN_H

#include <QDialog>

namespace Ui {
class PricesMin;
}

class PricesMin : public QDialog
{
    Q_OBJECT

public:
    explicit PricesMin(QWidget *parent = nullptr);
    ~PricesMin();

private slots:
    void on_cancelButton_clicked();

    void on_addButton_clicked();

private:
    Ui::PricesMin *ui;
};

#endif // PRICESMIN_H
