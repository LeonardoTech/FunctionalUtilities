#ifndef __YZAXISGRID_H__
#define __YZAXISGRID_H__
/*
ÖáÍø
*/
#include "YZProduct.h"

#define VESRION_AXISGRID 1

namespace YZ
{
	class MODEL_API AxisGrid : public Product
	{
	public:
		friend class ComponentMgr;

		//virtual void presync(void);
		//virtual void sync(void);
		//virtual void unsync(void);

		AxisGrid();
		AxisGrid(const std::string& id, CategoryType type);
		virtual ~AxisGrid(void);

	protected:
	};
}
#endif