#ifndef __ICOORDINATE_H__
#define __ICOORDINATE_H__
#include <string>
namespace coordinateaxis
{
	enum class AxisDirection
	{
		X_AXIS, 
		Y_AXIS, 
		Z_AXIS
	};


	class ICoordinateAxis
	{
	public:
		/// @fn	virtual void ICoordinate::setLabelText( Axis ax, float &x, float &y, float &z) = 0;
		///
		/// @brief 	<设置坐标轴标注>
		///
		/// @author	Admin
		/// @date	2016/3/14
		///
		/// @param	axis		<代表着X,Y,Z这三个轴.>
		/// @param label		<标注>
		virtual void setLabelText(AxisDirection axis, std::string label) = 0;// <>

		/// @fn	virtual void setLabelPosition(AxisDirection axis, float x, float y, float z) = 0;
		///
		/// @brief 	<设置标注出现的位置>
		///
		/// @author	Admin
		/// @date	2016/3/14
		///
		/// @param	axis		<代表着X,Y,Z这三个轴.>
		/// @param	x		 	<横坐标>
		/// @param y			<竖坐标>
		/// @param z			<高坐标>
		virtual void setLabelPosition(AxisDirection axis, float x, float y, float z) = 0;

		/// @fn	virtual void setColor(AxisDirection axis, float x, float y, float z) = 0;
		///
		/// @brief 	<设置轴和标注的颜色>
		///
		/// @author	Admin
		/// @date	2016/3/14
		///
		/// @param	axis		<代表着X,Y,Z这三个轴.>
		/// @param	x		 	<横坐标>
		/// @param y			<竖坐标>
		/// @param z			<高坐标>
		virtual void setColor(AxisDirection axis, float x, float y, float z) = 0;

		/// @fn	virtual void setOriginPoint(float x, float y) = 0;
		///
		/// @brief 	<设置原点>
		///
		/// @author	Admin
		/// @date	2016/3/14
		///
		/// @param	x		 	<屏幕的横坐标>
		/// @param y			<屏幕的竖坐标>
		virtual void setOriginPoint(float x, float y) = 0;

		/// @fn	virtual void setRadius(float radius) = 0;
		///
		/// @brief 	<设置原点>
		///
		/// @author	Admin
		/// @date	2016/3/14
		///
		/// @param	radius		 	<半径>
		virtual void setRadius(float radius) = 0;// <设置半径>

		/// @fn	virtual void getAxisDirection3D(AxisDirection axis, float& x, float& y, float& z) = 0;
		///
		/// @brief 	<获得轴的在3围空间位置>
		/// @brief	  <用了三个引用&amp;X,&amp;Y,&amp;Z，代表指向的向量.>
		///
		/// @author	Admin
		/// @date	2016/3/14
		///
		/// @param	axis		<代表着X,Y,Z这三个轴.>
		/// @param [out]	x	<指向的X向量>
		/// @param [out]	y	<指向的Y向量>
		/// @param [out]	z	<指向的Z向量>
		virtual void getAxisDirection3D(AxisDirection axis, float& x, float& y, float& z) = 0;

		/// @fn	virtual void getAxisDirection2D(AxisDirection axis, float& x, float& y) = 0;
		///
		/// @brief 	<获得轴的在屏幕的位置>
		/// @brief	  <用了三个引用&amp;X,&amp;Y代表指向的向量.>
		///
		/// @author	Admin
		/// @date	2016/3/14
		///
		/// @param	axis		<代表着X,Y,Z这三个轴.>
		/// @param [out]	x	<指向的X向量>
		/// @param [out]	y	<指向的Y向量>
		virtual void getAxisDirection2D(AxisDirection axis, float& x, float& y) = 0;// <获得轴的屏幕坐标>

		/// @fn	virtual void setDarkColor(AxisDirection axis, std::string color) = 0;
		///
		/// @brief 	<设置轴的渐变色的暗色>
		/// @brief	   <其中参数AxisDirection代表着X,Y,Z这三个轴.>
		///
		/// @author	Admin
		/// @date	2016/3/14
		///
		/// @param	axis		<代表着X,Y,Z这三个轴.>
		/// @param x	        <x代表红色值>
		/// @param y			<y代表绿色值>
		/// @param z			<z代表蓝色值>
		virtual void setDarkColor(AxisDirection axis,float x, float y, float z) = 0;

		/// @fn	virtual void setLabelVisibility(AxisDirection axis, bool bvisible) = 0;
		///
		/// @brief 	<设置标签是否可见>
		///
		/// @author	Admin
		/// @date	2016/3/14
		///
		/// @param	axis		        <代表着X,Y,Z这三个轴.>
		/// @param isVisibility	<轴是否可见>
		virtual void setLabelVisibility(AxisDirection axis, bool isVisibility) = 0;

		/// @fn	virtual void setAxisWidth(float width) = 0;
		///
		/// @brief 	<设置轴线的宽度>
		///
		/// @author	Admin
		/// @date	2016/3/14
		///
		/// @param width	<设置轴的宽度>
		virtual void setAxisWidth(float width) = 0;


		virtual void setEnableUpdate(bool enabled) = 0;
	};
}


#endif