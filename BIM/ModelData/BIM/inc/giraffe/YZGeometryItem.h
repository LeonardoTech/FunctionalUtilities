#ifndef __YZGeometryItem_H__
#define __YZGeometryItem_H__
/*
	一个几何项，所有几何数据基类
*/
#include "YZGeometry.h"
#include <osg/Geode>
#include <osg/Geometry>
#include <osg/Array>
#include <osgUtil/SmoothingVisitor>

#include "YZVector3.h"
#include "YZDirection3.h"
#include "YZPosition3.h"
#include "YZPlacement3.h"
#include "YZTransform3.h"

#define VESRION_GEOMETRY_ITEM 3

namespace YZ
{
	enum GeometryItemType
	{
		GIT_Unknown = 0, 

		GIT_Geometry_Set = 1,
		GIT_GeometryObject, 

		//Curve
		GIT_Curve_Line = 100, 
		GIT_Curve_Arc, 
		GIT_Curve_PolyLine, 
		//GIT_Curve_PolyArc, 
		GIT_Curve_PolyLoop, 
		GIT_Curve_Composite, 
		GIT_Curve_Helix, 
		GIT_Curve_Circle,

		//Profile
		GIT_Profile_Arbitrary = 500, 
		GIT_Profile_ArbitraryWithVoids, 

		//Profile_Parameterized
		GIT_Profile_Rectangle = 600, 
		GIT_Profile_RectHollow, 
		GIT_Profile_Circle, 
		GIT_Profile_CircleHollow, 
		GIT_Profile_Ellipse, 
		GIT_Profile_ShapeAsymI, 
		GIT_Profile_ShapeC, 
		GIT_Profile_ShapeI, 
		GIT_Profile_ShapeL, 
		GIT_Profile_ShapeT, 
		GIT_Profile_ShapeU, 
		GIT_Profile_ShapeZ, 

		//Surface
		GIT_Plane = 900, 

		//Solid
		GIT_Solid_Composite = 1000, 

		//Solid_Mesh
		GIT_Solid_GridMesh = 1100, 
		GIT_Solid_PolygonMesh, 
		GIT_Solid_TriangleMesh, 

		//Solid_SweptArea
		GIT_Solid_ExtrudedArea = 1200, 
		GIT_Solid_ScanningArea, 
		GIT_Solid_RevlovedArea, 

		//Solid_Primitive
		GIT_Solid_PrimitiveBlock = 1300, 
		GIT_Solid_PrimitiveCone, 
		GIT_Solid_PrimitiveCylinder, 
		GIT_Solid_PrimitivePyramid, 
		GIT_Solid_PrimitiveSphere
	};

	/*
		目前只存储osg::Geometry中的顶点，索引，颜色信息
	*/
	class GEOMETRY_API GeometryItem : public osg::Geometry
	{
	public:
		GeometryItem(void);
		GeometryItem(const GeometryItem& geometry, const osg::CopyOp& copyop = osg::CopyOp::SHALLOW_COPY);
		virtual ~GeometryItem(void);

		//获取当前几何类型
		virtual GeometryItemType type() const{ return GIT_Unknown; }

		//同步数据
		virtual void sync(void){}

		//对当前几何作变换
		virtual void transf(const Transform3& transf);

		//将数据集成进osgGeometry
		virtual void osg_integrate(osg::Geometry* osg){}

		//颜色
		void setColor(osg::Vec4 color);
		osg::Vec4 getColor(void) const;

		//判断数据是否合法
		//virtual bool is_legal(void) const;

		//克隆
		//virtual GeometryItem* _clone(void) const;

		//重置
		//virtual void reset(void);

		//转换为osg::Geometry
		//virtual osg::Geometry* asOsg(void);
		//osg::Geometry* getOsgGeometry(void){ return m_geometry.get(); }
		//virtual osg::Geode* asGeode(void);

	protected:
		osg::Vec4 m_color;//颜色
	};
}
#endif // __YZGeometryItem_H__