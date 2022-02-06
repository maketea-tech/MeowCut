#ifndef __CORE_MEOWCUT_CORE_H__
#define __CORE_MEOWCUT_CORE_H__

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

#endif  // !__CORE_MEOWCUT_CORE_H__