#include "LinePrimitives.h"

LinePrimitives::LinePrimitives(osg::Geometry *geo,osg::Geode* geode)
{
	_geometry = new Geometry();
	_geo =  _geometry->getGeometry();
	geo = _geo;
	_geometry->drawGeometry();
	_geo->setVertexArray(new osg::Vec3Array(2));
	_geo->addPrimitiveSet(new osg::DrawArrays(GL_LINES, 0, 2));
	_geode = geode;
	_state = false;
}


void LinePrimitives::setLineWidth(float width)
{
	_geode->addDrawable(_geo);
	osg::ref_ptr<osg::LineWidth>linewidth = new osg::LineWidth;
	linewidth->setWidth(width);
	_geode->getOrCreateStateSet()->setAttributeAndModes(linewidth.get(), osg::StateAttribute::ON);
	setCreateState();
}


void LinePrimitives::setColor(float red, float green, float blue)
{
	_geometry->setColor(red,green,blue	);
	setCreateState();
}

void LinePrimitives::setCreateState()
{
	if (!_state)
	{
		_state = true;
		_geode->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::OFF);
		_geode->getOrCreateStateSet()->setMode(GL_BLEND, osg::StateAttribute::ON);
		_geode->getOrCreateStateSet()->setRenderingHint(osg::StateSet::TRANSPARENT_BIN);
	}
}
