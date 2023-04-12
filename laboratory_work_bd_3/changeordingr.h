#ifndef CHANGEORDINGR_H
#define CHANGEORDINGR_H

#include <QDialog>
#include <QtGui>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>

class changeOrdIngr: public QDialog
{
    Q_OBJECT

protected:
    QLabel *stringLabel;
    QComboBox *ingr;
    QPushButton *changeButton;
    QPushButton *closeButton;

public slots:
    void changeIngr();
    int exec(QString ingrName, QString dishName);

public:
    changeOrdIngr(QDialog *parent = nullptr);

private:
    QString m_ingrName;
    QString m_dishName;
};

#endif // CHANGEORDINGR_H
