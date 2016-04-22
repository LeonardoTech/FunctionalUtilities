#include "ArcPrimitive.h"
using namespace YZ;


//默认值圆心(0,0,0)，起始点(1,0,0)，终止点(0,1,0)，法向量(0,0,1)
ArcPrimitive::ArcPrimitive()
{
	m_center = { 0.0, 0.0, 0.0 };
	m_start = { 1.0, 0.0, 0.0 };
	m_end = { 0.0, 1.0, 0.0 };
	m_normal = { 0.0, 0.0,1.0 };
	v_center.set(0.0, 0.0, 0.0);
	v_normal.set(0.0, 0.0, 1.0);
	m_centerArray = new osg::Vec3Array;
	m_normalArray = new osg::Vec3Array;
	m_startArray = new osg::Vec3Array;
	m_endArray = new osg::Vec3Array;
	m_centerArray->push_back(m_center);
	m_normalArray->push_back(m_normal);
	m_startArray->push_back(m_start);
	m_endArray->push_back(m_end);

 }

ArcPrimitive::ArcPrimitive(const Vertex& center, const Vertex& start, const Vertex& end, const Vertex& normal)
	:ArcPrimitive::ArcPrimitive()
{
	m_center.x() = center.x();
	m_center.y() = center.y();
	m_center.z() = center.z();
	m_start.x() = start.x();
	m_start.y() = start.y();
	m_start.z() = start.z();
	m_end.x() = end.x();
	m_end.y() = end.y();
	m_end.z() = end.z();
	m_normal.x() = normal.x();
	m_normal.y() = normal.y();
	m_normal.z() = normal.z();
	
	v_center = center;
	v_normal = normal;
	(*m_startArray)[0] = m_start;
	m_startArray->dirty();
	(*m_endArray)[0] = m_end;
	m_endArray->dirty();
	(*m_centerArray)[0] = m_center;
	m_centerArray->dirty();
	(*m_normalArray)[0] = m_normal;
	m_normalArray->dirty();
}




void ArcPrimitive::setCenter(float dx, float dy, float dz)
{
	v_center.set(dx, dy, dz);
	m_center.set(dx, dy, dz);
	(*m_centerArray)[0] = m_center;
	m_centerArray->dirty();
}

void ArcPrimitive::setCenter(const Vertex& center)
{
	m_center.x() = center.x();
	m_center.y() = center.y();
	m_center.z() = center.z();
	v_center = center;
	(*m_centerArray)[0] = m_center;
	m_centerArray->dirty();
}


void ArcPrimitive::setCenter(osg::Vec3 center)
{
	m_center = center;
	(*m_centerArray)[0] = m_center;
	m_centerArray->dirty();
}

void ArcPrimitive::setStart(osg::Vec3 start)
{
	m_start = start;
}

void ArcPrimitive::setEnd(osg::Vec3 end)
{
	m_end = end;
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
	v_normal.set(dx, dy, dz);
	m_normal.set(dx, dy, dz);
	(*m_normalArray)[0] = m_normal;
	m_normalArray->dirty();
}

void ArcPrimitive::setNormal(const Vertex& normal)
{
	v_normal = normal;
	m_normal.x() = normal.x();
	m_normal.y() = normal.y();
	m_normal.z() = normal.z();
	(*m_normalArray)[0] = m_normal;
	m_normalArray->dirty();
}

void ArcPrimitive::setNormal(osg::Vec3 normal)
{
	m_normal = normal;
	(*m_normalArray)[0] = m_normal;
	m_normalArray->dirty();
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
		Plist[i].x() = (NowP.x() - (*m_centerArray)[0].x())*((*m_normalArray)[0].x()*(*m_normalArray)[0].x() + (1 - (*m_normalArray)[0].x()*(*m_normalArray)[0].x())*Cos)
			+ (NowP.y() - (*m_centerArray)[0].y())*((*m_normalArray)[0].x()*(*m_normalArray)[0].y()*(1 - Cos) + (*m_normalArray)[0].z()*Sin)
			+ (NowP.z() - (*m_centerArray)[0].z())*((*m_normalArray)[0].x()*(*m_normalArray)[0].z()*(1 - Cos) - (*m_normalArray)[0].y()*Sin) + (*m_centerArray)[0].x();
		Plist[i].y() = (NowP.x() - (*m_centerArray)[0].x())*((*m_normalArray)[0].x()*(*m_normalArray)[0].y()*(1 - Cos) - (*m_normalArray)[0].z()*Sin)
			+ (NowP.y() - (*m_centerArray)[0].y())*((*m_normalArray)[0].y()*(*m_normalArray)[0].y() + (1 - (*m_normalArray)[0].y()*(*m_normalArray)[0].y())*Cos)
			+ (NowP.z() - (*m_centerArray)[0].z())*((*m_normalArray)[0].y()*(*m_normalArray)[0].z()*(1 - Cos) + (*m_normalArray)[0].x()*Sin) + (*m_centerArray)[0].y();
		Plist[i].z() = (NowP.x() - (*m_centerArray)[0].x())*((*m_normalArray)[0].x()*(*m_normalArray)[0].z()*(1 - Cos) + (*m_normalArray)[0].y()*Sin)
			+ (NowP.y() - (*m_centerArray)[0].y())*((*m_normalArray)[0].y()*(*m_normalArray)[0].z()*(1 - Cos) - (*m_normalArray)[0].x()*Sin)
			+ (NowP.z() - (*m_centerArray)[0].z())*((*m_normalArray)[0].z()*(*m_normalArray)[0].z() + (1 - (*m_normalArray)[0].z()*(*m_normalArray)[0].z())*Cos) + (*m_centerArray)[0].z();

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
	(*m_startArray)[0] = m_start;
	m_startArray->dirty();
}

void ArcPrimitive::setEnd(float dx, float dy, float dz)
{
	m_end.set(dx, dy, dz);
	(*m_endArray)[0] = m_end;
	m_endArray->dirty();
}

