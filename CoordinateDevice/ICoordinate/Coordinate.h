#ifndef __COORDINATE_H__
#define __COORDINATE_H__
#include "ICoordinate.h"
#include "osgViewer/Viewer"
#include "osg/Geometry"
#include "osg/MatrixTransform"
#include "osg/PolygonOffset"
#include "osgGA/MultiTouchTrackballManipulator"
#include "CoordinateUpdater.h"
#include "PointPrimitives.h"
#include "LinePrimitives.h"
#include "TextPrimitives.h"
#include <memory>


class Coordinate :public ICoordinate
{
public:
	Coordinate(osgGA::MultiTouchTrackballManipulator* manip);
	~Coordinate();
	virtual void setLabel(COORDINATE_NAME axis, string label) override;
	virtual void setLabelPosition(COORDINATE_NAME axis, float x, float y, float z) override;
	virtual void setColor(COORDINATE_NAME axis, float x, float y, float z)  override;
	virtual void setOriginPoint(float x, float y) override;
	virtual void setRadius(float radius) override;
	virtual void getAxisDirection3D(COORDINATE_NAME axis, float& x, float& y, float& z) override;
	virtual void setDarkColor(COORDINATE_NAME axis, string color) override;
	virtual void setLabelVisibility(COORDINATE_NAME axis, bool bvisible) override;
	virtual void setAxisWidth(float width) override;

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

	std::unique_ptr<LinePrimitives> _lineX;
	std::unique_ptr<LinePrimitives> _lineY;
	std::unique_ptr<LinePrimitives> _lineZ;

	std::unique_ptr<TextPrimitives>_labelX;
	std::unique_ptr<TextPrimitives>_labelY;
	std::unique_ptr<TextPrimitives>_labelZ;

	//osg::ref_ptr<osgText::Text> _xText;
	//osg::ref_ptr<osgText::Text> _yText;
	//osg::ref_ptr<osgText::Text> _zText;
	//osg::Vec4 m_colorX;
	//osg::Vec4 m_colorY;
	//osg::Vec4 m_colorZ;

	//osg::Vec4 m_colorXLabel;
	//osg::Vec4 m_colorYLabel;
	//osg::Vec4 m_colorZLabel;

	//osg::Vec3 m_labelPositionX;//ok
	//osg::Vec3 m_labelPositionY;//ok
	//osg::Vec3 m_labelPositionZ;//ok
	//

	float m_radius;
	float m_originx;
	float m_originy;

	//float m_widthX;
	//float m_widthY;
	//float m_widthZ;

	bool m_bvisibleX;
	bool m_bvisibleY;
	bool m_bvisibleZ;

	//string m_showLabelX;
	//string m_showLabelY;
	//string m_showLabelZ;
};

#endif