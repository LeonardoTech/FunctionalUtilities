#ifndef __YZPrerequire_H__
#define __YZPrerequire_H__
/*
	平台相关的声明，跨平台兼容
*/

#include <string>
#include <vector>
#include <map>
/*#include <unordered_map>*/
#include <list>
#include <algorithm>
#include "math.h"

#ifdef _WIN32
	#include <windows.h>
	static std::string _u8(const char* pANSI)
	{
		if (NULL == pANSI)
			return NULL;

		int nBuffer = MultiByteToWideChar(CP_ACP, 0, pANSI, -1, NULL, 0);
		wchar_t* pWideChar = new wchar_t[nBuffer + 1];
		MultiByteToWideChar(CP_ACP, 0, pANSI, -1, pWideChar, nBuffer);
		int nUTF8Buffer = WideCharToMultiByte(CP_UTF8, 0, pWideChar, nBuffer, NULL, 0, NULL, NULL);
		char* pUTF8Char = new char[nUTF8Buffer + 1];
		WideCharToMultiByte(CP_UTF8, 0, pWideChar, nBuffer, pUTF8Char, nUTF8Buffer, NULL, NULL);
		delete[] pWideChar;

		std::string temp = pUTF8Char;
		delete[] pUTF8Char;
		return temp;
	}

#else
	#define _u8(x) u8 ## x
#endif

namespace YZ
{
	//方便调整类型
	typedef int Int;
	typedef float Real;
	//只是为了方便输入，以免手疼
	typedef unsigned char uChar;
	typedef unsigned short uShort;
	typedef unsigned int uInt;
	typedef unsigned long uLong;

	typedef std::map<std::string, std::map<std::string, std::string> > MapMapStdString;
	typedef std::map<std::string, std::vector<std::string> > MapVecStdString;
	typedef std::map<int, std::vector<int> > MapVecIntInt;
	typedef std::map<int, int> MapIntInt;

	//用于确认数值是否为0
	const float GPresnul = 1e-08f;

	//用于确认两个值是否相同
	const float GPresabs = 1e-08f;

	//圆周率相关的常数值
	//const float YZ_E        = 2.71828182845904523536;
	//const float YZ_LOG2E    = 1.44269504088896340736;
	//const float YZ_LOG10E   = 0.434294481903251827651;
	//const float YZ_LN2      = 0.693147180559945309417;
	//const float YZ_LN10     = 2.30258509299404568402;
	const float YZ_PI = 3.14159265358979323846f;//180度
	const float YZ_PI_2 = 1.57079632679489661923f;//90度
	const float YZ_PI_4 = 0.785398163397448309616f;//45度
	//const float YZ_1_PI     = 0.318309886183790671538;
	//const float YZ_2_PI     = 0.636619772367581343076;
	//const float YZ_2_SQRTPI = 1.12837916709551257390;
	//const float YZ_SQRT2    = 1.41421356237309504880;
	//const float YZ_SQRT1_2  = 0.707106781186547524401;

	//字符串常量
	const std::string YZ_FLOOR = "FLOOR";
	const std::string YZ_CATEGORY = "CATEGORY";
	const std::string YZ_DOMAIN = "DOMAIN";
	const std::string YZ_GUID = "GUID";
	const std::string YZ_COMPONENT_NAME = "COMPONENT_NAME";
	const std::string YZ_TEMPLATE_NAME = "TEMPLATE_NAME";

	//结果状态
	enum ResultState
	{
		YZERROR = 0,//处理失败
		YZSUCCESS = 1,//处理成功
		DATABASE_VERSION_HIGH,//打开数据库文件版本过高
		DATABASE_VERSION_LOW,//打开数据库版本过低

		MEMORY_DATA_LOST = 25,//内存数据丢失
		LOCAL_DB_LOST,//本地数据库缺失
		LOCAL_BS_LOST,//本地二进制缺失

		OPEN_DB_FAILED = 50,//打开数据库失败
		LOAD_DB_FAILED,//读取数据库失败
		SAVE_DB_FAILED,//保存数据库失败

		OPEN_BS_FAILED = 75,//打开二进制失败
		LOAD_BS_FAILED,//读取二进制失败
		SAVE_BS_FAILED//保存二进制失败
	};

	//模型数据类型
	enum ModelDataType
	{
		MODEL_FLOOR = 0,
		MODEL_CATEGORY,
		MODEL_DOMAIN,
		MODEL_PROPERTY_GROUP,//属性组
		MODEL_PROPERTY_KEY,//属性名称
		MODEL_PROPERTY_VALUE,//属性值
		MODEL_PROJECT_GUID,
		MODEL_PROJECT_NAME,
		MODEL_STOREY_GUID,
		MODEL_STOREY_NAME,

		MODEL_COMPONENT_NAME = 100,//实体构件名称
		MODEL_COMPONENT_GUID,//实体构件GUID
		MODEL_COMPONENT_RVTID,//实体构件RevitID

		MODEL_TEMPLATE_NAME = 200,
		MODEL_TEMPLATE_GUID,
		MODEL_TEMPLATE_RVTID
	};
}

#endif // __YZPrerequire_H__