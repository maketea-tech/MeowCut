#include "meowcutcore.h"
#include <QDebug>

//load AVCodec lib
#ifdef Q_CC_MSVC
#ifdef QT_DEBUG
#pragma comment(lib,"AVCodecd.lib")
#else
#pragma comment(lib,"AVCodec.lib")
#endif // QT_DEBUG
#endif

MeowCutCore::MeowCutCore()
{
}

void MeowCutCore::test()
{
	qDebug() << "This is test function from MeowCutCore lib.";

	qDebug() << "	The next debug info is called by MeowCutCore lib==>>";
	avcodec.test();
}
