////////////
//    created by 孙庆号
////////////

#ifndef __SCREEN_CATURE_H__
#define __SCREEN_CATURE_H__
#include "YZModelCoreModule.h"
#include "IScreenCapture.h"

namespace bimWorld
{
	class YIZHU_EXPORT ScreenCapture :public YZModelCoreModule, public IScreenCapture
	{
	public:
		ScreenCapture(YZModelCoreInternal* host);
		virtual bool CaptureScreen(unsigned char** buffer, int & width, int & height, int & channels, int x, int y, const char* file) override;
	protected:
	};
}
#endif // __SCREEN_CATURE_H__