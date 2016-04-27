#ifndef __IDRAW_ELEMENT_H__
#define __IDRAW_ELEMENT_H__
#include <osg/Geometry>

#include "VertexArray.h"
#include "IColorable.h"

namespace geo
{
	/// @class	IDrawElement
	///
	/// @brief	 <一个绘制的接口类，继承于可着色的IColorable类，有获取顶点设置顶点的功能>
	///
	/// @author	Admin
	/// @date	2016/3/23

	class IDrawElement : public IColorable,public osg::Geometry
	{
	public:

		/// @fn	virtual VertexArray IDrawElement::getVertices() const = 0;
		///
		/// @brief	 <获取顶点，并把顶点返回>
		///
		/// @author	Admin
		/// @date	2016/3/23
		///
		/// @return	<返回一个VertexArray类型的容器>
		virtual VertexArray getVertices() const = 0;

		/// @fn	virtual void IDrawElement::setVertices(const VertexArray& arr) = 0;
		///
		/// @brief	 <设置顶点的位置，参数传递顶点数据>
		///
		/// @author	Admin
		/// @date	2016/3/23
		///
		/// @param	arr	The array.
		virtual void setVertices(const VertexArray& arr) = 0;

	};
}
#endif // __IDRAW_ELEMENT_H__
