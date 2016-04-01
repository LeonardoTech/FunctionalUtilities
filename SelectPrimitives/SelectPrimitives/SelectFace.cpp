#include "SelectFace.h"


SelectFace::SelectFace(osg::Camera* camera)
{
	_vertices = new osg::Vec3Array(3);
	m_face = new FacePrimitive;
	m_face->setColor(1.0f, 0.0f, 0.0f);
	m_camera = camera;
}




IDrawElement* SelectFace::select(float x, float y)
{
	return selectFace(x, y);
}


void SelectFace::doUserOperations(osgUtil::LineSegmentIntersector::Intersection& result)
{
	osg::Geometry* geom = dynamic_cast<osg::Geometry*>(result.drawable.get());
	if (!geom) return;// || !_selector || geom == _selector

	osg::Vec3Array* vertices = dynamic_cast<osg::Vec3Array*>(geom->getVertexArray());
	if (!vertices) return;// || !selVertices

	osg::Vec3 point = result.getWorldIntersectPoint();
	osg::Matrix matrix = osg::computeLocalToWorld(result.nodePath);
	osg::Matrix vpMatrix;
	
	if (m_camera) 
	{
		vpMatrix = m_camera->getViewMatrix() * m_camera->getProjectionMatrix();  // <相机矩阵，如果相机存在，就要用到相机矩阵进行处理>
		point = point * vpMatrix;
	}

	const std::vector<unsigned int>& selIndices = result.indexList; 

	if (selIndices.size() >= 3)
	{
		auto a = (*vertices)[selIndices[0]];// * matrix
		auto b = (*vertices)[selIndices[1]];// * matrix
		auto c = (*vertices)[selIndices[2]];// * matrix
		auto inverseMat = osg::Matrix::inverse(vpMatrix)*osg::Matrix::inverse(matrix);  // <对矩阵求逆>
		(*_vertices)[0] = a* matrix;
		(*_vertices)[1] = b* matrix;
		(*_vertices)[2] = c* matrix;

	}
	else
	{
		//assert(false);
	}
	m_face->setPosition((*_vertices)[0], (*_vertices)[1], (*_vertices)[2]);

}


FacePrimitive* SelectFace::selectFace(float x, float y)
{
	osg::ref_ptr<osgUtil::LineSegmentIntersector> intersector = new osgUtil::LineSegmentIntersector(osgUtil::Intersector::WINDOW, x, y);
	osgUtil::IntersectionVisitor iv(intersector.get());
	m_camera->accept(iv);
	 
	// <根据屏幕上的点求相交运算，返回三个三维坐标>
	if (intersector->containsIntersections())
	{
		osgUtil::LineSegmentIntersector::Intersection result = *(intersector->getIntersections().begin());
		doUserOperations(result);
	}
	return m_face;
}


FacePrimitive* SelectFace::getSelectedFace() const
{
	return m_face;
}


IDrawElement* SelectFace::getSelection() const
{
	return getSelectedFace();
}