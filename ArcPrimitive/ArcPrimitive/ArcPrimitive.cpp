#include "ArcPrimitive.h"
using namespace geo;


//默认值圆心(0,0,0)，起始点(1,0,0)，终止点(0,1,0)，法向量(0,0,1)
ArcPrimitive::ArcPrimitive()
{
	m_center = { 0.0, 0.0, 0.0 };
	m_start = { 1.0, 0.0, 0.0 };
	m_end = { 0.0, 1.0, 0.0 };
	m_normal = { 0.0, 0.0,1.0 };
	v_center.set(0.0, 0.0, 0.0);
	v_normal.set(0.0, 0.0, 1.0);
	v_start.set(0.0, 0.0, 0.0);
	v_end.set(0.0, 0.0, 0.0);

 }

ArcPrimitive::ArcPrimitive(const Vertex& center, const Vertex& start, const Vertex& end, const Vertex& normal)
	:ArcPrimitive::ArcPrimitive()
{
	m_center = { center.getX(), center.getY(), (float)center.getZ() };
	m_start = { start.getX(), start.getY(), start.getZ() };
	m_end = { end.getX(), end.getY(), end.getZ() };
	m_normal = { normal.getX(), normal.getY(), normal.getZ() };
	
	v_center = center;
	v_normal = normal;
	this->dirtyBound();
}


void ArcPrimitive::setCenter(float dx, float dy, float dz)
{
	v_center.set(dx, dy, dz);
	m_center.set(dx, dy, dz);
	this->dirtyBound();
}

void ArcPrimitive::setCenter(const Vertex& center)
{
	m_center = { center.getX(), center.getY(), (float)center.getZ() };
	v_center = center;
	this->dirtyBound();
}


void ArcPrimitive::setCenter(osg::Vec3 center)
{
	m_center = center;
	this->dirtyBound();
}

void ArcPrimitive::setStart(osg::Vec3 start)
{
	m_start = start;
	this->dirtyBound();
}

void ArcPrimitive::setEnd(osg::Vec3 end)
{
	m_end = end;
	this->dirtyBound();

}

const osg::Vec3& ArcPrimitive::getCenter() const
{
	return m_center;
}
 
const osg::Vec3& ArcPrimitive::getNormal() const 
{
	return m_normal;
}

void ArcPrimitive::setNormal(float dx, float dy, float dz)
{
	m_normal.set(dx, dy, dz);
	this->dirtyBound();
}

void ArcPrimitive::setNormal(const Vertex& normal)
{
	m_normal = { normal.getX(), normal.getY(), normal.getZ() };
	this->dirtyBound();
}

void ArcPrimitive::setNormal(osg::Vec3 normal)
{
	m_normal = normal;
	this->dirtyBound();
}

const Vertex& ArcPrimitive::getCenter(void) 
{
	v_center.set(m_center.x(), m_center.y(), m_center.z());
	return v_center;
}

const Vertex& ArcPrimitive::getNormal(void) 
{
	v_normal.set(m_normal.x(), m_normal.y(), m_normal.z());
	return v_normal;
}

float Distance(float x1, float y1, float z1, float x2, float y2, float z2)
{
	return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) + (z1 - z2)*(z1 - z2));
}

void ArcPrimitive::drawImplementation(osg::RenderInfo& renderInfo)const
{
	const int Num = 360;
	int Ra;
	//<圆弧点集>
	osg::Vec3 Plist[Num];
	float  Dis = 999999;
	osg::Vec3 NowP = m_start;
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

		if (Distance(Plist[i].x(), Plist[i].y(), Plist[i].z(), NowP.x(), NowP.y(), NowP.z()) < Dis)
		{
			Ra = i;
			Dis = Distance(Plist[i].x(), Plist[i].y(), Plist[i].z(), m_end.x(), m_end.y(), m_end.z());
		}
		NowP = Plist[i];
	}
	Plist[0] = m_start;
	Plist[Ra] = m_end;
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, Plist);
	glDrawArrays(GL_LINE_STRIP, 0, Ra+1);
	glEnableClientState(GL_VERTEX_ARRAY);
}

void ArcPrimitive::setStart(float dx, float dy, float dz)
{
	m_start.set(dx, dy, dz);
	this->dirtyBound();
}

void ArcPrimitive::setStart(const Vertex& start)
{
	m_start = { start.getX(), start.getY(), start.getZ() };
	getVector();
}

void ArcPrimitive::setEnd(float dx, float dy, float dz)
{
	m_end.set(dx, dy, dz);
	this->dirtyBound();
}

void ArcPrimitive::setEnd(const Vertex& end)
{
	m_end = { end.getX(), end.getY(), end.getZ() };
	getVector();
}


Vertex& ArcPrimitive::getStart()
{
	v_start.set(m_start.x(), m_start.y(), m_start.z());
	return v_start;
}

Vertex& ArcPrimitive::getEnd()
{
	v_end.set(m_end.x(), m_end.y(), m_end.z());
	return v_end;
}