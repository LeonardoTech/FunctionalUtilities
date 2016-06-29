#ifndef __YZSolid_H__
#define __YZSolid_H__
/*
	所有模型的基类
*/
#include "YZGeometryItem.h"
#include "YZVector3.h"
#include "YZDirection3.h"
#include "YZPosition3.h"
#include "YZPlacement3.h"
#include "YZTransform3.h"

#define VESRION_SOLID 1

namespace YZ
{
	class GEOMETRY_API Solid : public GeometryItem
	{
	public:
		Solid(void);
		Solid(const Solid& geometry, const osg::CopyOp& copyop = osg::CopyOp::SHALLOW_COPY);
		virtual ~Solid(void);
	};
}
#endif // __YZSolid_H__