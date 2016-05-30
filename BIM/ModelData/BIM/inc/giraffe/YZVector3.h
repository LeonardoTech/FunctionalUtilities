#ifndef __YZVector3_H__
#define __YZVector3_H__
/*
	向量
*/
#include "YZGeometry.h"
//#include "YZSerializeDeclare.h"

#include <osg/Vec3>

namespace YZ
{
	class Direction3;
	class GEOMETRY_API Vector3 : public osg::Vec3
	{
	//	SERIALIZE_DECLARE(Vector3)
	public:
		/*---------------
			构造
		----------------*/
		Vector3(void);
		Vector3(float x, float y, float z);
		Vector3(const osg::Vec3& value);
		explicit Vector3(float value[3]);
		Vector3(const Vector3& cPt);
		~Vector3(void);

		/*---------------
			运算符
		----------------*/
		Vector3& operator=(const float& scalar);
		Vector3& operator=(const Vector3& vec);
		bool operator==(const Vector3& vec) const;
		bool operator!=(const Vector3& vec) const;
		Vector3 operator+(const float& inc) const;
		Vector3 operator+(const Vector3& vec) const;
		Vector3 operator+(const Direction3& dir) const;
		Vector3 operator-(const float& dec) const;
		Vector3 operator-(const Vector3& vec) const;
		Vector3 operator-(const Direction3& dir) const;
		Vector3 operator*(const float& scalar) const;
		//Vector3 operator/(const float& scalar) const;
		//Vector3 operator/(const Vector3& vec) const;

		//cross product，叉积，矢量积，结果垂直于两个向量
		Vector3 operator*(const Vector3& vec) const;
		Vector3 operator*(const Direction3& dir) const;

		//scalar product，内积
		//dot product，点积，标量积，结果为0则互相垂直
		float operator%(const Vector3& vec) const;
		float operator%(const Direction3& dir) const;

		Vector3& operator+=(const float& inc);
		Vector3& operator+=(const Vector3& vec);
		Vector3& operator-=(const float& dec);
		Vector3& operator-=(const Vector3& vec);
		Vector3& operator*=(const float& scalar);
		Vector3& operator*=(const Vector3& vec);
		Vector3& operator/=(const float& scalar);
		Vector3& operator/=(const Vector3& vec);
		Vector3 operator-(void) const;

		GEOMETRY_API friend Vector3 operator+(const float& inc, const Vector3& vec);
		GEOMETRY_API friend Vector3 operator-(const float& dec, const Vector3& vec);
		GEOMETRY_API friend Vector3 operator*(const float& scalar, const Vector3& vec);
		//GEOMETRY_API friend Vector3 operator/(const float& scalar, const Vector3& vec);

		/*---------------
			常量
		----------------*/
		static const Vector3 ZERO;
		static const Vector3 UNIT_SCALE;
		static const Vector3 UNIT_X;
		static const Vector3 UNIT_Y;
		static const Vector3 UNIT_Z;
		static const Vector3 NEGATIVE_UNIT_X;
		static const Vector3 NEGATIVE_UNIT_Y;
		static const Vector3 NEGATIVE_UNIT_Z;

		/*---------------
			读写
		----------------*/
		void set_x(float dx);
		void set_y(float dy);
		void set_z(float dz);
		void set_value(const Vector3& vec);

		void get_value(float& dx, float& dy, float& dz) const;

		/*---------------
			功能
		----------------*/
		virtual Vector3* clone(void) const;

		//0,0,0
		virtual void reset(void);

		//是否是零向量
		bool is_zero(const float res = GPresnul) const;

		//获取当前向量长度的平方
		float sqre_len(void) const;

		//获取当前向量长度
		float length(void) const;

		//单位化当前向量，返回当前向量长度
		Direction3 normalise(void) const;

		//两个向量是否相同
		bool equal_to(const Vector3& vec, const float res = GPresabs) const;

		//两个向量是否同向平行
		bool parallel(const Vector3& vec, const float res = GPresabs) const;
		bool parallel(const Direction3& dir, const float res = GPresabs) const;

		//两个向量是否双向平行
		bool biparallel(const Vector3& vec, const float res = GPresabs) const;
		bool biparallel(const Direction3& dir, const float res = GPresabs) const;

		//两个向量是否反向平行
		bool antiparallel(const Vector3& vec, const float res = GPresabs) const;
		bool antiparallel(const Direction3& dir, const float res = GPresabs) const;

		//两个向量是否垂直
		bool perpendicular(const Vector3& vec, const float res = GPresabs) const;
		bool perpendicular(const Direction3& dir, const float res = GPresabs) const;
	};
}
#endif // __YZVector3_H__