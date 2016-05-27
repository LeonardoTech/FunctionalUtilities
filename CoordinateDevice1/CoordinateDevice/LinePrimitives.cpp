#include "LinePrimitives.h"

LinePrimitives::LinePrimitives()
{
	_geometry = new osg::Geometry;
	_color = new osg::Vec4Array(1);
	_startPosition = { 0.0f, 0.0f, 0.0f };
	_endPosition = { 0.0f, 0.0f, 0.0f };
}


void LinePrimitives::drawGeometry()
{
	 
	_geometry->setDataVariance(osg::Object::DYNAMIC);
	_geometry->setUseDisplayList(false);
	_geometry->setUseVertexBufferObjects(true);
	_geometry->setVertexArray(new osg::Vec3Array(2));
	_geometry->setColorArray(_color);
	_geometry->setColorBinding(osg::Geometry::BIND_OVERALL);
	_geometry->addPrimitiveSet(new osg::DrawArrays(GL_LINES, 0, 2));
	auto stateSet = _geometry->getOrCreateStateSet();
	stateSet->setMode(GL_LIGHTING, osg::StateAttribute::OFF);
	//osg::ref_ptr<osg::Geode> geode = new osg::Geode;
	//geode->addDrawable(_geometry.get());
	//geode->getOrCreateStateSet()->setAttributeAndModes(new osg::Point(10.0f));
	//geode->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::OFF);
	//geode->getOrCreateStateSet()->setMode(GL_BLEND, osg::StateAttribute::ON);
	//geode->getOrCreateStateSet()->setRenderingHint(osg::StateSet::TRANSPARENT_BIN);
}


void LinePrimitives::setLineWidth(float width)
{
	osg::ref_ptr<osg::LineWidth>linewidth = new osg::LineWidth;
	linewidth->setWidth(width);
	_geometry->getOrCreateStateSet()->setAttributeAndModes(linewidth, osg::StateAttribute::ON);
}

void LinePrimitives::setColor(float red, float green, float blue)
{
	osg::Vec4 color = { red, green, blue, 1.0f };
	//osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array(1);
	(*_color)[0] = color;
	//colors = dynamic_cast<osg::Vec4Array*>(_geometry->getColorArray());
	_color->dirty();
	_geometry->setColorArray(_color);
	_geometry->dirtyBound();
}



void LinePrimitives::setVertex()
{
	osg::ref_ptr<osg::Vec3Array>verties = new osg::Vec3Array(2);
	(*verties)[0] = _startPosition;
	(*verties)[1] = _endPosition;
	_geometry->setVertexArray(verties); 
	//verties = dynamic_cast<osg::Vec3Array*>(_geometry->getVertexArray());
	_geometry->dirtyBound();
}


osg::Geometry* LinePrimitives::getGeometry()
{
	return _geometry;
}



void LinePrimitives::setStartPosition(float x, float y, float z)
{
	_startPosition = { x, y, z };
}

void LinePrimitives::setEndPosition(float x, float y, float z)
{
	_endPosition = { x, y, z };
	setVertex();
}

