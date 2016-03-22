#ifndef __ILINEPRIMITIVES_H__
#define __ILINEPRIMITIVES_H__

#include "IDrawElement.h"


class  ILinePrimitives :public IDrawElement
{
public:
	virtual void setLineWidth(float width) = 0;

	virtual void getStartPosition(float& x, float& y, float& z) = 0;

	virtual void getEndPosition(float& x, float& y, float& z) = 0;

	virtual void setStartPosition(float x, float y, float z) = 0;

	virtual void setEndPosition(float x, float y, float z) = 0;

};

#endif	// __ILINEPRIMITIVES_H__
