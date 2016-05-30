////////////
//    created by 孙庆号
////////////

#ifndef __VECTOR_EXT_H__
#define __VECTOR_EXT_H__

#include <vector>
#include "config.h"
#include <functional>

namespace util
{
	//================================VectorExtension===============================
	/// @brief <矢量扩展类>
	///
	/// <矢量扩展类>
	//================================================================================
	class YIZHU_EXPORT VectorExtension
	{
	public:
		template< class T >
		static bool contains(const std::vector<T>& This, T value)
		{
			for (auto iter = This.begin(); iter != This.end(); iter++)
			{
				if (*iter == value)
					return true;
			}
			return false;
		}

		template< class T >
		static bool contains(const std::vector<T>& This, std::function<bool(T)> condition)
		{
			for (auto iter = This.begin(); iter != This.end(); iter++)
			{
				if (condition(*iter))
					return true;
			}
			return false;
		}
	protected:
	};
}

#endif // __VECTOR_EXT_H__