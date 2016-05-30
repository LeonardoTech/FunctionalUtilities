////////////
//    created by 孙庆号
////////////

#ifndef __CAMERA_ANIMATION_H__
#define __CAMERA_ANIMATION_H__
#include "YZModelCoreModule.h"
#include "CameraAnimator.h"
#include <osg/ref_ptr>
#include <osg/Vec3d>
#include "osg/Node"
#include <vector>

namespace bimWorld
{
	class BIMCameraManipulator;

	class YIZHU_EXPORT CameraAnimation : public YZModelCoreModule
	{
	public:
		CameraAnimation(YZModelCoreInternal* host);

		void play(osg::Vec3d pos, osg::Vec3d center, osg::Vec3d up);

	//internal:
		std::vector<bimWorld::CameraVector> createAnimationPath(osg::Vec3d pos, osg::Vec3d center, osg::Vec3d up, float delta_time = 50);
		
		// <创建动画路径，在创建之后将把中心点移动到目标点>
		std::function<void(int, bimWorld::BIMCameraManipulator*)> createAnimationPath(osg::Vec3d pos, osg::Vec3d center, float& total_frame, float min_frame = 60);
		
		std::function<void(int, bimWorld::BIMCameraManipulator*)> createAnimationPath(osg::Vec3d center, float& total_frame, float min_frame = 60);
		
	protected:
		// <绘制：true，更新：false。在执行 Camera 动画之前，在绘制阶段还是在仅更新阶段。>
		bool origin_draw;
		osg::ref_ptr<CameraAnimator> m_cameraAnimator;
		//std::vector<osg::Node*> m_lastTransparentNodes;
	};
}

#endif // __CAMERA_ANIMATION_H__