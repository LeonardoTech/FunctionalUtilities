////////////
//    created by 孙庆号
////////////

#ifndef __YZ_IEFFECTS_H__
#define __YZ_IEFFECTS_H__
#include "config.h"
#include <memory>
#include "IMaterialSetting.h"
#include "IBasicShader.h"
//#include "ISlice.h"
namespace bimWorld
{
	class YIZHU_EXPORT IEffects
	{
	public:
		virtual std::shared_ptr<bimWorld::IMaterialSetting> MaterialSetting() = 0;
		
		virtual std::shared_ptr<bimWorld::IBasicShader> BasicShader() = 0;

		//virtual std::shared_ptr<bimWorld::ISlice> Slice() = 0;

	};
}

#endif // __YZ_IEFFECTS_H__