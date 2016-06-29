////////////
//    created by 孙庆号
////////////

#ifndef __BIM_WORLD_CONFIG_H__
#define __BIM_WORLD_CONFIG_H__
#include <string>
//On some platforms, std::string is supported better than std::wstring
//This macro give us the choice.
//On windows platform, we may need to turn on this macro, since windows platform supports std::wstring better
//On iOS platform, we may not need this macro.
namespace bimWorld{
#ifndef YIZHU_BIMWORLD_USE_WCHAR
#ifdef _MSC_VER
#define YIZHU_BIMWORLD_USE_WCHAR
#endif
#endif
#ifdef YIZHU_BIMWORLD_USE_WCHAR
	typedef std::wstring YZString;
#else
	typedef std::string YZString;
#endif

#ifdef _MSC_VER
#ifdef YIZHU_API_DEFINE
#define YIZHU_EXPORT __declspec(dllexport)
#else
#define YIZHU_EXPORT __declspec(dllimport)
#endif
#else
#define YIZHU_EXPORT
#endif

	class Config
	{
	public:
		////////////////////////////////////////////////////////配置文件//////////////////////////////////////////////////////////////////////////////////
		virtual bool readConfigFromFile(const char *fileName);

		virtual bool readConfigFromContent(const char *content);

	protected:
	private:
	};
}

#endif // __BIM_WORLD_CONFIG_H__
