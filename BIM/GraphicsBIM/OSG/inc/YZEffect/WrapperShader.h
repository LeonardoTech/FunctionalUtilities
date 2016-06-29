#ifndef __WRAPPER_SHADER_H__
#define __WRAPPER_SHADER_H__
#include "IShader.h"
#include <functional>

namespace bimWorld
{
	class YIZHU_EXPORT WrapperShader :public IShader
	{
	public:
		WrapperShader(std::function<void(osg::StateSet* stateSet)> func)
		{
			m_func = func;
		}

		virtual void apply(osg::StateSet* stateSet) override
		{
			m_func(stateSet);
		}
		
		static WrapperShader* create(std::function<void(osg::StateSet* stateSet)> func)
		{
			return new WrapperShader(func);
		}

	protected:
		std::function<void(osg::StateSet* stateSet)> m_func;
	};
}

#endif // __WRAPPER_SHADER_H__
