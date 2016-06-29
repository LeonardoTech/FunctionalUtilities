////////////
//    created by 孙庆号
////////////

#ifndef __IMODEL_CORE_FACTORY_H__
#define __IMODEL_CORE_FACTORY_H__
#include "IModelCore.h"
#include <memory>
#include "config.h"

#ifdef _WIN32
#ifdef USING_QT
//#include "osgQt/GraphicsWindowQt"
#else
#include <windows.h>
#endif
#endif
#include "ITestModule.h"

namespace bimWorld
{
	class YIZHU_EXPORT IModelCoreFactory
	{
	public:
#ifdef _WIN32
#ifdef USING_QT
		//virtual std::shared_ptr<IModelCore> getModule(int width, int height) = 0;
		virtual std::shared_ptr<IModelCore> getModule(QWidget* widget) = 0;
#else
		virtual std::shared_ptr<IModelCore> getModule(HWND hwnd) = 0;
#endif
#else
		virtual std::shared_ptr<IModelCore> getModule(int x,int y,int width,int height) = 0;
#endif // _WIN32

		virtual std::shared_ptr<ITestModule> getTestModule(IModelCore* host) = 0;
		virtual std::shared_ptr<IPlottingScale>getPlottingScale(IModelCore* host) = 0;

	protected:
	};
}
#endif // __IMODEL_CORE_FACTORY_H__