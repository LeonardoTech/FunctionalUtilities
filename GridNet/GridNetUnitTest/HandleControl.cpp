#include "HandleControl.h"
#include <osgViewer/Viewer>

HandleControl::HandleControl(GridNet*grid)
{
	_grid = grid;
	num = 1.0;
	_geode = _grid->createCircle(num);
}

bool HandleControl::handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa)
{
	osgViewer::Viewer* viewer = dynamic_cast<osgViewer::Viewer*>(&aa);

	if (ea.getButton() == osgGA::GUIEventAdapter::LEFT_MOUSE_BUTTON || ea.getButton() == osgGA::GUIEventAdapter::PUSH)
	{
		int x = ea.getX();
		int y = ea.getY();

		num += 0.1;
		_geode = _grid->createCircle(num);
		viewer->setSceneData(_geode);
		return false;
	}

	return false;


}

//============================HandleControl::getRoot()============================
/// @brief <�Ժ������и���˵��>
///
/// <�Ժ���������ϸ˵��>
///
///
/// @return <����ֵ˵�����������ʹ��DocGenList��DocGenTable>
///
/// @remark <�����ر�˵��>
///
/// @code
///      <�ڴ����ʾ������>
/// @endcode
///
/// @sa <���Բο�����������ÿո�ָ����������ƺ�����()>
//================================================================================
osg::Geode* HandleControl::getRoot()
{
	return _geode;
}




