#ifndef __SELECT_LINE_H__
#define __SELECT_LINE_H__

#include "ISelectPrimitives.h"
#include "LinePrimitive.h"


#include <osg/Camera>
#include <osgUtil/LineSegmentIntersector>

// <ѡ����Ԫ���࣬�̳���ISelectPrimitives�ӿ���>
class SelectLine :public ISelectPrimitives
{
public:

	// <���캯������ʼ��˽�г�Ա���������������>
	SelectLine(osg::Camera* camera);

	// <�ӿ�����ⲿ��������Ļ�ϵ�ĳһ���������Ϊ������ȷ�����λ��>
	virtual IDrawElement* select(float x, float y) override;

	//  <�ӿ�����ⲿ��������ȡѡ����Ķ���λ�ã���ȡ��Ԫ��ָ��>
	virtual IDrawElement* getSelection() const override;

	// <��Ļ�ϵ�ĳһ���������Ϊ������������>
	virtual LinePrimitive* selectLine(float x, float y);

	//  <��ȡѡ����Ķ���λ�ã���ȡ��Ԫָ��>
	virtual LinePrimitive* getSelectedLine() const;


	osg::Node* getRoot() const;


protected:

	// <ͨ���ཻ�㷨����󷵻صĽ������ȷ�����λ�ã���ͨ������Ѷ�ά������ת��Ϊ��ά�ģ�ΪҪ����ͼ��ȷ����������>
	void doUserOperations(osgUtil::LineSegmentIntersector::Intersection& result);

	LinePrimitive* m_line;
	osg::Camera* m_camera;
};

#endif // __SELECT_LINE_H__
