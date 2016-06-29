////////////
//    created by 孙庆号
////////////

#ifndef __CHAR_EXTENSION_H__
#define __CHAR_EXTENSION_H__
#include "config.h"

namespace util
{

	//=================================CharExtension================================
	/// @brief <字符扩展类>
	///
	/// <字符扩展类>
	//================================================================================
	class YIZHU_EXPORT CharExtension
	{

	public:

#pragma region ToValue

#pragma region char

		//===================================toShort()==================================
		/// @brief <数据类型转换>
		///
		/// <将char类型数据转换为short类型数据>
		///
		/// @param [in] srcChar <需要被转换的数据>
		/// @param [out] outShort <传出存储转换完成后的数据>
		///
		/// @return <返回值为True说明转换成功， 否则失败。>
		//================================================================================
		static bool toShort(char srcChar, short& outShort);

		//====================================toInt()===================================
		/// @brief <数据类型转换>
		///
		/// <将char类型数据转换为int类型数据>
		///
		/// @param [in] srcChar <需要被转换的数据>
		/// @param [out] outInt <传出存储转换完成后的数据>
		///
		/// @return <返回值为True说明转换成功， 否则失败。>
		//================================================================================
		static bool toInt(char srcChar, int& outInt);

		//====================================toLong()====================================
		/// @brief <数据类型转换>
		///
		/// <将char类型数据转换为long类型数据>
		///
		/// @param [in] srcChar <需要被转换的数据>
		/// @param [out] outLong <传出存储转换完成后的数据>
		///
		/// @return <返回值为True说明转换成功， 否则失败。>
		//================================================================================
		static bool toLong(char srcChar, long& outLong);

#pragma endregion

#pragma region wchar_t

		//===================================toShort()==================================
		/// @brief <数据类型转换>
		///
		/// <将wchar_t数据转换为short数据>
		///
		/// @param [in] srcChar <需要被转换的数据>
		/// @param [out] outShort <传出存储转换完成后的数据>
		///
		/// @return <返回值为True说明转换成功， 否则失败。>
		//================================================================================
		static bool toShort(wchar_t srcChar, short& outShort);

		//====================================toInt()===================================
		/// @brief <数据类型转换>
		///
		/// <将wchar_t数据转换为int数据>
		///
		/// @param [in] srcChar <需要被转换的数据>
		/// @param [out] outInt <传出存储转换完成后的数据>
		///
		/// @return <返回值为True说明转换成功， 否则失败。>
		//================================================================================
		static bool toInt(wchar_t srcChar, int& outInt);

		//====================================toLong()====================================
		/// @brief <数据类型转换>
		///
		/// <将wchar_t数据转换为int数据>
		///
		/// @param [in] srcChar <需要被转换的数据>
		/// @param [out] outLong <传出存储转换完成后的数据>
		///
		/// @return <返回值为True说明转换成功， 否则失败。>
		//================================================================================
		static bool toLong(wchar_t srcChar, long& outLong);

#pragma endregion


#pragma endregion

	};
}
#endif // __CHAR_EXTENSION_H__