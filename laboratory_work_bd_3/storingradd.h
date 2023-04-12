#ifndef STORINGRADD_H
#define STORINGRADD_H

#include <QDialog>
#include <QtGui>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class storIngrAdd: public QDialog
{
    Q_OBJECT

protected:
    QLabel *ingrLabel;
    QLineEdit *ingr;
    QPushButton *addButton;
    QPushButton *closeButton;

public slots:
    void addIngredient();

public:
    storIngrAdd(QDialog *parent = nullptr);
};

#endif // STORINGRADD_H
