#ifndef STORINGRDELETE_H
#define STORINGRDELETE_H

#include <QDialog>
#include <QtGui>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>

class storIngrDelete: public QDialog
{
    Q_OBJECT

protected:
    QLabel *ingrLabel;
    QComboBox *ingr;
    QPushButton *delButton;
    QPushButton *closeButton;

public slots:
    void deleteIngredient();

public:
    storIngrDelete(QDialog *parent = nullptr);
};

#endif // STORINGRDELETE_H
