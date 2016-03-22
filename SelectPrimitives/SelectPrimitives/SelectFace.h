#ifndef __SELECT_FACE_H__
#define __SELECT_FACE_H__
#include "ISelectPrimitives.h"

class SelectFace :public ISelectPrimitives
{
public:
	virtual IDrawElement select(float x, float y) = 0;

};

#endif // __SELECT_FACE_H__
