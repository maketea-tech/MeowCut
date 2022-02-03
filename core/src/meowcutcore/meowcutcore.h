#ifndef __CORE_MEOWCUTCORE_H__
#define __CORE_MEOWCUTCORE_H__

#include "avcodec/avcodec.h"

class MeowCutCore
{
public:
    MeowCutCore();

#ifdef DEBUG
    void test();
#endif  // !DEBUG

private:
	AVCodec avcodec;
};

#endif  // !__CORE_MEOWCUTCORE_H__