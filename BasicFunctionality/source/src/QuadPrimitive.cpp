#include "QuadPrimitive.h"

#include <osg/Geometry>

QuadPrimitive::QuadPrimitive()
{

	m_vertexArray = new osg::Vec3Array(4);
	_colors = new osg::Vec4Array(1);

	m_center = { 0.0f, 0.0f, 0.0f };
	m_localX = { 0.0f, 0.0f, 0.0f };
	m_localX = { 0.0f, 0.0f, 0.0f };
	m_unitLength = { 0.0f, 0.0f };
	m_height = 0.0f;
	m_width = 0.0f;

	osg::Vec2Array* texcoords = new osg::Vec2Array(4);
	(*texcoords)[0].set(0.0f, 0.0f);
	(*texcoords)[1].set(1.0f, 0.0f);
	(*texcoords)[2].set(1.0f, 1.0f);
	(*texcoords)[3].set(0.0f, 1.0f);

	osg::Vec3Array * normalArray = new osg::Vec3Array;
	normalArray->push_back(osg::Vec3(0, 1, 0));

	 _geometry = new osg::Geometry();
	_geometry->setUseVertexBufferObjects(true);
	_geometry->setVertexArray(m_vertexArray);
	_geometry->setColorArray(_colors);
	_geometry->setColorBinding(osg::Geometry::BIND_OVERALL);
	_geometry->setNormalArray(normalArray, osg::Array::BIND_PER_PRIMITIVE_SET);
	_geometry->setTexCoordArray(0, texcoords, osg::Array::BIND_PER_VERTEX);
	_geometry->addPrimitiveSet(new osg::DrawArrays(GL_QUADS, 0, 4));

}



void QuadPrimitive::setVertices(Vertex vet1, Vertex vet2, Vertex vet3, Vertex vet4)
{
	osg::Vec3 vertex1 = { vet1.getX(), vet1.getY(), vet1.getZ() };
	(*m_vertexArray)[0] = vertex1;

	osg::Vec3 vertex2 = { vet2.getX(), vet2.getY(), vet2.getZ() };
	(*m_vertexArray)[1] = vertex2;

	osg::Vec3 vertex3 = { vet3.getX(), vet3.getY(), vet3.getZ() };
	(*m_vertexArray)[2] = vertex3;

	osg::Vec3 vertex4 = { vet4.getX(), vet4.getY(), vet4.getZ() };
	(*m_vertexArray)[3] = vertex4;

	m_vertexArray->dirty();
	_geometry->dirtyBound();
}

void QuadPrimitive::getVertices(Vertex& vet1, Vertex& vet2, Vertex& vet3, Vertex& vet4)
{
	vet1.set((*m_vertexArray)[0].x(), (*m_vertexArray)[0].y(), (*m_vertexArray)[0].z());
	vet2.set((*m_vertexArray)[1].x(), (*m_vertexArray)[1].y(), (*m_vertexArray)[1].z());
	vet3.set((*m_vertexArray)[2].x(), (*m_vertexArray)[2].y(), (*m_vertexArray)[2].z());
	vet4.set((*m_vertexArray)[3].x(), (*m_vertexArray)[3].y(), (*m_vertexArray)[3].z());
}

// <length是宽高，先宽后高>
//QuadPrimitive::QuadPrimitive(const osg::Vec3& center, const osg::Vec2& length, const osg::Vec3& localX, const osg::Vec3& localY):
//QuadPrimitive::QuadPrimitive()
void QuadPrimitive::createQuad(const osg::Vec3& center, const osg::Vec2& length, const osg::Vec3& localX, const osg::Vec3& localY)
{
	m_center = center;
	m_width = length.x();
	m_height = length.y();
	m_unitLength = length / 2.0f;
	m_localX = localX;
	m_localY = localY;


	(*m_vertexArray)[0].set(center - localX * m_unitLength.x() - localY * m_unitLength.y());
	(*m_vertexArray)[1].set(center + localX * m_unitLength.x() - localY * m_unitLength.y());
	(*m_vertexArray)[2].set(center + localX * m_unitLength.x() + localY * m_unitLength.y());
	(*m_vertexArray)[3].set(center - localX * m_unitLength.x() + localY * m_unitLength.y());

	m_vertexArray->dirty();
	_geometry->dirtyBound();

}

void QuadPrimitive::setHeight(float height)
{
	m_height = height;
	createQuad(m_center, osg::Vec2{ m_width, m_height }, m_localX, m_localY);
}

void QuadPrimitive::setWidth(float width)
{
	m_width = width;
	createQuad(m_center, osg::Vec2{ m_width, m_height }, m_localX, m_localY);
}


void QuadPrimitive::setColor(float red, float green, float blue)
{
	osg::Vec4 color = { red, green, blue, 1.0f };
	(*_colors)[0] = color;
	_colors->dirty();
}


osg::Geometry* QuadPrimitive::getGeometry()
{
	return _geometry;
}

void QuadPrimitive::setVertices(const VertexArray& arr)
{
	osg::Vec3 vec = { 0.0f, 0.0f, 0.0f };
	int i = 0;
	for ( i = 0; i < arr.size(); i++)
	{
		(*m_vertexArray)[i].set(arr[i].getX(),arr[i].getY(),arr[i].getZ());
		vec += {arr[i].getX(), arr[i].getY(), arr[i].getZ()};
	}
	m_center = vec / 4.0;
	m_height = ((*m_vertexArray)[1] - (*m_vertexArray)[0]).length();
	m_width = ((*m_vertexArray)[2] - (*m_vertexArray)[1]).length();

	m_vertexArray->dirty();
	_geometry->dirtyBound();
}



VertexArray QuadPrimitive::getVertices() const
{
	VertexArray arr(m_vertexArray->size());
	for (int i = 0; i < m_vertexArray->size(); i++)
	{
		std::vector<float> vf;
		vf.push_back((*m_vertexArray)[i].x());
		vf.push_back((*m_vertexArray)[i].y());
		vf.push_back((*m_vertexArray)[i].z());
		arr[i].setVertices(vf);
		(*m_vertexArray)[i].set(arr[i].getX(), arr[i].getY(), arr[i].getZ());
	}
	return arr;
}



