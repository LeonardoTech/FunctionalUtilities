#ifndef __SELECT_LINE_H__
#define __SELECT_LINE_H__
#include "ISelectPrimitives.h"
#include "LinePrimitives.h"
#include "osg/Camera"
#include <osgUtil/LineSegmentIntersector>

class SelectLine :public ISelectPrimitives
{
public:
	SelectLine(osg::Camera* camera);

	virtual IDrawElement* select(float x, float y) override;

	virtual IDrawElement* getSelection() const override;

	virtual LinePrimitives* selectLine(float x, float y);

	virtual LinePrimitives* getSelectedLine() const;
protected:
	void doUserOperations(osgUtil::LineSegmentIntersector::Intersection& result);

	LinePrimitives* m_line;
	osg::Camera* m_camera;
};

#endif // __SELECT_LINE_H__
