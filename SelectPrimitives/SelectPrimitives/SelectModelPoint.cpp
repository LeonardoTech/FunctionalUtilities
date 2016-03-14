#include "SelectModelPoint.h"

osg::Geode* SelectModelPoint::createSelector()
{
	osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array(1);
	(*colors)[0] = selectedColor;

	_selector = new osg::Geometry;
	_selector->setDataVariance(osg::Object::DYNAMIC);
	_selector->setUseDisplayList(false);
	_selector->setUseVertexBufferObjects(true);
	_selector->setVertexArray(new osg::Vec3Array(1));
	_selector->setColorArray(colors.get());
	_selector->setColorBinding(osg::Geometry::BIND_OVERALL);
	_selector->addPrimitiveSet(new osg::DrawArrays(GL_POINTS, 0, 1));

	osg::ref_ptr<osg::Geode> geode = new osg::Geode;
	geode->addDrawable(_selector.get());
	geode->getOrCreateStateSet()->setAttributeAndModes(new osg::Point(10.0f));
	geode->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::OFF);
	geode->getOrCreateStateSet()->setMode(GL_BLEND, osg::StateAttribute::ON);
	geode->getOrCreateStateSet()->setRenderingHint(osg::StateSet::TRANSPARENT_BIN);
	return geode.release();
}


bool SelectModelPoint::drawbyCoordinate(float x, float y, osg::Camera* camera)
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


void SelectModelPoint::doUserOperations(osgUtil::LineSegmentIntersector::Intersection& result)
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
		/*cout << "pint in screen: " << point[0] << " " << point[1] << "" << point[2] << endl;*/
		point = point * vpMatrix;
	}

	const std::vector<unsigned int>& selIndices = result.indexList;

	if (selIndices.size() >= 3)
	{
		auto inverseMat = osg::Matrix::inverse(vpMatrix)*osg::Matrix::inverse(matrix);
		_position = point*inverseMat * matrix;
		(*selVertices)[0] = _position;
	}
	selVertices->dirty();
	_selector->dirtyBound();
}

osg::Vec3 SelectModelPoint::getPosition()
{
	return _position;
}


