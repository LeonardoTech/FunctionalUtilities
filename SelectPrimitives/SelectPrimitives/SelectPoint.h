#ifndef __SELECT_POINT_H__
#define __SELECT_POINT_H__
#include "ISelectPrimitives.h"
#include "PointPrimitives.h"
#include "osg/Camera"
#include <osgUtil/LineSegmentIntersector>

class SelectPoint :public ISelectPrimitives
{
public:
	SelectPoint(osg::Camera* camera);

	virtual IDrawElement* select(float x, float y) override;

	virtual IDrawElement* getSelection() const override;

	virtual PointPrimitives* selectPoint(float x, float y);

	virtual PointPrimitives* getSelectedPoint() const;
protected:
	void doUserOperations(osgUtil::LineSegmentIntersector::Intersection& result);

	PointPrimitives* m_point;
	osg::Camera* m_camera;
};

#endif // __SELECT_POINT_H__
