﻿#pragma once
#include "Selector.h"
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


// class	PickHandler
// 
// brief	 <继承于osgGA::GUIEventHandler，对数表事件的定义，以及获取鼠标的位置，>
// 
// author	Admin
// date	2016/3/14
class PickHandler : public osgGA::GUIEventHandler
{
public:
	// <构造函数，对私有变量进行初始化（定义两个图形）>
	PickHandler(Selector* selector, Selector *selector1);
	// <对鼠标事件的更改，以完成功能上的要求>
	virtual bool handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa);
	// <把点，线，文字等都加到一个组里>
	void setRoot(osg::Group* node);
	// <创建一条线>
	osg::Geode* createLine();
	// <设置并创建文字>
	osgText::Text* createText();
protected:
	Selector* _select2;
	Selector* _select1;
	osg::Group* _root;
	osg::Vec3 _axis1;
	osg::Vec3 _axis2;
	bool _isSelect1Down;
	bool _isSelect2Down;
	osg::Geometry* _geometry;
	osgText::Text *_text;
};
