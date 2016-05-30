#ifndef __YZDRAGON_H__
#define __YZDRAGON_H__
//#pragma warning (disable : 4251)
//#pragma warning (disable : 4996)

#ifdef _WIN32
#ifdef MODEL_EXPORTS
#define MODEL_API __declspec(dllexport)
#else
#define MODEL_API __declspec(dllimport)
#endif
#else
#define MODEL_API
#endif

#include "YZPrerequire.h"

namespace YZ
{
	//模块版本号，记录每个发布版本相关联的BIM版本号，跟数据无关
	static const std::string YZModelVersion = _u8("2.0.0");
}

#endif