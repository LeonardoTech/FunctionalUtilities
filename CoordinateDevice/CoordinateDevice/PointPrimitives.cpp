#include "PointPrimitives.h"

PointPrimitives::PointPrimitives(osg::Geode *geode)
{
	_geometry = new Geometry();
	_geometry->drawGeometry();
	_geo->setVertexArray(new osg::Vec3Array(1));
	_geo->addPrimitiveSet(new osg::DrawArrays(GL_POINTS, 0, 1));
	_geode = geode;
}

void drawGeometry()
{

}


void PointPrimitives::setSize(float size)
{
	_geode = new osg::Geode;
	_geode->addDrawable(_geo.get());
	_geode->getOrCreateStateSet()->setAttributeAndModes(new osg::Point(size));
	setGeode();
}
void PointPrimitives::setColor(float red, float green, float blue)
{
	_geometry->setColor(red, green, blue);
	osg::ref_ptr<osg::Geode> _geode = new osg::Geode;
	_geode->addDrawable(_geo.get());
	setGeode();
}


void PointPrimitives::setPoint(float size, float red, float green, float blue)
{
	_geometry->setColor(red, green, blue);
	_geode = new osg::Geode;
	_geode->addDrawable(_geo.get());
	_geode->getOrCreateStateSet()->setAttributeAndModes(new osg::Point(size));
	setGeode();
}


void PointPrimitives::setGeode()
{
	_geode->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::OFF);
	_geode->getOrCreateStateSet()->setMode(GL_BLEND, osg::StateAttribute::ON);
	_geode->getOrCreateStateSet()->setRenderingHint(osg::StateSet::TRANSPARENT_BIN);
}