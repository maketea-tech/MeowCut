#pragma once

#include "avcodec.h"

#include <QtWidgets/QMainWindow>
#include "ui_avcodecwidget.h"

class AVCodecWidget : public QMainWindow
{
    Q_OBJECT

public:
    AVCodecWidget(QWidget *parent = Q_NULLPTR);

private slots:
	void on_pushButton_clicked();

private:
    Ui::AVCodecWidgetClass ui;
	AVCodec avcodec;
};
