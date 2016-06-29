#ifndef __YZMatrix3_H__
#define __YZMatrix3_H__
/*
	用于坐标变换的3X3矩阵，可以进行旋转，比例，剪切，映像等变换
	三维坐标系统遵从右手定则

	绕X轴旋转t角度，t>0表明在YZ平面上逆时针旋转
	  RX =    1       0       0
	          0     cos(t)  sin(t)
	          0    -sin(t)  cos(t)

	绕Y轴旋转t角度，t>0表明在ZX平面上逆时针旋转
	  RY =  cos(t)    0    -sin(t)
	          0       1       0
	        sin(t)    0     cos(t)

	绕Z轴旋转t角度，t>0表明在XY平面上逆时针旋转
	  RZ =  cos(t)  sin(t)    0
	       -sin(t)  cos(t)    0
	          0       0       1

	XYZ轴分别缩放a,b,c
	a  0  0
	0  b  0
	0  0  c

	XY轴剪切       YZ轴剪切        ZX轴剪切
	1  a  0        1  0  0         1  0  a
	b  1  0        0  1  a         0  1  0
	0  0  1        0  b  1         b  0  1

	X轴对称		  Y轴对称		 Z轴对称	    原点对称
	1   0  0      -1  0   0      -1  0   0     -1   0   0
	0  -1  0      0   1   0      0   -1  0      0  -1   0
	0   0  -1     0   0  -1      0   0   1      0   0  -1
*/
#include "YZGeometry.h"
#include <osg/Vec3>

namespace YZ
{
	class Vector3;
	class Direction3;
	class Position3;
	class Transform3;

	class GEOMETRY_API Matrix3
	{
	public:
		/*---------------
			构造
		----------------*/
		Matrix3(void);
		Matrix3(float value00, float value01, float value02,
			   float value10, float value11, float value12,
			   float value20, float value21, float value22);

		//通过三个行轴构造矩阵
		Matrix3(const Vector3& axisX, const Vector3& axisY, const Vector3& axisZ);

		//通过三个行轴构造矩阵
		Matrix3(const Direction3& axisX, const Direction3& axisY, const Direction3& axisZ);

		explicit Matrix3(float value[3][3]);
		Matrix3(const Matrix3& mat);
		~Matrix3(void);

		/*---------------
			运算符
		----------------*/
		//inline float* operator[](uInt iRow) const{return (float*)m_Matrix[iRow];}//可能引起不必要的越界，暂不开放
		inline float operator()(int row, int col) const { return m_matrix[row][col]; }
		inline float& operator()(int row, int col) { return m_matrix[row][col]; }
		Matrix3& operator=(const Matrix3& mat);
		bool operator==(const Matrix3& mat) const;
		bool operator!=(const Matrix3& mat) const;
		Matrix3 operator-() const;// -Matrix3

		Matrix3 operator+(const Matrix3& mat) const;// Matrix3 + Matrix3
		Matrix3& operator+=(const Matrix3& mat);// Matrix3 += Matrix3
		Matrix3 operator-(const Matrix3& mat) const;// Matrix3 - Matrix3
		Matrix3& operator-=(const Matrix3& mat);// Matrix3 -= Matrix3
		Matrix3 operator*(const Matrix3& mat) const;// Matrix3 * Matrix3
		Matrix3& operator*=(const Matrix3& mat);// Matrix3 *= Matrix3


		//左乘，一般不会使用
		Matrix3 operator*(float scalar) const;// Matrix3 * scalar
		Matrix3& operator*=(float scalar);// Matrix3 *= scalar
		Vector3 operator*(const Vector3& vec) const;//Matrix3 * vector [3x3 * 3x1 = 3x1]
		Direction3 operator*(const Direction3& dir) const;//Matrix3 * direction [3x3 * 3x1 = 3x1]
		Position3 operator*(const Position3& pos) const;//Matrix3 * position [3x3 * 3x1 = 3x1]

		/*---------------
			常量
		----------------*/
		static const Matrix3 REFLECT_X;//X轴对称
		static const Matrix3 REFLECT_Y;//Y轴对称
		static const Matrix3 REFLECT_Z;//Z轴对称
		static const Matrix3 IDENTITY;//单位矩阵
		static const Matrix3 REFLECT_ORIGIN;//原点对称

		/*---------------
			读写
		----------------*/
		void set_value(uInt row, uInt col, float value);
		void set_value(const Vector3& axisX, const Vector3& axisY, const Vector3& axisZ);
		void set_value(const Direction3& axisX, const Direction3& axisY, const Direction3& axisZ);
		void set_row(uInt row, const Vector3& value);//行
		void set_row(uInt row, const Direction3& value);
		void set_column(uInt col, const Vector3& value);//列
		void set_column(uInt col, const Direction3& value);

		float get_value(uInt row, uInt col) const;
		Vector3 get_row(uInt row) const;//行
		Vector3 get_column(uInt col) const;//列

		/*---------------
			功能
		----------------*/
		virtual Matrix3* clone(void) const;
		virtual void reset(void);

		//获取矩阵行列式值，符号记为 |A| 或 detA
		//行列式为0，则为奇异矩阵，不为0，则为非奇异矩阵
		float determinant() const;

		//获取转置矩阵，符号记为 A' 或 At
		Matrix3 transpose() const;

		//获取逆矩阵，符号记为 A-1
		//必须为非奇异矩阵，即|A| != 0
		Matrix3 inverse() const;

		//获取伴随矩阵，符号记为 A*
		//Matrix3 adjoint() const;

		//是否单位矩阵
		bool identity() const;

		//两个矩阵是否相同，在精度范围内
        bool equalto(const Matrix3& mat, const float res = GPresabs) const;

		float m_matrix[3][3];
	};
    
    //右乘
	GEOMETRY_API osg::Vec3 operator*(const osg::Vec3& vec, const Matrix3& mat);
    GEOMETRY_API Vector3 operator*(const Vector3& vec, const Matrix3& mat);// vector * Matrix3 [1x3 * 3x3 = 1x3]
    GEOMETRY_API Vector3 operator*=(Vector3& vec, const Matrix3& mat);// vector *= Matrix3 [1x3 * 3x3 = 1x3]
    GEOMETRY_API Direction3 operator*(const Direction3& dir, const Matrix3& mat);// direction * Matrix3 [1x3 * 3x3 = 1x3]
    GEOMETRY_API Direction3 operator*=(Direction3& dir, const Matrix3& mat);// direction *= Matrix3 [1x3 * 3x3 = 1x3]
    GEOMETRY_API Position3 operator*(const Position3& pos, const Matrix3& mat);// position * Matrix3 [1x3 * 3x3 = 1x3]
    GEOMETRY_API Position3 operator*=(Position3& pos, const Matrix3& mat);// position * Matrix3 [1x3 * 3x3 = 1x3]
    GEOMETRY_API Matrix3 operator*(float scalar, const Matrix3& mat);// scalar * Matrix3
    //Matrix3 operator*(const Transform3& transf) const;//Matrix3 * tranform [3x3 * 3x3 = 3x3]
    //GEOMETRY_API friend Matrix3 operator*(const Transform3& transf, const Matrix3& mat);// tranform * Matrix3 [3x3 * 3x3 = 3x3]
    
    //沿着轴旋转角度
    GEOMETRY_API Matrix3 rotation(float angle, const Direction3& axis);
    //GEOMETRY_API friend Matrix3 rotation(float angle, const Vector3& axis);
    
    //对平面的映射，normal为平面法向量
    GEOMETRY_API Matrix3 reflection(const Direction3& normal);
    //GEOMETRY_API friend Matrix3 reflection(const Vector3& normal);
    
    //整体缩放
    GEOMETRY_API Matrix3 scaling(float factor);
    
    //不规则缩放
    GEOMETRY_API Matrix3 scaling(float factorX, float factorY, float factorZ);
    GEOMETRY_API Matrix3 scaling(const Vector3& factor);
    
    //三个平面上的剪切
    GEOMETRY_API Matrix3 shearing(float shearXY, float shearXZ, float shearYZ);
    
    //不规则缩放 加 剪切
    GEOMETRY_API Matrix3 scaling(float factorX, float factorY, float factorZ, float shearXY, float shearXZ, float shearYZ);
}

#endif // __YZMatrix3_H__