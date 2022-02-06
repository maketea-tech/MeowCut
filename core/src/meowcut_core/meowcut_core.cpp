#include "meowcut_core.h"
#ifdef DEBUG
#include <QDebug>
#endif	// !DEBUG


MeowCutCore::MeowCutCore()
{
}
#ifdef DEBUG
void MeowCutCore::test()
{
    qDebug() << "This is test function from MeowCutCore lib.";

    qDebug() << "	The next debug info is called by MeowCutCore lib==>>";
    avcodec.test();
}

#endif	// !DEBUG
