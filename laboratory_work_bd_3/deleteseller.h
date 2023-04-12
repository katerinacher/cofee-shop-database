#ifndef DELETESELLER_H
#define DELETESELLER_H

#include <QDialog>
#include <QtGui>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>

class deleteSeller: public QDialog
{
    Q_OBJECT

protected:
    QLabel *nameLabel;
    QComboBox *name;
    QPushButton *deleteButton;
    QPushButton *closeButton;

public slots:
    void deleteSel();

public:
    deleteSeller(QWidget *parent = nullptr);
};

#endif // DELETESELLER_H
