////////////
//    created by 孙庆号
////////////

#ifndef __ISCREEN_CAPTURE_H__
#define __ISCREEN_CAPTURE_H__

namespace bimWorld
{
	class YIZHU_EXPORT IScreenCapture
	{
	public:
		virtual bool CaptureScreen(unsigned char** buffer, int & width, int & height, int & channels, int x, int y, const char* file) = 0;

	};
}
#endif // __ISCREEN_CAPTURE_H__