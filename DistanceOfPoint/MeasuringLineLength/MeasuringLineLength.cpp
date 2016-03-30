
#include "MeasuringLineLength.h"


MeasuringLineLength::MeasuringLineLength(osg::Camera* camera) :
_select1(new SelectPoint(camera)),
_select2(new SelectPoint(camera)),
_text(new TextPrimitive()),
_line(new LinePrimitive())
{
	_line->setColor(1, 0, 0);
	_text->setColor(1, 1, 1);
	_root = new osg::Group;
	_root->addChild(_select2->getRoot());
	_root->addChild(_select1->getRoot());
	_root->addChild(_line->getGeometry());
	_root->addChild(_text->getOsgText());
	_camera = camera;
}


MeasuringLineLength::~MeasuringLineLength()
{

}


void MeasuringLineLength::setStartPoint(float x, float y)
{
	auto start = _select1->selectPoint(x, y);
	if (!start)
	{
		std::cerr << "select point failed." << std::endl;
		return;
	}
	updateLineAndLabelPos();
}

void MeasuringLineLength::setEndPoint(float x, float y)
{
	auto end = _select2->selectPoint(x, y);
	if (!end)
	{
		std::cerr << "select point failed." << std::endl;
		return;
	}
	_line->setEndPosition(end->getPosition());
	updateLineAndLabelPos();

}

void MeasuringLineLength::setLabel(string name, float x, float y, float z)
{
	_text->setTextContent(name); // <设置文字的内容>
	_text->setPosition(x, y, z);
}

float MeasuringLineLength::getDistance()
{
	auto start = _select1->getSelectedPoint();
	if (!start)
	{
		return 0;
	}
	auto end = _select2->getSelectedPoint();
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
	return _root;
}


void MeasuringLineLength::setLabel(string name, SHOW_METHOD method)
{
	_text->setTextContent(name);
	m_showMethod = method;
	updateLineAndLabelPos();
}

void MeasuringLineLength::getStartPoint(float& x, float& y, float& z)
{
	auto point = _select1->getSelectedPoint();
	point->getPosition(x, y, z);
}

void MeasuringLineLength::getEndPoint(float& x, float& y, float& z)
{
	auto point = _select2->getSelectedPoint();
	point->getPosition(x, y, z);
}

void MeasuringLineLength::updateLineAndLabelPos()
{
	auto start = _select1->getSelectedPoint();
	if (!start)
	{
		std::cerr << "no selection." << std::endl;
		return;
	}
	auto end = _select2->getSelectedPoint();
	if (!end)
	{
		_select2->setPointPosition(start->getPosition());
		end = start;
	}

	_line->setStartPosition(start->getPosition());
	_line->setEndPosition(end->getPosition());

	osg::Vec3 middle;
	if (m_showMethod == LEFT)
	{
		middle = start->getPosition();
	}
	else if (m_showMethod == RIGHT)
	{
		middle = end->getPosition();
	}
	else if (m_showMethod == CENTER)
	{
		middle = start->getPosition() + end->getPosition();
		middle /= 2.0;
	}

	_text->setPosition(middle.x(), middle.y(), middle.z());// <设置文字的坐标>
}
