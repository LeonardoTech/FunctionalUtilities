#ifndef __IMEASURING_LINE_LENGTH_H__
#define __IMEASURING_LINE_LENGTH_H__
#include <string>
// enum Num
// {
// 	SelectOne,
// 	SelectTwo
// };
enum SHOW_METHOD
{
	LEFT,
	CENTER,
	RIGHT
};

class IMeasuringLineLength
{
public:
	virtual void setStartPoint(float x, float y) = 0;
	virtual void setEndPoint(float x, float y) = 0;
	// TODO: <以后公开出来这个接口>
	//virtual void setLabel(string name, float x, float y, float z) = 0;
	virtual void setLabel(std::string name, SHOW_METHOD method) = 0;
	virtual float getDistance() = 0;

	virtual void getStartPoint(float& x, float& y, float& z) = 0;
	virtual void getEndPoint(float& x, float& y, float& z) = 0;
};

#endif