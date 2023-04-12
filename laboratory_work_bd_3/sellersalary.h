#ifndef SELLERSALARY_H
#define SELLERSALARY_H

#include <QDialog>

namespace Ui {
class SellerSalary;
}

class SellerSalary : public QDialog
{
    Q_OBJECT

public:
    explicit SellerSalary(QWidget *parent = nullptr);
    ~SellerSalary();

private slots:
    void on_result_clicked();

private:
    Ui::SellerSalary *ui;
};

#endif // SELLERSALARY_H
