#include "Coordinate.h"
#include "LinePrimitives.h"
#include "TextPrimitives.h"


Coordinate::Coordinate(osgGA::MultiTouchTrackballManipulator* manip) :
_lineX(new LinePrimitives()),
_lineY(new LinePrimitives()),
_lineZ(new LinePrimitives()),
_labelX(new TextPrimitives()),
_labelY(new TextPrimitives()),
_labelZ(new TextPrimitives())
{
	m_manip = manip;
	m_update = new CoordinateUpdater(m_manip);

	osg::ref_ptr<osg::Geode> geode = new osg::Geode;
	
	m_originx = 0;
	m_originy = 0;
	m_radius = 80;
	_lineX->setColor(0, 0, 1);
	_lineY->setColor(0, 1, 0);
	_lineZ->setColor(1, 0, 0);

	_lineX->setStartPosition(0.0f, 0.0f, 0.0f);
	_lineX->setEndPosition(m_radius, 0.0f, 0.0f);
	_lineY->setStartPosition(0.0f, 0.0f, 0.0f);
	_lineY->setEndPosition(0.0f, m_radius, 0.0f);
	_lineZ->setStartPosition(0.0f, 0.0f, 0.0f);
	_lineZ->setEndPosition(0.0f, 0.0f, m_radius);

	geode->setDataVariance(osg::Object::DYNAMIC);
	geode->addDrawable(_lineX->getGeometry());
	geode->addDrawable(_lineY->getGeometry());
	geode->addDrawable(_lineZ->getGeometry());

	_labelX->setPosition(m_radius + 5.0f, 0.0f, 0.0f);
	_labelY->setPosition(0.0f, m_radius + 5.0f, 0.0f);
	_labelZ->setPosition(0.0f, 0.0f, m_radius + 5.0f);
	_labelX->setText("X");
	_labelY->setText("Y");
	_labelZ->setText("Z");

	_labelX->setColor(0, 0, 1);
	_labelY->setColor(0, 1, 0);
	_labelZ->setColor(1, 0, 0);

	m_transNode = new osg::MatrixTransform();
	auto rotNode = new osg::MatrixTransform();
	rotNode->addChild(geode.get());
	rotNode->addChild(_labelX->getOsgText());
	rotNode->addChild(_labelY->getOsgText());
	rotNode->addChild(_labelZ->getOsgText());

	rotNode->setUpdateCallback(m_update);
	m_transNode->addChild(rotNode);
}


Coordinate::~Coordinate()
{
}

//================================================================
void Coordinate::setLabel(COORDINATE_NAME axis, string label)
{
	if (axis == X_AXIS)
		_labelX->setText(label);
	if (axis == Y_AXIS)
		_labelY->setText(label);
	if (axis == Z_AXIS)
		_labelZ->setText(label);
}

void Coordinate::setLabelPosition(COORDINATE_NAME axis, float x, float y, float z)
{
	if (axis == X_AXIS)
		_labelX->setPosition(x, y, z);
	if (axis == Y_AXIS)
		_labelY->setPosition(x, y, z);
	if (axis == Z_AXIS)
		_labelZ->setPosition(x, y, z);
}

//设置轴的颜色  //设置标注的颜色
void Coordinate::setColor(COORDINATE_NAME axis, float x, float y, float z)
{
	if (axis == X_AXIS)
	{
		_labelX->setColor(x, y, z);
	}

	if (axis == Y_AXIS)
	{
		_labelY->setColor(x, y, z);
	}

	if (axis == Z_AXIS)
	{
		_labelZ->setColor(x, y, z);
	}

}

void Coordinate::setOriginPoint(float x, float y)
{
	m_originx = x;
	m_originy = y;
	m_transNode->setMatrix(osg::Matrix::translate(osg::Vec3(m_originx, m_originy, -m_radius*1.5)));
}

void Coordinate::setRadius(float radius)
{
	m_radius = radius;

	_lineX->setStartPosition(0.0f, 0.0f, 0.0f);
	_lineX->setEndPosition(m_radius, 0.0f, 0.0f);
	_lineY->setStartPosition(0.0f, 0.0f, 0.0f);
	_lineY->setEndPosition(0.0f, m_radius, 0.0f);
	_lineZ->setStartPosition(0.0f, 0.0f, 0.0f);
	_lineZ->setEndPosition(0.0f, 0.0f, m_radius);

	_labelX->setPosition(m_radius + 5.0f, 0.0f, 0.0f);
	_labelY->setPosition(0.0f, m_radius + 5.0f, 0.0f);
	_labelZ->setPosition(0.0f, 0.0f, m_radius + 5.0f);

}

void Coordinate::getAxisDirection3D(COORDINATE_NAME axis, float& x, float& y, float& z)
{
	osg::Vec3  result;
	if (axis == X_AXIS)
	{
		result = m_update->getResult(Axis(0));
		x = result._v[0];
		y = result._v[1];
		z = result._v[2];
	}
	if (axis == Y_AXIS)
	{
		result = m_update->getResult(Axis(1));
		x = result._v[0];
		y = result._v[1];
		z = result._v[2];
	}
	if (axis == Z_AXIS)
	{
		result = m_update->getResult(Axis(2));
		x = result._v[0];
		y = result._v[1];
		z = result._v[2];
	}
}

// <可以先不做>
void Coordinate::setDarkColor(COORDINATE_NAME axis, string color)
{

}

void Coordinate::setLabelVisibility(COORDINATE_NAME axis, bool bvisible)
{
	//if (axis == X_AXIS)
	//	m_bvisibleX = bvisible;
	//if (axis == Y_AXIS)
	//	m_bvisibleY = bvisible;
	//if (axis == Z_AXIS)
	//	m_bvisibleZ = bvisible;
}

void Coordinate::setAxisWidth(float width)
{
	//if (axis == X_AXIS)
	_lineX->setLineWidth(width);
	//if (axis == Y_AXIS)
	_lineY->setLineWidth(width);
	//if (axis == Z_AXIS)
	_lineZ->setLineWidth(width);
}

osg::MatrixTransform* Coordinate::getNode()
{
	return m_transNode;
}
