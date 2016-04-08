#include "QuadPrimitive.h"
#include <iostream>
#include <osg/Geometry>
#include <osg/Geode>
#include <osg/Node>
#include <osg/LineWidth>
#include "QuadPrimitiveImp.h"
#include <osg/ValueObject >
	

QuadPrimitive::QuadPrimitive()
{
	_outLine = new osg::Geometry();
	_root = new osg::Geode;
	m_vertexArray = new osg::Vec3Array(4);
	_quadColors = new osg::Vec4Array(1);
	_frameColors = new osg::Vec4Array(1);		// <指定颜色，连成一条线的两个点需要用相同的颜色>

	m_center = { 0.0f, 0.0f, 0.0f };
	m_localX = { 0.0f, 0.0f, 0.0f };
	m_localX = { 0.0f, 0.0f, 0.0f };
	m_unitLength = { 0.0f, 0.0f };
	m_height = 0.0f;
	m_width = 0.0f;

	_texcoords = new osg::Vec2Array(4);
	(*_texcoords)[0].set(0.0f, 0.0f);
	(*_texcoords)[1].set(1.0f, 0.0f);
	(*_texcoords)[2].set(1.0f, 1.0f);
	(*_texcoords)[3].set(0.0f, 1.0f);

	_normalsArray = new osg::Vec3Array;
	_normalsArray->push_back(osg::Vec3(0, 1, 0));

	 _geometry = new osg::Geometry();
	_geometry->setUseVertexBufferObjects(true);
	_geometry->setVertexArray(m_vertexArray);
	_geometry->setColorArray(_quadColors);
	_geometry->setColorBinding(osg::Geometry::BIND_OVERALL);
	_geometry->setNormalArray(_normalsArray, osg::Array::BIND_PER_PRIMITIVE_SET);
	_geometry->setTexCoordArray(0, _texcoords, osg::Array::BIND_PER_VERTEX);
	_geometry->addPrimitiveSet(new osg::DrawArrays(GL_QUADS, 0, 4));

	_root->addDrawable(_geometry);


	//_geometry->setUserValue("m_center", m_center);
	//_geometry->setUserValue("m_width", m_width);
	//_geometry->setUserValue("m_height", m_height);
	//_geometry->setUserValue("m_localX", m_localX);
	//_geometry->setUserValue("m_localY", m_localY);
	//_geometry->setUserValue("_primitive_type", "QuadPrimitive");
	//_geometry->setUserValue("id", "QuadPrimitive");
}



void QuadPrimitive::setVertices(Vertex vet1, Vertex vet2, Vertex vet3, Vertex vet4)
{
	osg::Vec3 vecX = { 0.0f, 0.0f, 0.0f };
	osg::Vec3 vecY = { 0.0f, 0.0f, 0.0f };

	osg::Vec3 vertex1 = { vet1.getX(), vet1.getY(), vet1.getZ() };
	(*m_vertexArray)[0] = vertex1;

	osg::Vec3 vertex2 = { vet2.getX(), vet2.getY(), vet2.getZ() };
	(*m_vertexArray)[1] = vertex2;

	osg::Vec3 vertex3 = { vet3.getX(), vet3.getY(), vet3.getZ() };
	(*m_vertexArray)[2] = vertex3;

	osg::Vec3 vertex4 = { vet4.getX(), vet4.getY(), vet4.getZ() };
	(*m_vertexArray)[3] = vertex4;

	m_center = (vertex1 + vertex1 + vertex1 + vertex1) / 4.0;
	
	vecY = ((*m_vertexArray)[1] - (*m_vertexArray)[0]);
	m_height = vecY.length();
	vecY.normalize();
	m_localY = vecY;
	vecX = (*m_vertexArray)[2] - (*m_vertexArray)[1];
	m_width = vecX.length();
	vecX.normalize();
	m_localX = vecX;

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

osg::Node* QuadPrimitive::getRoot()
{
	return _root;
}

void QuadPrimitive::setNeedDrawOutLine(bool draw)
{
	if (draw == true)
	{
		this->initOutLine();
		_root->addDrawable(_outLine);
	}
}

void QuadPrimitive::initOutLine()
{
	_outLine->setUseVertexBufferObjects(true);
	_outLine->setVertexArray(m_vertexArray);
	_outLine->setColorArray(_frameColors.get(), osg::Array::BIND_PER_PRIMITIVE_SET);
	_outLine->setNormalArray(_normalsArray, osg::Array::BIND_PER_PRIMITIVE_SET);
	_outLine->setTexCoordArray(0, _texcoords, osg::Array::BIND_PER_VERTEX);
	_outLine->addPrimitiveSet(new osg::DrawArrays(GL_LINE_LOOP, 0, 4));
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
	setFrameColor(red, green, blue);
	setQuadColor(red, green, blue);
}


osg::Geometry* QuadPrimitive::getQuadGeometry()
{
	return _geometry;
}

osg::Geometry* QuadPrimitive::getFrameGeometry()
{
	return _outLine;
}

void QuadPrimitive::setVertices(const VertexArray& arr)
{

	int i = 0;
	for ( i = 0; i < arr.size(); i++)
	{
		(*m_vertexArray)[i].set(arr[i].getX(),arr[i].getY(),arr[i].getZ());
	}
	this->setVertices(arr[0], arr[1], arr[2], arr[3]);






	//m_center = vec / 4.0;
	//vecY = ((*m_vertexArray)[1] - (*m_vertexArray)[0]);
	//m_height =  vecY.length();
	//vecY.normalize(); 
	//m_localY = vecY;
	//vecX = (*m_vertexArray)[2] - (*m_vertexArray)[1];
	//m_width = vecX.length();
	//vecX.normalize();
	//m_localX = vecX;

	//m_vertexArray->dirty();
	//_geometry->dirtyBound();
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



void QuadPrimitive::setQuadColor(float red, float green, float blue)
{
	osg::Vec4 color = { red, green, blue, 1.0f };
	(*_quadColors)[0] = color;
	_quadColors->dirty();
}
void QuadPrimitive::setFrameColor(float red, float green, float blue)
{
	osg::Vec4 color = { red, green, blue, 1.0f };
	(*_frameColors)[0] = color;
	_frameColors->dirty();
}

void QuadPrimitive::setFrameWidth(float width)
{
	osg::ref_ptr <osg::LineWidth> lineWidth = new osg::LineWidth;
	lineWidth->setWidth(width);
	_outLine->getOrCreateStateSet()->setAttributeAndModes(lineWidth.get(), osg::StateAttribute::ON);
}


void  QuadPrimitive::setCenter(const osg::Vec3& center)
{
	m_center = center;
	createQuad(m_center, osg::Vec2{ m_width, m_height }, m_localX, m_localY);
}


void QuadPrimitive::getPosition(float& x, float& y, float& z)
{
	x = m_center.x();
	y = m_center.y();
	z = m_center.z();
}


void QuadPrimitive::setPosition(float x, float y, float z)
{
	osg::Vec3 vet{x,y,z};
	setCenter(vet);
}



IDrawElement* QuadPrimitive::create(osg::Geometry *geom)const
{
	//std::string type;
	//if (!geom->getUserValue("_primitive_type", type))
	//{
	//	return NULL;
	//}
	//if (type != "QuadPrimitive")
	//{
	//	return NULL;
	//}
	QuadPrimitive* quad = new QuadPrimitive();
	quad->_geometry = geom;
	quad->m_vertexArray = dynamic_cast<osg::Vec3Array*>(geom->getVertexArray());
	quad->_quadColors = dynamic_cast<osg::Vec4Array*>(geom->getColorArray());

	//geom->getUserValue("m_center", quad->m_center);
	//geom->getUserValue("m_width", quad->m_width);
	//geom->getUserValue("m_height", quad->m_height);
	//geom->getUserValue("m_localX", quad->m_localX);
	//geom->getUserValue("m_localY", quad->m_localY);
	return quad;
}
