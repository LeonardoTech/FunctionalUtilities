#ifndef __YZCompositeMesh_H__
#define __YZCompositeMesh_H__
/*

*/
#include "YZMeshSolid.h"

#define VESRION_COMPOSITE_MESH 1

namespace YZ
{
	class GEOMETRY_API CompositeMesh : public MeshSolid
	{
	public:
		CompositeMesh(void);
		CompositeMesh(const CompositeMesh& geometry, const osg::CopyOp& copyop = osg::CopyOp::SHALLOW_COPY);
		//CompositeMesh(const CompositeMesh& mesh);
		virtual ~CompositeMesh(void);

		META_Node(Giraffe, CompositeMesh);

		virtual GeometryItemType type(void) const{ return GIT_Solid_Composite; }
		virtual void sync(void){}
		virtual void presync(void){}
	};
}
#endif // __YZCompositeMesh_H__