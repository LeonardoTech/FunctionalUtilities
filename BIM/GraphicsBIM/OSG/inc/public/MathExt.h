////////////
//    created by 孙庆号
////////////

#ifndef __MATH_EXTENSION_H__
#define __MATH_EXTENSION_H__
#include "config.h"

namespace util
{

	//=================================MathExtension================================
	/// @brief <数学扩展类>
	///
	/// <数学扩展类>
	//================================================================================
	class YIZHU_EXPORT MathExtension
	{
	public:



#pragma region PositivePow

		//=================================positivePow()================================
		/// @brief <幂运算>
		///
		/// <返回值为short的幂运算>
		///
		/// @param [in] base <底数>
		/// @param [in] exponent <指数>
		///
		/// @return <运算结果>
		//================================================================================
		static short positivePow(short base, short exponent);

		//=================================positivePow()================================
		/// @brief <幂运算>
		///
		/// <返回值为int的幂运算>
		///
		/// @param [in] base <底数>
		/// @param [out] exponent <指数>
		///
		/// @return <运算结果>
		//================================================================================
		static int positivePow(int base, int exponent);

		//=================================positivePow()================================
		/// @brief <对函数进行概括说明>
		///
		/// <返回值为long的幂运算>
		///
		/// @param [in, out] base <底数>
		/// @param [in, out] exponent <指数>
		///
		/// @return <返回值为long的幂运算>
		//================================================================================
		static long positivePow(long base, long exponent);

#pragma endregion

	};
}
#endif // __MATH_EXTENSION_H__