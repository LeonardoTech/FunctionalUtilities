#ifndef MY_HH
#define MY_HH

/// @enum	Axis
///
/// @brief<	一个枚举类型 成员分别代表着X,Y,Z的轴向.>
enum Axis
{
	///< 代表着X轴>
	X_Axis,
	///< 代表着Y轴>
	Y_Axis,
	///< 代表着Z轴>
	Z_Axis
};


/// @class	ICoordinateAxis
///
/// @brief	 <一个叫ICoordinateAxis的接口类 成员函数分别是根据属性制作一个坐标系和获取X,Y或Z轴的方向.>
///
/// @author	Admin
/// @date	2016/3/14
class ICoordinateAxis
{
public:

	/// @fn	virtual void ICoordinateAxis::getAxisDirection( Axis ax, float &x, float &y, float &z) = 0;
	///
	/// @brief 	<获取某一个轴的指向.>
	/// @brief	  <其中参数Axis代表着X,Y,Z这三个轴.>
	/// @brief	  <用了三个引用&amp;X,&amp;Y,&amp;Z，代表指向的向量.>
	///
	/// @author	Admin
	/// @date	2016/3/14
	///
	/// @param	ax		 	The ax. 
	/// @param [out]	x	<指向的X向量>
	/// @param [out]	y	<指向的Y向量>
	/// @param [out]	z	<指向的Z向量>
	virtual void getAxisDirection(Axis ax, float &x, float &y, float &z) = 0;

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
	virtual osg::MatrixTransform* setAxis(float x, float y, float radius, osg::Camera *camera) = 0;
};



#endif