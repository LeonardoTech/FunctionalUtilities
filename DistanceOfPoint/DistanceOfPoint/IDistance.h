#pragma once

enum Num
{
	SelectOne,
	SelectTwo
};

/// @class	IDistance
///
/// @brief	 <一个接口类。实现测距>
///
/// @author	Admin
/// @date	2016/3/16
class IDistance
{
public:

	/// @fn	virtual bool IDistance::setPoint(float x, float y,Num num) = 0;
	///
	/// @brief	  <画出一个点，结合内部的函数完成测量距离>.
	///
	/// @author	Admin
	/// @date	2016/3/16
	///
	/// @param	x  	<屏幕上的二维横坐标>.
	/// @param	y  	<屏幕上的二维纵坐标>.
	/// @param	num <一个枚举值，确定画的是第一个点还是第二个点>.
	///
	/// @return	true if it succeeds, false if it fails.
	virtual bool  setPoint(float x, float y,Num num) = 0;
};