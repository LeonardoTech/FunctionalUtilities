#ifndef __YZTiger_H__
#define __YZTiger_H__
//#pragma warning (disable : 4251)

#ifdef _WIN32
#ifdef MODELDB_EXPORTS
#define MODELDB_API __declspec(dllexport)
#else
#define MODELDB_API __declspec(dllimport)
#endif
#else
#define MODELDB_API
#endif

#include "YZPrerequire.h"

namespace YZ
{
	//数据版本号，跟数据相关联，数据没有变动版本号不会变
	static const std::string YZModelDBVersion = _u8("2.0.0");
}

#endif