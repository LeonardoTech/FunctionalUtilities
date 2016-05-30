////////////
//    created by 孙庆号
////////////

#ifndef __I_EVENT_H__
#define __I_EVENT_H__
#include <functional>
#include "InstanceFunction.h"

namespace core
{

	template<class _Func>
	class IEvent
	{
	public:
		typedef InstanceFunction<_Func> EventType;
		typedef std::function<_Func> EventBaseType;
		EventBaseType _eventType;

		//==================================operator+=()==================================
		/// @brief <+运算符重载>
		///
		/// <重载+运算符，以实现InstanceFunction类对+符号操作的支持>
		///
		/// @param [in, out] func <参数说明，[in, out]表示参数的传递方向，需要根据情况进行选择>
		///
		/// @return <void>
		//================================================================================
		virtual void operator+=(EventType& func) = 0;

		//==================================operator-=()==================================
		/// @brief <-运算符重载>
		///
		/// <重载-运算符，以实现InstanceFunction类对-符号操作的支持>
		///
		/// @param [in, out] func <参数说明，[in, out]表示参数的传递方向，需要根据情况进行选择>
		///
		/// @return <void>
		//================================================================================
		virtual void operator-=(FunctionKey& func) = 0;

		virtual void for_each(std::function<void(EventBaseType)> func) = 0;

#define core_Event_Trigger(_event, ...) _event.for_each([&](decltype(_event._eventType) callback){callback(__VA_ARGS__);})

	};

}
#endif __I_EVENT_H__