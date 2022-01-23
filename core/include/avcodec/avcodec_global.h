#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(AVCODEC_LIB)
#  define AVCODEC_EXPORT Q_DECL_EXPORT
# else
#  define AVCODEC_EXPORT Q_DECL_IMPORT
# endif
#else
# define AVCODEC_EXPORT
#endif
