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
/// @brief <对函数进行概括说明>
///
/// <对函数进行详细说明>
///
///
/// @return <返回值说明，可以配合使用DocGenList或DocGenTable>
///
/// @remark <函数特别说明>
///
/// @code
///      <在此添加示例代码>
/// @endcode
///
/// @sa <可以参考的类或函数，用空格分隔，函数名称后必须加()>
//================================================================================
osg::Geode* HandleControl::getRoot()
{
	return _geode;
}




