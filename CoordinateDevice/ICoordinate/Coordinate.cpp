#include "Coordinate.h"
using namespace  coordinatedevice_coordinate_coordinate;

Coordinate::Coordinate(osgGA::MultiTouchTrackballManipulator* manip) :
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
	m_labelX->setText(m_showLabelX);
	m_labelY->setText(m_showLabelY);
	m_labelZ->setText(m_showLabelZ);

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


Coordinate::~Coordinate()
{
}

#pragma region interface implement

void Coordinate::setLabelText(CoordinateNames axis, std::string label)
{
	if (axis == CoordinateNames::X_AXIS)
	{
		m_labelX->setText(label);
		m_showLabelX = label;
	}
		
	if (axis == CoordinateNames::Y_AXIS)
	{
		m_labelY->setText(label);
		m_showLabelY = label;
	}
	if (axis == CoordinateNames::Z_AXIS)
	{
		m_labelZ->setText(label);
		m_showLabelZ = label;
	}
}

void Coordinate::setLabelPosition(CoordinateNames axis, float x, float y, float z)
{
	if (axis == CoordinateNames::X_AXIS)
		m_labelX->setPosition(x, y, z);
	if (axis == CoordinateNames::Y_AXIS)
		m_labelY->setPosition(x, y, z);
	if (axis == CoordinateNames::Z_AXIS)
		m_labelZ->setPosition(x, y, z);
}

// <设置轴的颜色>  // <设置标注的颜色>
void Coordinate::setColor(CoordinateNames axis, float x, float y, float z)
{
	if (axis == CoordinateNames::X_AXIS)
	{
		m_labelX->setColor(x, y, z);
		m_lineX->setColor(x, y, z);
	} 
	if (axis == CoordinateNames::Y_AXIS)
	{
		m_labelY->setColor(x, y, z);
		m_lineY->setColor(x, y, z);
	}

	if (axis == CoordinateNames::Z_AXIS)
	{
		m_labelZ->setColor(x, y, z);
		m_lineZ->setColor(x, y, z);
	}
}

void Coordinate::setOriginPoint(float x, float y)
{
	m_originX = x;
	m_originY = y;
	m_transNode->setMatrix(osg::Matrix::translate(osg::Vec3(m_originX, m_originY, -m_radius*1.5)));
}

void Coordinate::setRadius(float radius)
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

void Coordinate::getAxisDirection3D(CoordinateNames axis, float& x, float& y, float& z)
{
	osg::Vec3  result;
	if (axis == CoordinateNames::X_AXIS)
	{
		result = m_update->getResult(Axis(0));
		x = result._v[0];
		y = result._v[1];
		z = result._v[2];
	}
	if (axis == CoordinateNames::Y_AXIS)
	{
		result = m_update->getResult(Axis(1));
		x = result._v[0];
		y = result._v[1];
		z = result._v[2];
	}
	if (axis == CoordinateNames::Z_AXIS)
	{
		result = m_update->getResult(Axis(2));
		x = result._v[0];
		y = result._v[1];
		z = result._v[2];
	}
}

void Coordinate::getAxisDirection2D(CoordinateNames axis, float& x, float& y)
{
	osg::Vec3  result;
	if (axis == CoordinateNames::X_AXIS)
	{
		result = m_update->getResult(Axis(0));
		x = result._v[0];
		y = result._v[1];
	}
	if (axis == CoordinateNames::Y_AXIS)
	{
		result = m_update->getResult(Axis(1));
		x = result._v[0];
		y = result._v[1];
	}
	if (axis == CoordinateNames::Z_AXIS)
	{
		result = m_update->getResult(Axis(2));
		x = result._v[0];
		y = result._v[1];
	}
}

//TODO <可以先不做>
void Coordinate::setDarkColor(CoordinateNames axis, float x, float y, float z)
{

}

void Coordinate::setLabelVisibility(CoordinateNames axis, bool isVisibility)
{
	if (!isVisibility)
	{
		if (axis == CoordinateNames::X_AXIS)
			m_labelX->setText("");
		if (axis == CoordinateNames::Y_AXIS)
			m_labelY->setText("");
		if (axis == CoordinateNames::Z_AXIS)
			m_labelZ->setText("");
	}
	else
	{
		if (axis == CoordinateNames::X_AXIS)
			m_labelX->setText(m_showLabelX);
		if (axis == CoordinateNames::Y_AXIS)
			m_labelY->setText(m_showLabelY);
		if (axis == CoordinateNames::Z_AXIS)
			m_labelZ->setText(m_showLabelZ);
	}
}

void Coordinate::setAxisWidth(float width)
{
	m_lineX->setLineWidth(width);
	m_lineY->setLineWidth(width);
	m_lineZ->setLineWidth(width);
}

#pragma endregion

osg::MatrixTransform* Coordinate::getNode()
{
	return m_transNode;
}
