#include "meowcut.h"

MeowCut::MeowCut(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MeowCut)
{
    ui->setupUi(this);
}

void MeowCut::on_pushButton_clicked()
{
#ifdef DEBUG
    meowCutCore.test();
#endif // !DEBUG
}

MeowCut::~MeowCut()
{
    delete ui;
}
