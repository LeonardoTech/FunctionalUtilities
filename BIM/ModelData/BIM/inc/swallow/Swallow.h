#ifndef __YZSwallow_H__
#define __YZSwallow_H__

#ifdef _WIN32
#ifdef SERIALIZE_EXPORTS
#define MODELBS_API __declspec(dllexport)
#else
#define MODELBS_API __declspec(dllimport)
#endif
#else
#define MODELBS_API
#endif

#include "YZPrerequire.h"

#endif