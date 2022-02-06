#ifndef __CORE_AVCODEC_DEMO_H__
#define __CORE_AVCODEC_DEMO_H__

#include "avcodec/avcodec.h"

#include <QtWidgets/QMainWindow>
#include "ui_avcodec.h"

class AVCodecDemo : public QMainWindow
{
    Q_OBJECT

public:
    AVCodecDemo(QWidget *parent = nullptr);

private slots:
	void on_pushButton_clicked();

private:
    Ui::AVCodecDemo *ui;
	AVCodec avcodec;
};


#endif  // !__CORE_AVCODEC_DEMO_H__