#ifndef __SCALEBAR_H__
#define __SCALEBAR_H__



#include <osg/NodeCallback>
#include <osg/MatrixTransform>
#include <osgGA/MultiTouchTrackballManipulator>



class ScaleBar :public osg::NodeCallback
{
public:
	// brief	 <构造私有成员进行初始化，利用传进来的manip来表示当前的环境>
	ScaleBar(osgGA::MultiTouchTrackballManipulator* manip);
	// <对传进来的manip进行操作.>
	virtual void operator()(osg::Node* node, osg::NodeVisitor* nv) override;
	//// < 根据传进来Axis的枚举值，来确定获取哪个轴的结果.>
	//osg::Vec3 getResult(Axis ax);

private:
	osgGA::MultiTouchTrackballManipulator* m_manip;
	osg::Vec3 result;
	double _distance;
};



#endif