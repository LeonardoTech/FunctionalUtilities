#include <osg/Point>
//#include <osg/ValueObject>
#include "PointPrimitive.h"
#include <osg/ValueObject >

#pragma region PointPrimitives

// <初始化>
PointPrimitive::PointPrimitive()
{
	_size = 1;
	//_geometry = new osg::Geometry;
	_vertices = new osg::Vec3Array(1);
	_color = new osg::Vec4Array(1);
	_vertex = { 0.0f, 0.0f, 0.0f };

	this->setDataVariance(osg::Object::DYNAMIC);
	this->setUseDisplayList(false);
	this->setUseVertexBufferObjects(true);
	this->setVertexArray(_vertices);
	this->setColorArray(_color);
	this->setColorBinding(osg::Geometry::BIND_OVERALL);
	this->addPrimitiveSet(new osg::DrawArrays(GL_POINTS, 0, 1));
	auto stateSet = this->getOrCreateStateSet();
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
	auto stateSet = getOrCreateStateSet();
	stateSet->setAttributeAndModes(new osg::Point(size));
	dirtyBound();
}

#pragma endregion

#pragma region SetColor
void PointPrimitive::setColor(float red, float green, float blue)
{

	osg::Vec4 color = { red, green, blue, 1.0f };
	(*_color)[0] = color;
	_color->dirty();
	setColorArray(_color);
	dirtyBound();
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
	dirtyBound();
}

void PointPrimitive::getPosition(float& x, float& y, float& z)
{
	x = _vertex.x();
	y = _vertex.y();
	z = _vertex.z();
}

void PointPrimitive::setPosition(const osg::Vec3& pos)
{
	_vertex = pos;
	(*_vertices)[0] = _vertex;
	_vertices->dirty();
	dirtyBound();
}

void PointPrimitive::setVertices(const VertexArray& arr)
{
	_vertex.set(arr[0].getX(), arr[0].getY(), arr[0].getZ());
}

#pragma endregion


#pragma region GetGeometry
// <获取osg::Geometry节点>
osg::Geometry *PointPrimitive::getGeometry()
{
	return this;
}

#pragma endregion

IDrawElement* PointPrimitive::create(osg::Geometry *geom)const
{
	PointPrimitive *point = new PointPrimitive();
	point = dynamic_cast<PointPrimitive *>(geom);
	point->_vertices = dynamic_cast<osg::Vec3Array*>(geom->getVertexArray());
	point->_color = dynamic_cast<osg::Vec4Array*>(geom->getColorArray());
	//geom->getUserValue("_vertex", point->_vertex);

	return point;
}




