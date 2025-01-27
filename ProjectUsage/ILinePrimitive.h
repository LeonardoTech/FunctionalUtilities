﻿#ifndef __ILINEPRIMITIVE_H__
#define __ILINEPRIMITIVE_H__

#include "IDrawElement.h"

/// @class	ILinePrimitives
///
/// @brief	 <绘制线元的接口，绘制线元，继承于IDrawElement间接继承IColorable>.
///
/// @author	Admin
/// @date	2016/3/23
class  ILinePrimitive :public IDrawElement
{
public:

	/// @fn	virtual void ILinePrimitives::setLineWidth(float width) = 0;
	///
	/// @brief	Sets <设置线宽>.
	///
	/// @author	Admin
	/// @date	2016/3/23
	///
	/// @param	width	<设置线的宽度>.
	virtual void setLineWidth(float width) = 0;

	/// @fn	virtual void ILinePrimitives::getStartPosition(float& x, float& y, float& z) = 0;
	///
	/// @brief	 <获取线段起始位置的坐标>.
	///
	/// @author	Admin
	/// @date	2016/3/23
	///
	/// @param [out]	x	<获取起始位置的X轴坐标>.
	/// @param [out]	y	<获取起始位置的Y轴坐标>.
	/// @param [out]	z	<获取起始位置的Z轴坐标>.
	virtual void getStartPosition(float& x, float& y, float& z) = 0;

	/// @fn	virtual void ILinePrimitives::getEndPosition(float& x, float& y, float& z) = 0;
	///
	/// @brief <获取线段结束位置的坐标>.
	///
	/// @author	Admin
	/// @date	2016/3/23
	///
	/// @param [in,out]	x	<获取线段结束位置的X坐标>.
	/// @param [in,out]	y	<获取线段结束位置的Y坐标>.
	/// @param [in,out]	z	<获取线段结束位置的Z坐标>.
	virtual void getEndPosition(float& x, float& y, float& z) = 0;


	/// @fn	virtual void ILinePrimitives::setStartPosition(float x, float y, float z) = 0;
	///
	/// @brief <设置线段起始位置的坐标>.
	///
	/// @author	Admin
	/// @date	2016/3/23
	///
	/// @param	x <设置起始位置的X轴坐标>.
	/// @param	y <设置起始位置的Y轴坐标>.
	/// @param	z <设置起始位置的Z轴坐标>.
	virtual void setStartPosition(float x, float y, float z) = 0;

	/// @fn	virtual void ILinePrimitives::setEndPosition(float x, float y, float z) = 0;
	///
	/// @brief	 <设置线段起始位置的坐标>.
	///
	/// @author	Admin
	/// @date	2016/3/23
	///
	/// @param	x	<设置起始位置的X轴坐标>.
	/// @param	y	<设置起始位置的Y轴坐标>.
	/// @param	z	<设置起始位置的Z轴坐标>.
	virtual void setEndPosition(float x, float y, float z) = 0;

	/// @fn	virtual void ILinePrimitive::setGradientColor(float startR, float startG, float startB, float endR, float endG, float endB) = 0;
	///
	/// @brief	Sets <设置颜色的外部函数，其中最后一个透明度默认为1.0>.
	///
	/// @author	Leonardo Sun
	/// @date	2016/04/08
	///
	/// @param	startR  	<设置红色的数值>
	/// @param	startG	<设置绿色的数值>
	/// @param	startB 	<设置蓝色的数值>
	/// @param	endR  	<设置红色的数值>
	/// @param	endG	<设置绿色的数值>
	/// @param	endB 	<设置蓝色的数值>
	virtual void setGradientColor(float startR, float startG, float startB, float endR, float endG, float endB) = 0;

	/// @fn	virtual void IColorable::setGradientColor(float red, float green, float blue) = 0;
	///
	/// @brief	Sets <设置线的结束端点颜色，透明度默认为1.0>.
	///
	/// @author	Leonardo Sun
	/// @date	2016/04/08
	///
	/// @param	red  	<设置红色的数值>
	/// @param	green	<设置绿色的数值>
	/// @param	blue 	<设置蓝色的数值>
	/// @param	alpha <设置透明度>
	virtual void setEndedColor(float red, float green, float blue, float alpha = 1.0f) = 0;
};

#endif	// __ILINEPRIMITIVE_H__
