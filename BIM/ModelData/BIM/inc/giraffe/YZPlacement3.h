#ifndef __YZPlacement3_H__
#define __YZPlacement3_H__
/*
	代表三维空间中一个位置信息，包含了点和局部坐标系
*/
#include "YZGeometry.h"
//#include "YZSerializeDeclare.h"

#include "YZPosition3.h"
#include "YZDirection3.h"

namespace YZ
{
	class GEOMETRY_API Placement3
	{
	//	SERIALIZE_DECLARE(Placement3)
	public:
		/*---------------
			构造
		----------------*/
		//默认值都是原点(0,0,0)，X轴(1,0,0)，Y轴(0,1,0)，Z轴(0,0,1)
		Placement3(void);
		//Placement3(const Position3& origin = Position3::ORIGIN);
		//根据法向量会生成默认的XY轴
		//Placement3(const Direction3& normal, const Position3& origin = Position3::ORIGIN);
		//根据XY轴会生成Z轴，但是如果XY轴平行，则生成默认值，origin始终处理
		//Placement3(const Direction3& axisX, const Direction3& axisY, const Position3& origin = Position3::ORIGIN);
		//Placement3(const Direction3& axisY, const Direction3& axisZ, const Position3& origin = Position3::ORIGIN);
		//Placement3(const Direction3& axisZ, const Direction3& axisX, const Position3& origin = Position3::ORIGIN);
		Placement3(const Position3& origin, const Direction3& axisX, const Direction3& axisY, const Direction3& axisZ);
		Placement3(const Placement3& place);
		~Placement3(void);

		/*---------------
			运算符
		----------------*/
		Placement3& operator=(const Placement3& place);
		bool operator==(const Placement3& place) const;
		bool operator!=(const Placement3& place) const;

		/*---------------
			读写
		----------------*/
		void set_origin(float x, float y, float z);
		void set_origin(const Position3& orgin);
		//void set_axis(const Direction3& axisX, const Direction3& axisY, const Direction3& axisZ);
		//void set_axisx(float x, float y, float z);
		//void set_axisx(const Direction3& axisX);
		//void set_axisy(float x, float y, float z);
		//void set_axisy(const Direction3& axisY);

		//根据XY轴生成坐标系,会生成Z轴，但是如果XY轴平行，则生成默认值
		void set_plane_xy(const Direction3& axisX, const Direction3& axisY);

		//根据YZ生成坐标系轴,会生成X轴，但是如果YZ轴平行，则生成默认值
		void set_plane_yz(const Direction3& axisY, const Direction3& axisZ);

		//根据ZX生成坐标系轴,会生成Y轴，但是如果ZX轴平行，则生成默认值
		void set_plane_zx(const Direction3& axisZ, const Direction3& axisX);

		//根据Z轴生成坐标系，XY轴按默认方式生成
		void set_normal(const Direction3& axisZ);

		void get_origin(float& x, float& y, float& z) const;
		const Position3& get_origin(void) const;
		void get_axisx(float& x, float& y, float& z) const;
		const Direction3& get_axisx(void) const;
		void get_axisy(float& x, float& y, float& z) const;
		const Direction3& get_axisy(void) const;
		void get_axisz(float& x, float& y, float& z) const;
		const Direction3& get_axisz(void) const;
		void get_axis(Direction3& axisX, Direction3& axisY, Direction3& axisZ) const;

		/*---------------
			功能
		----------------*/
		virtual Placement3* clone(void) const;
		virtual void reset(void);

		void transf(const Transform3& transf);

	protected:
		/*---------------
			内部
		----------------*/
		//根据XY轴计算出Z轴，右手坐标系
		//如果XY轴平行，返回标准坐标系
		//如果XY轴不垂直，则以XY轴所在平面的法向量为Z轴，再以YZ所在平面的法向量为X轴形成坐标系
		//可以用该函数更新确认XYZ轴的垂直关系
		void update_axis_from_xy(const Direction3& axisX, const Direction3& axisY);

		//如果YZ轴不垂直，则以YZ轴所在平面的法向量为X轴，再以ZX所在平面的法向量为Y轴形成坐标系
		void update_axis_from_yz(const Direction3& axisY, const Direction3& axisZ);

		//如果ZX轴不垂直，则以ZX轴所在平面的法向量为Y轴，再以XY所在平面的法向量为Z轴形成坐标系
		void update_axis_from_zx(const Direction3& axisZ, const Direction3& axisX);

	protected:
		Position3 m_origin;
		Direction3 m_axisx;
		Direction3 m_axisy;
		Direction3 m_axisz;
	};
}
#endif // __YZPlacement3_H__