#ifndef __ISELECT_PRIMITIVES_H__
#define __ISELECT_PRIMITIVES_H__
#include "IDrawElement.h"

/// @class	ISelectPrimitives
///
/// @brief	 <选择点、线、面的接口类>.
///
/// @author	Admin
/// @date	2016/3/23
class ISelectPrimitives
{
public:

	/// @fn	virtual IDrawElement* ISelectPrimitives::select(float x, float y) = 0;
	///
	/// @brief	 <根据屏幕上的位置来确定选择的物品>.
	///
	/// @author	Admin
	/// @date	2016/3/23
	///
	/// @param	x	<选择位置的X轴坐标>.
	/// @param	y	<选择位置的Y轴坐标>.
	///
	/// @return	null if it fails, else a pointer to an IDrawElement.
	virtual IDrawElement* select(float x, float y) = 0;

	/// @fn	virtual IDrawElement* ISelectPrimitives::getSelection() const = 0;
	///
	/// @brief <根据选择的位置，来返回相应的坐标，>.
	///  <选择点返回点的三维坐标>
	///  <选择线返回线的两个端点的三维坐标>
	///  <选择面返回面的三个端点的三维坐标>
	/// 
	/// @author	Admin
	/// @date	2016/3/23
	///
	/// @return	<返回IDrawElement类型的端点的集合>
	virtual IDrawElement* getSelection() const = 0;
};

#endif // __ISELECT_PRIMITIVES_H__
