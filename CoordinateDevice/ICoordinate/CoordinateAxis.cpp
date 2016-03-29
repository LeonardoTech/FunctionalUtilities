#include "CoordinateAxis.h"
using namespace  coordinatedevice_coordinate_coordinate;

CoordinateAxis::CoordinateAxis(osgGA::MultiTouchTrackballManipulator* manip) :
m_lineX(new LinePrimitives()),
m_lineY(new LinePrimitives()),
m_lineZ(new LinePrimitives()),
m_labelX(new TextPrimitives()),
m_labelY(new TextPrimitives()),
m_labelZ(new TextPrimitives()),
m_showLabelX("X"),
m_showLabelY("Y"),
m_showLabelZ("Z")
{
	m_manip = manip;
	m_update = new CoordinateUpdater(m_manip);

	osg::ref_ptr<osg::Geode> geode = new osg::Geode;
	
	m_originX = 0;
	m_originY = 0;
	m_radius = 80;
	m_lineX->setColor(0, 0, 1);
	m_lineY->setColor(0, 1, 0);
	m_lineZ->setColor(1, 0, 0);

	m_lineX->setStartPosition(0.0f, 0.0f, 0.0f);
	m_lineX->setEndPosition(m_radius, 0.0f, 0.0f);
	m_lineY->setStartPosition(0.0f, 0.0f, 0.0f);
	m_lineY->setEndPosition(0.0f, m_radius, 0.0f);
	m_lineZ->setStartPosition(0.0f, 0.0f, 0.0f);
	m_lineZ->setEndPosition(0.0f, 0.0f, m_radius);

	geode->setDataVariance(osg::Object::DYNAMIC);
	geode->addDrawable(m_lineX->getGeometry());
	geode->addDrawable(m_lineY->getGeometry());
	geode->addDrawable(m_lineZ->getGeometry());

	m_labelX->setPosition(m_radius + 5.0f, 0.0f, 0.0f);
	m_labelY->setPosition(0.0f, m_radius + 5.0f, 0.0f);
	m_labelZ->setPosition(0.0f, 0.0f, m_radius + 5.0f);
	m_labelX->setTextContent(m_showLabelX);
	m_labelY->setTextContent(m_showLabelY);
	m_labelZ->setTextContent(m_showLabelZ);

	m_labelX->setColor(0, 0, 1);
	m_labelY->setColor(0, 1, 0);
	m_labelZ->setColor(1, 0, 0);

	m_transNode = new osg::MatrixTransform();
	auto rotNode = new osg::MatrixTransform();
	rotNode->addChild(geode.get());
	rotNode->addChild(m_labelX->getOsgText());
	rotNode->addChild(m_labelY->getOsgText());
	rotNode->addChild(m_labelZ->getOsgText());

	rotNode->setUpdateCallback(m_update);
	m_transNode->addChild(rotNode);
}


CoordinateAxis::~CoordinateAxis()
{
}

#pragma region interface implement

void CoordinateAxis::setLabelText(AxisDirection axis, std::string label)
{
	if (axis == AxisDirection::X_AXIS)
	{
		m_labelX->setTextContent(label);
		m_showLabelX = label;
	}
		
	if (axis == AxisDirection::Y_AXIS)
	{
		m_labelY->setTextContent(label);
		m_showLabelY = label;
	}
	if (axis == AxisDirection::Z_AXIS)
	{
		m_labelZ->setTextContent(label);
		m_showLabelZ = label;
	}
}

void CoordinateAxis::setLabelPosition(AxisDirection axis, float x, float y, float z)
{
	if (axis == AxisDirection::X_AXIS)
		m_labelX->setPosition(x, y, z);
	if (axis == AxisDirection::Y_AXIS)
		m_labelY->setPosition(x, y, z);
	if (axis == AxisDirection::Z_AXIS)
		m_labelZ->setPosition(x, y, z);
}

// <设置轴的颜色>  // <设置标注的颜色>
void CoordinateAxis::setColor(AxisDirection axis, float x, float y, float z)
{
	if (axis == AxisDirection::X_AXIS)
	{
		m_labelX->setColor(x, y, z);
		m_lineX->setColor(x, y, z);
	} 
	if (axis == AxisDirection::Y_AXIS)
	{
		m_labelY->setColor(x, y, z);
		m_lineY->setColor(x, y, z);
	}

	if (axis == AxisDirection::Z_AXIS)
	{
		m_labelZ->setColor(x, y, z);
		m_lineZ->setColor(x, y, z);
	}
}

void CoordinateAxis::setOriginPoint(float x, float y)
{
	m_originX = x;
	m_originY = y;
	m_transNode->setMatrix(osg::Matrix::translate(osg::Vec3(m_originX, m_originY, -m_radius*1.5)));
}

void CoordinateAxis::setRadius(float radius)
{
	m_radius = radius;

	m_lineX->setStartPosition(0.0f, 0.0f, 0.0f);
	m_lineX->setEndPosition(m_radius, 0.0f, 0.0f);
	m_lineY->setStartPosition(0.0f, 0.0f, 0.0f);
	m_lineY->setEndPosition(0.0f, m_radius, 0.0f);
	m_lineZ->setStartPosition(0.0f, 0.0f, 0.0f);
	m_lineZ->setEndPosition(0.0f, 0.0f, m_radius);

	m_labelX->setPosition(m_radius + 5.0f, 0.0f, 0.0f);
	m_labelY->setPosition(0.0f, m_radius + 5.0f, 0.0f);
	m_labelZ->setPosition(0.0f, 0.0f, m_radius + 5.0f);

}

void CoordinateAxis::getAxisDirection3D(AxisDirection axis, float& x, float& y, float& z)
{
	osg::Vec3  result;
	if (axis == AxisDirection::X_AXIS)
	{
		result = m_update->getResult(AxisDirection::X_AXIS);
		x = result._v[0];
		y = result._v[1];
		z = result._v[2];
	}
	if (axis == AxisDirection::Y_AXIS)
	{
		result = m_update->getResult(AxisDirection::Y_AXIS);
		x = result._v[0];
		y = result._v[1];
		z = result._v[2];
	}
	if (axis == AxisDirection::Z_AXIS)
	{
		result = m_update->getResult(AxisDirection::Z_AXIS);
		x = result._v[0];
		y = result._v[1];
		z = result._v[2];
	}
}


void CoordinateAxis::getAxisDirection2D(AxisDirection axis, float& x, float& y){
	osg::Vec3  result;
	if (axis == AxisDirection::X_AXIS)
	{
		result = m_update->getResult(AxisDirection::X_AXIS);
		x = result._v[0];
		y = result._v[1];
	}
	if (axis == AxisDirection::Y_AXIS)
	{
		result = m_update->getResult(AxisDirection::Y_AXIS);
		x = result._v[0];
		y = result._v[1];
	}
	if (axis == AxisDirection::Z_AXIS)
	{
		result = m_update->getResult(AxisDirection::Z_AXIS);
		x = result._v[0];
		y = result._v[1];
	}
}

//TODO <可以先不做>
void CoordinateAxis::setDarkColor(AxisDirection axis, float x, float y, float z)
{

}

void CoordinateAxis::setLabelVisibility(AxisDirection axis, bool isVisibility)
{
	if (!isVisibility)
	{
		if (axis == AxisDirection::X_AXIS)
			m_labelX->setTextContent("");
		if (axis == AxisDirection::Y_AXIS)
			m_labelY->setTextContent("");
		if (axis == AxisDirection::Z_AXIS)
			m_labelZ->setTextContent("");
	}
	else
	{
		if (axis == AxisDirection::X_AXIS)
			m_labelX->setTextContent(m_showLabelX);
		if (axis == AxisDirection::Y_AXIS)
			m_labelY->setTextContent(m_showLabelY);
		if (axis == AxisDirection::Z_AXIS)
			m_labelZ->setTextContent(m_showLabelZ);
	}
}

void CoordinateAxis::setAxisWidth(float width)
{
	m_lineX->setLineWidth(width);
	m_lineY->setLineWidth(width);
	m_lineZ->setLineWidth(width);
}

#pragma endregion

osg::MatrixTransform* CoordinateAxis::getNode()
{
	return m_transNode;
}
