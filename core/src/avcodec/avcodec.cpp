#include "avcodec.h"
#ifdef DEBUG
#include <QDebug>
#endif  // ! DEBUG

AVCodec::AVCodec()
{
}

#ifdef DEBUG
void AVCodec::test()
{
	qDebug() << "This is test function from AVCodec lib.";
}
#endif  // ! DEBUG
