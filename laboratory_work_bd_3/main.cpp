
#include "dialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog openDia;
    openDia.show();
    return a.exec();
}
