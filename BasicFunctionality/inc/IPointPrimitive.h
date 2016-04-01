
#ifndef __IPOINT_PRIMITIVE_H__
#define __IPOINT_PRIMITIVE_H__

#include "IDrawElement.h"
#include "IMoveable.h"
#include "IPrimitiveFactor.h"


namespace geo
{
	/// @class	IPointPrimitives
	///
	/// @brief	 <绘制点元的接口类 继承IDrawElement类>.
	///
	/// @author	Admin
	/// @date	2016/3/23
	class IPointPrimitive :public IMoveable, public IPrimitiveFactor
	{
		public:

			/// @fn	virtual void IPointPrimitives::getPosition(float& x, float& y, float& z) const = 0;
			///
			/// @brief	 <获取点的坐标> .
			///
			/// @author	Admin
			/// @date	2016/3/23
			///
			/// @param [out]	x	<获取点的X轴坐标>.
			/// @param [out]	y	<获取点的Y轴坐标>.
			/// @param [out]	z	<获取点的Z轴坐标>.
			virtual void getPosition(float& x, float& y, float& z) const = 0;

			/// @fn	virtual void IPointPrimitives::setPosition(float x, float y, float z) = 0;
			///
			/// @brief	 <设置点的坐标>.
			///
			/// @author	Admin
			/// @date	2016/3/23
			///
			/// @param	x	<设置点的X轴坐标>
			/// @param	y	<设置点的Y轴坐标>
			/// @param	z	<设置点的Z轴坐标>
			virtual void setPosition(float x, float y, float z) = 0;

			/// @fn	virtual float IPointPrimitives::getSize() const = 0;
			///
			/// @brief	 <获取当前点的大小>.
			///
			/// @author	Admin
			/// @date	2016/3/23
			///
			/// @return <返回的是字体大小的浮点值>.
			virtual float getSize() const = 0;

			/// @fn	virtual void IPointPrimitives::setSize(float size) = 0;
			///
			/// @brief <设置当前点的大小>.
			///
			/// @author	Admin
			/// @date	2016/3/23
			///
			/// @param	size	<设置点大小的浮点值>.
			virtual void setSize(float size) = 0;
		};
};

#endif // __IPOINT_PRIMITIVE_H__
