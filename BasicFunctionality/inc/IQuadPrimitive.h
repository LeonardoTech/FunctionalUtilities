
#ifndef __IQUAD_PRIMITIVES_H__
#define __IQUAD_PRIMITIVES_H__
#include "IDrawElement.h"

/// @class	IQuadPrimitives
///
/// @brief	 <绘制面元的接口，继承于IDrawElement和IColorable>.
///
/// @author	Admin
/// @date	2016/3/23
class IQuadPrimitive :public IDrawElement
{
public:

	/// @fn	virtual void IQuadPrimitive::setVertices(Vertex vet1, Vertex vet2, Vertex vet3, Vertex vet4) = 0;
	///
	/// @brief	 <设置顶点的坐标>.
	///
	/// @author	Admin
	/// @date	2016/3/28
	///
	/// @param	vet1	<第一个顶点坐标>.
	/// @param	vet2	<第二个顶点坐标>.
	/// @param	vet3	<第三个顶点坐标>.
	/// @param	vet4	<第四个顶点坐标>.
	virtual void setVertices(Vertex vet1, Vertex vet2, Vertex vet3, Vertex vet4) = 0;

	/// @fn	virtual void IQuadPrimitive::getVertices(Vertex& vet1, Vertex& vet2, Vertex& vet3, Vertex& vet4) = 0;
	///
	/// @brief	 <获取顶点的坐标>.
	///
	/// @author	Admin
	/// @date	2016/3/28
	///
	/// @param [in,out]	<第一个顶点坐标>.
	/// @param [in,out]	<第二个顶点坐标>.
	/// @param [in,out]	<第三个顶点坐标>.
	/// @param [in,out]	<第四个顶点坐标>.
	virtual void getVertices(Vertex& vet1, Vertex& vet2, Vertex& vet3, Vertex& vet4) = 0;
};



#endif // __IQUAD_PRIMITIVES_H__
