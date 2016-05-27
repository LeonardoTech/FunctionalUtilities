

#include "PickHandle.h"
#include <osgViewer/Viewer>


//brief <�Թ��캯�����г�ʼ��.>
//param [in]	selector 	<����һ��Select�����.>
//param [in]	selector1	<����һ��Select�����.>
PickHandler::PickHandler(MeasuringLineLength* selector)
{
	_select = selector;
	_isSelect1Down = false;
	_isSelect2Down = false;
}



//brief	<ͨ���̳� osgGA::GUIEventHandler��������handle�Ĳ��ֹ��ܽ�����д����ʵ����Ҫ������¼�.>
//param	ea	 <����¼�.>
bool PickHandler::handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa)
{
	// <ɸѡ����������ƶ�ʱ�������¼�>
	// <������ƶ�ʱ�����ᷢ��������£���Ҳ����������ƶ�������ͨ����ȡ��ǰ����λ�ã������㣬�����ͻ���ֵ�������>
	if (ea.getEventType() == osgGA::GUIEventAdapter::MOVE)
	{
		osgViewer::View* viewer = dynamic_cast<osgViewer::View*>(&aa);
		if (!_isSelect1Down)
		{
			//_select->setPoint(ea.getX(), ea.getY(),SelectOne);
			_select->setStartPoint(ea.getX(), ea.getY());
		}
		if (!_isSelect2Down)
		{
			//_select->setPoint(ea.getX(), ea.getY(),SelectTwo);
			_select->setEndPoint(ea.getX(), ea.getY());
		}


	}

	// <������������ʱ�������¼���������������ʱ�����е�����£����ǲ�����ֻ���>
	if (ea.getEventType() == osgGA::GUIEventAdapter::PUSH && ea.getEventType() == osgGA::GUIEventAdapter::LEFT_MOUSE_BUTTON)
	{

		osgViewer::View* viewer = dynamic_cast<osgViewer::View*>(&aa);
		bool isExeced = false;
		if (!_isSelect1Down&& !isExeced)
		{
			_isSelect1Down = true;
			_isSelect2Down = false;
			isExeced = true;
			//_select->setPoint(ea.getX(), ea.getY(),SelectOne);
			_select->setStartPoint(ea.getX(), ea.getY());
		}
		if (!_isSelect2Down&&!isExeced)
		{
			isExeced = true;
			_isSelect2Down = true;
			_isSelect1Down = false;
			//_select->setPoint(ea.getX(), ea.getY(),SelectTwo);
			_select->setEndPoint(ea.getX(), ea.getY());
		}
	}
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
	(*colors)[0] = normalColor;

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