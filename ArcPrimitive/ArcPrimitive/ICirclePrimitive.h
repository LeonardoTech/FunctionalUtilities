#ifndef __GEO_ICIRCLE__PRIMITIVE_H__
#define  __GEO_ICIRCLE__PRIMITIVE_H__
#include "VertexArray.h"

namespace geo
{
	class ICirclePrimitive
	{
	public:
		virtual void setCenter(float dx, float dy, float dz) = 0;
		virtual void setCenter(Vertex center) = 0;
		virtual void setNormal(float dx, float dy, float dz) = 0;
		virtual void setNormal(Vertex _normal) = 0;
		virtual void setRadius(float radius);
		virtual  const Vertex& getCenter()  = 0;
		virtual  const Vertex& getNormal() = 0;
	private:

	};
}

#endif // !__GEO_ICIRCLE__PRIMITIVE_H__
