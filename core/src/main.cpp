#include <QtWidgets/QApplication>

#if defined(DEMO_AUDIO_EFFECT)
#elif defined(DEMO_AVCODEC)
#include "avcodec/demo/avcodec.h"
#elif defined(DEMO_AVSYNC)
#elif defined(DEMO_IMAGE_FILTER)
#elif defined(DEMO_MEOWCUT_CORE)
#elif defined(DEMO_VIDEO_RENDER)
#endif //! DEMO_AUDIO_EFFECT

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
#if defined(DEMO_AUDIO_EFFECT)
#elif defined(DEMO_AVCODEC)
    AVCodecDemo w;
#elif defined(DEMO_AVSYNC)
#elif defined(DEMO_IMAGE_FILTER)
#elif defined(DEMO_MEOWCUT_CORE)
#elif defined(DEMO_VIDEO_RENDER)
#endif //! DEMO_AUDIO_EFFECT
    w.show();
    return a.exec();
}
