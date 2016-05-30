#ifndef __YZStone_H__
#define __YZStone_H__

#ifdef _WIN32
#ifdef MODELCORE_EXPORTS
#define CORE_API __declspec(dllexport)
#else
#define CORE_API __declspec(dllimport)
#endif
#else
#define CORE_API
#endif

#include "YZPrerequire.h"

#endif