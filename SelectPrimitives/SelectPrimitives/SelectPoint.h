#ifndef __SELECT_POINT_H__
#define __SELECT_POINT_H__

#include <osg/Camera>
#include <osgUtil/LineSegmentIntersector>

#include "ISelectPrimitives.h"
#include "PointPrimitives.h"

// <ѡ����Ԫ���࣬�̳���ISelectPrimitives�ӿ���>
class SelectPoint :public ISelectPrimitives
{
public:
	// <���캯������ʼ��˽�г�Ա���������������>
	SelectPoint(osg::Camera* camera);

	// <�ӿ�����ⲿ��������Ļ�ϵ�ĳһ���������Ϊ������ȷ�����λ��>
	virtual IDrawElement* select(float x, float y) override;

	//  <�ӿ�����ⲿ��������ȡѡ����Ķ���λ�ã���ȡ��Ԫ��ָ��>
	virtual IDrawElement* getSelection() const override;

// internal:
	// <��Ļ�ϵ�ĳһ���������Ϊ���������Ƶ�>
	virtual PointPrimitives* selectPoint(float x, float y);

	//  <��ȡѡ���Ķ���λ�ã���ȡ��Ԫָ��>
	virtual PointPrimitives* getSelectedPoint() const;

	osg::Node* getRoot() const;

	void setPointPosition(const osg::Vec3& pos);

protected:

	// <�����ཻ����Ľ����ȷ���ߵĶ���λ��>
	void doUserOperations(osgUtil::LineSegmentIntersector::Intersection& result);
	PointPrimitives* m_point;
	osg::Camera* m_camera;
};

#endif // __SELECT_POINT_H__
