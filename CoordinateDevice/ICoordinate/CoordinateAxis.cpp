#include "CoordinateAxis.h"
using namespace  coordinateaxis;

CoordinateAxisImplement::CoordinateAxisImplement(osgGA::MultiTouchTrackballManipulator* manip) :
m_lineX(new LinePrimitive()),
m_lineY(new LinePrimitive()),
m_lineZ(new LinePrimitive()),
m_labelX(new TextPrimitive()),
m_labelY(new TextPrimitive()),
m_labelZ(new TextPrimitive()),
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
	_rotNode = new osg::MatrixTransform();
	_rotNode->addChild(geode.get());
	_rotNode->addChild(m_labelX->getOsgText());
	_rotNode->addChild(m_labelY->getOsgText());
	_rotNode->addChild(m_labelZ->getOsgText());

	_rotNode->setUpdateCallback(m_update);
	m_transNode->addChild(_rotNode);
}


CoordinateAxisImplement::~CoordinateAxisImplement()
{
}

#pragma region interface implement

void CoordinateAxisImplement::setLabelText(AxisDirection axis, std::string label)
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

void CoordinateAxisImplement::setLabelPosition(AxisDirection axis, float x, float y, float z)
{
	if (axis == AxisDirection::X_AXIS)
		m_labelX->setPosition(x, y, z);
	if (axis == AxisDirection::Y_AXIS)
		m_labelY->setPosition(x, y, z);
	if (axis == AxisDirection::Z_AXIS)
		m_labelZ->setPosition(x, y, z);
}

// <设置轴的颜色>  // <设置标注的颜色>
void CoordinateAxisImplement::setColor(AxisDirection axis, float x, float y, float z)
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

void CoordinateAxisImplement::setOriginPoint(float x, float y)
{
	m_originX = x;
	m_originY = y;
	m_transNode->setMatrix(osg::Matrix::translate(osg::Vec3(m_originX, m_originY, -m_radius*1.5)));
}

void CoordinateAxisImplement::setRadius(float radius)
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

void CoordinateAxisImplement::getAxisDirection3D(AxisDirection axis, float& x, float& y, float& z)
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


void CoordinateAxisImplement::getAxisDirection2D(AxisDirection axis, float& x, float& y){
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
void CoordinateAxisImplement::setDarkColor(AxisDirection axis, float x, float y, float z)
{

}

void CoordinateAxisImplement::setLabelVisibility(AxisDirection axis, bool isVisibility)
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

void CoordinateAxisImplement::setAxisWidth(float width)
{
	m_lineX->setLineWidth(width);
	m_lineY->setLineWidth(width);
	m_lineZ->setLineWidth(width);
}

#pragma endregion

osg::MatrixTransform* CoordinateAxisImplement::getNode()
{
	return m_transNode;
}




void CoordinateAxis::setEnableUpdate(bool enabled)
{
	if (enabled == true)
	{
		_rotNode->setUpdateCallback(m_update);
	}
	else
	{
		_rotNode->setUpdateCallback(NULL);
	}
}