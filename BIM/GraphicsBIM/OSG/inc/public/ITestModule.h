////////////
//    created by 孙庆号
////////////

#ifndef __ITEST_MODULE_H__
#define __ITEST_MODULE_H__
#include <string>
#include "config.h"

namespace bimWorld
{

	class YIZHU_EXPORT ITestModule
	{
	public:
		virtual void test() = 0;
	};
}

#endif // __ITEST_MODULE_H__