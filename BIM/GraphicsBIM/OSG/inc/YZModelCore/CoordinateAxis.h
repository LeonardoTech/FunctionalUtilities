#ifndef __COORDINATE_AXIS_H__
#define __COORDINATE_AXIS_H__
#include "ICoordinateAxis.h"
#include "osgViewer/Viewer"
#include "osg/Geometry"
#include "osg/MatrixTransform"
#include "osg/PolygonOffset"
#include "osgGA/MultiTouchTrackballManipulator"
#include "CoordinateUpdater.h"
#include "D:\\WorkSpace\\BIM\\GraphicsBIM\\OSG\inc\\YZGraphics\\PointPrimitive.h"
#include "D:\\WorkSpace\\BIM\\GraphicsBIM\\OSG\inc\\YZGraphics\\LinePrimitive.h"
#include "D:\\WorkSpace\\BIM\\GraphicsBIM\\OSG\inc\\YZGraphics\\TextPrimitive.h"
#include <memory>
#include <osg/Geode>


class CoordinateAxis :public ICoordinateAxis
{
public:
	CoordinateAxis(osgGA::MultiTouchTrackballManipulator* manip);
	virtual void setLabel(COORDINATE_AXIS axis, std::string label) override;
	virtual void setLabelPosition(COORDINATE_AXIS axis, float x, float y, float z) override;
	virtual void setColor(COORDINATE_AXIS axis, float x, float y, float z)  override;
	virtual void setOriginPoint(float x, float y) override;
	virtual void setRadius(float radius) override;
	virtual void getAxisDirection3D(COORDINATE_AXIS axis, float& x, float& y, float& z) override;
	virtual void setDarkColor(COORDINATE_AXIS axis, float x, float y, float z) override;
	virtual void setLabelVisibility(COORDINATE_AXIS axis, bool bvisible) override;
	virtual void setAxisWidth(float width) override;
	virtual void setEnableUpdate(bool enabled) override;// <设置轴是否需要更新>
	virtual void setVisibility(bool visibility) override;
	virtual void setCoordinateType(CoordinateTypes type) override;

	//osg::Geometry* createSimpleGeometry_x();
	//osg::Geometry* createSimpleGeometry_y();
	//osg::Geometry* createSimpleGeometry_z();
	//osgText::Text* createText(const string name, const osg::Vec3 &position, const osg::Vec4 &color);

	osg::MatrixTransform* getNode();

protected:
	osg::ref_ptr<CoordinateUpdater> m_update;
	osgGA::MultiTouchTrackballManipulator* m_manip;
	//osg::ref_ptr<osg::Geode> m_geode;
	osg::ref_ptr<osg::MatrixTransform> m_transNode;
	osg::ref_ptr<osg::MatrixTransform> m_rotNode;

	std::unique_ptr<LinePrimitive> _lineX;
	std::unique_ptr<LinePrimitive> _lineY;
	std::unique_ptr<LinePrimitive> _lineZ;

	std::unique_ptr<TextPrimitive> _labelX;
	std::unique_ptr<TextPrimitive> _labelY;
	std::unique_ptr<TextPrimitive> _labelZ;

	osg::ref_ptr<osg::Geode> _geode;

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
	CoordinateTypes m_coordinateType;
	//string m_showLabelX;
	//string m_showLabelY;
	//string m_showLabelZ;
};

#endif // __COORDINATE_AXIS_H__