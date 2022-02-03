#include "meowcut/meowcut.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MeowCut w;
    w.show();
    return a.exec();
}
