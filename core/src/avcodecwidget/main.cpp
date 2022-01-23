#include "avcodecwidget.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AVCodecWidget w;
    w.show();
    return a.exec();
}
