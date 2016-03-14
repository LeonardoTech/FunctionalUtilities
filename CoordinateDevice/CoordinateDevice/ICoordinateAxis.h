#ifndef MY_HH
#define MY_HH

/// @enum	Axis
///
/// @brief	һ��ö������ ��Ա�ֱ������X,Y,Z������.
enum Axis
{
	///< ������X��
	X_Axis,
	///< ������Y��
	Y_Axis,
	///< ������Z��
	Z_Axis
};


/// @class	ICoordinateAxis
///
/// @brief	һ����ICoordinateAxis�Ľӿ��� ��Ա�����ֱ��Ǹ�����������һ������ϵ�ͻ�ȡX,Y��Z��ķ���.
///
/// @author	Admin
/// @date	2016/3/14
class ICoordinateAxis
{
public:
	/// @fn	virtual void ICoordinateAxis::getAxisDirection( Axis ax, float &x, float &y, float &z) = 0;
	///
	/// @brief	��ȡĳһ�����ָ��.
	/// @brief	���в���Axis������X,Y,Z��������.
	/// @brief	������������&amp;X,&amp;Y,&amp;Z������ָ�������.
	///
	/// @author	Admin
	/// @date	2016/3/14
	///
	/// @param	ax		 	The ax. 
	/// @param [out]	x	ָ���X����
	/// @param [out]	y	ָ���Y����
	/// @param [out]	z	ָ���Z����
	virtual void getAxisDirection(Axis ax, float &x, float &y, float &z) = 0;

	/// @fn	virtual osg::MatrixTransform* ICoordinateAxis::setAxis(float x, float y, float radius, osg::Camera *camera) = 0;
	///
	/// @brief	ͨ��ָ���Ķ�ά��Ļ���껭������ϵ������ָ������ϵ�İ뾶���ȣ���Ҫ����Ļ�����Ϊ��������ȥ
	///
	/// @author	Admin
	/// @date	2016/3/14
	///
	/// @param	x			  	��ά������
	/// @param	y			  	��ά������
	/// @param	radius		������߰뾶
	/// @param [in]			����Ļ�����Ϊ����������
	///
	/// @return	null if it fails, else a pointer to an osg::MatrixTransform.
	virtual osg::MatrixTransform* setAxis(float x, float y, float radius, osg::Camera *camera) = 0;
};



#endif