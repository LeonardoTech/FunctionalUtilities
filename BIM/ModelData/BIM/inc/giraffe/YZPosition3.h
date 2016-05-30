#ifndef __YZPosition3_H__
#define __YZPosition3_H__
/*
	代表三维空间中一个位置点信息
*/
#include "YZGeometry.h"
#include <osg/Vec3>
#include <osg/Array>
#include <osg/MixinVector>

namespace YZ
{
	class Vector3;
	class Transform3;

	enum PosDistType
	{
		PosDist_ALL, //三维空间距离
		PosDist_XY, //XY平面距离
		PosDist_YZ, //YZ平面距离
		PosDist_ZX, //ZX平面距离
	};

	class GEOMETRY_API Position3 : public osg::Vec3
	{
	public:
		Position3(void);
		Position3(float x, float y, float z);
		Position3(const osg::Vec3& value);
		explicit Position3(float value[3]);
		Position3(const Position3& pos);
		~Position3(void);

		//inline operator osg::Vec3*(){ return &m_value; }
		//inline operator osg::Vec3&(){ return m_value; }

		Position3& operator=(const Position3& pos);
		bool operator==(const Position3& pos) const;
		bool operator!=(const Position3& pos) const;
		Position3 operator-(void) const;

		//坐标的平移
		Position3 operator+(const Vector3& vec) const;
		Position3 operator-(const Vector3& vec) const;
		Position3& operator+=(const Vector3& vec);
		Position3& operator-=(const Vector3& vec);
		GEOMETRY_API friend Position3 operator+(const Vector3& vec, const Position3& pos);

		//求向量
		Vector3 operator-(const Position3& pos) const;

		//缩放
		Position3 operator*(const float& scalar) const;
		Position3 operator/(const float& scalar) const;
		Position3& operator*=(const float& scalar);
		Position3& operator/=(const float& scalar);
		GEOMETRY_API friend Position3 operator*(const float& scalar, const Position3& pos);
		GEOMETRY_API friend Position3 operator/(const float& scalar, const Position3& pos);

		static const Position3 ORIGIN;

		void set_x(float x);
		void set_y(float y);
		void set_z(float z);
		void set_value(const Position3& pos);

		void get_value(float& x, float& y, float& z) const;

		virtual Position3* clone(void) const;

		//0,0,0
		virtual void reset(void);

		//是否是零坐标
		bool is_zero(const float res = GPresnul) const;

		//两个坐标点是否相同
		bool equal_to(const Position3& pos, const float res = GPresabs) const;

		//距离另外一点的距离
		//type:0-三维距离，1-XY平面距离，2-YZ平面距离，3-ZX平面距离
		float dist_to(const Position3& pos, PosDistType type = PosDist_ALL) const;

		//转换为Vector3
		Vector3 as_vector(void) const;

		//取两个坐标数据中的最小值作为新数据
		void make_floor(const Position3& pos);

		//取两个坐标数据中的最大值作为新数据
		void make_ceil(const Position3& pos);

		//如果包含相同的点返回所在数组的索引值，没有返回-1
		int is_contained(const std::vector<Position3>& vctPt);
	};

	typedef osg::TemplateArray<Position3, osg::Array::Vec3dArrayType, 3, GL_DOUBLE> Pos3Array;
// 	osg::Pos3Array<Position3, osg::Array::Vec3dArrayType, 3, GL_DOUBLE>::operator osg::Vec3dArray*() const
// 	{
// 		return _impl;
// 	}
}
#endif // __YZPosition3_H__