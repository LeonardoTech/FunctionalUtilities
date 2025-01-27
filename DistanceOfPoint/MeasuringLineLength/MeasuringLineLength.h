#ifndef __MEASURINGLINELENGTH_H__
#define __MEASURINGLINELENGTH_H__

#include <osg/Group>
#include <osg/MatrixTransform>
#include <osg/Point>
#include <osg/PolygonOffset>
#include <osgUtil/SmoothingVisitor>
#include <osgViewer/Viewer>
#include <osgDB/readFile>
#include <memory>
#include <osgGA/GUIEventHandler>

#include "IMeasuringLineLength.h"
#include "SelectPoint.h"
#include "TextPrimitive.h"
#include "LinePrimitive.h"
//#include "SelectModelPoint.h"

using namespace  measuringlinelength;
using namespace geo;

class MeasuringLineLengthImplement :
	public IMeasuringLineLength
{
public:
	MeasuringLineLengthImplement(osg::Camera* camera);
	~MeasuringLineLengthImplement();

	virtual void setStartPoint(float x, float y) override;

	void updateLineAndLabelPos();

	virtual void setEndPoint(float x, float y) override;

	virtual void setLabel(std::string name, float x, float y, float z) /*override*/;
	void CreateNewSelector();

	virtual void setLabelText(std::string name, Alignments method) override;;
	virtual float getDistance() override;

	virtual void getStartPoint(float& x, float& y, float& z) override;

	virtual void getEndPoint(float& x, float& y, float& z) override;

	//bool setPoint(float x, float y, Num num);
	//internal
	osg::Group* getRoot();
protected:
	osg::ref_ptr<osg::Group> m_root;
	osg::ref_ptr<osg::Camera> m_camera;
	std::unique_ptr<TextPrimitive> m_text;
	std::unique_ptr<LinePrimitive> m_line;
	std::unique_ptr<SelectPoint> m_select1;
	std::unique_ptr<SelectPoint> m_select2;
	Alignments m_showMethod;
};

#endif
