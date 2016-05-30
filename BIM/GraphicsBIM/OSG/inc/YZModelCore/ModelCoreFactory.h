////////////
//    created by 孙庆号
////////////

#ifndef __MODEL_CORE_FACTORY_H__
#define __MODEL_CORE_FACTORY_H__
#include "IModelCore.h"
#include "IModelCoreFactory.h"
#ifdef USING_QT
//#include "osgQt/GraphicsWindowQt"
#endif

namespace bimWorld
{
	class YIZHU_EXPORT ModelCoreFactory :public IModelCoreFactory
	{
	public:
#ifdef _WIN32
#ifdef USING_QT
		//std::shared_ptr<IModelCore> getModule(int width, int height) override;
		std::shared_ptr<IModelCore> getModule(QWidget* widget) override;
#else
		std::shared_ptr<IModelCore> getModule(HWND hwnd) override;
#endif
#else
		std::shared_ptr<IModelCore> getModule(int x,int y,int width,int height) override;
#endif // _WIN32

		std::shared_ptr<ITestModule> getTestModule(IModelCore* host) override;
		std::shared_ptr<IPlottingScale>getPlottingScale(IModelCore* host)override;
	protected:
	private:
	};
}
#endif // __MODEL_CORE_FACTORY_H__