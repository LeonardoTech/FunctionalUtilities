////////////
//    created by 孙庆号
////////////

#ifndef __INSTANCE_FUNCTION_H__
#define __INSTANCE_FUNCTION_H__
#include <functional>
#include <sstream>
#include "config.h"

namespace core
{
	class YIZHU_EXPORT FunctionKey
	{
	public:
		FunctionKey(void* instance, const std::string& funcName)
		{
			m_instance = instance;
			m_funcName = funcName;
		}

		FunctionKey(const FunctionKey& src)
		{
			m_instance = src.m_instance;
			m_funcName = src.m_funcName;
		}

		std::string getKey() const
		{
			long address = (long)m_instance;
			std::ostringstream ostr;
			ostr << m_funcName << address;
			return ostr.str();
		}

		void* getInstance() const
		{
			return m_instance;
		}

		std::string getFuncName() const
		{
			return m_funcName;
		}

	protected:
		std::string m_funcName;
		void* m_instance;
	};

	template<class _Fty>
	class YIZHU_EXPORT InstanceFunction :public FunctionKey
	{
	public:
		InstanceFunction(std::function < _Fty > origin, void* instance, const std::string& funcName):
			m_originFunc(origin),
			FunctionKey(instance, funcName)
		{
		}

		InstanceFunction(const InstanceFunction& src) :
			m_originFunc(src.m_originFunc),
			FunctionKey(src)
		{
		}

		bool operator==(const InstanceFunction& target)
		{
			return this->getKey() == target.getKey();
		}

		std::function < _Fty > getFunc()
		{
			return m_originFunc;
		}

	protected:
		std::function < _Fty > m_originFunc;
	};
}
#endif // __INSTANCE_FUNCTION_H__