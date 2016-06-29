#ifndef __YZDirection3_H__
#define __YZDirection3_H__
/*
	单位向量，可以保证所有接口获取的数据都是单位向量
	默认值是(0,0,1)，代表了方向
*/
#include "YZGeometry.h"
//#include "YZSerializeDeclare.h"

#include <osg/Vec3>

namespace YZ
{
	class Vector3;
	class GEOMETRY_API Direction3 : public osg::Vec3
	{
	//	SERIALIZE_DECLARE(Direction3)
	public:
		/*---------------
			构造
		----------------*/
		Direction3(void);
		Direction3(float x, float y, float z);
		Direction3(const osg::Vec3& value);
		explicit Direction3(float value[3]);
		Direction3(const Direction3& dir);
		~Direction3(void);

		/*---------------
			运算符
		----------------*/
		Direction3& operator=(const Direction3& dir);
		bool operator==(const Direction3& dir) const;
		bool operator!=(const Direction3& dir) const;
		Vector3 operator+(const float& inc) const;
		Vector3 operator+(const Direction3& dir) const;
		Vector3 operator+(const Vector3& vec) const;
		Vector3 operator-(const float& dec) const;
		Vector3 operator-(const Direction3& dir) const;
		Vector3 operator-(const Vector3& vec) const;
		Vector3 operator*(const float& scalar) const;

		//cross product，叉积，矢量积，结果垂直于两个向量
		Vector3 operator*(const Direction3& dir) const;
		Vector3 operator*(const Vector3& vec) const;

		//scalar product，内积
		//dot product，点积，标量积，结果为0则互相垂直
		float operator%(const Direction3& dir) const;
		float operator%(const Vector3& vec) const;

		Direction3 operator-(void) const;

		/*---------------
			常量
		----------------*/
		static const Direction3 ZERO;
		static const Direction3 UNIT_SCALE;
		static const Direction3 UNIT_X;
		static const Direction3 UNIT_Y;
		static const Direction3 UNIT_Z;
		static const Direction3 NEGATIVE_UNIT_X;
		static const Direction3 NEGATIVE_UNIT_Y;
		static const Direction3 NEGATIVE_UNIT_Z;

		/*---------------
			读写
		----------------*/
		//每次设置完数据都会单位化
		void set_value(const Direction3& dir);

		void get_value(float& dx, float& dy, float& dz) const;
		//const Direction3& getValue(void) const;

		/*---------------
			功能
		----------------*/
		virtual Direction3* clone(void) const;

		//0,0,0
		virtual void reset(void);

		//是否是零向量
		bool is_zero(const float res = GPresnul) const;

		//两个向量是否相同
		bool equal_to(const Direction3& dir, const float res = GPresabs) const;

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

		//根据Z轴计算出XY轴
		GEOMETRY_API friend void compute_axis_from_z(const Direction3& axisZ, Direction3& axisX, Direction3& axisY);

	protected:
		/*---------------
			内部
		----------------*/
		//单位化当前向量
		void normalise(void);
	};
}
#endif // __YZDirection3_H__