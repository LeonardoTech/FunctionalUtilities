#include "PickHandler.h"
#include <osgViewer/Viewer>

/// @fn	PickHandler::PickHandler(Selector* selector, Selector *selector1)
///
/// @brief <	�Թ��캯�����г�ʼ��.>
///
/// @author	Admin
/// @date	2016/3/14
///
/// @param [in]	selector 	<����һ��Select�����.>
/// @param [in]	selector1	<����һ��Select�����.>
PickHandler::PickHandler(Selector* selector, Selector *selector1)
{
	_axis1 = { 0, 0, 0 };
	_axis2 = { 0, 0, 0 };
	_select2 = selector;
	_select1 = selector1;
	_isSelect1Down = false;
	_isSelect2Down = false;
}

/// @fn	osgText::Text * PickHandler::createText()
///
/// @brief	<�����ı���û���ƶ�λ�ú�����.>
///
/// @author	Admin
/// @date	2016/3/14
///
/// @return	null if it fails, else the new text.
osgText::Text * PickHandler::createText()
{
	osg::ref_ptr<osgText::Font> g_font = osgText::readFontFile("fonts/arial.ttf");
	_text = new osgText::Text;
	_text->setFont(g_font.get());
	_text->setCharacterSize(40);
	_text->setCharacterSizeMode(osgText::Text::SCREEN_COORDS);//�����ֵĴ�С������ͼ�� �ķŴ���С���ı䣬���ԾͰ�������ʾ����Ļ�����ĸ�ʽ
	_text->setAxisAlignment(osgText::Text::SCREEN); //����ʼ�ձ��ִ�ֱ����Ļ����������ͼ�ε���ת����ת
	_text->setDataVariance(osg::Object::DYNAMIC);  //��Ϊ�����ڱ䶯������������������óɶ�̬��

	return _text;
}

/// @fn	bool PickHandler::handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa)
///
/// @brief	ͨ���̳� osgGA::GUIEventHandler��������handle�Ĳ��ֹ��ܽ�����д����ʵ����Ҫ������¼�.
///
/// @author	Admin
/// @date	2016/3/14
///
/// @param	ea	 ����¼�.
/// @param	aa	The aa.
///
/// @return	true if it succeeds, false if it fails.
bool PickHandler::handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa)
{
	///ɸѡ����������ƶ�ʱ�������¼�
	///������ƶ�ʱ�����ᷢ��������£���Ҳ����������ƶ�������ͨ����ȡ��ǰ����λ�ã������㣬�����ͻ���ֵ�������
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

		///����vec3Array����߶����������Ϣ
		osg::Vec3Array* selPosition = dynamic_cast<osg::Vec3Array*>(_geometry->getVertexArray());
		(*selPosition)[0] = _select1->getPosition();
		(*selPosition)[1] = _select2->getPosition();
		auto middle = (*selPosition)[0] + (*selPosition)[1];
		middle /= 2.0;

		float length = ((*selPosition)[1] - (*selPosition)[0]).length();
		stringstream ss;
		ss << length;
			
		_text->setText(ss.str()); ///�������ֵ�����
		_text->setPosition(middle);///�������ֵ�����
		_text->dirtyBound();
		selPosition->dirty();
		_geometry->dirtyBound();
	}

	///������������ʱ�������¼���������������ʱ�����е�����£����ǲ�����ֻ���
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


/// @fn	void PickHandler::setRoot(osg::Group* node)
///
/// @brief	 �����е�ͼ�ζ��Ž�root����
///
/// @author	Admin
/// @date	2016/3/14
///
/// @param [in] 
void PickHandler::setRoot(osg::Group* node)
{
	_root = node;
	_root->addChild(_select2->createSelector());
	_root->addChild(_select1->createSelector());
	_root->addChild(createLine());
	_root->addChild(createText());
}

/// @fn	osg::Geode* PickHandler::createLine()
///
/// @brief	�����ߣ�û�����ö��������
///
/// @author	Admin
/// @date	2016/3/14
///
/// @return	null if it fails, else the new line.
osg::Geode* PickHandler::createLine()
{
	osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array(1);
	(*colors)[0] = selectedColor;

	_geometry = new osg::Geometry;
	_geometry->setDataVariance(osg::Object::DYNAMIC);
	_geometry->setUseDisplayList(false);
	_geometry->setUseVertexBufferObjects(true);
	_geometry->setVertexArray(new osg::Vec3Array(2)); ///���õ�����꣬������ߵĻ������ͱ�����2��2�����㣩
	_geometry->setColorArray(colors.get());
	_geometry->setColorBinding(osg::Geometry::BIND_OVERALL);
	_geometry->addPrimitiveSet(new osg::DrawArrays(GL_LINES, 0, 2)); ///ע�⣬��Ҫʹ��GL_LINE�滻GL_LINES��Ϊ����

	osg::ref_ptr<osg::Geode> geode = new osg::Geode;
	geode->addDrawable(_geometry);
	geode->getOrCreateStateSet()->setAttributeAndModes(new osg::Point(10.0f));
	geode->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::OFF);
	geode->getOrCreateStateSet()->setMode(GL_BLEND, osg::StateAttribute::ON);
	geode->getOrCreateStateSet()->setRenderingHint(osg::StateSet::TRANSPARENT_BIN);
	return geode.release();
}

