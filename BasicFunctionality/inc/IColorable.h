#ifndef __ICOLORABLE_H__
#define __ICOLORABLE_H__

namespace geo
{
	/// @class	IColorable
	///
	/// @brief <一个设置颜色的接口类，>
	///
	/// @author	Admin
	/// @date	2016/3/23
	class IColorable//IColorable
	{
	public:

		/// @fn	virtual void IColorable::setColor(float red, float green, float blue) = 0;
		///
		/// @brief	Sets <设置颜色的外部函数，其中最后一个透明度默认为1.0>.
		///
		/// @author	Admin
		/// @date	2016/3/23
		///
		/// @param	red  	<设置红色的数值>
		/// @param	green	<设置绿色的数值>
		/// @param	blue 	<设置蓝色的数值>
		virtual void setColor(float red, float green, float blue) = 0;
	private:

	};
}
#endif // __ICOLORABLE_H__
