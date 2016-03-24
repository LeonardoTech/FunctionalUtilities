#ifndef __MEASURINGLINELENGTH_H__
#define __MEASURINGLINELENGTH_H__
#include <osgText/Font>
#include <osgText/Text>
#include <osg/Group>
#include <osg/Geometry>
#include <osg/Geode>
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
#include "TextPrimitives.h"
#include "LinePrimitives.h"
#include "SelectModelPoint.h"

using namespace  distanceofpoint_measuringlinelength_imeasuringlinelength;

namespace distanceofpoint_measuringlinelength_measuringlinelength
{
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
		std::unique_ptr<TextPrimitives> m_text;
		std::unique_ptr<LinePrimitives> m_line;
		std::unique_ptr<SelectPoint> m_select1;
		std::unique_ptr<SelectPoint> m_select2;
		Alignments m_showMethod;
	};
}
#endif
