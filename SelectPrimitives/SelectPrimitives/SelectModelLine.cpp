// SelectModelLine.cpp : 定义控制台应用程序的入口点。
//

#include "SelectModelLine.h"
#include "LinePrimitives.h"


// <创建线>
osg::Geode* SelectModelLine::createSelector()
{
	LinePrimitives *line = new LinePrimitives;
	line->setColor(selectedColor._v[0], selectedColor._v[1], selectedColor._v[2]);
	_selector =  line->getGeometry();

	osg::ref_ptr<osg::Geode> geode = new osg::Geode;
	geode->addDrawable(_selector.get());

	return geode.release();
}

// <根据给定的二维坐标来画线>
bool SelectModelLine::drawbyCoordinate(float x, float y, osg::Camera* camera)
{
	if (camera)
	{
		osg::ref_ptr<osgUtil::LineSegmentIntersector> intersector =
			new osgUtil::LineSegmentIntersector(osgUtil::Intersector::WINDOW, x, y);
		osgUtil::IntersectionVisitor iv(intersector.get());
		camera->accept(iv);

		if (intersector->containsIntersections())
		{
			osgUtil::LineSegmentIntersector::Intersection result = *(intersector->getIntersections().begin());
			doUserOperations(result);
		}
	}
	return true;
}

// <通过相交算法运算后返回的结果，来确定点的位置，并通过矩阵把二维的坐标转换为三维的，为要画的图形确定顶点坐标>
void SelectModelLine::doUserOperations(osgUtil::LineSegmentIntersector::Intersection& result)
{
	osg::Geometry* geom = dynamic_cast<osg::Geometry*>(result.drawable.get());
	if (!geom || !_selector || geom == _selector) return;

	osg::Vec3Array* vertices = dynamic_cast<osg::Vec3Array*>(geom->getVertexArray());
	osg::Vec3Array* selVertices = dynamic_cast<osg::Vec3Array*>(_selector->getVertexArray());
	if (!vertices || !selVertices) return;

	osg::Vec3 point = result.getWorldIntersectPoint();
	osg::Matrix matrix = osg::computeLocalToWorld(result.nodePath);
	osg::Matrix vpMatrix;

	if (_camera.valid())
	{
		vpMatrix = _camera->getViewMatrix() * _camera->getProjectionMatrix();
		point = point * vpMatrix;
	}

	const std::vector<unsigned int>& selIndices = result.indexList;
	if (selIndices.size() >= 3)
	{
		auto a = (*vertices)[selIndices[0]];// * matrix
		auto b = (*vertices)[selIndices[1]];// * matrix
		auto c = (*vertices)[selIndices[2]];// * matrix
		auto inverseMat = osg::Matrix::inverse(vpMatrix)*osg::Matrix::inverse(matrix);
		//auto inP = point*inverseMat;
		float d_ab = (a - point*inverseMat).length() + (b - point*inverseMat).length() - (a - b).length();
		float d_ac = (a - point*inverseMat).length() + (c - point*inverseMat).length() - (a - c).length();
		float d_bc = (b - point*inverseMat).length() + (c - point*inverseMat).length() - (b - c).length();

		if (d_ab <= d_ac&&d_ab <= d_bc && d_ab<0.01)
		{
			// ab
			(*selVertices)[0] = a * matrix;
			(*selVertices)[1] = b * matrix;
		}
		else if (d_ac <= d_ab&&d_ac <= d_bc && d_ac<0.01)
		{
			//ac
			(*selVertices)[0] = a * matrix;
			(*selVertices)[1] = c * matrix;
		}
		else if (d_bc <= d_ab&&d_bc <= d_ac && d_bc<0.01)
		{
			//bc
			(*selVertices)[0] = b * matrix;
			(*selVertices)[1] = c * matrix;
		}
	}
	else
	{
		//assert(false);
	}
	_startPosition = (*selVertices)[0];
	_endPosition = (*selVertices)[1];
	selVertices->dirty();
	_selector->dirtyBound();
}

void SelectModelLine::getPosition(float &x1, float &y1, float &z1, float &x2, float &y2, float &z2)
{
	x1 = _startPosition._v[0];
	y1 = _startPosition._v[1];
	z1 = _startPosition._v[2];
	x2 = _endPosition._v[0];
	y2 = _endPosition._v[1];
	z2 = _endPosition._v[2];
}








