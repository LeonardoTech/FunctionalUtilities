
#include "CoordinateAxis.h"
#include <osg/MatrixTransform>
#include "CoordinateUpdater.h"

/// @fn	osg::Geometry* createSimpleGeometry(float radius)
///
/// @brief 根据参数所指定的半径画出一个坐标系，返回一个osg::Geometry*类型的变量
/// 	   
/// @author	Admin
/// @date	2016/3/14
///
/// @param	radius	坐标系的边长.
///
/// @return	null if it fails, else the new simple geometry.
osg::Geometry* createSimpleGeometry(float radius)
{
	osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array(8);
	(*vertices)[0].set(0.0f, 0.0f, 0.0f);
	(*vertices)[1].set(radius, 0.0f, 0.0f);
	(*vertices)[2].set(0.0f, 0.0f, 0.0f);
	(*vertices)[3].set(0.0f, radius, 0.0f);
	(*vertices)[4].set(0.0f, 0.0f, 0.0f);
	(*vertices)[5].set(0.0f, 0.0f, radius);

	osg::ref_ptr<osg::DrawElementsUInt> indices = new osg::DrawElementsUInt(GL_LINES, 6);
	(*indices)[0] = 0; (*indices)[1] = 1; (*indices)[2] = 2; (*indices)[3] = 3;
	(*indices)[4] = 4; (*indices)[5] = 5;

	osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array;///指定颜色，连成一条线的两个点需要用相同的颜色
	colors->push_back(osg::Vec4(0.0f, 0.0f, 1.0f, 0.5f));
	colors->push_back(osg::Vec4(0.0f, 0.0f, 1.0f, 0.5f));
	colors->push_back(osg::Vec4(0.0f, 1.0f, 0.0f, 0.5f));
	colors->push_back(osg::Vec4(0.0f, 1.0f, 0.0f, 0.5f));
	colors->push_back(osg::Vec4(1.0f, 0.0f, 0.0f, 0.5f));
	colors->push_back(osg::Vec4(1.0f, 0.0f, 0.0f, 0.5f));
	osg::ref_ptr<osg::Geometry> geom = new osg::Geometry;
	geom->setDataVariance(osg::Object::DYNAMIC);
	geom->setUseDisplayList(false);
	geom->setUseVertexBufferObjects(true);
	geom->setColorArray(colors.get());
	geom->setVertexArray(vertices.get());
	geom->setColorArray(colors.get());
	geom->setColorBinding(osg::Geometry::BIND_PER_VERTEX);//需要将颜色绑定设置成每个顶点绑定
	geom->addPrimitiveSet(indices.get());

	osg::ref_ptr <osg::LineWidth> LineSize = new osg::LineWidth;
	LineSize->setWidth(3.0f);
	geom->getOrCreateStateSet()->setAttributeAndModes(LineSize.get(), osg::StateAttribute::ON);
	auto stateSet = geom->getOrCreateStateSet();
	stateSet->setMode(GL_LIGHTING, osg::StateAttribute::OFF);

	osgUtil::SmoothingVisitor::smooth(*geom);
	return geom.release();
}

/// @fn	osgText::Text* createText(const string name, const osg::Vec3 &position, const osg::Vec4 &color)
///
/// @brief	 在屏幕生成文字，以显示坐标轴指向的三维向量
///
/// @author	Admin
/// @date	2016/3/14
///
/// @param	name		坐标轴三维向量.
/// @param	position	生成文字的位置.
/// @param	color   		文字的颜色.
///
/// @return	null if it fails, else the new text.

osgText::Text* createText(const string name, const osg::Vec3 &position, const osg::Vec4 &color){
	osg::ref_ptr<osgText::Text> Label = new osgText::Text();
	Label->setCharacterSize(15.0f);
	Label->setFont(osgText::readFontFile("fonts/arial.ttf"));
	Label->setText(name);
	Label->setAxisAlignment(osgText::Text::SCREEN);
	Label->setDrawMode(osgText::Text::TEXT);

	Label->setAlignment(osgText::Text::CENTER_CENTER);
	Label->setPosition(position);
	Label->setColor(color);
	return Label.release();
}
/// @fn	CoordinateAxis::CoordinateAxis(osgGA::MultiTouchTrackballManipulator* manip)
///
/// @brief	 构造函数，对私有变量的初始化
///
/// @author	Admin
/// @date	2016/3/14
///
/// @param [in,out]	manip	If non-null, the manip.

CoordinateAxis::CoordinateAxis(osgGA::MultiTouchTrackballManipulator* manip)
{
	m_manip = manip;
	update = new CoordinateUpdater(m_manip);
}

CoordinateAxis::~CoordinateAxis()
{
}

/// @fn	void CoordinateAxis::getAxisDirection(Axis ax, float &x, float &y, float &z)
///
/// @brief	 通过参数指定的轴向来获取向量
///
/// @author	Admin
/// @date	2016/3/14
///
/// @param	ax		 	The ax.
/// @param [in,out]	x	指向的x向量.
/// @param [in,out]	y	指向的y向量.
/// @param [in,out]	z	指向的z向量.
void CoordinateAxis::getAxisDirection(Axis ax, float &x, float &y, float &z) {
	osg::Vec3  result = update->getResult(ax);
	x = result._v[0];
	y = result._v[1];
	z = result._v[2];
}

/// @fn	osg::MatrixTransform* CoordinateAxis::setAxis(float x, float y, float radius, osg::Camera *camera)
///
/// @brief	通过指定的二维屏幕坐标画出坐标系，可以指定坐标系的半径长度，需要把屏幕相机作为参数传进去
///
/// @author	Admin
/// @date	2016/3/14
///
/// @param	x			  	屏幕的二维横坐标.
/// @param	y			  	屏幕的二维纵坐标.
/// @param	radius		 坐标系 的边长.
/// @param [in]	camera	If non-null, the camera.
///
/// @return	null if it fails, else a pointer to an osg::MatrixTransform.
osg::MatrixTransform* CoordinateAxis::setAxis(float x, float y, float radius, osg::Camera *camera) {
	osg::ref_ptr<osg::Geode> geode = new osg::Geode;
	geode->addDrawable(createSimpleGeometry(radius));

	auto  _xText = createText("x", osg::Vec3(radius+5.0f, 0.0f, 0.0f), osg::Vec4(0.0f, 0.0f, 1.0f, 1.0f));
	auto  _yText = createText("y", osg::Vec3(0.0f, radius + 5.0f, 0.0f), osg::Vec4(0.0f, 1.0f, 0.0f, 1.0f));
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