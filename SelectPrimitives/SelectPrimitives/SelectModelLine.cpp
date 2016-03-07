// SelectModelLine.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "SelectModelLine.h"

osg::Geode* SelectModelLine::createSelector()
{
	osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array(1);
	(*colors)[0] = selectedColor;

	_selector = new osg::Geometry;
	_selector->setDataVariance(osg::Object::DYNAMIC);
	_selector->setUseDisplayList(false);
	_selector->setUseVertexBufferObjects(true);
	_selector->setVertexArray(new osg::Vec3Array(2));
	_selector->setColorArray(colors.get());
	_selector->setColorBinding(osg::Geometry::BIND_OVERALL);
	_selector->addPrimitiveSet(new osg::DrawArrays(GL_LINES, 0, 2));

	osg::ref_ptr<osg::Geode> geode = new osg::Geode;
	geode->addDrawable(_selector.get());
	geode->getOrCreateStateSet()->setAttributeAndModes(new osg::Point(10.0f));
	geode->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::OFF);
	geode->getOrCreateStateSet()->setMode(GL_BLEND, osg::StateAttribute::ON);
	geode->getOrCreateStateSet()->setRenderingHint(osg::StateSet::TRANSPARENT_BIN);
	return geode.release();
}


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
	selVertices->dirty();
	_selector->dirtyBound();
}

