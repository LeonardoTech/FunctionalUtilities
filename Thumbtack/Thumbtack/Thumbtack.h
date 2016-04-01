#ifndef __THUMBTACK_H__
#define __THUMBTACK_H__
#include <osg/DrawPixels>
#include <osg/Geode>
#include <osg/LOD>
#include <osgUtil/Simplifier>
#include <osg/Switch>
#include <memory>

#include "IThumbtack.h"
#include "../../BasicFunctionality/inc/IQuadPrimitive.h"
#include "../../BasicFunctionality/source/inc/QuadPrimitive.h"

using namespace thumbtack_thumbtack_ithumbtack;

namespace thumbtack_thumbtack_thumbtack
{
	class Thumbtack :
		public IThumbtack
	{
	public:
		Thumbtack();
		~Thumbtack();

		virtual void setLevelImage(const std::string& level0, const std::string& level1, const std::string& level2) override;

		virtual void bindClick(long,std::function<void(IThumbtack*)> click) override;

		
		virtual void setSize(float width, float height) override;

		virtual void changImage(const std::string& imhePath, Layer level) override;

		virtual void setLevelScale(float level0, float level1, float level2) override;

		virtual void setLevelWidthAndHeight(float w1, float h1, float w2, float h2, float w3, float h3) override;
		
		//internal
		osg::Geometry* getGeometry();
		osg::LOD* getLod();
		float getScale();
		virtual void triggerClick();
		void showDifferentLevelThumbtack();
	protected:
		osg::ref_ptr<osg::Image> m_level0Image;
		osg::ref_ptr<osg::Image> m_level1Image;
		osg::ref_ptr<osg::Image> m_level2Image;
		osg::ref_ptr<osg::Image> m_levelChangeImage;
		osg::ref_ptr<osg::Geometry>  m_geometry;
		std::unique_ptr<QuadPrimitive> m_quadprimitive;
		osg::Vec3 center;
		osg::Vec2 longth;
		osg::Vec3 localX;
		osg::Vec3 localY;

		float m_level0;
		float m_level1;
		float m_level2;
		float m_scale;

		float m_level0Width;
		float m_level0Hight;
		float m_level1Width;
		float m_level1Hight;
		float m_level2Width;
		float m_level2Hight;
	
		std::map<long, std::function<void(IThumbtack*)>> m_click;
		
	};
}


#endif