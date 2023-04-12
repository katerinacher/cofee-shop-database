#ifndef SUPPLIERWINDOW_H
#define SUPPLIERWINDOW_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSettings>
#include <dialog.h>

namespace Ui {
class SupplierWindow;
}

class SupplierWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SupplierWindow(QWidget *parent = nullptr);
    ~SupplierWindow();


private slots:
    void slotShortcutENTER();

private:
    Ui::SupplierWindow *ui;
    QShortcut *keyENTER;
};

#endif // SUPPLIERWINDOW_H
