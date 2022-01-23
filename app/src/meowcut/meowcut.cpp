#include "meowcut.h"

//load MeowCutCore lib
#ifdef Q_CC_MSVC
#ifdef QT_DEBUG
#pragma comment(lib,"MeowCutCored.lib")
#else
#pragma comment(lib,"MeowCutCore.lib")
#endif // QT_DEBUG
#endif

MeowCut::MeowCut(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

void MeowCut::on_pushButton_clicked()
{
	meowCutCore.test();
}
