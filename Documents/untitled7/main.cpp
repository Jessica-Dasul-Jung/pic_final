#include "someclass.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SomeClass w;
    w.show();

    return a.exec();
}
