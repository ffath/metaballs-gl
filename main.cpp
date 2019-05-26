#include "metaballs.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Metaballs w;
    w.show();

    return a.exec();
}
