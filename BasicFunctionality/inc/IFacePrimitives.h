
#ifndef __IFACE_PRIMITIVES_H__
#define __IFACE_PRIMITIVES_H__
#include "IDrawElement.h"

/// @class	IFacePrimitives
///
/// @brief	 <绘制面元的接口，继承于IDrawElement和IColorable>.
///
/// @author	Admin
/// @date	2016/3/23
class IFacePrimitives :public IDrawElement
{
public:

	/// @fn	virtual void IFacePrimitives::setPosition(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3) = 0;
	///
	/// @brief	 <设置面顶点的坐标，每个顶点的三维坐标用float浮点值传进去，共9个>.
	///
	/// @author	Admin
	/// @date	2016/3/23
	///
	/// @param	x1 <第一个顶点的X轴坐标>.
	/// @param	y1 <第一个顶点的Y轴坐标>.
	/// @param	z1 <第一个顶点的Z轴坐标>.
	/// @param	x2 <第二个顶点的X轴坐标>.
	/// @param	y2 <第二个顶点的Y轴坐标>.
	/// @param	z2 <第二个顶点的Z轴坐标>.
	/// @param	x3 <第三个顶点的X轴坐标>.
	/// @param	y3 <第三个顶点的Y轴坐标>.
	/// @param	z3 <第三个顶点的Z轴坐标>.
	virtual void setPosition(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3) = 0;

	/// @fn	virtual void IFacePrimitives::getPosition(float& x1, float& y1, float& z1, float& x2, float& y2, float& z2, float& x3, float& y3, float& z3) = 0;
	///
	/// @brief	 <获取面顶点的位置，并使用引用的方式传出来>.
	///
	/// @author	Admin
	/// @date	2016/3/23
	///
	/// @param [out]	x1	 <第一个顶点的X轴坐标>.
	/// @param [out]	y1	 <第一个顶点的Y轴坐标>.
	/// @param [out]	z1	 <第一个顶点的Z轴坐标>.
	/// @param [out]	x2	 <第二个顶点的X轴坐标>.
	/// @param [out]	y2	 <第二个顶点的Y轴坐标>.
	/// @param [out]	z2	 <第二个顶点的Z轴坐标>.
	/// @param [out]	x3	 <第三个顶点的X轴坐标>.
	/// @param [out]	y3	 <第三个顶点的Y轴坐标>.
	/// @param [out]	z3	 <第三个顶点的Z轴坐标>.
	virtual void getPosition(float& x1, float& y1, float& z1, float& x2, float& y2, float& z2, float& x3, float& y3, float& z3) = 0;
};

#endif // __IFACE_PRIMITIVES_H__
