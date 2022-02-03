#ifndef __CORE_AVCODEC_H__
#define __CORE_AVCODEC_H__

class AVCodec {
public:
    AVCodec();

#ifdef DEBUG
    void test();
#endif  // ! DEBUG
};

#endif  // ! __CORE_AVCODEC_H__