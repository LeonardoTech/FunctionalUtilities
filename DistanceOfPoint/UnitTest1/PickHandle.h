
#include "../DistanceOfPoint/PickHandler.h"
#include <osg/Geometry>
#include <osg/Geode>
#include <osg/MatrixTransform>
#include <osg/Point>
#include <osg/PolygonOffset>
#include <osgUtil/SmoothingVisitor>
#include <osgViewer/Viewer>
#include <osgDB/readFile>
#include <iostream>
#include "osgGA/GUIEventHandler"
#include "SelectModelPoint.h"
#include <osgText/Font>
#include <osgText/Text>
#include "osg/Group"
#include "../DistanceOfPoint/Distance.h"


// class	PickHandler
// brief	 <�̳���osgGA::GUIEventHandler���������¼��Ķ��壬�Լ���ȡ����λ�ã�>
// date	2016/3/14
class PickHandler : public osgGA::GUIEventHandler
{
public:
	// <���캯������˽�б������г�ʼ������������ͼ�Σ�>
	PickHandler(Distance* selector);

	// <������¼��ĸ��ģ�����ɹ����ϵ�Ҫ��>
	virtual bool handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa);
	// <�ѵ㣬�ߣ����ֵȶ��ӵ�һ������>
	void setRoot(osg::Group* node);
	// <����һ����>
	osg::Geode* createLine();

protected:
	Distance* _select;

	osg::Group* _root;
	bool _isSelect1Down;
	bool _isSelect2Down;
	osg::Geometry* _geometry;
	osgText::Text *_text;
};





osg::Geometry* createSimpleGeometry();