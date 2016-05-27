#ifndef __HUDCAMARA_H__
#define __HUDCAMARA_H__

#include <osg/Camera>
class HUDCamera
{
public:
	HUDCamera();
	osg::Camera* getHUDCamera();
private:
	osg::ref_ptr<osg::Camera>_camera;
};

#endif
