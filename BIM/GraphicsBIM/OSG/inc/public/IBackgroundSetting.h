////////////
//    created by 孙庆号
////////////

#ifndef __IBACKGROUND_SETTING_H__
#define __IBACKGROUND_SETTING_H__
#include <string>
#include "config.h"

namespace bimWorld
{

	class YIZHU_EXPORT IBackgroundSetting
	{
	public:
		
		virtual bool getBackgroundColor(int& red, int& green, int& blue, int& alpha) = 0;

		virtual void setBackgroundColor(int red, int green, int blue, int alpha) = 0;

		virtual void revertBackgroundColor() = 0;

		virtual void setSkyBox(const std::string& hdr) = 0;

		virtual void setSkyBox(const std::string& right, const std::string& left, const std::string& front, const std::string& back, const std::string& up, const std::string& down) = 0;

		virtual void updateSkyBoxRadius() = 0;
	};
}

#endif // __IBACKGROUND_SETTING_H__