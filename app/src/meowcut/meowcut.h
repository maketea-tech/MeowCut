#pragma once

#include "MeowCutCore/meowcutcore.h"

#include <QtWidgets/QMainWindow>
#include "ui_meowcut.h"

class MeowCut : public QMainWindow
{
    Q_OBJECT

public:
    MeowCut(QWidget *parent = Q_NULLPTR);

private slots:
	void on_pushButton_clicked();
private:
    Ui::MeowCutClass ui;
	MeowCutCore meowCutCore;
};
