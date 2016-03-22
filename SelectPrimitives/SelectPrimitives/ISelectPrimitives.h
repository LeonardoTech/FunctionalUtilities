#ifndef __ISELECT_PRIMITIVES_H__
#define __ISELECT_PRIMITIVES_H__
#include "IDrawElement.h"

class ISelectPrimitives
{
public:
	virtual IDrawElement* select(float x, float y) = 0;

	virtual IDrawElement* getSelection() const = 0;
};

#endif // __ISELECT_PRIMITIVES_H__
