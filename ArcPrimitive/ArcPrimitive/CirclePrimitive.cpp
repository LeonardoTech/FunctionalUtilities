#include "CirclePrimitive.h"
#include <osg/Drawable>

using namespace geo;

CirclePrimitive::CirclePrimitive()
{
	m_center = { 0.0, 0.0, 0.0 };
	m_normal = { 0, -1, 0 };
	m_face = { 0.0, 0.0, 0.0 };
	m_vertex = { 0.0, 0.0, 0.0 };
	m_radius = 1.0;
	v_normal.set(m_normal.x(), m_normal.y(), m_normal.z());
	v_center.set(m_center.x(), m_center.y(), m_center.z());
	getVertex();
}

CirclePrimitive::CirclePrimitive(Vertex& center, Vertex normal, float radius)
	:CirclePrimitive::CirclePrimitive()
{
	m_center.set(center.getX(), center.getY(), center.getZ());
	m_normal.set(normal.getX(), normal.getY(), normal.getZ());
	m_radius = radius;
	v_normal.set(m_normal.x(), m_normal.y(), m_normal.z());
	v_center.set(m_center.x(), m_center.y(), m_center.z());
	getVertex();
}

void CirclePrimitive::getVertex()
{
	m_normal.normalize();
	if ((m_normal == osg::Vec3{ 1.0, 0.0, 0.0 }) || (m_normal == osg::Vec3{ -1.0, 0.0, 0.0 }) || (m_normal == osg::Vec3{ 0.0, 1.0, 0.0 }) || (m_normal == osg::Vec3{ 0.0, -1.0, 0.0 }))
	{
		m_face = osg::Vec3{ 0.0, 0.0, 1.0 };
	}
	else if ((m_normal == osg::Vec3{ 0.0, 0.0, 1.0 }) || (m_normal == osg::Vec3(0.0, 0.0, -1.0)))
	{
		m_face = osg::Vec3{ 1.0, 0.0, 0.0 };
	}
	else
	{
		m_face.x() = (m_normal.y())*(m_normal.z());
		m_face.y() = (m_normal.x())*(m_normal.z());
		m_face.z() = -2 * (m_normal.x())*(m_normal.y());
		m_face.normalize();
	}
	m_vertex.x() = m_center.x() + m_radius*m_face.x();
	m_vertex.y() = m_center.y() + m_radius*m_face.y();
	m_vertex.z() = m_center.z() + m_radius*m_face.z();

	this->dirtyBound();
}


void CirclePrimitive::drawImplementation(osg::RenderInfo& RenderInfo) const
{
	const float PI = 3.1415926;

	const int Num = 60;
	//<Ô²»¡µã¼¯>
	osg::Vec3 Plist[Num];
	float  Dis = 999999;
	osg::Vec3 NowP = m_vertex;
	Plist[0] = m_vertex;
	for (int i = 1; i < Num; i++)
	{
		float Cos, Sin;
		Cos = cos(2 * PI / Num);
		Sin = sin(2 * PI / Num);

		Plist[i].x() = (NowP.x() - m_center.x())*(m_normal.x()*m_normal.x() + (1 - m_normal.x()*m_normal.x())*Cos)
			+ (NowP.y() - m_center.y())*(m_normal.x()*m_normal.y()*(1 - Cos) + m_normal.z()*Sin)
			+ (NowP.z() - m_center.z())*(m_normal.x()*m_normal.z()*(1 - Cos) - m_normal.y()*Sin) + m_center.x();
		Plist[i].y() = (NowP.x() - m_center.x())*(m_normal.x()*m_normal.y()*(1 - Cos) - m_normal.z()*Sin)
			+ (NowP.y() - m_center.y())*(m_normal.y()*m_normal.y() + (1 - m_normal.y()*m_normal.y())*Cos)
			+ (NowP.z() - m_center.z())*(m_normal.y()*m_normal.z()*(1 - Cos) + m_normal.x()*Sin) + m_center.y();
		Plist[i].z() = (NowP.x() - m_center.x())*(m_normal.x()*m_normal.z()*(1 - Cos) + m_normal.y()*Sin)
			+ (NowP.y() - m_center.y())*(m_normal.y()*m_normal.z()*(1 - Cos) - m_normal.x()*Sin)
			+ (NowP.z() - m_center.z())*(m_normal.z()*m_normal.z() + (1 - m_normal.z()*m_normal.z())*Cos) + m_center.z();

		NowP = Plist[i];
	}
	glPointSize(3.0f);
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, Plist);
	glDrawArrays(GL_LINE_LOOP, 0, Num);
	glEnableClientState(GL_VERTEX_ARRAY);
}


void CirclePrimitive::setCenter(float dx, float dy, float dz)
{
	m_center.set(dx, dy, dz);
	getVertex();
}

void CirclePrimitive::setCenter(osg::Vec3 center)
{
	m_center = center;
	getVertex();
}

void CirclePrimitive::setNormal(osg::Vec3 normal)
{
	m_normal = normal;

	getVertex();
}

osg::Vec3& CirclePrimitive::getCenter()
{
	return m_center;
}

osg::Vec3& CirclePrimitive::getNormal()
{
	return m_normal;
}

void CirclePrimitive::setCenter(Vertex center)
{
	m_center.set(center.getX(), center.getY(), center.getZ());
	v_center = center;	
	getVertex();
}

void CirclePrimitive::setNormal(float dx, float dy, float dz)
{
	m_normal.set(dx, dy, dz);
	v_normal.set(dx, dy, dz);

	getVertex();
}

void CirclePrimitive::setNormal(Vertex normal)
{
	m_normal.set(normal.getX(), normal.getY(), normal.getZ());		

	getVertex();
}

  
const Vertex& CirclePrimitive::getCenter() const
{
	return v_center;
}

const Vertex& CirclePrimitive::getNormal() const
{
	return v_normal;
}


void CirclePrimitive::setRadius(float radius)
{
	m_radius = radius;
	getVertex();
}
