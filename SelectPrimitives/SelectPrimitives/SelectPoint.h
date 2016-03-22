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

// internal:
	virtual PointPrimitives* selectPoint(float x, float y);

	virtual PointPrimitives* getSelectedPoint() const;

	osg::Node* getRoot() const;

	void setPointPosition(const osg::Vec3& pos);

protected:
	void doUserOperations(osgUtil::LineSegmentIntersector::Intersection& result);
	PointPrimitives* m_point;
	osg::Camera* m_camera;
	bool m_selected;
};

#endif // __SELECT_POINT_H__
