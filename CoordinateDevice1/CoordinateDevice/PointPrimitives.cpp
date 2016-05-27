#include "PointPrimitives.h"

PointPrimitives::PointPrimitives()
{
	_geometry = new osg::Geometry;
	_color = new osg::Vec4Array(1);
	_vertex = { 0.0f, 0.0f, 0.0f };
}

void PointPrimitives::drawGeometry()
{
	_geometry->setDataVariance(osg::Object::DYNAMIC);
	_geometry->setUseDisplayList(false);
	_geometry->setUseVertexBufferObjects(true);
	_geometry->setVertexArray(new osg::Vec3Array(1));
	_geometry->setColorArray(_color);
	_geometry->setColorBinding(osg::Geometry::BIND_OVERALL);
	_geometry->addPrimitiveSet(new osg::DrawArrays(GL_POINTS, 0, 1));
	auto stateSet = _geometry->getOrCreateStateSet();
	stateSet->setMode(GL_LIGHTING, osg::StateAttribute::OFF);
}


void PointPrimitives::setSize(float size)
{
	auto stateSet = _geometry->getOrCreateStateSet();
	stateSet->setAttributeAndModes(new osg::Point(size));
	setGeode();
	_geometry->dirtyBound();
}
void PointPrimitives::setColor(float red, float green, float blue)
{

	osg::Vec4 color = { red, green, blue, 1.0f };
	(*_color)[0] = color;
	_color->dirty();
	_geometry->setColorArray(_color);
	_geometry->dirtyBound();
}


void PointPrimitives::setPosition(float x, float y, float z)
{
	_vertex = { x, y, z };
	osg::ref_ptr<osg::Vec3Array>verties = new osg::Vec3Array(1);
	(*verties)[0] = _vertex;
	_geometry->dirtyBound();
}


osg::Geometry *PointPrimitives::getGeometry()
{
	return _geometry;
}

