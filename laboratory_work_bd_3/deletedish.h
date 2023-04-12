#ifndef DELETEDISH_H
#define DELETEDISH_H

#include <QDialog>
#include "dialog.h"

namespace Ui {
class deleteDish;
}

class deleteDish : public QDialog
{
    Q_OBJECT

public:
    explicit deleteDish(QWidget *parent = nullptr);
    ~deleteDish();

private:
    Ui::deleteDish *ui;


private slots:
    void on_deleteButton_clicked();
    void on_cancelButton_clicked();
};

#endif // DELETEDISH_H
