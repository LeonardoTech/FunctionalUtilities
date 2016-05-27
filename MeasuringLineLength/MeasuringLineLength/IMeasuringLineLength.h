#pragma once

enum Num
{
	SelectOne,
	SelectTwo
};

/// @class	IDistance
///
/// @brief	 <һ���ӿ��ࡣʵ�ֲ��>
///
/// @author	Admin
/// @date	2016/3/16
class IMeasuringLineLength
{
public:

	/// @fn	virtual bool IDistance::setPoint(float x, float y,Num num) = 0;
	///
	/// @brief	  <����һ���㣬����ڲ��ĺ�����ɲ�������>.
	///
	/// @author	Admin
	/// @date	2016/3/16
	///
	/// @param	x  	<��Ļ�ϵĶ�ά������>.
	/// @param	y  	<��Ļ�ϵĶ�ά������>.
	/// @param	num <һ��ö��ֵ��ȷ�������ǵ�һ���㻹�ǵڶ�����>.
	///
	/// @return	true if it succeeds, false if it fails.
	//virtual bool  setPoint(float x, float y,Num num) = 0;

	virtual void setStartPoint(float x, float y) = 0;

	virtual void setEndPoint(float x, float y) = 0;

	virtual void setLabel(string name, float x, float y) = 0;

	virtual float getDistance() = 0;


};