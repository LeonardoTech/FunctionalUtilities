#ifndef __YZTransform3_H__
#define __YZTransform3_H__
/*
	变换，为了便于数据获取和处理这里不使用4X4矩阵
	矩阵行数据还是列数据作为坐标轴取决于是左乘还是右乘
	这里使用右乘，也就是行矩阵
*/
#include "YZGeometry.h"
//#include "YZSerializeDeclare.h"
#include <osg/Matrixf>

#include "YZMatrix3.h"
#include "YZVector3.h"

namespace YZ
{
	class Position3;
	class Direction3;
	class Placement3;

	class GEOMETRY_API Transform3 : public osg::Matrixf
	{
	//	SERIALIZE_DECLARE(Transform3)
	public:
		/*---------------
			构造
		----------------*/
		Transform3(void);
		Transform3(const Transform3& transf);
		Transform3(float a00, float a01, float a02, float a03,
			float a10, float a11, float a12, float a13,
			float a20, float a21, float a22, float a23,
			float a30, float a31, float a32, float a33);
		~Transform3(void);

		/*---------------
			运算符
		----------------*/
		Transform3& operator=(const Transform3& transf);
		bool operator==(const Transform3& transf) const;
		bool operator!=(const Transform3& transf) const;
		Transform3& operator*=(const Transform3& transf);//乘积，变换的累加
		Transform3 operator*(const Transform3& transf);//乘积，变换的累加


		/*---------------
			功能
		----------------*/
		Transform3* clone(void) const;
		void setMatrix3(const Matrix3& mat);

		
	};
    
    //右乘
    //GEOMETRY_API friend Transform3 operator*(const Transform3& transf1, const Transform3& transf2);
    GEOMETRY_API Vector3 operator*(const Vector3& vec, const Transform3& transf);
    GEOMETRY_API Vector3 operator*=(Vector3& vec, const Transform3& transf);
    GEOMETRY_API Direction3 operator*(const Direction3& dir, const Transform3& transf);
    GEOMETRY_API Direction3 operator*=(Direction3& dir, const Transform3& transf);
    GEOMETRY_API Position3 operator*(const Position3& pos, const Transform3& transf);
    GEOMETRY_API Position3 operator*=(Position3& pos, const Transform3& transf);
    //GEOMETRY_API friend Placement3 operator*(const Placement3& place, const Transform3& transf);
    //GEOMETRY_API friend Placement3 operator*=(Placement3& place, const Transform3& transf);
    
    //坐标系的变换
    GEOMETRY_API Transform3 coordinate_transf(const Placement3& place);
    //坐标系的变换，坐标轴XYZ代表了旋转，原点origin代表了平移
    //GEOMETRY_API friend Transform3 coordinate_transf(const Position3& origin, const Direction3& axisX, const Direction3& axisY, const Direction3& axisZ);
    
    //如果XY轴平行，不变换
    //如果XY轴不垂直，则以XY轴所在平面的法向量为Z轴，再以YZ所在平面的法向量为X轴形成坐标系
    //GEOMETRY_API friend Transform3 coordinate_transf(const Position3& origin, const Direction3& axisX, const Direction3& axisY);
    
    //整体缩放，缩放值最好为正数
    //如果需要沿着XYZ轴作对称变换，请使用reflect_transf(轴)的组合变换，而不是使用负数来缩放，这样违背了转换的初衷
    GEOMETRY_API Transform3 scale_transf(float scale);
    
    //不规则缩放
    GEOMETRY_API Transform3 scale_transf(float factorX, float factorY, float factorZ);
    GEOMETRY_API Transform3 scale_transf(const Vector3& factor);
    
    //平移变换
    GEOMETRY_API Transform3 translate_transf(const Vector3& translate);
    GEOMETRY_API Transform3 translate_transf(float transX, float transY, float transZ);
    
    //旋转变换
    //绕axis轴旋转angle角度，angle为弧度值
    GEOMETRY_API Transform3 rotate_transf(float angle, const Direction3& axis);
    //从from轴旋转到to轴
    GEOMETRY_API Transform3 rotate_transf(const Direction3& from, const Direction3& to);
    
    //映射变换，normal为映射平面的法向量，平面过原点（对称，镜像）
    GEOMETRY_API Transform3 reflect_transf(const Direction3& normal);
    //GEOMETRY_API friend Transform3 reflect_transf(const Vector3& normal);
    
    //三个平面上的剪切
    //剪切值为0则该平面上无变换
    GEOMETRY_API Transform3 shear_transf(float shearXY, float shearXZ, float shearYZ);
    
    //不规则缩放 加 剪切
    //如果三个方向的缩放值在误差范围GPresabs内相等并且三个剪切值在误差范围GPresnul内为0，则使用scale_transf(float)
    GEOMETRY_API Transform3 scale_transf(float factorX, float factorY, float factorZ, float shearXY, float shearXZ, float shearYZ);//XYZ缩放，平面剪切
}
#endif // __YZTransform3_H__