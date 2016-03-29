#include <osg/LineWidth>

#include "LinePrimitive.h"


// <构造函数>
#pragma region LinePrimitives

LinePrimitive::LinePrimitive()
{
	_geometry = new osg::Geometry;
	_vertices = new osg::Vec3Array(2);
	_color = new osg::Vec4Array(1);
	_startPosition = { 0.0f, 0.0f, 0.0f };
	_endPosition = { 0.0f, 0.0f, 0.0f };

	_geometry->setDataVariance(osg::Object::DYNAMIC);
	_geometry->setUseDisplayList(false);
	_geometry->setUseVertexBufferObjects(true);
	_geometry->setVertexArray(_vertices);
	_geometry->setColorArray(_color);
	_geometry->setColorBinding(osg::Geometry::BIND_OVERALL);
	_geometry->addPrimitiveSet(new osg::DrawArrays(GL_LINES, 0, 2));
	auto stateSet = _geometry->getOrCreateStateSet();
	stateSet->setMode(GL_LIGHTING, osg::StateAttribute::OFF);
}

#pragma endregion 

#pragma region SetLineWidth

void LinePrimitive::setLineWidth(float width)
{
	osg::ref_ptr<osg::LineWidth>linewidth = new osg::LineWidth;
	linewidth->setWidth(width);
	_geometry->getOrCreateStateSet()->setAttributeAndModes(linewidth, osg::StateAttribute::ON);
}

#pragma endregion

#pragma region SetColor

void LinePrimitive::setColor(float red, float green, float blue)
{
	osg::Vec4 color = { red, green, blue, 1.0f };
	(*_color)[0] = color;
	_color->dirty();
	//_geometry->setColorArray(_color);
	_geometry->dirtyBound();
}

#pragma endregion

#pragma region getGeometry

osg::Geometry* LinePrimitive::getGeometry()
{
	return _geometry;
}
#pragma endregion

#pragma region GetStartPosition

void LinePrimitive::getStartPosition(float& x, float& y, float& z)
{
	x = _startPosition.x();
	y = _startPosition.y();
	z = _startPosition.z();
}

osg::Vec3 LinePrimitive::getStartPosition() const
{
	return _startPosition;
}

#pragma endregion

#pragma region GetEndPosition

void LinePrimitive::getEndPosition(float& x, float& y, float& z)
{
	x = _endPosition.x();
	y = _endPosition.y();
	z = _endPosition.z();
}

osg::Vec3 LinePrimitive::getEndPosition() const
{
	return _endPosition;
}

#pragma endregion

#pragma region SetStartPosition

void LinePrimitive::setStartPosition(float x, float y, float z)
{
	_startPosition = { x, y, z };
	(*_vertices)[0] = _startPosition;
	_vertices->dirty();
	_geometry->dirtyBound();
}

void LinePrimitive::setStartPosition(osg::Vec3 pos)
{
	_startPosition = pos;
	(*_vertices)[0] = _startPosition;
	_vertices->dirty();
	_geometry->dirtyBound();
}

#pragma endregion

#pragma region SetEndPosition

void LinePrimitive::setEndPosition(float x, float y, float z)
{
	_endPosition = { x, y, z };
	(*_vertices)[1] = _endPosition;
	_vertices->dirty();
	_geometry->dirtyBound();
}

void LinePrimitive::setEndPosition(osg::Vec3 pos)
{
	_endPosition = pos;
	(*_vertices)[1] = _endPosition;
	_vertices->dirty();
	_geometry->dirtyBound();
}

#pragma endregion

#pragma region SetVertices

void LinePrimitive::setVertices(const VertexArray& arr)
{
	_vertices = new osg::Vec3Array(arr.size());
	for (int i = 0; i < arr.size();i++)
	{
		(*_vertices)[i].set(arr[i].getX(), arr[i].getY(), arr[i].getZ());
	}
}

#pragma endregion

#pragma region GetVertices

VertexArray LinePrimitive::getVertices() const
{
	VertexArray arr(_vertices->size());
	for (int i = 0; i < _vertices->size(); i++)
	{
		std::vector<float> vf;
		vf.push_back((*_vertices)[i].x());
		vf.push_back((*_vertices)[i].y());
		vf.push_back((*_vertices)[i].z());
		arr[i].setVertices(vf);
		(*_vertices)[i].set(arr[i].getX(), arr[i].getY(), arr[i].getZ());
	}
	return arr;
}

#pragma endregion