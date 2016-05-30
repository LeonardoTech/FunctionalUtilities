#pragma once
#include "IMeasuringLineLength.h"
#include "SelectPoint.h"
#include "TextPrimitive.h"
#include "LinePrimitive.h"
#include "osg/Group"
#include <memory>


class MeasuringLineLength :
	public IMeasuringLineLength
{
public:
	MeasuringLineLength(osg::Camera* camera);
	~MeasuringLineLength();
	virtual void setStartPoint(float x, float y) override;

	void updateLineAndLabelPos();

	virtual void setEndPoint(float x, float y) override;
	virtual void setLabel(std::string name, float x, float y, float z) /*override*/;
	virtual void setLabel(std::string name, SHOW_METHOD method) override;
	virtual float getDistance() override;


	virtual void getStartPoint(float& x, float& y, float& z) override;
	virtual void getEndPoint(float& x, float& y, float& z) override;

	//bool setPoint(float x, float y, Num num);
	osg::Group* getRoot();

protected:
	osg::Group* _root;
	osg::ref_ptr<osg::Camera>_camera;
	std::unique_ptr<TextPrimitive> _text;
	std::unique_ptr<LinePrimitive> _line;
	std::unique_ptr<SelectPoint> _select1;
	std::unique_ptr<SelectPoint> _select2;

	SHOW_METHOD m_showMethod;
};

