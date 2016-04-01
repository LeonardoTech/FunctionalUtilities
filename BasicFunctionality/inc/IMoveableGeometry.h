#ifndef __IMOVEABLE_GEOMETRY_H__
#define __IMOVEABLE_GEOMETRY_H__
#include "IMoveable.h"
#include "osg/Geometry"

/// @class	IMoveableGeometry
///
/// @brief <一个设置位置的接口类，>
///
/// @author	Admin
/// @date	2016/3/23
class IMoveableGeometry : public IMoveable
{
public:

	/// @fn	virtual void IMoveableGeometry::setPosition(float x float y, float z) = 0;

	virtual IMoveableGeometry* create(osg::Geometry* geom) = 0;
private:

};

#endif // __IMOVEABLE_GEOMETRY_H__
