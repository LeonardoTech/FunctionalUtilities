#include <osgText/Font>
#include <osgText/Text>
#include "MeasuringLineLength.h"

using namespace  distanceofpoint_measuringlinelength_measuringlinelength;

MeasuringLineLength::MeasuringLineLength(osg::Camera* camera) :
m_select1(new SelectPoint(camera)),
m_select2(new SelectPoint(camera)),
m_text(new TextPrimitive()),
m_line(new LinePrimitive())
{
	m_line->setColor(1, 0, 0);
	m_text->setColor(1, 1, 1);
	m_root = new osg::Group;
	m_root->addChild(m_select2->getRoot());
	m_root->addChild(m_select1->getRoot());
	m_root->addChild(m_line->getGeometry());
	m_root->addChild(m_text->getOsgText());
	m_camera = camera;
}

void MeasuringLineLength::CreateNewSelector()
{
	MeasuringLineLength s(m_camera);
}

MeasuringLineLength::~MeasuringLineLength()
{

}

#pragma region implement interface

void MeasuringLineLength::setStartPoint(float x, float y)
{
	auto start = m_select1->selectPoint(x, y);
	if (!start)
	{
		std::cerr << "select point failed." << std::endl;
		return;
	}
	updateLineAndLabelPos();
}

void MeasuringLineLength::setEndPoint(float x, float y)
{
	auto end = m_select2->selectPoint(x, y);
	if (!end)
	{
		std::cerr << "select point failed." << std::endl;
		return;
	}
	m_line->setEndPosition(end->getPosition());
	updateLineAndLabelPos();

}

void MeasuringLineLength::setLabel(std::string name, float x, float y, float z)
{
	m_text->setTextContent(name); // <设置文字的内容>
	m_text->setPosition(x, y, z);
}

float MeasuringLineLength::getDistance()
{
	auto start = m_select1->getSelectedPoint();
	if (!start)
	{
		return 0;
	}
	auto end = m_select2->getSelectedPoint();
	if (!end)
	{
		return 0;
	}

	float length = (end->getPosition() - start->getPosition()).length();
	return length;
}

// fn	void PickHandler::setRoot(osg::Group* node)
// 
// brief	 <将所有的图形都放进root组里>

osg::Group* MeasuringLineLength::getRoot()
{
	return m_root;
}

void MeasuringLineLength::setLabelText(std::string name, Alignments method)
{
	m_text->setTextContent(name);
	m_showMethod = method;
	updateLineAndLabelPos();
}

void MeasuringLineLength::getStartPoint(float& x, float& y, float& z)
{
	auto point = m_select1->getSelectedPoint();
	point->getPosition(x, y, z);
}

void MeasuringLineLength::getEndPoint(float& x, float& y, float& z)
{
	auto point = m_select2->getSelectedPoint();
	point->getPosition(x, y, z);
}

#pragma endregion

#pragma region internal interface

void MeasuringLineLength::updateLineAndLabelPos()
{
	auto start = m_select1->getSelectedPoint();
	if (!start)
	{
		std::cerr << "no selection." << std::endl;
		return;
	}
	auto end = m_select2->getSelectedPoint();
	if (!end)
	{
		m_select2->setPointPosition(start->getPosition());
		end = start;
	}

	m_line->setStartPosition(start->getPosition());
	m_line->setEndPosition(end->getPosition());

	osg::Vec3 middle;
	if (m_showMethod == Alignments::Left)
	{
		middle = start->getPosition();
	}
	else if (m_showMethod == Alignments::Right)
	{
		middle = end->getPosition();
	}
	else if (m_showMethod == Alignments::Center)
	{
		middle = start->getPosition() + end->getPosition();
		middle /= 2.0;
	}

	m_text->setPosition(middle.x(), middle.y(), middle.z());// <设置文字的坐标>
}
#pragma endregion