#ifndef __YZGEOMETRY_H__
#define __YZGEOMETRY_H__
//#pragma warning (disable : 4275)

#ifdef _WIN32
#ifdef GEOMETRY_EXPORTS
#define GEOMETRY_API __declspec(dllexport)
#else
#define GEOMETRY_API __declspec(dllimport)
#endif
#else
#define GEOMETRY_API
#endif

#include "YZPrerequire.h"


#endif