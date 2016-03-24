#ifndef __ICOORDINATE_H__
#define __ICOORDINATE_H__
#include <string>
namespace coordinatedevice_coordinate_icoordinate
{
	enum class CoordinateNames
	{
		X_AXIS, 
		Y_AXIS, 
		Z_AXIS
	};


	class ICoordinate
	{
	public:
		/// @fn	virtual void ICoordinate::setLabelText( Axis ax, float &x, float &y, float &z) = 0;
		///
		/// @brief 	<�����������ע>
		///
		/// @author	Admin
		/// @date	2016/3/14
		///
		/// @param	axis		<������X,Y,Z��������.>
		/// @param label		<��ע>
		virtual void setLabelText(CoordinateNames axis, std::string label) = 0;// <>

		/// @fn	virtual void setLabelPosition(CoordinateNames axis, float x, float y, float z) = 0;
		///
		/// @brief 	<���ñ�ע���ֵ�λ��>
		///
		/// @author	Admin
		/// @date	2016/3/14
		///
		/// @param	axis		<������X,Y,Z��������.>
		/// @param	x		 	<������>
		/// @param y			<������>
		/// @param z			<������>
		virtual void setLabelPosition(CoordinateNames axis, float x, float y, float z) = 0;

		/// @fn	virtual void setColor(CoordinateNames axis, float x, float y, float z) = 0;
		///
		/// @brief 	<������ͱ�ע����ɫ>
		///
		/// @author	Admin
		/// @date	2016/3/14
		///
		/// @param	axis		<������X,Y,Z��������.>
		/// @param	x		 	<������>
		/// @param y			<������>
		/// @param z			<������>
		virtual void setColor(CoordinateNames axis, float x, float y, float z) = 0;

		/// @fn	virtual void setOriginPoint(float x, float y) = 0;
		///
		/// @brief 	<����ԭ��>
		///
		/// @author	Admin
		/// @date	2016/3/14
		///
		/// @param	x		 	<��Ļ�ĺ�����>
		/// @param y			<��Ļ��������>
		virtual void setOriginPoint(float x, float y) = 0;

		/// @fn	virtual void setRadius(float radius) = 0;
		///
		/// @brief 	<����ԭ��>
		///
		/// @author	Admin
		/// @date	2016/3/14
		///
		/// @param	radius		 	<�뾶>
		virtual void setRadius(float radius) = 0;// <���ð뾶>

		/// @fn	virtual void getAxisDirection3D(CoordinateNames axis, float& x, float& y, float& z) = 0;
		///
		/// @brief 	<��������3Χ�ռ�λ��>
		/// @brief	  <������������&amp;X,&amp;Y,&amp;Z������ָ�������.>
		///
		/// @author	Admin
		/// @date	2016/3/14
		///
		/// @param	axis		<������X,Y,Z��������.>
		/// @param [out]	x	<ָ���X����>
		/// @param [out]	y	<ָ���Y����>
		/// @param [out]	z	<ָ���Z����>
		virtual void getAxisDirection3D(CoordinateNames axis, float& x, float& y, float& z) = 0;

		/// @fn	virtual void getAxisDirection2D(CoordinateNames axis, float& x, float& y) = 0;
		///
		/// @brief 	<����������Ļ��λ��>
		/// @brief	  <������������&amp;X,&amp;Y����ָ�������.>
		///
		/// @author	Admin
		/// @date	2016/3/14
		///
		/// @param	axis		<������X,Y,Z��������.>
		/// @param [out]	x	<ָ���X����>
		/// @param [out]	y	<ָ���Y����>
		virtual void getAxisDirection2D(CoordinateNames axis, float& x, float& y) = 0;// <��������Ļ����>

		/// @fn	virtual void setDarkColor(CoordinateNames axis, std::string color) = 0;
		///
		/// @brief 	<������Ľ���ɫ�İ�ɫ>
		/// @brief	   <���в���CoordinateNames������X,Y,Z��������.>
		///
		/// @author	Admin
		/// @date	2016/3/14
		///
		/// @param	axis		<������X,Y,Z��������.>
		/// @param x	        <x�����ɫֵ>
		/// @param y			<y������ɫֵ>
		/// @param z			<z������ɫֵ>
		virtual void setDarkColor(CoordinateNames axis,float x, float y, float z) = 0;

		/// @fn	virtual void setLabelVisibility(CoordinateNames axis, bool bvisible) = 0;
		///
		/// @brief 	<���ñ�ǩ�Ƿ�ɼ�>
		///
		/// @author	Admin
		/// @date	2016/3/14
		///
		/// @param	axis		        <������X,Y,Z��������.>
		/// @param isVisibility	<���Ƿ�ɼ�>
		virtual void setLabelVisibility(CoordinateNames axis, bool isVisibility) = 0;

		/// @fn	virtual void setAxisWidth(float width) = 0;
		///
		/// @brief 	<�������ߵĿ��>
		///
		/// @author	Admin
		/// @date	2016/3/14
		///
		/// @param width	<������Ŀ��>
		virtual void setAxisWidth(float width) = 0;
	};
}


#endif