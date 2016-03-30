#include "CoordinateAxis.h"
#include <osg/MatrixTransform>
#include "CoordinateUpdater.h"
#include "LinePrimitives.h"
#include "TextPrimitives.h"

osg::Geometry* createSimpleGeometry_x(float radius)
{

	LinePrimitives *linex = new LinePrimitives;
	linex->drawGeometry();
	linex->setStartPosition(0.0f, 0.0f, 0.0f);
	linex->setEndPosition(radius, 0.0f, 0.0f);
	linex->setColor(1.0f, 0.0f, 0.0f);
	osg::ref_ptr<osg::Geometry>geomx = linex->getGeometry();
	return geomx.release();
}

osg::Geometry* createSimpleGeometry_y(float radius)
{
	LinePrimitives *linex = new LinePrimitives;
	linex->drawGeometry();
	linex->setStartPosition(0.0f, 0.0f, 0.0f);
	linex->setEndPosition(0.0f, radius, 0.0f);
	linex->setColor(1.0f, 0.0f, 0.0f);
	osg::ref_ptr<osg::Geometry>geomx = linex->getGeometry();
	return geomx.release();
}

osg::Geometry* createSimpleGeometry_z(float radius)
{

	LinePrimitives *linex = new LinePrimitives;
	linex->drawGeometry();
	linex->setStartPosition(0.0f, 0.0f, 0.0f);
	linex->setEndPosition(0.0f, 0.0f, radius);
	linex->setColor(1.0f, 0.0f, 0.0f);
	osg::ref_ptr<osg::Geometry>geomx = linex->getGeometry();
	return geomx.release();
}


//  <在屏幕生成文字，以显示坐标轴指向的三维向量>
osgText::Text* createText(const string name, const osg::Vec3 &position, const osg::Vec4 &color){

	TextPrimitives *text = new TextPrimitives;
	text->drawGeometry();
	text->setColor(color._v[0], color._v[1], color._v[2] );
	text->setPosition(position._v[0], position._v[1], position._v[2]);
	text->setText(name);
	osg::ref_ptr<osgText::Text> Label =text->getOsgText();

	return Label.release();
}

//	 <构造函数，对私有变量的初始化>
CoordinateAxis::CoordinateAxis(osgGA::MultiTouchTrackballManipulator* manip)
{
	m_manip = manip;
	update = new CoordinateUpdater(m_manip);
}

CoordinateAxis::~CoordinateAxis()
{
}

//  <通过参数指定的轴向来获取向量>
void CoordinateAxis::getAxisDirection(Axis ax, float &x, float &y, float &z) {
	osg::Vec3  result = update->getResult(ax);
	x = result._v[0];
	y = result._v[1];
	z = result._v[2];
}

// 	<通过指定的二维屏幕坐标画出坐标系，可以指定坐标系的半径长度，需要把屏幕相机作为参数传进去
osg::MatrixTransform* CoordinateAxis::setAxis(float x, float y, float radius, osg::Camera *camera) {
	osg::ref_ptr<osg::Geode> geode = new osg::Geode;
	geode->addDrawable(createSimpleGeometry_x(radius));
	geode->addDrawable(createSimpleGeometry_y(radius));
	geode->addDrawable(createSimpleGeometry_z(radius));

	auto  _xText = createText("x", osg::Vec3(radius + 5.0f, 0.0f, 0.0f), osg::Vec4(0.0f, 0.0f, 1.0f, 0.5f));
	auto  _yText = createText("y", osg::Vec3(0.0f, radius + 5.0f, 0.0f), osg::Vec4(0.0f, 1.0f, 0.0f, 0.5f));
	auto  _zText = createText("z", osg::Vec3(0.0f, 0.0f, radius + 5.0f), osg::Vec4(1.0f, 0.0f, 0.0f, 1.0f));

	osg::ref_ptr<osg::MatrixTransform> textGeode = new osg::MatrixTransform;

	auto transNode = new osg::MatrixTransform();

	transNode->setMatrix(osg::Matrix::translate(osg::Vec3(x, y, -100)));
	camera->addChild(transNode);
	transNode->addChild(textGeode.get());
	textGeode->addChild(geode.get());
	textGeode->addChild(_xText);
	textGeode->addChild(_yText);
	textGeode->addChild(_zText);

	textGeode->setUpdateCallback(update);
	return textGeode.release();

}