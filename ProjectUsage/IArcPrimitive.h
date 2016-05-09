#ifndef __GEO_IARC_H__
#define __GEO_IARC_H__

#include "VertexArray.h"
#include "IDrawElement.h"

namespace geo
{
	class IArcPrimitive :public IDrawElement
	{
	public:
		virtual void setCenter(float dx, float dy, float dz) = 0;
		virtual void setCenter(const Vertex& center) = 0;
		virtual void setNormal(float dx, float dy, float dz) = 0;
		virtual void setNormal(const Vertex& normal) = 0;
		virtual const Vertex& getCenter(void)  = 0;
		virtual const Vertex& getNormal(void)  = 0;
		virtual void setStart(float dx, float dy, float dz) = 0;
		virtual void setStart(const Vertex& start) = 0;
		virtual void setEnd(float dx, float dy, float dz) = 0;
		virtual void setEnd(const Vertex& end) = 0;

		virtual Vertex& getStart() = 0;
		virtual Vertex& getEnd() = 0;

	};

}

#endif // __GEO_IARC_H__