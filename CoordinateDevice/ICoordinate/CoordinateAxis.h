#ifndef __COORDINATE_H__
#define __COORDINATE_H__
#include <osgViewer/Viewer>
#include <osg/Geometry>
#include <osg/MatrixTransform>
#include <osg/PolygonOffset>
#include <osgGA/MultiTouchTrackballManipulator>
#include <memory>

#include "CoordinateUpdater.h"
#include "PointPrimitive.h"
#include "LinePrimitive.h"
#include "TextPrimitive.h"
#include "ICoordinateAxis.h"

using namespace coordinatedevice_coordinate_icoordinate;

namespace coordinatedevice_coordinate_coordinate
{
	class CoordinateAxis :public ICoordinateAxis
	{
	public:
		CoordinateAxis(osgGA::MultiTouchTrackballManipulator* manip);
		~CoordinateAxis();

		virtual void setLabelText(AxisDirection axis, std::string label) override;

		virtual void setLabelPosition(AxisDirection axis, float x, float y, float z) override;

		virtual void setColor(AxisDirection axis, float x, float y, float z)  override;

		virtual void setOriginPoint(float x, float y) override;

		virtual void setRadius(float radius) override;

		virtual void getAxisDirection3D(AxisDirection axis, float& x, float& y, float& z) override;

		virtual void getAxisDirection2D(AxisDirection axis, float& x, float& y) override;

		virtual void setDarkColor(AxisDirection axis, float x, float y, float z) override;

		virtual void setLabelVisibility(AxisDirection axis, bool isVisibility) override;

		virtual void setAxisWidth(float width) override;

		virtual void setEnableUpdate(bool enabled) override;

		//osg::Geometry* createSimpleGeometry_x();
		//osg::Geometry* createSimpleGeometry_y();
		//osg::Geometry* createSimpleGeometry_z();
		//osgText::Text* createText(const string name, const osg::Vec3 &position, const osg::Vec4 &color);

		osg::MatrixTransform* getNode();

	protected:
		CoordinateUpdater* m_update;
		osgGA::MultiTouchTrackballManipulator* m_manip;
		//osg::ref_ptr<osg::Geode> m_geode;
		osg::ref_ptr<osg::MatrixTransform> m_transNode;

		std::unique_ptr<LinePrimitive> m_lineX;
		std::unique_ptr<LinePrimitive> m_lineY;
		std::unique_ptr<LinePrimitive> m_lineZ;

		std::unique_ptr<TextPrimitive> m_labelX;
		std::unique_ptr<TextPrimitive> m_labelY;
		std::unique_ptr<TextPrimitive> m_labelZ;

		osg::ref_ptr<osg::MatrixTransform> _rotNode;
		float m_radius;
		float m_originX;
		float m_originY;

		//float m_widthX;
		//float m_widthY;
		//float m_widthZ;

		bool m_bvisibleX;
		bool m_bvisibleY;
		bool m_bvisibleZ;

		std::string m_showLabelX;
		std::string m_showLabelY;
		std::string m_showLabelZ;
	};
}
#endif