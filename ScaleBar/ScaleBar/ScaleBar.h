#ifndef __SCALEBAR_H__
#define __SCALEBAR_H__



#include <osg/NodeCallback>
#include <osg/MatrixTransform>
#include <osgGA/MultiTouchTrackballManipulator>



class ScaleBar :public osg::NodeCallback
{
public:
	// brief	 <����˽�г�Ա���г�ʼ�������ô�������manip����ʾ��ǰ�Ļ���>
	ScaleBar(osgGA::MultiTouchTrackballManipulator* manip);
	// <�Դ�������manip���в���.>
	virtual void operator()(osg::Node* node, osg::NodeVisitor* nv) override;
	//// < ���ݴ�����Axis��ö��ֵ����ȷ����ȡ�ĸ���Ľ��.>
	//osg::Vec3 getResult(Axis ax);

private:
	osgGA::MultiTouchTrackballManipulator* m_manip;
	osg::Vec3 result;
	double _distance;
};



#endif