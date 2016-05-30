////////////
//    created by 孙庆号
////////////

#ifndef __ICAMERA_SETTING_H__
#define __ICAMERA_SETTING_H__
#include "DataModel.h"

namespace bimWorld
{
	class YIZHU_EXPORT ICameraSettings
	{
	public:
		///////////////////////////////////////////////////////////////////////相机视口相关操作//////////////////////////////////////////////////////////////////////////////////

		virtual bool getCameraView(CameraView& cameraView) = 0;
		
		///-------------------------------------------------------------------------------------------------
		/// <summary>	获取相机视图，并进行截图. </summary>
		///
		/// <remarks>	Sqh, 2015/5/6. </remarks>
		///
		/// <param name="cameraView">	 	[in,out] 传出获取到的相机视图. </param>
		/// <param name="strFileAllPath">	传入截获的图片存储路径，包括文件名及后缀. </param>
		/// <param name="buffer">		 	[in,out] If non-null, 传出截获的图片像素数据. </param>
		/// <param name="width">		 	[in,out] 图片的宽度. </param>
		/// <param name="height">		 	[in,out] 图片的高度. </param>
		/// <param name="channels">		 	[in,out] 图片的通道数. </param>
		///
		/// <returns>	true if it succeeds, false if it fails. </returns>
		///-------------------------------------------------------------------------------------------------

		virtual bool getCameraView(CameraView& cameraView, const char* strFileAllPath, unsigned char** buffer, int &width, int &height, int &channels) = 0;

		virtual bool getBIMCameraView(BIMCameraView& cameraView) = 0;

		virtual bool getBIMCameraView(BIMCameraView& cameraView, const char* strFileAllPath, unsigned char** buffer, int &width, int &height, int &channels)  = 0;

		virtual bool getCameraPerspective(CameraPerspective& cameraPerspective) = 0;

		virtual bool getCameraSetting(CameraSetting& cameraSetting) = 0;

		virtual bool setCameraView(const CameraView& cameraView) = 0;

		virtual bool setBIMCameraView(const BIMCameraView& cameraView) = 0;

		virtual bool setCameraPerspective(const CameraPerspective& cameraPerspective) = 0;

		virtual bool setCameraSetting(const CameraSetting& cameraSetting) = 0;

		//////////////////////////////////////////////////////////多视景体跟随相机//////////////////////////////////////////////////////////////////////////////////

		//// <创建默认图形设备特性参数>
		//virtual void* createDefaultTraits() = 0;

		//// <添加跟随相机>
		//virtual void addSlaveCamera(void* traits) = 0;

	};

}
#endif // __ICAMERA_SETTING_H__