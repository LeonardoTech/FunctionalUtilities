#include <osg/Point>

#include "PointPrimitive.h"

// <���캯��>
#pragma region PointPrimitives

PointPrimitive::PointPrimitive()
{
	_size = 1;
	_geometry = new osg::Geometry;
	_vertices = new osg::Vec3Array(1);
	_color = new osg::Vec4Array(1);
	_vertex = { 0.0f, 0.0f, 0.0f };

	_geometry->setDataVariance(osg::Object::DYNAMIC);
	_geometry->setUseDisplayList(false);
	_geometry->setUseVertexBufferObjects(true);
	_geometry->setVertexArray(_vertices);
	_geometry->setColorArray(_color);
	_geometry->setColorBinding(osg::Geometry::BIND_OVERALL);
	_geometry->addPrimitiveSet(new osg::DrawArrays(GL_POINTS, 0, 1));
	auto stateSet = _geometry->getOrCreateStateSet();
	stateSet->setMode(GL_LIGHTING, osg::StateAttribute::OFF);
	stateSet->setAttributeAndModes(new osg::Point(_size));
}

#pragma endregion

#pragma region GetSize

float PointPrimitive::getSize() const
{
	return _size;
}

#pragma endregion

#pragma region SetSize

void PointPrimitive::setSize(float size)
{
	_size = size;
	auto stateSet = _geometry->getOrCreateStateSet();
	stateSet->setAttributeAndModes(new osg::Point(size));
	_geometry->dirtyBound();
}

#pragma endregion

#pragma region SetColor

void PointPrimitive::setColor(float red, float green, float blue)
{

	osg::Vec4 color = { red, green, blue, 1.0f };
	(*_color)[0] = color;
	_color->dirty();
	_geometry->setColorArray(_color);
	_geometry->dirtyBound();
}

#pragma endregion

#pragma region getPosition

void PointPrimitive::getPosition(float& x, float& y, float& z) const
{
	x = _vertex.x();
	y = _vertex.y();
	z = _vertex.z();
}

osg::Vec3 PointPrimitive::getPosition() const
{
	return _vertex;
}

VertexArray PointPrimitive::getVertices() const
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

#pragma endregion

#pragma region setPosition

void PointPrimitive::setPosition(float x, float y, float z)
{
	_vertex = { x, y, z };
	(*_vertices)[0] = _vertex;
	_vertices->dirty();
	_geometry->dirtyBound();
}

void PointPrimitive::setPosition(const osg::Vec3& pos)
{
	_vertex = pos;
	(*_vertices)[0] = _vertex;
	_vertices->dirty();
	_geometry->dirtyBound();
}


void PointPrimitive::setVertices(const VertexArray& arr)
{

	_vertex.set(arr[0].getX(), arr[0].getY(), arr[0].getZ());
}

#pragma endregion

// <��ȡ�ӿڷ������>
#pragma region GetGeometry

osg::Geometry *PointPrimitive::getGeometry()
{
	return _geometry;
}

#pragma endregion
