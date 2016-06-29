////////////
//    created by 孙庆号
////////////

#ifndef __CAMERA_SETTING_H__
#define __CAMERA_SETTING_H__
#include "YZModelCoreModule.h"
#include "DataModel.h"
#include "ICameraSettings.h"

namespace bimWorld
{
	class YIZHU_EXPORT CameraSettings :public YZModelCoreModule, public ICameraSettings
	{
	public:
		CameraSettings(YZModelCoreInternal* host);

		///////////////////////////////////////////////////////////////////////相机视口相关操作//////////////////////////////////////////////////////////////////////////////////

		virtual bool getCameraView(CameraView& cameraView) override;


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

		virtual bool getCameraView(CameraView& cameraView, const char* strFileAllPath, unsigned char** buffer, int &width, int &height, int &channels) override;
		
		virtual bool getBIMCameraView(BIMCameraView& cameraView) override;

		virtual bool getBIMCameraView(BIMCameraView& cameraView, const char* strFileAllPath, unsigned char** buffer, int &width, int &height, int &channels) override;

		virtual bool getCameraPerspective(CameraPerspective& cameraPerspective) override;

		virtual bool getCameraSetting(CameraSetting& cameraSetting) override;

		virtual bool setCameraView(const CameraView& cameraView) override;

		virtual bool setBIMCameraView(const BIMCameraView& cameraView) override;

		virtual bool setCameraPerspective(const CameraPerspective& cameraPerspective) override;

		virtual bool setCameraSetting(const CameraSetting& cameraSetting) override;

		//////////////////////////////////////////////////////////多视景体跟随相机//////////////////////////////////////////////////////////////////////////////////

		//// <创建默认图形设备特性参数>
		//virtual void* createDefaultTraits() override;

		//// <添加跟随相机>
		//virtual void addSlaveCamera(void* traits) override;

	protected:
	};

}
#endif // __CAMERA_SETTING_H__