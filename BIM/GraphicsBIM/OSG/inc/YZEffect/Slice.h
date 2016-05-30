////////////
//    created by 孙庆号
////////////

#ifndef __YZ_SLICE_H__
#define __YZ_SLICE_H__
#include "config.h"
#include "IEffect.h"
#include "SlicePlaneDirection.h"
#include "osg/Geode"
#include "osg/ShapeDrawable"
#include "D:\\WorkSpace\\BIM\\GraphicsBIM\\OSG\inc\\YZGraphics\\QuadPrimitive.h"
#include "D:\\WorkSpace\\BIM\\GraphicsBIM\\OSG\\inc\\YZMaterial\\YZEffectModule.h"

namespace bimWorld
{

	class YIZHU_EXPORT Slice : public YZEffectModule, public IEffect
	{
	public:
		Slice(YZEffect* host);

		virtual bool apply(osg::Node* node) override;
		virtual void setSlicePlaneEnabled(SlicePlaneDirection direction, bool enabled, osg::Node* node, osg::BoundingBox box);
		virtual void setSlicePlanePosition(SlicePlaneDirection direction, float posX, float posY, float posZ, float offset);
		virtual bool getSlicePlanePosition(SlicePlaneDirection direction, float& posX, float& posY, float& posZ, float& offset);
		virtual void setSlicePlaneVisibility(SlicePlaneDirection direction, bool visible);
		//virtual void setSize(float size);

		//internal:
		virtual bool getSlicePlanePosition(SlicePlaneDirection direction, osg::Vec4f& position);
		virtual void setSlicePlanePosition(SlicePlaneDirection direction, osg::Vec4f position);

		virtual osg::Node* getPlaneGeometry(SlicePlaneDirection direction);

		void createZNegativePlane(float size, const osg::Vec3& position);
		void createZNegativePlane(float xLenth, float yLength, const osg::Vec3& position);

		void createZPositivePlane(float size, const osg::Vec3& position);
		void createZPositivePlane(float xLenth, float yLength, const osg::Vec3& position);

		void createYNegativePlane(float size, const osg::Vec3& position);
		void createYNegativePlane(float xLenth, float yLength, const osg::Vec3& position);

		void createYPositivePlane(float size, const osg::Vec3& position);
		void createYPositivePlane(float xLenth, float yLength, const osg::Vec3& position);

		void createXNegativePlane(float size, const osg::Vec3& position);
		void createXNegativePlane(float xLenth, float yLength, const osg::Vec3& position);

		void createXPositivePlane(float size, const osg::Vec3& position);
		void createXPositivePlane(float xLenth, float yLength, const osg::Vec3& position);

		void setNeedDrawOutLine(bool drawOutLine);

		void reset(osg::Node* node, osg::BoundingBox box);

	protected:

		osg::Vec4f clip_plane_xPositive;
		osg::Vec4f clip_plane_xNegative;
		osg::Vec4f clip_plane_yPositive;
		osg::Vec4f clip_plane_yNegative;
		osg::Vec4f clip_plane_zPositive;
		osg::Vec4f clip_plane_zNegative;

		bool enable_clip_plane_xPositive;
		bool enable_clip_plane_xNegative;
		bool enable_clip_plane_yPositive;
		bool enable_clip_plane_yNegative;
		bool enable_clip_plane_zPositive;
		bool enable_clip_plane_zNegative;

		bool clip_plane_xPositive_visible;
		bool clip_plane_xNegative_visible;
		bool clip_plane_yPositive_visible;
		bool clip_plane_yNegative_visible;
		bool clip_plane_zPositive_visible;
		bool clip_plane_zNegative_visible;

		//osg::Plane* clip_plane_shp_xPositive;
		//osg::Plane* clip_plane_shp_xNegative;
		//osg::Plane* clip_plane_shp_yPositive;
		//osg::Plane* clip_plane_shp_yNegative;
		//osg::Plane* clip_plane_shp_zPositive;
		//osg::Plane* clip_plane_shp_zNegative;

		std::unique_ptr<QuadPrimitive> clip_plane_simp_xPositive;
		std::unique_ptr<QuadPrimitive> clip_plane_simp_xNegative;
		std::unique_ptr<QuadPrimitive> clip_plane_simp_yPositive;
		std::unique_ptr<QuadPrimitive> clip_plane_simp_yNegative;
		std::unique_ptr<QuadPrimitive> clip_plane_simp_zPositive;
		std::unique_ptr<QuadPrimitive> clip_plane_simp_zNegative;

		//osg::Box* clip_plane_shp_xPositive;
		//osg::Box* clip_plane_shp_xNegative;
		//osg::Plane* clip_plane_shp_yPositive;
		//osg::Plane* clip_plane_shp_yNegative;
		//osg::Plane* clip_plane_shp_zPositive;
		//osg::Plane* clip_plane_shp_zNegative;

		osg::ref_ptr<osg::Node> clip_plane_geo_xPositive;
		osg::ref_ptr<osg::Node> clip_plane_geo_xNegative;
		osg::ref_ptr<osg::Node> clip_plane_geo_yPositive;
		osg::ref_ptr<osg::Node> clip_plane_geo_yNegative;
		osg::ref_ptr<osg::Node> clip_plane_geo_zPositive;
		osg::ref_ptr<osg::Node> clip_plane_geo_zNegative;

		osg::Vec3 m_startPos;

		bool m_drawOutLine;
	};
}

#endif // __YZ_SLICE_H__