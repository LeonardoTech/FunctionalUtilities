#pragma once
#include <osg/Camera>
const osg::Vec4 normalColor(1.0f, 1.0f, 1.0f, 1.0f);
const osg::Vec4 selectedColor(1.0f, 0.0f, 0.0f, 1.0f);
class Selector
{
public:

	/// @fn	virtual osg::Geode* Selector::createSelector() = 0;
	///
	/// @brief	<����ͼ��.>
	///
	/// @author	Admin
	/// @date	2016/3/14
	///
	/// @return	null if it fails, else the new selector.
	virtual osg::Geode* createSelector() = 0;

	/// @fn	virtual bool Selector::drawbyCoordinate(float x, float y, osg::Camera* camera) = 0;
	///
	/// @brief 	<�����������Ļ��Ķ�ά������ȷ��ͼ�ε�λ��.>
	///
	/// @author	Admin
	/// @date	2016/3/14
	///
	/// @param	x			  	<��Ļ�ĺ�����>.
	/// @param	y			  	<��Ļ������>.
	/// @param [in,out]	camera	If non-null, the camera.
	///
	/// @return	true if it succeeds, false if it fails.
	virtual bool drawbyCoordinate(float x, float y, osg::Camera* camera) = 0;

	/// @fn	virtual osg::Vec3 Selector::getPosition() = 0;
	///
	/// @brief 	<ȡ����ͼ�ζ������ά����.>
	///
	/// @author	Admin
	/// @date	2016/3/14
	///
	/// @return	The position.
	virtual osg::Vec3 getPosition() = 0;

};