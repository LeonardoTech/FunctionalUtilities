#include "PickHandler.h"
#include <osgViewer/Viewer>


//brief <对构造函数进行初始化.>
//param [in]	selector 	<创建一个Select类对象.>
//param [in]	selector1	<创建一个Select类对象.>
PickHandler::PickHandler(Selector* selector, Selector *selector1)
{
	_axis1 = { 0, 0, 0 };
	_axis2 = { 0, 0, 0 };
	_select2 = selector;
	_select1 = selector1;
	_isSelect1Down = false;
	_isSelect2Down = false;
}


//brief	<创建文本，没有制定位置和内容.>
osgText::Text * PickHandler::createText()
{
	osg::ref_ptr<osgText::Font> g_font = osgText::readFontFile("fonts/arial.ttf");
	_text = new osgText::Text;
	_text->setFont(g_font.get());
	_text->setCharacterSize(40);
	_text->setCharacterSizeMode(osgText::Text::SCREEN_COORDS);// <让文字的大小不随着图形 的放大缩小而改变，所以就把文字显示成屏幕像数的格式>
	_text->setAxisAlignment(osgText::Text::SCREEN); // <文字始终保持垂直于屏幕，不会随着图形的旋转而旋转>
	_text->setDataVariance(osg::Object::DYNAMIC);  // <因为数字在变动，所以这里最好是设置成动态的>

	return _text;
}

//brief	<通过继承 osgGA::GUIEventHandler的类来对handle的部分功能进行重写，以实现想要的鼠标事件.>
//param	ea	 <鼠标事件.>
bool PickHandler::handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa)
{
	// <筛选出当鼠标在移动时发生的事件>
	// <鼠标在移动时，不会发生点的落下，点也会随着鼠标移动，可以通过获取当前鼠标的位置，画出点，这样就会出现点跟随鼠标>
	if (ea.getEventType() == osgGA::GUIEventAdapter::MOVE)
	{
		osgViewer::View* viewer = dynamic_cast<osgViewer::View*>(&aa);
		if (!_isSelect1Down)
		{
			_select1->drawbyCoordinate(ea.getX(), ea.getY(), viewer->getCamera());
		}
		if (!_isSelect2Down)
		{
			_select2->drawbyCoordinate(ea.getX(), ea.getY(), viewer->getCamera());
		}

		// <利用vec3Array存放线顶点的坐标信息>
		osg::Vec3Array* selPosition = dynamic_cast<osg::Vec3Array*>(_geometry->getVertexArray());
		(*selPosition)[0] = _select1->getPosition();
		(*selPosition)[1] = _select2->getPosition();
		auto middle = (*selPosition)[0] + (*selPosition)[1];
		middle /= 2.0;

		float length = ((*selPosition)[1] - (*selPosition)[0]).length();
		stringstream ss;
		ss << length;
			
		_text->setText(ss.str()); // <设置文字的内容>
		_text->setPosition(middle);// <设置文字的坐标>
		_text->dirtyBound();
		selPosition->dirty();
		_geometry->dirtyBound();
	}

	// <当鼠标左键单击时触发的事件，当鼠标左键单击时，会有点的落下，但是不会出现画线>
	if (ea.getEventType() == osgGA::GUIEventAdapter::PUSH && ea.getEventType() == osgGA::GUIEventAdapter::LEFT_MOUSE_BUTTON)
	{

		osgViewer::View* viewer = dynamic_cast<osgViewer::View*>(&aa);
		bool isExeced = false;
		if (!_isSelect1Down&& !isExeced)
		{
			_isSelect1Down = true;
			_isSelect2Down = false;
			isExeced = true;
			_select1->drawbyCoordinate(ea.getX(), ea.getY(), viewer->getCamera());
		}
		if (!_isSelect2Down&&!isExeced)
		{
			isExeced = true;
			_isSelect2Down = true;
			_isSelect1Down = false;
			_select2->drawbyCoordinate(ea.getX(), ea.getY(), viewer->getCamera());
		}
	}
	return false;
}


// fn	void PickHandler::setRoot(osg::Group* node)
// 
// brief	 <将所有的图形都放进root组里>
void PickHandler::setRoot(osg::Group* node)
{
	_root = node;
	_root->addChild(_select2->createSelector());
	_root->addChild(_select1->createSelector());
	_root->addChild(createLine());
	_root->addChild(createText());
}

// brief	<创建线，没有设置顶点的坐标>
osg::Geode* PickHandler::createLine()
{
	osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array(1);
	(*colors)[0] = selectedColor;

	_geometry = new osg::Geometry;
	_geometry->setDataVariance(osg::Object::DYNAMIC);
	_geometry->setUseDisplayList(false);
	_geometry->setUseVertexBufferObjects(true);
	_geometry->setVertexArray(new osg::Vec3Array(2)); // <设置点的坐标，如果是线的话参数就必须是2（2个顶点）>
	_geometry->setColorArray(colors.get());
	_geometry->setColorBinding(osg::Geometry::BIND_OVERALL);
	_geometry->addPrimitiveSet(new osg::DrawArrays(GL_LINES, 0, 2)); // <注意，不要使用GL_LINE替换GL_LINES作为参数>

	osg::ref_ptr<osg::Geode> geode = new osg::Geode;
	geode->addDrawable(_geometry);
	geode->getOrCreateStateSet()->setAttributeAndModes(new osg::Point(10.0f));
	geode->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::OFF);
	geode->getOrCreateStateSet()->setMode(GL_BLEND, osg::StateAttribute::ON);
	geode->getOrCreateStateSet()->setRenderingHint(osg::StateSet::TRANSPARENT_BIN);
	return geode.release();
}

