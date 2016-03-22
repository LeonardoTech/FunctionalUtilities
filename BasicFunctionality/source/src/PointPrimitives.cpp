#include "PointPrimitives.h"

PointPrimitives::PointPrimitives()
{
	_size = 1;
	_geometry = new osg::Geometry;
	_color = new osg::Vec4Array(1);
	_vertex = { 0.0f, 0.0f, 0.0f };

	_geometry->setDataVariance(osg::Object::DYNAMIC);
	_geometry->setUseDisplayList(false);
	_geometry->setUseVertexBufferObjects(true);
	_geometry->setVertexArray(new osg::Vec3Array(1));
	_geometry->setColorArray(_color);
	_geometry->setColorBinding(osg::Geometry::BIND_OVERALL);
	_geometry->addPrimitiveSet(new osg::DrawArrays(GL_POINTS, 0, 1));
	auto stateSet = _geometry->getOrCreateStateSet();
	stateSet->setMode(GL_LIGHTING, osg::StateAttribute::OFF);
	stateSet->setAttributeAndModes(new osg::Point(_size));
}

float PointPrimitives::getSize() const
{
	return _size;
}

void PointPrimitives::setSize(float size)
{
	_size = size;
	auto stateSet = _geometry->getOrCreateStateSet();
	stateSet->setAttributeAndModes(new osg::Point(size));
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

void PointPrimitives::getPosition(float& x, float& y, float& z) const
{
	x = _vertex.x();
	y = _vertex.y();
	z = _vertex.z();
}


void PointPrimitives::setPosition(float x, float y, float z)
{
	_vertex = { x, y, z };
	osg::ref_ptr<osg::Vec3Array>verties = new osg::Vec3Array(1);
	(*verties)[0] = _vertex;
	_geometry->setVertexArray(verties);
	_geometry->dirtyBound();
}


osg::Geometry *PointPrimitives::getGeometry()
{
	return _geometry;
}


VertexArray PointPrimitives::getVertices() const
{
	VertexArray arr;
	Vertex v;
	std::vector<float> vf;
	vf.push_back(_vertex.x());
	vf.push_back(_vertex.y());
	vf.push_back(_vertex.z());
	v.setVertices(vf);
	arr.push_back(v);
	return arr;
}

void PointPrimitives::setVertices(const VertexArray& arr)
{
	_vertex.set(arr[0].getX(), arr[0].getY(), arr[0].getZ());
}