#ifndef __IARCPRIMITIVE_H__
#define __IARCPRIMITIVE_H__

#include "VertexArray.h"

namespace YZ
{
	class IArcPrimitive:public Vertex
	{
	public:
		virtual void setCenter(float dx, float dy, float dz) = 0;
		virtual void setCenter(const Vertex& center) = 0;
		virtual void setNormal(float dx, float dy, float dz) = 0;
		virtual void setNormal(const Vertex& normal) = 0;
		virtual const Vertex& getCenter(void)  = 0;
		virtual const Vertex& getNormal(void)  = 0;
	private:

	};

}

#endif // __IARCPRIMITIVE_H__