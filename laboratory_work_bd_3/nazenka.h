#ifndef NAZENKA_H
#define NAZENKA_H

#include <QDialog>

namespace Ui {
class nazenka;
}

class nazenka : public QDialog
{
    Q_OBJECT

public:
    explicit nazenka(QWidget *parent = nullptr);
    ~nazenka();
public slots:
    int exec(QString dishName);


private slots:
    void on_addButton_clicked();

    void on_closeButton_clicked();

private:
    Ui::nazenka *ui;
    QString m_dishName;
};

#endif // NAZENKA_H
