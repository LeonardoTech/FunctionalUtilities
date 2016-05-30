////////////
//    created by 孙庆号
////////////

#ifndef __ICOORDINATE_H__
#define __ICOORDINATE_H__
//#include "CoordinateHelper.h"
#include "ICoordinateAxis.h"
namespace bimWorld
{
	class YIZHU_EXPORT ICoordinate:public ICoordinateAxis
	{
	public:
		//virtual util::CoordinateHelper* CoordinateHelper() = 0;
		//virtual ICoordinateAxis* CoordinateAxisHelper() = 0;

		/// @fn	virtual osg::MatrixTransform* ICoordinateAxis::setAxis(float x, float y, float radius, osg::Camera *camera) = 0;
		///
		/// @brief	 <通过指定的二维屏幕坐标画出坐标系，可以指定坐标系的半径长度，需要把屏幕相机作为参数传进去>
		///
		/// @author	Admin
		/// @date	2016/3/14
		///
		/// @param	x			  	<二维横坐标>
		/// @param	y			  	<二维纵坐标>
		/// @param	radius		<坐标轴边半径>
		/// @param [in] camera <把屏幕相机作为参数传进来>
		///
		/// @return	null if it fails, else a pointer to an osg::MatrixTransform.
		virtual bool setAxis(float x, float y, float radius) = 0;

	};
}
#endif // __ICOORDINATE_H__