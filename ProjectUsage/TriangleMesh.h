#ifndef __GEO_TRIANGLE_MESH_H__
#define __GEO_TRIANGLE_MESH_H__
/*

*/
#include "IDrawElement.h"
#include "../YZModelCore/ComponentDrawable.h"

namespace geo
{
	class TriangleMesh :public bimWorld::ComponentDrawable, public IDrawElement
	{
	public:
		TriangleMesh(void);
		
		virtual void drawImplementation(osg::RenderInfo&) const override;

		void glDrawArray() const;

		//internal:

	protected:
	};
}
#endif // __GEO_TRIANGLE_MESH_H__