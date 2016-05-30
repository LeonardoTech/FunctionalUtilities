////////////
//    created by 孙庆号
////////////

#ifndef __STRING_EXTENSION_H__
#define __STRING_EXTENSION_H__

#include <vector>
#include <string>
#include <sstream>
//#include <math.h>
#include <algorithm>
#include "config.h"

namespace util
{

	//================================StringExtension===============================
	/// @brief <字符串功能扩展>
	///
	/// <字符串功能扩展>
	//================================================================================
	class YIZHU_EXPORT StringExtension
	{
	public:

#pragma region Split

		//====================================split()===================================
		/// @brief <字符串分割>
		///
		/// <字符串分割>
		///
		/// @param [in] srcStr <待分割字符串>
		/// @param [in] splitStr <字符串分割符>
		/// @param [out] outResult <传出操作后的字符串>
		///
		/// @return <如操作成功返回True,否则返回False>
		//================================================================================
		static bool split(const std::string& srcStr, const std::string splitStr, std::vector< std::string >& outResult);

		//====================================split()===================================
		/// @brief <字符串分割>
		///
		/// <字符串分割>
		///
		/// @param [in] srcStr <待分割字符串>
		/// @param [in] splitStr <字符串分割符>
		/// @param [out] outResult <传出操作后的字符串>
		///
		/// @return <如操作成功返回True,否则返回False>
		//================================================================================
		static bool split(const std::wstring& srcStr, const std::wstring splitStr, std::vector< std::wstring >& outResult);

		//====================================split()===================================
		/// @brief <字符串划分>
		///
		/// <字符串分割>
		///
		/// @param [in] srcStr <待分割字符串>
		/// @param [in] splitStrs <字符串分割符>
		/// @param [in] splitLength <字符串分割符长度>
		/// @param [out] outResult <传出操作后的字符串>
		///
		/// @return <如操作成功返回True,否则返回False>
		//================================================================================
		static bool split(const std::string& srcStr, const std::string *splitStrs, int splitLength, std::vector< std::string >& outResult);

		//====================================split()===================================
		/// @brief <字符串划分>
		///
		/// <字符串分割>
		///
		/// @param [in] srcStr <待分割字符串>
		/// @param [in] splitStrs <字符串分割符>
		/// @param [in] splitLength <字符串分割符长度>
		/// @param [out] outResult <传出操作后的字符串>
		///
		/// @return <如操作成功返回True,否则返回False>
		//================================================================================
		static bool split(const std::wstring& srcStr, const std::wstring *splitStrs, int splitLength, std::vector< std::wstring >& outResult);

#pragma endregion

#pragma region ParseToValue

#pragma region std::string

		//=================================parseToShort()=================================
		/// @brief <将字符串转换为Short>
		///
		/// <将字符串转换为Short>
		///
		/// @param [in] srcStr <需要被转换的数据>
		/// @param [out] outInt <传出转换后的数据>
		///
		/// @return <如转换成功返回True,否则返回False>
		//================================================================================
		static bool parseToShort(const std::string& srcStr, short& outInt);

		//==================================parseToInt()==================================
		/// @brief <将字符串转换为Int>
		///
		/// <将字符串转换为Int>
		///
		/// @param [in] srcStr <需要被转换的数据>
		/// @param [out] outInt <传出转换后的数据>
		///
		/// @return <如转换成功返回True,否则返回False>
		//================================================================================
		static bool parseToInt(const std::string& srcStr, int& outInt);

		//=================================parseToLong()================================
		/// @brief <将字符串转换为Long>
		///
		/// <将字符串转换为Long>
		///
		/// @param [in] srcStr <需要被转换的数据>
		/// @param [out] outLong <传出转换后的数据>
		///
		/// @return <如转换成功返回True,否则返回False>
		//================================================================================
		static bool parseToLong(const std::string& srcStr, long& outLong);

#pragma endregion


#pragma region std::wstring

		//=================================parseToShort()=================================
		/// @brief <将字符串转换为short>
		///
		/// <将std::wstring类型字符串转换为short>
		///
		/// @param [in] srcStr <需要被转换的数据>
		/// @param [out] outInt <传出转换后的数据>
		///
		/// @return <如转换成功返回True,否则返回False>
		//================================================================================
		static bool parseToShort(const std::wstring& srcStr, short& outInt);

		//==================================parseToInt()==================================
		/// @brief <将字符串转换为Int>
		///
		/// <将std::wstring类型字符串转换为short>
		///
		/// @param [in] srcStr <需要被转换的数据>
		/// @param [out] outInt <传出转换后的数据>
		///
		/// @return <如转换成功返回True,否则返回False>
		//================================================================================
		static bool parseToInt(const std::wstring& srcStr, int& outInt);

		//=================================parseToLong()================================
		/// @brief <将字符串转换为Long>
		///
		/// <将std::wstring类型字符串转换为short>
		///
		/// @param [in] srcStr <需要被转换的数据>
		/// @param [out] outLong <传出转换后的数据>
		///
		/// @return <如转换成功返回True,否则返回False>
		//================================================================================
		static bool parseToLong(const std::wstring& srcStr, long& outLong);

#pragma endregion

#pragma endregion

#pragma region ParseToVector

#pragma region std::string

		//==============================parseToShortVector()==============================
		/// @brief <将字符串提取出short类型的数组>
		///
		/// <将std::string型字符串提取出short类型的数组>
		///
		/// @param [in] srcStr <待提取字符串>
		/// @param [out] outVector <提取后待传出数组>
		/// @param [in] splitter <字符串分割符>
		///
		/// @return <如转换成功返回True,否则返回False>
		//================================================================================
		static bool parseToShortVector(const std::string& srcStr, std::vector<short>& outVector, const char* splitter);

		//===============================parseToIntVector()===============================
		/// @brief <将字符串提取出int类型的数组>
		///
		/// <将std::string型字符串提取提取出int类型的数组>
		///
		/// @param [in] srcStr <待提取字符串>
		/// @param [out] outVector <提取后待传出数组>
		/// @param [in] splitter <字符串分割符>
		///
		/// @return <如转换成功返回True,否则返回False>
		//================================================================================
		static bool parseToIntVector(const std::string& srcStr, std::vector<int>& outVector, const char* splitter);

		//==============================parseToLongVector()=============================
		/// @brief <将字符串提出long类型的数组>
		///
		/// <将std::string型字符串提取出long类型的数组>
		///
		/// @param [in] srcStr <待提取字符串>
		/// @param [out] outVector <提取后待传出数组>
		/// @param [in] splitter <字符串分割符>
		///
		/// @return <如转换成功返回True,否则返回False>
		//================================================================================
		static bool parseToLongVector(const std::string& srcStr, std::vector<long>& outVector, const char* splitter);

		//================================parseToVector()===============================
		/// @brief <在字符串中提取数据信息>
		///
		/// <在std::string型字符串中提取数据信息>
		///
		/// @param [in] idsStr <待分提取符串>
		/// @param [out] idset <提取后待传出数组>
		/// @param [in] splitter <字符串分割符>
		///
		/// @return <如转换成功返回True,否则返回False>

		//================================================================================
		static bool parseToVector(const std::string& idsStr, std::vector<std::string>& idset, const char* splitter);

#pragma endregion

#pragma region std::wstring

		//==============================parseToShortVector()==============================
		/// @brief <将字符串提取出short型数组>
		///
		/// <将std::wstring型字符串提取出short型数组>
		///
		/// @param [in] srcStr <待提取字符串>
		/// @param [out] outVector <字符串提取出的数组>
		/// @param [in] splitter <字符串分割符>
		///
		/// @return <如转换成功返回True,否则返回False>
		//================================================================================
		static bool parseToShortVector(const std::wstring& srcStr, std::vector<short>& outVector, const wchar_t* splitter);

		//===============================parseToIntVector()===============================
		/// @brief <将字符串转换为int型矢量>
		///
		/// <将std::wstring型字符串提取出short型数组>
		///
		/// @param [in] srcStr <待提取字符串>
		/// @param [out] outVector <字符串提取出的数组>
		/// @param [in] splitter <字符串分割符>
		///
		/// @return <如转换成功返回True,否则返回False>
		//================================================================================
		static bool parseToIntVector(const std::wstring& srcStr, std::vector<int>& outVector, const wchar_t* splitter);

		//==============================parseToLongVector()=============================
		/// @brief <将字符串提取出short型数组>
		///
		/// <将std::wstring型字符串提取出short型数组>
		///
		/// @param [in] srcStr <待提取字符串>
		/// @param [out] outVector <字符串提取出的数组>
		/// @param [in] splitter <字符串分割符>
		///
		/// @return <如转换成功返回True,否则返回False>
		//================================================================================
		static bool parseToLongVector(const std::wstring& srcStr, std::vector<long>& outVector, const wchar_t* splitter);
#pragma endregion

#pragma endregion

#pragma region ConvertWideStrAndStr

		// Prototype for conversion functions
		//===============================StringToWString()==============================
		/// @brief <转换字符串类型>
		///
		/// <将std::string类型字符串转换为std::wstring类型字符串>
		///
		/// @param [in] str <待转换字符串>
		///
		/// @return <返回转换后的字符串>
		//================================================================================
		static std::wstring StringToWString(const std::string& str);

		//===============================WStringToString()==============================
		/// @brief <转换字符串类型>
		///
		/// <将std::wstring类型字符串转换为std::string类型字符串>
		///
		/// @param [in] str <待转换字符串>
		///
		/// @return <返回转换后的字符串>
		//================================================================================
		static std::string WStringToString(const std::wstring& str);

		//==================================toYZString()==================================
		/// @brief <转换字符串类型>
		///
		/// <将std::string类型字符串转换为bimWorld::YZString类型字符串>
		///
		/// @param [in] str <待转换字符串>
		///
		/// @return <返回转换后的字符串>
		//================================================================================
		static bimWorld::YZString toYZString(const std::string& str);
		
		//==================================toYZString()==================================
		/// @brief <转换字符串类型>
		///
		/// <将std::wstring类型字符串转换为bimWorld::YZString类型字符串>
		///
		/// @param [in] str <待转换字符串>
		///
		/// @return <返回转换后的字符串>
		//================================================================================
		static bimWorld::YZString toYZString(const std::wstring& str);

		//=================================toStdString()================================
		/// @brief <转换字符串类型>
		///
		/// <将bimWorld::YZString类型字符串转换为std::string类型字符串>
		///
		/// @param [in] str <待转换字符串>
		///
		/// @return <返回转换后的字符串>
		//================================================================================
		static std::string toStdString(const std::string& str);

		//=================================toStdString()================================
		/// @brief <转换字符串类型>
		///
		/// <将bimWorld::YZString类型字符串转换为std::wstring类型字符串>
		///
		/// @param [in] str <待转换字符串>
		///
		/// @return <返回转换后的字符串>
		//================================================================================
		static std::string toStdString(const std::wstring& str);
#pragma endregion

#pragma region ToString

		template<class T>
		static std::string toString(T value);

#pragma endregion

	protected:
	};

	template<class T>
	std::string util::StringExtension::toString(T value)
	{
#ifdef __ANDROID__
		std::ostringstream os;
		os << value;
		return os.str();
#else
		return std::to_string(value);
#endif
	}

}
#endif // __STRING_EXTENSION_H__