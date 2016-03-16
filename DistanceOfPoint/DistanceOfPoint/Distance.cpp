#include "Distance.h"

Distance::Distance(Selector *select1,Selector *select2)
{
	_select1 = select1;
	_select2 = select2;
	_camera = _select1->getCamera();
	_isSelect1Down = false;
	_isSelect2Down = false;
}


bool Distance::setPoint(float x, float y, Num num)
{
	if (num == SelectOne)
	_select1->drawbyCoordinate(x, y,_camera);
	else if (num == SelectTwo)
	{
		_select2->drawbyCoordinate(x,y,_camera);
	}
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

	return true;
}



//brief	<创建文本，没有制定位置和内容.>
osgText::Text * Distance::createText()
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


// brief	<创建线，没有设置顶点的坐标>
osg::Geode* Distance::createLine()
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



// fn	void PickHandler::setRoot(osg::Group* node)
// 
// brief	 <将所有的图形都放进root组里>
void Distance::setRoot(osg::Group* node)
{
	_root = node;
	_root->addChild(_select2->createSelector());
	_root->addChild(_select1->createSelector());
	_root->addChild(createLine());
	_root->addChild(createText());
}

