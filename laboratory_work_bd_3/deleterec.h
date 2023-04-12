#ifndef DELETEREC_H
#define DELETEREC_H

#include <QDialog>
#include <QtGui>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>

class deleteRec: public QDialog
{
    Q_OBJECT

protected:
    QLabel *stringLabel;
    QPushButton *yesButton;
    QPushButton *noButton;

public slots:
     void deleteRecipe();
     int exec(QString ingrName, QString dishName);

public:
    deleteRec(QWidget *parent = nullptr);

private:
    QString m_ingrName;
    QString m_dishName;
};

#endif // DELETEREC_H
