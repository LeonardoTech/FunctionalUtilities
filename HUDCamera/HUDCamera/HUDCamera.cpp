#include "HUDCamera.h"


HUDCamera::HUDCamera()
{
	_camera = new osg::Camera;
	_camera->setReferenceFrame(osg::Transform::ABSOLUTE_RF);
	_camera->setClearMask(GL_DEPTH_BUFFER_BIT);
	_camera->setRenderOrder(osg::Camera::POST_RENDER);
	_camera->setAllowEventFocus(false);
	_camera->setProjectionMatrix(osg::Matrix::ortho2D(0, 1920, 0, 1080));
}


osg::Camera* HUDCamera::getHUDCamera()
{
	return _camera;
}