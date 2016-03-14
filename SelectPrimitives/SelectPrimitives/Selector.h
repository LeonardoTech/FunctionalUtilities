#pragma once
#include <osg/Camera>
const osg::Vec4 normalColor(1.0f, 1.0f, 1.0f, 1.0f);
const osg::Vec4 selectedColor(1.0f, 0.0f, 0.0f, 1.0f);
class Selector
{
public:
	//����ͼ��
	virtual osg::Geode* createSelector() = 0;

	//�����������Ļ��Ķ�ά������ȷ��ͼ�ε�λ��
	virtual bool drawbyCoordinate(float x, float y, osg::Camera* camera) = 0;

	//ȡ����ͼ�ζ������ά����
	virtual osg::Vec3 getPosition() = 0;

};