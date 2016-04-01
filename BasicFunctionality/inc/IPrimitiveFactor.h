
#ifndef __IPRIMITIVEFACTOR_H__
#define __IPRIMITIVEFACTOR_H__
#include "IDrawElement.h"
#include <osg/Geometry>

/// @class	IFacePrimitives
///
/// @brief	 <一个添加绘制几何的接口>
///
/// @author	Admin
/// @date	2016/3/23
class IPrimitiveFactor :public IDrawElement
{
public:

	virtual IDrawElement* create(osg::Geometry *geo) const = 0;
};

#endif // __IPRIMITIVEFACTOR_H__
