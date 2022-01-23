#include "avcodecwidget.h"

//load AVCodec lib
#ifdef Q_CC_MSVC
#ifdef QT_DEBUG
#pragma comment(lib,"avcodecd.lib")
#else
#pragma comment(lib,"avcodec.lib")
#endif // QT_DEBUG
#endif

AVCodecWidget::AVCodecWidget(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

void AVCodecWidget::on_pushButton_clicked()
{
	avcodec.test();
}