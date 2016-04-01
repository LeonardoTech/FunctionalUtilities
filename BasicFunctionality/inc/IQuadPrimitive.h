
#ifndef __IQUAD_PRIMITIVE_H__
#define __IQUAD_PRIMITIVE_H__
#include "IDrawElement.h"
#include "IMoveable.h"
#include "IPrimitiveFactor.h"

/// @class	IQuadPrimitives
///
/// @brief	 <绘制面元的接口，继承于IDrawElement和IColorable>.
///
/// @author	Admin
/// @date	2016/3/23
class IQuadPrimitive :public IMoveable, public IPrimitiveFactor
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

	/// @fn	virtual void IQuadPrimitive::setHeight(float const height) = 0;
	///
	/// @brief	 <设置四边形面的高度>.
	///
	/// @author	Admin
	/// @date	2016/3/30
	///
	/// @param	height	<四边形面的高度>.
	virtual void setHeight(float const height) = 0;

	/// @fn	virtual void IQuadPrimitive::setWidth(float const width) = 0;
	///
	/// @brief	 <设置四边形面的宽度>.
	///
	/// @author	Admin
	/// @date	2016/3/30
	///
	/// @param	width	<四边形面的宽度>.
	virtual void setWidth(float const width) = 0;

	/// @fn	virtual void IQuadPrimitive::setQuadColor(float const red, float const green, float const blue) = 0;
	///
	/// @brief	 <设置四边形面的颜色>.
	///
	/// @author	Admin
	/// @date	2016/3/30
	///
	/// @param	red  	<设置红色的数值>.
	/// @param	green	<设置绿色的数值>.
	/// @param	blue 	<设置蓝色的数值>.
	virtual void setQuadColor(float const red, float const green, float const blue) = 0;

	/// @fn	virtual void IQuadPrimitive::setFrameColor(float const red, float const green, float const blue) = 0;
	///
	/// @brief	 <设置边框线的颜色>.
	///
	/// @author	Admin
	/// @date	2016/3/30
	///
	/// @param	red  	<设置红色的数值>.
	/// @param	green	<设置绿色的数值>.
	/// @param	blue 	<设置蓝色的数值>.
	virtual void setFrameColor(float const red, float const green, float const blue) = 0;

	/// @fn	virtual void IQuadPrimitive::setFrameWidth(float const width) = 0;
	///
	/// @brief	 <设置边框线的宽度>.
	///
	/// @author	Admin
	/// @date	2016/3/30
	///
	/// @param	width	<宽度的大小>.
	virtual void setFrameWidth(float const width) = 0;

	/// @fn	virtual osg::Node* IQuadPrimitive::getRoot() = 0;
	///
	/// @brief	 <获取四边形节点>.
	///
	/// @author	Admin
	/// @date	2016/3/30
	///
	/// @return	null if it fails, else the root.
	virtual osg::Node* getRoot() = 0;

	/// @fn	virtual void IQuadPrimitive::setNeedDrawOutLine(bool draw) = 0;
	///
	/// @brief	 <是否绘制边框>.
	///
	/// @author	Admin
	/// @date	2016/3/30
	///
	/// @param	<是否画边框的bool值>.
	virtual void setNeedDrawOutLine(bool draw) = 0;

	/// @fn	virtual void IQuadPrimitive::setCenter(const osg::Vec3& center) = 0;
	///
	/// @brief	 <设置面的中心位置>.
	///
	/// @author	Admin
	/// @date	2016/3/30
	///
	/// @param	center	<中心的坐标>.
	virtual void  setCenter(const osg::Vec3& center) = 0;

};



#endif // __IQUAD_PRIMITIVE_H__
