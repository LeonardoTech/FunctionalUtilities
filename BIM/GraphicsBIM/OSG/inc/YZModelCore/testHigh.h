#ifndef TESTHIGH_H
#define TESTHIGH_H
#include <vector>
#include "YZModelCoreModule.h"
//#include "D:\\WorkSpace\\BIM\\GraphicsBIM\\OSG\\inc\\YZModelCore\\YZModelCoreModule.h"

namespace bimWorld
{
	class TestHigh
	{
	public:
		TestHigh(YZModelCoreInternal* viewer);

	private:
		YZModelCoreInternal* m_viewer;
		double _scale = 1.0;
	};

}

#endif // TESTHIGH_H
