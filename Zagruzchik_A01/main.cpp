#include "zagruzchik.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Zagruzchik w;
    w.show();
    return a.exec();
}
