#ifndef __ICOORDINATE_H__
#define __ICOORDINATE_H__
#include <iostream>
using namespace std;
enum COORDINATE_NAME
{
	X_AXIS, 
	Y_AXIS, 
	Z_AXIS
};


class ICoordinate
{
public:
	virtual void setLabel(COORDINATE_NAME axis, string label) = 0;//设置标注
	virtual void setLabelPosition(COORDINATE_NAME axis, float x, float y, float z) = 0;///设置标注出现的位置
	virtual void setColor(COORDINATE_NAME axis, float x, float y, float z) = 0;//设置轴的颜色
	virtual void setOriginPoint(float x, float y) = 0;//设置原点
	virtual void setRadius(float radius) = 0;//设置半径
	virtual void getAxisDirection3D(COORDINATE_NAME axis, float& x, float& y, float& z) = 0;//获得轴的位置
	virtual void setDarkColor(COORDINATE_NAME axis, string color) = 0;//设置轴的渐变色的暗色
	virtual void setLabelVisibility(COORDINATE_NAME axis, bool bvisible) = 0;//设置轴是否可见
	virtual void setAxisWidth(float width) = 0;//设置轴线的宽度
};

#endif