#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(MEOWCUTCORE_LIB)
#  define MEOWCUTCORE_EXPORT Q_DECL_EXPORT
# else
#  define MEOWCUTCORE_EXPORT Q_DECL_IMPORT
# endif
#else
# define MEOWCUTCORE_EXPORT
#endif
