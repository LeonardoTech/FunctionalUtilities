#include "SelectLine.h"

SelectLine::SelectLine(osg::Camera* camera)
{
	m_line = new LinePrimitives();
	m_line->setColor(1, 0, 0);
	m_line->setLineWidth(2);
	m_camera = camera;
	m_selected = false;
}

IDrawElement* SelectLine::select(float x, float y)
{
	return selectLine(x, y);
}


void SelectLine::doUserOperations(osgUtil::LineSegmentIntersector::Intersection& result)
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
	osg::Vec3 start, end;
	if (selIndices.size() >= 3)
	{
		auto a = (*vertices)[selIndices[0]];// * matrix
		auto b = (*vertices)[selIndices[1]];// * matrix
		auto c = (*vertices)[selIndices[2]];// * matrix
		auto inverseMat = osg::Matrix::inverse(vpMatrix)*osg::Matrix::inverse(matrix);
		//auto inP = point*inverseMat;
		//  <获取选择的点到任意两个顶点距离，再减去两个顶点的距离>
		float d_ab = (a - point*inverseMat).length() + (b - point*inverseMat).length() - (a - b).length(); 
		float d_ac = (a - point*inverseMat).length() + (c - point*inverseMat).length() - (a - c).length();
		float d_bc = (b - point*inverseMat).length() + (c - point*inverseMat).length() - (b - c).length();

		// <判断差值的大小,差值小说明已经选择的点离线很近>
		if (d_ab <= d_ac&&d_ab <= d_bc && d_ab<0.01)
		{
			// ab
			start = a * matrix;
			end = b * matrix;
		}
		else if (d_ac <= d_ab&&d_ac <= d_bc && d_ac<0.01)
		{
			//ac
			start = a * matrix;
			end = c * matrix;
		}
		else if (d_bc <= d_ab&&d_bc <= d_ac && d_bc<0.01)
		{
			//bc
			start = b * matrix;
			end = c * matrix;
		}
	}
	else
	{
		//assert(false);
	}
	m_line->setStartPosition(start);
	m_line->setEndPosition(end);
	//selVertices->dirty();
	//_selector->dirtyBound();
}

LinePrimitives* SelectLine::selectLine(float x, float y)
{
	osg::ref_ptr<osgUtil::LineSegmentIntersector> intersector =
		new osgUtil::LineSegmentIntersector(osgUtil::Intersector::WINDOW, x, y);
	osgUtil::IntersectionVisitor iv(intersector.get());
	m_camera->accept(iv);

	if (intersector->containsIntersections())
	{
		osgUtil::LineSegmentIntersector::Intersection result = *(intersector->getIntersections().begin());
		doUserOperations(result);
	}
	m_selected = true;
	return m_line;
}

LinePrimitives* SelectLine::getSelectedLine() const
{
	if (!m_selected)
	{
		return NULL;
	}
	return m_line;
}

IDrawElement* SelectLine::getSelection() const
{
	return getSelectedLine();
}

osg::Node* SelectLine::getRoot() const
{
	return m_line->getGeometry();
}
