#pragma once
#include <osg/Camera>
const osg::Vec4 normalColor(1.0f, 1.0f, 1.0f, 1.0f);
const osg::Vec4 selectedColor(1.0f, 0.0f, 0.0f, 1.0f);
class Selector
{
public:

	//	<创建图形.>
	virtual osg::Geode* createSelector() = 0;

	//brief 	<根据鼠标在屏幕点的二维坐标来确定图形的位置.>
	//param	x			  	<屏幕的横坐标>.
	//param	y			  	<屏幕纵坐标>.
	virtual bool drawbyCoordinate(float x, float y, osg::Camera* camera) = 0;


	// 	<取所画图形顶点的三维坐标.>
	virtual osg::Vec3 getPosition() = 0;

};