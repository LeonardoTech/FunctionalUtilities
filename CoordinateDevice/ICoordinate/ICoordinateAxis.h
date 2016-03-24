#ifndef __ICOORDINATE_AXIS_H__
#define __ICOORDINATE_AXIS_H__
#include <string>
enum COORDINATE_NAME
{
	X_AXIS, 
	Y_AXIS, 
	Z_AXIS
};


class ICoordinateAxis
{
public:
	virtual void setLabel(COORDINATE_NAME axis, std::string label) = 0;//���ñ�ע
	virtual void setLabelPosition(COORDINATE_NAME axis, float x, float y, float z) = 0;///���ñ�ע���ֵ�λ��
	virtual void setColor(COORDINATE_NAME axis, float x, float y, float z) = 0;//���������ɫ
	virtual void setOriginPoint(float x, float y) = 0;//����ԭ��
	virtual void setRadius(float radius) = 0;//���ð뾶
	virtual void getAxisDirection3D(COORDINATE_NAME axis, float& x, float& y, float& z) = 0;//������λ��
	virtual void setDarkColor(COORDINATE_NAME axis, std::string color) = 0;//������Ľ���ɫ�İ�ɫ
	virtual void setLabelVisibility(COORDINATE_NAME axis, bool bvisible) = 0;//�������Ƿ�ɼ�
	virtual void setAxisWidth(float width) = 0;//�������ߵĿ��
};

#endif // __ICOORDINATE_AXIS_H__