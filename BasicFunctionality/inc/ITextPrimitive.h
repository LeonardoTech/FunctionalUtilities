#ifndef __ITEXTPRIMITIVE_H__
#define __ITEXTPRIMITIVE_H__
#include <string>

#include "IColorable.h"

namespace geo
{

	class ITextPrimitive :public IColorable
	{
	public:

		/// @fn	virtual void ITextPrimitives::setPosition(float x, float y, float z) = 0;
		///
		/// @brief	 <设置文字的坐标>
		///
		/// @author	Admin
		/// @date	2016/3/23
		///
		/// @param	x	<设置文字的X轴坐标> .
		/// @param	y	<设置文字的Y轴坐标> .
		/// @param	z	<设置文字的Z轴坐标> .
		virtual void setPosition(float x, float y, float z) = 0;

		/// @fn	virtual void ITextPrimitives::setSize(float size) = 0;
		///
		/// @brief	  <设置字体的大小>
		///
		/// @author	Admin
		/// @date	2016/3/23
		///
		/// @param	size	<字体的大小的浮点值>.
		virtual void setSize(float size) = 0;

		/// @fn	virtual void ITextPrimitives::setText(const std::string& content) = 0;
		///
		/// @brief	 <设置文本的内容>.
		///
		/// @author	Admin
		/// @date	2016/3/23
		///
		/// @param	content	<文本的内容>.
		virtual void setTextContent(const std::string& content) = 0;

		/// @fn	virtual void ITextPrimitives::setFontFile(const std::string& fontFile) = 0;
		///
		/// @brief	 <设置字体文件 ，默认是fonts/arial.ttf">.
		///
		/// @author	Admin
		/// @date	2016/3/23
		///
		/// @param	fontFile	 <字体文件>. 
		virtual void setFontFile(const std::string& fontFile) = 0;

	};
}

#endif // __ITEXTPRIMITIVES_H__