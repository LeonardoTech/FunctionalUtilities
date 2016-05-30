////////////
//    created by 孙庆号
////////////

#include "ModelCoreFactory.h"
#include "YZModelCoreInternal.h"
#if defined(_WIN32)
#ifdef USING_QT
#include <osgQt/GraphicsWindowQt>
#include "TestModule.h"
std::shared_ptr<bimWorld::IModelCore> bimWorld::ModelCoreFactory::getModule(QWidget* widget)
{
	auto core = std::make_shared<YZModelCoreInternal>();
	core->_ViewerData()->initOSG([widget](osg::GraphicsContext::Traits* traits)
	{
		// do not change window property, just create it.

		traits->width = widget->width();
		traits->height = widget->height();

		osg::ref_ptr<osgQt::GraphicsWindowQt::WindowData> sNewData = new osgQt::GraphicsWindowQt::WindowData((osgQt::GLWidget*)widget);
		traits->inheritedWindowData = sNewData;
	});
	return core;
}
#else
#include <osgViewer/api/Win32/GraphicsWindowWin32>
std::shared_ptr<bimWorld::IModelCore> bimWorld::ModelCoreFactory::getModule(HWND hwnd)
{
	auto core = std::make_shared<YZModelCoreInternal>();
	core->_ViewerData()->initOSG([hwnd](osg::GraphicsContext::Traits* traits)
	{
		// Local Variable to hold window size data
		RECT rect;

		// Get the current window size
		::GetWindowRect(hwnd, &rect);
		// Init the win data Variable that holds the handle for the Window to display OSG in.
		osg::ref_ptr<osg::Referenced> windata = new osgViewer::GraphicsWindowWin32::WindowData(hwnd);
		traits->width = rect.right - rect.left;
		traits->height = rect.bottom - rect.top;
		traits->inheritedWindowData = windata;
	});
	return core;
}
#endif
#elif defined(Android)

std::shared_ptr<bimWorld::IModelCore> bimWorld::ModelCoreFactory::getModule(int x,int y,int width,int height)
{
	auto core = std::make_shared<YZModelCoreInternal>();
	core->_ViewerData()->initOSG(x,y,width, height);
	return core;
}

#endif // _WIN32

std::shared_ptr<bimWorld::ITestModule> bimWorld::ModelCoreFactory::getTestModule(IModelCore* host)
{
	//return NULL;
	auto module = std::make_shared<bimWorld::TestModule>((YZModelCoreInternal*)(host));
	return module;
}
std::shared_ptr<bimWorld::IPlottingScale> bimWorld::ModelCoreFactory::getPlottingScale(IModelCore* host)
{
	auto scale = std::make_shared<bimWorld::PlottingScale>((YZModelCoreInternal*)(host));
	return scale;
}