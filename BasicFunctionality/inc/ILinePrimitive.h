#ifndef __ILINEPRIMITIVE_H__
#define __ILINEPRIMITIVE_H__

#include "IDrawElement.h"
namespace geo
{

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
	};
}
#endif	// __ILINEPRIMITIVE_H__
