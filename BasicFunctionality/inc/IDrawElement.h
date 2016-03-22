#ifndef __IDRAW_ELEMENT_H__
#define __IDRAW_ELEMENT_H__
#include "VertexArray.h"
#include "IGeometry.h"

class IDrawElement : public IGeometry
{
public:
	virtual VertexArray getVertices() const = 0;

	virtual void setVertices(const VertexArray& arr) = 0;

};

#endif // __IDRAW_ELEMENT_H__
