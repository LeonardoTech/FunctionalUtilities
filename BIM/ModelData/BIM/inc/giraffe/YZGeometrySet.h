#ifndef __YZGeometrySet_H__
#define __YZGeometrySet_H__
/*
几何集合
*/
#include "YZGeometryItem.h"

#define VESRION_GEOMETRY_SET 1

namespace YZ
{
	class TriangleMesh;

	class GEOMETRY_API GeometrySet : public GeometryItem
	{
	public:
		GeometrySet(void);
		GeometrySet(const GeometrySet& geometry, const osg::CopyOp& copyop = osg::CopyOp::SHALLOW_COPY);
		virtual ~GeometrySet(void);

		META_Node(Giraffe, GeometrySet);

		virtual GeometryItemType type(void) const{ return GIT_Geometry_Set; }
		virtual void sync(void);
		virtual void transf(const Transform3& transf);
		virtual void osg_integrate(osg::Geometry* osg){}

		void add_geometry(GeometryItem* geo);
		const std::vector<osg::ref_ptr<GeometryItem> >& get_geometrys(void) const;
		int geometry_num(void) const;
		GeometryItem* get_geometry(int index) const;

		//
		//virtual GeometrySet* _clone(void) const;
		//virtual void reset(void);
		//virtual void presync(void);

	protected:
		std::vector<osg::ref_ptr<GeometryItem> > m_geometrys;
	};
}
#endif // __YZGeometrySet_H__