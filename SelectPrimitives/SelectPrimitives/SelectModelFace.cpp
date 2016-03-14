// SelectModelLine.cpp : 定义控制台应用程序的入口点。
//

#include "SelectModelFace.h"

osg::Geode* SelectModelFace::createSelector()
{
	osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array(1);
	(*colors)[0] = selectedColor;

	_selector = new osg::Geometry;
	_selector->setDataVariance(osg::Object::DYNAMIC);
	_selector->setUseDisplayList(false);
	_selector->setUseVertexBufferObjects(true);
	_selector->setVertexArray(new osg::Vec3Array(3));
	_selector->setColorArray(colors.get());
	_selector->setColorBinding(osg::Geometry::BIND_OVERALL);
	_selector->addPrimitiveSet(new osg::DrawArrays(GL_TRIANGLES, 0, 3));

	osg::ref_ptr<osg::Geode> geode = new osg::Geode;
	geode->addDrawable(_selector.get());
	geode->getOrCreateStateSet()->setAttributeAndModes(new osg::Point(10.0f));
	geode->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::OFF);
	geode->getOrCreateStateSet()->setMode(GL_BLEND, osg::StateAttribute::ON);
	geode->getOrCreateStateSet()->setRenderingHint(osg::StateSet::TRANSPARENT_BIN);
	return geode.release();
}

bool SelectModelFace::drawbyCoordinate(float x, float y, osg::Camera* camera)
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


void SelectModelFace::doUserOperations(osgUtil::LineSegmentIntersector::Intersection& result)
{
	osg::Geometry* geom = dynamic_cast<osg::Geometry*>(result.drawable.get());
	if (!geom || !_selector || geom == _selector) return;

	osg::Vec3Array* vertices = dynamic_cast<osg::Vec3Array*>(geom->getVertexArray());
	osg::Vec3Array* selVertices = dynamic_cast<osg::Vec3Array*>(_selector->getVertexArray());
	if (!vertices || !selVertices) return;

	osg::Matrix matrix = osg::computeLocalToWorld(result.nodePath);
	const std::vector<unsigned int>& selIndices = result.indexList;
	for (unsigned int i = 0; i<3 && i<selIndices.size(); ++i)
	{

		unsigned int pos = selIndices[i];
		(*selVertices)[i] = (*vertices)[pos] * matrix;
		cout << (*selVertices)[i]._v[0] << " " << (*selVertices)[i]._v[1] << " " << (*selVertices)[i]._v[2] << endl;
	}
	selVertices->dirty();
	_selector->dirtyBound();
}

