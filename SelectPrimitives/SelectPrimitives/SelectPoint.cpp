#include "SelectPoint.h"

SelectPoint::SelectPoint(osg::Camera* camera)
{
	m_point = new PointPrimitive();
	m_point->setColor(1, 0, 0);
	m_point->setSize(10);
	m_camera = camera;
}

IDrawElement* SelectPoint::select(float x, float y)
{
	return selectPoint(x, y);
}

// <通过相交算法运算后返回的结果，来确定点的位置，并通过矩阵把二维的坐标转换为三维的，为要画的图形确定顶点坐标>
void SelectPoint::doUserOperations(osgUtil::LineSegmentIntersector::Intersection& result)
{
	osg::Geometry* geom = dynamic_cast<osg::Geometry*>(result.drawable.get());
	if (!geom ) return;// || !_selector || geom == _selector

	osg::Vec3Array* vertices = dynamic_cast<osg::Vec3Array*>(geom->getVertexArray());
	//osg::Vec3Array* selVertices = dynamic_cast<osg::Vec3Array*>(_selector->getVertexArray());
	if (!vertices) return;// || !selVertices

	osg::Vec3 point = result.getWorldIntersectPoint();
	osg::Matrix matrix = osg::computeLocalToWorld(result.nodePath);
	osg::Matrix vpMatrix;

	if (m_camera)
	{
		vpMatrix = m_camera->getViewMatrix() * m_camera->getProjectionMatrix();
		point = point * vpMatrix;
	}

	const std::vector<unsigned int>& selIndices = result.indexList;
	osg::Vec3 position;
	if (selIndices.size() >= 3)
	{
		auto inverseMat = osg::Matrix::inverse(vpMatrix)*osg::Matrix::inverse(matrix);
		position = point*inverseMat * matrix;
		//(*selVertices)[0] = _position; // <获取当前的三维坐标>
	}
	else
	{
		//assert(false);
	}
	m_point->setPosition(position);
	//selVertices->dirty();
	//_selector->dirtyBound();
}

PointPrimitive* SelectPoint::selectPoint(float x, float y)
{
	osg::ref_ptr<osgUtil::LineSegmentIntersector> intersector = new osgUtil::LineSegmentIntersector(osgUtil::Intersector::WINDOW, x, y);
	osgUtil::IntersectionVisitor iv(intersector.get());
	m_camera->accept(iv);

	if (intersector->containsIntersections())
	{
		osgUtil::LineSegmentIntersector::Intersection result = *(intersector->getIntersections().begin());
		doUserOperations(result);
	}
	return m_point;
}

PointPrimitive* SelectPoint::getSelectedPoint() const
{
	
	return m_point;
}

IDrawElement* SelectPoint::getSelection() const
{
	return getSelectedPoint();
}

osg::Node* SelectPoint::getRoot() const
{
	return m_point->getGeometry();
}

void SelectPoint::setPointPosition(const osg::Vec3& pos)
{
	m_point->setPosition(pos);
}
