#pragma once

#include "meowcutcore_global.h"

#include "AVCodec/avcodec.h"

class MEOWCUTCORE_EXPORT MeowCutCore
{
public:
    MeowCutCore();
	void test();

private:
	AVCodec avcodec;
};
