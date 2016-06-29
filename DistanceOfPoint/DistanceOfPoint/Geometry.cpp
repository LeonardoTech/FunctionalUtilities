#include "Geometry.h"
#include <osg/Geometry>
#include <osg/Geode>


void Geometry::drawGeometry()
{
	_geometry = new osg::Geometry;
	_geometry->setDataVariance(osg::Object::DYNAMIC);
	_geometry->setUseDisplayList(false);
	_geometry->setUseVertexBufferObjects(true);
	_geometry->setColorBinding(osg::Geometry::BIND_OVERALL);
}

void Geometry::setColor(float red, float green, float blue)
{
	osg::Vec4 color = { red, green, blue, 1.0f };
	osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array(1);
	(*colors)[0] = color;
	_geometry->setColorArray(colors.get());
}


osg::Geometry * Geometry::getGeometry()
{
	return _geometry;
}
