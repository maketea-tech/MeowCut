#ifndef __APP_MEOWCUT_H__
#define __APP_MEOWCUT_H__

#include "meowcutcore/meowcutcore.h"

#include <QtWidgets/QMainWindow>
#include "ui_meowcut.h"

class MeowCut : public QMainWindow
{
    Q_OBJECT

public:
    MeowCut(QWidget *parent = nullptr);
    ~MeowCut();

private slots:
    void on_pushButton_clicked();
    
private:
    Ui::MeowCut *ui;
    MeowCutCore meowCutCore;
};

#endif  // !__APP_MEOWCUT_H__