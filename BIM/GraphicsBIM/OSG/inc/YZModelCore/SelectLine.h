#ifndef __SELECT_LINE_H__
#define __SELECT_LINE_H__
#include "ISelectPrimitives.h"
#include "LinePrimitive.h"
#include "osg/Camera"
#include <osgUtil/LineSegmentIntersector>

class SelectLine :public ISelectPrimitives
{
public:
	SelectLine(osg::Camera* camera);

	virtual IDrawElement* select(float x, float y) override;

	virtual IDrawElement* getSelection() const override;

	// internal:
	virtual LinePrimitive* selectLine(float x, float y);

	virtual LinePrimitive* getSelectedLine() const;

	osg::Node* getRoot() const;


protected:
	void doUserOperations(osgUtil::LineSegmentIntersector::Intersection& result);

	LinePrimitive* m_line;
	osg::Camera* m_camera;
	bool m_selected;
};

#endif // __SELECT_LINE_H__
