#pragma once
#include <osg/Camera>
const osg::Vec4 normalColor(1.0f, 1.0f, 1.0f, 1.0f);
const osg::Vec4 selectedColor(1.0f, 0.0f, 0.0f, 1.0f);
class Selector
{
public:

	/// @fn	virtual osg::Geode* Selector::createSelector() = 0;
	///
	/// @brief	<创建图形.>
	///
	/// @author	Admin
	/// @date	2016/3/14
	///
	/// @return	null if it fails, else the new selector.
	virtual osg::Geode* createSelector() = 0;

	/// @fn	virtual bool Selector::drawbyCoordinate(float x, float y, osg::Camera* camera) = 0;
	///
	/// @brief 	<根据鼠标在屏幕点的二维坐标来确定图形的位置.>
	///
	/// @author	Admin
	/// @date	2016/3/14
	///
	/// @param	x			  	<屏幕的横坐标>.
	/// @param	y			  	<屏幕纵坐标>.
	/// @param [in,out]	camera	If non-null, the camera.
	///
	/// @return	true if it succeeds, false if it fails.
	virtual bool drawbyCoordinate(float x, float y, osg::Camera* camera) = 0;

	/// @fn	virtual osg::Vec3 Selector::getPosition() = 0;
	///
	/// @brief 	<取所画图形顶点的三维坐标.>
	///
	/// @author	Admin
	/// @date	2016/3/14
	///
	/// @return	The position.
	virtual osg::Vec3 getPosition() = 0;

};