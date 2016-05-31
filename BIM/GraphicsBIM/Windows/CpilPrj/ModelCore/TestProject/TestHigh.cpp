#include "testHigh.h"
#include "YZModelCoreInternal.h"

bimWorld::TestHigh::TestHigh(bimWorld::YZModelCoreInternal* viewer)
{
	if (viewer==nullptr)
	{
		return;
	}
	m_viewer = viewer;
	core::InstanceFunction<void(bimWorld::IPlottingScale*)> func([this](bimWorld::IPlottingScale* scale){
		_scale = scale->getScale();
		if (_scale>1)
		{
			return;
		}
		if (_scale <  0.002)
		{
			m_viewer->NodeControl()->highlight(m_viewer->ViewerData()->getModelRoot());
		}
	}, this, "TestHigh");
	m_viewer->PlottingScales()->scaleChanged() += func;
}
