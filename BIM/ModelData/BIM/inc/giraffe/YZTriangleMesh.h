#ifndef __YZTriangleMesh_H__
#define __YZTriangleMesh_H__
/*
������Ƭʵ��
���ݶ��������ֵ��ȷ��ʵ�壬������ֵ����Ϊһ���ʾһ��������Ƭ������ֵ�ǽ���������
*/
#include "YZMeshSolid.h"

#define VESRION_TRIANGLE_MESH 2

namespace YZ
{
	class GEOMETRY_API TriangleMesh : public MeshSolid
	{
	public:
		TriangleMesh(void);
		TriangleMesh(const TriangleMesh& geometry, const osg::CopyOp& copyop = osg::CopyOp::SHALLOW_COPY);
		virtual ~TriangleMesh(void);

		META_Node(Giraffe, TriangleMesh);

		//virtual void drawImplementation(osg::RenderInfo& renderInfo) const;
		virtual GeometryItemType type(void) const{ return GIT_Solid_TriangleMesh; }
		virtual void sync(void);
		//virtual void presync(void);
		virtual void osg_integrate(osg::Geometry* osg);

		//
		void add_mesh(const std::vector<int>& meshs);
		int mesh_count(void) const;
		const std::vector<int>& get_mesh(int index) const;

		//
// 		void add_color(const osg::Vec4& color);
// 		int color_count(void) const;
// 		const osg::Vec4& get_color(int index) const;

		//��������DrawArray����ʽ���ɽ�osgGeometry
		void osg_integrate_array(osg::Geometry* osg);

		//void drawTriangle(osg::RenderInfo& renderInfo) const;

		//virtual GeometryItem* _clone(void) const;
		//virtual void reset(void);

		//����Ŀ�Ƿ���ͬ
		//virtual bool is_legal(void) const;

		//��������Ŀ
		//uInt face_count(void) const;

	protected:
		//����һ��std::vector<int>����һ�������������һ���ּ��λ���һ����������
		//������Ҫ�Լ�����
		std::vector<std::vector<int> > m_meshs;

		//mesh��Ӧ����ɫ
		//std::vector<osg::Vec4> m_colors;
	};
}
#endif // __YZTriangleMesh_H__