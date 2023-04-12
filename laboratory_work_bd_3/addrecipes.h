#ifndef ADDRECIPES_H
#define ADDRECIPES_H

#include <QDialog>

namespace Ui {
class addRecipes;
}

class addRecipes : public QDialog
{
    Q_OBJECT

public:
    explicit addRecipes(QWidget *parent = nullptr);
    ~addRecipes();
    int exec(QString dishname);

private slots:
    void on_addBut_clicked();

    void on_exitBut_clicked();

private:
    Ui::addRecipes *ui;
    QString m_dishname;
};

#endif // ADDRECIPES_H
