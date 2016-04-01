#include "FacePrimitive.h"

// <构造函数>
#pragma region FacePrimitives

FacePrimitive::FacePrimitive()
{
	_position = { 0.0f, 0.0f, 0.0f };
	_vertices = new osg::Vec3Array(3);
	_color = new osg::Vec4Array(1);
	_geometry = new osg::Geometry;
	_geometry->setDataVariance(osg::Object::DYNAMIC);
	_geometry->setUseDisplayList(false);
	_geometry->setUseVertexBufferObjects(true);
	_geometry->setVertexArray(_vertices);
	_geometry->setColorArray(_color);
	_geometry->setColorBinding(osg::Geometry::BIND_OVERALL);
	_geometry->addPrimitiveSet(new osg::DrawArrays(GL_TRIANGLES, 0, 3));    //  <由于画的是三角面，所以参数是三角形，三个顶点>

	auto stateSet = _geometry->getOrCreateStateSet();
	stateSet->setMode(GL_LIGHTING, osg::StateAttribute::OFF);   //  <设置高亮>
}

#pragma endregion

#pragma region SetPosition

void FacePrimitive::setPosition(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3)
{
	(*_vertices)[0] = osg::Vec3{ x1, y1, z1 };
	(*_vertices)[1] = osg::Vec3{ x2, y2, z2 };
	(*_vertices)[2] = osg::Vec3{ x3, y3, z3 };
	_vertices->dirty();													// <刷新功能，刷新顶点位置>
	_geometry->dirtyBound();									// <_geometry 刷新>
}

void FacePrimitive::setPosition(osg::Vec3 vertices1, osg::Vec3 vertices2, osg::Vec3 vertices3)
{
	(*_vertices)[0] = vertices1;
	(*_vertices)[1] = vertices2;
	(*_vertices)[2] = vertices3;
	_vertices->dirty();
	_geometry->dirtyBound();
}

void FacePrimitive::setVertices(const VertexArray& arr)
{
	_vertices = new osg::Vec3Array(arr.size());
	for (int i = 0; i < arr.size(); i++)
	{
		(*_vertices)[i].set(arr[i].getX(), arr[i].getY(), arr[i].getZ());
	}
}

#pragma endregion

#pragma region GetPosition

void FacePrimitive::getPosition(osg::Vec3 &vertices1, osg::Vec3 &vertices2, osg::Vec3 &vertices3)
{
	vertices1 = (*_vertices)[0];
	vertices2 = (*_vertices)[1];
	vertices3 = (*_vertices)[2];
}

void FacePrimitive::getPosition(float& x1, float& y1, float& z1, float& x2, float& y2, float& z2, float& x3, float& y3, float& z3)
{
	x1 = (*_vertices)[0].x();
	y1 = (*_vertices)[0].y();
	z1 = (*_vertices)[0].z();
	x2 = (*_vertices)[1].x();
	y2 = (*_vertices)[1].y();
	z2 = (*_vertices)[1].z();
	x3 = (*_vertices)[2].x();
	y3 = (*_vertices)[2].y();
	z3 = (*_vertices)[2].z();
}

VertexArray FacePrimitive::getVertices() const
{
	VertexArray arr(_vertices->size());
	for (int i = 0; i < _vertices->size(); i++)
	{
		std::vector<float> vf;
		vf.push_back((*_vertices)[i].x());
		vf.push_back((*_vertices)[i].y());
		vf.push_back((*_vertices)[i].z());
		arr[i].setVertices(vf);
		(*_vertices)[i].set(arr[i].getX(), arr[i].getY(), arr[i].getZ());  // <获取_vertices 中的内容>
	}
	return arr;
}

#pragma endregion

#pragma region SetColor

void FacePrimitive::setColor(float red, float green, float blue)
{
	osg::Vec4 color = { red, green, blue, 1.0f };   // <透明度默认为1，否则会被覆盖掉>
	(*_color)[0] = color;
	_color->dirty();
	_geometry->dirtyBound();
}

#pragma endregion

#pragma region GetGeometry

osg::Geometry* FacePrimitive::getGeometry()
{
	return _geometry;
}

#pragma endregion









