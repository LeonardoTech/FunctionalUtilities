
#include "CoordinateAxis.h"
#include <osg/MatrixTransform>
#include "CoordinateUpdater.h"

//
//osg::ref_ptr<osgText::Font> g_font = osgText::readFontFile("fonts/arial.ttf");

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

	osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array;
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
	geom->setColorBinding(osg::Geometry::BIND_PER_VERTEX);
	geom->addPrimitiveSet(indices.get());

	osg::ref_ptr <osg::LineWidth> LineSize = new osg::LineWidth;
	LineSize->setWidth(3.0f);
	geom->getOrCreateStateSet()->setAttributeAndModes(LineSize.get(), osg::StateAttribute::ON);
	auto stateSet = geom->getOrCreateStateSet();
	stateSet->setMode(GL_LIGHTING, osg::StateAttribute::OFF);

	osgUtil::SmoothingVisitor::smooth(*geom);
	return geom.release();
}

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

CoordinateAxis::CoordinateAxis(osgGA::MultiTouchTrackballManipulator* manip)
{
	m_manip = manip;
	update = new CoordinateUpdater(m_manip);
}

CoordinateAxis::~CoordinateAxis()
{
}

//void CoordinateAxis::getAxisDirection(Axis axis, float &x, float &y, float &z) {
void CoordinateAxis::getAxisDirection(Axis ax, float &x, float &y, float &z) {
	osg::Vec3  result = update->getResult(ax);
	x = result._v[0];
	y = result._v[1];
	z = result._v[2];
}

osg::MatrixTransform* CoordinateAxis::setAxis(float x, float y, float radius, osg::Camera *camera) {
	osg::ref_ptr<osg::Geode> geode = new osg::Geode;
	geode->addDrawable(createSimpleGeometry(radius));

	auto  _xText = createText("x", osg::Vec3(radius+5.0f, 0.0f, 0.0f), osg::Vec4(0.0f, 0.0f, 1.0f, 1.0f));
	auto  _yText = createText("y", osg::Vec3(0.0f, radius + 5.0f, 0.0f), osg::Vec4(0.0f, 1.0f, 0.0f, 1.0f));
	auto  _zText = createText("z", osg::Vec3(0.0f, 0.0f, radius + 5.0f), osg::Vec4(1.0f, 0.0f, 0.0f, 1.0f));
	
	//osg::ref_ptr<osg::Group> root = new osg::Group;
	//osgViewer::Viewer view;
	//view.setCameraManipulator(manip);
	osg::ref_ptr<osg::MatrixTransform> textGeode = new osg::MatrixTransform;
	
	//textGeode->setUpdateCallback(new CoordinateUpdater(manip));
	//m_manip = manip;

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
	
	//camera->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::OFF);
	//
	//view.setSceneData(root.get());
	//view.run();

}