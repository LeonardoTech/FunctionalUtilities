////////////
//    created by 孙庆号
////////////

#ifndef __ICAMERA_ANIMATION_H__
#define __ICAMERA_ANIMATION_H__
namespace bimWorld
{
	class ICameraAnimation
	{
	public:
		void play(osg::Vec3d pos, osg::Vec3d center, osg::Vec3d up);
	};
}
#endif // __ICAMERA_ANIMATION_H__