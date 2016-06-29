////////////
//    created by 孙庆号
////////////

#ifndef __TEST_MODULE_H__
#define __TEST_MODULE_H__
#include "ITestModule.h"
#include "YZModelCoreModule.h"
#include "testHigh.h"
//#include "YZModelCoreInternal.h"


namespace bimWorld
{
	class YIZHU_EXPORT TestModule : public YZModelCoreModule, public ITestModule
	{
	public:

		TestModule(YZModelCoreInternal* host);
		virtual void test() override;

	protected:
		std::string m_string;
		YZModelCoreInternal* m_host;
	};
}

#endif // __TEST_MODULE_H__