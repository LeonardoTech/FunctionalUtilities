#ifndef __COORDINATE_H__
#define __COORDINATE_H__
#include <iostream>
using namespace std;
enum AXIS_DIRECTION
{
	X_AXIS,
	Y_AXIS,
	Z_AXIS
};

class ICoordinate
{
public:
	virtual void setLabel(AXIS_DIRECTION axis, string label) = 0;//设置标注
	virtual void setLabelPosition(AXIS_DIRECTION axis, float x, float y, float z ) = 0;///设置标注出现的位置
	virtual void setColor(AXIS_DIRECTION axis, string color) = 0;//设置轴的颜色
	virtual void setOriginPoint(float x,float y) = 0;//设置原点
	virtual void setRadius(float radius)=0;//设置半径
	virtual void getAxisDirection3D(AXIS_DIRECTION axis,float& x, float& y, float& z) = 0;//获得轴的位置
	virtual void setDarkColor(AXIS_DIRECTION axis, string color) = 0;//设置轴的渐变色的暗色
	virtual void setLabelVisibility(AXIS_DIRECTION axis, bool bvisible) = 0;//设置轴是否可见
	virtual void setAxisWidth(AXIS_DIRECTION axis, float width) = 0;//设置轴线的宽度
};


#endif