#include "PickHandle.h"
#include <osgViewer/Viewer>


//brief <对构造函数进行初始化.>
//param [in]	selector 	<创建一个Select类对象.>
//param [in]	selector1	<创建一个Select类对象.>
PickHandler::PickHandler(osg::Group* root, MeasuringLineLength* selector)
{
	_select = selector;
	_isSelect1Down = false;
	_isSelect2Down = false;
	_root = root;

	_root->addChild(_select->getRoot());
}

osg::Group* PickHandler::getRoot()
{
	return _root;
}


//brief	<通过继承 osgGA::GUIEventHandler的类来对handle的部分功能进行重写，以实现想要的鼠标事件.>
//param	ea	 <鼠标事件.>
bool PickHandler::handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa)
{

	osgViewer::View* viewer = dynamic_cast<osgViewer::View*>(&aa);
	osg::ref_ptr<osg::Camera>camera = viewer->getCamera();
	if (_isSelect2Down)
	{
		//return false;
	}
	// <筛选出当鼠标在移动时发生的事件>
	// <鼠标在移动时，不会发生点的落下，点也会随着鼠标移动，可以通过获取当前鼠标的位置，画出点，这样就会出现点跟随鼠标>
	if (ea.getEventType() == osgGA::GUIEventAdapter::MOVE)
	{
		//MeasuringLineLength* _select = new MeasuringLineLength(camera);

		osgViewer::View* viewer = dynamic_cast<osgViewer::View*>(&aa);
		if (!_isSelect1Down && !_isSelect2Down)
		{
			_select->setStartPoint(ea.getX(), ea.getY());	
			_select->setEndPoint(ea.getX(), ea.getY());
		}
		//if (!_isSelect1Down && !_isSelect2Down)
		//{
		//	_select->setStartPoint(ea.getX(), ea.getY());
		//}
		if (!_isSelect2Down)
		{
			_select->setEndPoint(ea.getX(), ea.getY());
		}
	}

	// <当鼠标左键单击时触发的事件，当鼠标左键单击时，会有点的落下，但是不会出现画线>
	if (ea.getEventType() == osgGA::GUIEventAdapter::PUSH && ea.getEventType() == osgGA::GUIEventAdapter::LEFT_MOUSE_BUTTON)
	{
		osgViewer::View* viewer = dynamic_cast<osgViewer::View*>(&aa);
		bool isExeced = false;
		if (!_isSelect1Down&& !isExeced)
		{
			_isSelect1Down = true;
			isExeced = true;
			_select->setStartPoint(ea.getX(), ea.getY());
		}
		if (!_isSelect2Down&&!isExeced)
		{
			isExeced = true;
			_isSelect2Down = true;
			_select->setEndPoint(ea.getX(), ea.getY());
			_lineVector.push_back(_select);

			MeasuringLineLength* newSelect = new MeasuringLineLength(camera);
			_select = newSelect;
			_root->addChild(_select->getRoot());

			_isSelect1Down = false;
			_isSelect2Down = false;
		}

	}
	auto dist = _select->getDistance();
	std::stringstream ss;
	ss << dist;
	_select->setLabelText(ss.str(), Alignments::Center);

	return false;
}

osg::Geometry* createSimpleGeometry()
{
	osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array(8);
	(*vertices)[0].set(-0.5f, -0.5f, -0.5f);
	(*vertices)[1].set(0.5f, -0.5f, -0.5f);
	(*vertices)[2].set(0.5f, 0.5f, -0.5f);
	(*vertices)[3].set(-0.5f, 0.5f, -0.5f);
	(*vertices)[4].set(-0.5f, -0.5f, 0.5f);
	(*vertices)[5].set(0.5f, -0.5f, 0.5f);
	(*vertices)[6].set(0.5f, 0.5f, 0.5f);
	(*vertices)[7].set(-0.5f, 0.5f, 0.5f);

	osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array(1);
	(*colors)[0] = osg::Vec4{1.0f,1.0f,1.0f,1.0f};

	osg::ref_ptr<osg::DrawElementsUInt> indices = new osg::DrawElementsUInt(GL_QUADS, 24);
	(*indices)[0] = 0; (*indices)[1] = 1; (*indices)[2] = 2; (*indices)[3] = 3;
	(*indices)[4] = 4; (*indices)[5] = 5; (*indices)[6] = 6; (*indices)[7] = 7;
	(*indices)[8] = 0; (*indices)[9] = 1; (*indices)[10] = 5; (*indices)[11] = 4;
	(*indices)[12] = 1; (*indices)[13] = 2; (*indices)[14] = 6; (*indices)[15] = 5;
	(*indices)[16] = 2; (*indices)[17] = 3; (*indices)[18] = 7; (*indices)[19] = 6;
	(*indices)[20] = 3; (*indices)[21] = 0; (*indices)[22] = 4; (*indices)[23] = 7;

	osg::ref_ptr<osg::Geometry> geom = new osg::Geometry;
	geom->setDataVariance(osg::Object::DYNAMIC);
	geom->setUseDisplayList(false);
	geom->setUseVertexBufferObjects(true);
	geom->setVertexArray(vertices.get());
	geom->setColorArray(colors.get());
	geom->setColorBinding(osg::Geometry::BIND_OVERALL);
	geom->addPrimitiveSet(indices.get());

	osgUtil::SmoothingVisitor::smooth(*geom);
	return geom.release();
}







