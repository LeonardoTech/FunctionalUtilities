#pragma once
#include <osg/Camera>
const osg::Vec4 normalColor(1.0f, 1.0f, 1.0f, 1.0f);
const osg::Vec4 selectedColor(1.0f, 0.0f, 0.0f, 1.0f);
class Selector
{
public:
	virtual osg::Geode* createSelector() = 0;

	virtual bool drawbyCoordinate(float x, float y, osg::Camera* camera) = 0;

};