////////////
//    created by 孙庆号
////////////

#ifndef __SKY_BOX_H__
#define __SKY_BOX_H__
#include <osg/Depth>
#include <osg/TexGen>
#include <osg/TextureCubeMap>
#include <osg/ShapeDrawable>
#include <osg/Geode>
#include <osg/MatrixTransform>
#include <osgDB/ReadFile>
#include <osgUtil/CullVisitor>
#include <osgViewer/Viewer>

namespace bimWorld
{
	class SkyBox : public osg::Transform
	{
	public:
		SkyBox();
		SkyBox(const SkyBox& copy, osg::CopyOp copyop =
			osg::CopyOp::SHALLOW_COPY)
			: osg::Transform(copy, copyop) {}
		META_Node(osg, SkyBox);

		virtual bool computeLocalToWorldMatrix(osg::Matrix& matrix,
			osg::NodeVisitor* nv) const;
		virtual bool computeWorldToLocalMatrix(osg::Matrix& matrix,
			osg::NodeVisitor* nv) const;

		void setHDR(const std::string& filename, float radius);

		void createDrawable(float radius);

		void setCubeMap(const std::string& right, const std::string& left, const std::string& front, const std::string& back, const std::string& up, const std::string& down, float radius);
		
		void updateSkyBoxRadius(float radius);

	protected:
		void setEnvironmentMap(unsigned int unit, osg::Image* posX,
			osg::Image* negX, osg::Image* posY, osg::Image* negY,
			osg::Image* posZ, osg::Image* negZ);
		void setEnvironmentMap(unsigned int unit, osg::Image* hdr);
		virtual ~SkyBox() {}

		osg::Sphere* m_sphere;
	};
}

#endif // __SKY_BOX_H__