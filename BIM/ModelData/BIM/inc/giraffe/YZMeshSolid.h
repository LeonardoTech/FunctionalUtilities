#ifndef __YZMeshSolid_H__
#define __YZMeshSolid_H__
/*
	由网格构成的几何实体数据基类
*/
#include "YZSolid.h"

#define VESRION_MESH_SOLID 2

namespace YZ
{
	struct osgPointInfo
	{
		int m_index;
		std::vector<int> m_indexArray;
		//osg::Vec3* m_point;
		osg::Vec3* m_normal;
		std::vector<Vector3> m_tempNormal;
	};

	class GEOMETRY_API MeshSolid : public Solid
	{
	public:
		MeshSolid(void);
		MeshSolid(const MeshSolid& geometry, const osg::CopyOp& copyop = osg::CopyOp::SHALLOW_COPY);
		virtual ~MeshSolid(void);

		virtual void transf(const Transform3& transf);

		void add_point(float dx, float dy, float dz);
		void add_point(const Position3& pos);
		void add_points(const std::vector<Position3>& points);
		//void set_points(const Pos3Array& points);
		//void set_points(Pos3Array* points);
		//void set_points(osg::Vec3Array* points);
		//void set_points(const std::vector<Position3>& points);

		const std::vector<Position3>& get_points(void) const;
		std::vector<Position3>& get_points(void);
		//osg::Vec3Array* get_points(void);

		//
		//void add_color(float dx, float dy, float dz);
		//void add_colors(const std::vector<Position3>& colors);

		//std::vector<Position3> get_colors(void) const;

		//判断当前网格数据是否合法
		//virtual bool is_legal(void) const;

		//坐标点数目
		int point_count(void) const;

		//坐标点是否为空
		bool is_empty(void) const;

	protected:
		std::vector<Position3> m_points;
	};
}
#endif // __GPMeshSolid_H__