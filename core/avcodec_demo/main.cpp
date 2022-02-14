#include <QtWidgets/QApplication>

#include "avcodec.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AVCodecDemo w;
    w.show();
    return a.exec();
}
