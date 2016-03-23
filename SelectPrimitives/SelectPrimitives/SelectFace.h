#ifndef __SELECT_FACE_H__
#define __SELECT_FACE_H__
#include "ISelectPrimitives.h"
#include "FacePrimitives.h"
#include "osg/Camera"
#include <osgUtil/LineSegmentIntersector>

class SelectFace :public ISelectPrimitives
{
public:

	SelectFace(osg::Camera* camera);

	virtual IDrawElement* select(float x, float y) override;

	virtual IDrawElement* getSelection() const override;

	virtual FacePrimitives* selectFace(float x, float y);

	virtual FacePrimitives* getSelectedFace() const;

protected:
	void doUserOperations(osgUtil::LineSegmentIntersector::Intersection& result);
	osg::ref_ptr<osg::Vec3Array>_vertices;
	FacePrimitives* m_face;
	osg::Camera* m_camera;
};

#endif // __SELECT_FACE_H__
