#include "avcodec.h"

AVCodecDemo::AVCodecDemo(QWidget *parent)
    : QMainWindow(parent) 
    , ui(new Ui::AVCodecDemo)
{
    ui->setupUi(this);
}

void AVCodecDemo::on_pushButton_clicked()
{
	avcodec.test();
}