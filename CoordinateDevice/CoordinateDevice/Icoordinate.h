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
	virtual void setLabel(AXIS_DIRECTION axis, string label) = 0;//���ñ�ע
	virtual void setLabelPosition(AXIS_DIRECTION axis, float x, float y, float z ) = 0;///���ñ�ע���ֵ�λ��
	virtual void setColor(AXIS_DIRECTION axis, string color) = 0;//���������ɫ
	virtual void setOriginPoint(float x,float y) = 0;//����ԭ��
	virtual void setRadius(float radius)=0;//���ð뾶
	virtual void getAxisDirection3D(AXIS_DIRECTION axis,float& x, float& y, float& z) = 0;//������λ��
	virtual void setDarkColor(AXIS_DIRECTION axis, string color) = 0;//������Ľ���ɫ�İ�ɫ
	virtual void setLabelVisibility(AXIS_DIRECTION axis, bool bvisible) = 0;//�������Ƿ�ɼ�
	virtual void setAxisWidth(AXIS_DIRECTION axis, float width) = 0;//�������ߵĿ��
};


#endif