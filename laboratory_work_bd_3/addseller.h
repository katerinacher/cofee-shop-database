#ifndef ADDSELLER_H
#define ADDSELLER_H

#include <QDialog>
#include <QtGui>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class addSeller: public QDialog
{
    Q_OBJECT

protected:
    QLabel *nameLabel;
    QLineEdit *name;
    QLabel *numberLabel;
    QLineEdit *number;
    QPushButton *addButton;
    QPushButton *closeButton;

public slots:
    void addSel();

public:
    addSeller(QWidget *parent = nullptr);
};

#endif // ADDSELLER_H
