#ifndef __IMOVEABLE_H__
#define __IMOVEABLE_H__

/// @class	IMoveable
///
/// @brief <一个设置位置的接口类，>
///
/// @author	Admin
/// @date	2016/3/23
class IMoveable
{
public:

	/// @fn	virtual void IMoveable::setPosition(float x float y, float z) = 0;
	///
	/// @brief	Sets <设置位置>.
	///
	/// @author	Admin
	/// @date	2016/3/23
	///
	/// @param	x  	<设置x轴的坐标>
	/// @param	y	<设置y轴的坐标>
	/// @param	z 	<设置z轴的坐标>
	virtual void getPosition(float& x, float& y, float& z) = 0;

	virtual void setPosition(float x, float y, float z) = 0;
private:

};

#endif // __IMOVEABLE_H__
