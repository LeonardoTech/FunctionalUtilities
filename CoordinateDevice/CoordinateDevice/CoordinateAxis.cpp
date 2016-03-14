
#include "CoordinateAxis.h"
#include <osg/MatrixTransform>
#include "CoordinateUpdater.h"

/// @fn	osg::Geometry* createSimpleGeometry(float radius)
///
/// @brief ���ݲ�����ָ���İ뾶����һ������ϵ������һ��osg::Geometry*���͵ı���
/// 	   
/// @author	Admin
/// @date	2016/3/14
///
/// @param	radius	����ϵ�ı߳�.
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

	osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array;///ָ����ɫ������һ���ߵ���������Ҫ����ͬ����ɫ
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
	geom->setColorBinding(osg::Geometry::BIND_PER_VERTEX);//��Ҫ����ɫ�����ó�ÿ�������
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
/// @brief	 ����Ļ�������֣�����ʾ������ָ�����ά����
///
/// @author	Admin
/// @date	2016/3/14
///
/// @param	name		��������ά����.
/// @param	position	�������ֵ�λ��.
/// @param	color   		���ֵ���ɫ.
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
/// @brief	 ���캯������˽�б����ĳ�ʼ��
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
/// @brief	 ͨ������ָ������������ȡ����
///
/// @author	Admin
/// @date	2016/3/14
///
/// @param	ax		 	The ax.
/// @param [in,out]	x	ָ���x����.
/// @param [in,out]	y	ָ���y����.
/// @param [in,out]	z	ָ���z����.
void CoordinateAxis::getAxisDirection(Axis ax, float &x, float &y, float &z) {
	osg::Vec3  result = update->getResult(ax);
	x = result._v[0];
	y = result._v[1];
	z = result._v[2];
}

/// @fn	osg::MatrixTransform* CoordinateAxis::setAxis(float x, float y, float radius, osg::Camera *camera)
///
/// @brief	ͨ��ָ���Ķ�ά��Ļ���껭������ϵ������ָ������ϵ�İ뾶���ȣ���Ҫ����Ļ�����Ϊ��������ȥ
///
/// @author	Admin
/// @date	2016/3/14
///
/// @param	x			  	��Ļ�Ķ�ά������.
/// @param	y			  	��Ļ�Ķ�ά������.
/// @param	radius		 ����ϵ �ı߳�.
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