#ifndef __ICOORDINATE_AXIS_H__
#define __ICOORDINATE_AXIS_H__
#include <string>
enum COORDINATE_AXIS
{
	X_AXIS, 
	Y_AXIS, 
	Z_AXIS
};

enum class CoordinateTypes
{
	LeftHand,
	RightHand,
};

class ICoordinateAxis
{
public:
	virtual void setLabel(COORDINATE_AXIS axis, std::string label) = 0;// <设置标注>
	
	virtual void setLabelPosition(COORDINATE_AXIS axis, float x, float y, float z) = 0;// <设置标注出现的位置>
	
	virtual void setColor(COORDINATE_AXIS axis, float x, float y, float z) = 0;// <设置轴的颜色>
	
	virtual void setOriginPoint(float x, float y) = 0;// <设置原点>
	
	virtual void setRadius(float radius) = 0;// <设置半径>
	
	virtual void getAxisDirection3D(COORDINATE_AXIS axis, float& x, float& y, float& z) = 0;// <获得轴的位置>
	
	virtual void setDarkColor(COORDINATE_AXIS axis, float x, float y, float z) = 0;// <设置轴的渐变色的暗色>
	
	virtual void setLabelVisibility(COORDINATE_AXIS axis, bool bvisible) = 0;// <设置轴是否可见>
	
	virtual void setAxisWidth(float width) = 0;// <设置轴线的宽度>
	
	virtual void setEnableUpdate(bool enabled) = 0;// <设置轴是否需要更新>
	
	virtual void setVisibility(bool visibility) = 0;

	virtual void setCoordinateType(CoordinateTypes type) = 0;
};

#endif // __ICOORDINATE_AXIS_H__