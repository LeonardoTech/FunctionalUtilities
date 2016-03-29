#include <osgDB/ReadFile>
#include <osg/Image>
#include <osgUtil/Simplifier>
#include <osg/Node>
#include <osg/Texture2D>
#include <osg/Material>

#include "Thumbtack.h"
using namespace thumbtack_thumbtack_thumbtack;

Thumbtack::Thumbtack()
: m_quadprimitive(new QuadPrimitive)
{
	center={ 1.0f, 1.0f, 1.0f };
	longth={ 10.0, 10.0 };
	localX={ 1.0f, 0.0f, 0.0f };
	localY={ 0.0f, 1.0f, 0.0f };

	Vertex vertex1 = { 1.0f, 0.0f, 0.0f };
	Vertex vertex2 = { 1.0f, 1.0f, 0.0f };
	Vertex vertex3 = { 0.0f, 1.0f, 0.0f };
	Vertex vertex4 = { 0.0f, 0.0f, 0.0f };

	VertexArray* vertices = new VertexArray(4);
	(*vertices)[0] = vertex1;
	(*vertices)[1] = vertex2;
	(*vertices)[2] = vertex3;
	(*vertices)[3] = vertex4;

	m_quadprimitive->createQuad(center, longth, localX, localY);
	setSize(30, 30);

	m_quadprimitive->setColor(1, 1, 1);
	m_geometry = m_quadprimitive->getGeometry();

	m_scale = 0.0;
}


Thumbtack::~Thumbtack()
{
}

void Thumbtack::setLevelImage(const std::string& level0, const std::string& level1, const std::string& level2)
{
	// <读取图片>
	m_level0Image = osgDB::readImageFile(level0);
	if (!m_level0Image.valid())
	{
		std::cout << "load level0 image falied" << std::endl;
		return;
	}		

	osg::ref_ptr<osg::Texture2D> cubemap0 = new osg::Texture2D;
	cubemap0->setImage(0, m_level0Image);
	m_geometry->getOrCreateStateSet()->setTextureAttributeAndModes(0, cubemap0.get(), osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);

 	m_level1Image = osgDB::readImageFile(level1);
 	if (!m_level1Image.valid())
 	{
 		std::cout << "load level1 image falied" << std::endl;
 		return;
 	} 
 	m_level2Image = osgDB::readImageFile(level2);
 	if (!m_level2Image.valid())
 	{
 		std::cout << "load level3 image falied" << std::endl;
 		return;
 	}
}

// <设置平面的大小>
void Thumbtack::setSize(float width, float height)
{
	m_quadprimitive->setWidth(width);
	m_quadprimitive->setHeight(height);
}

// <更换图片图片>
void Thumbtack::changImage(const std::string& imhePath, Layer level)
{
	m_levelChangeImage = osgDB::readImageFile(imhePath);
	if (!m_levelChangeImage.valid())
	{
		std::cout << "load imhePath image falied" << std::endl;
		return;
	}
	osg::ref_ptr<osg::Texture2D> cubemap4 = new osg::Texture2D;
	if (level ==Layer::Level0)
	{
		m_level0Image = m_levelChangeImage;
		cubemap4->setImage(0, m_level0Image);
	}
		
	else if (level == Layer::Level1)
	{
		m_level1Image = m_levelChangeImage;
		cubemap4->setImage(0, m_level1Image);
	}
		
	else if (level == Layer::Level2)
	{
		m_level2Image = m_levelChangeImage;
		cubemap4->setImage(0, m_level2Image);
	}
	if (m_geometry)
		m_geometry->getOrCreateStateSet()->setTextureAttributeAndModes(0, cubemap4.get(), osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
}

// <设置比例尺>
void Thumbtack::setLevelScale(float level0, float level1, float level2 )
{
	m_level0 = level0;
	m_level1 = level1;
	m_level2 = level2;
}

// <图片点击事件>
void Thumbtack::bindClick(long sequ,std::function<void(IThumbtack*)> click)
{
	m_click[sequ] = click; 
}

void Thumbtack::setLevelWidthAndHeight(float x1, float y1, float x2, float y2, float x3, float y3)
{
	m_level0Width = x1;
	m_level0Hight  = y1;
	m_level1Width = x2;
	m_level1Hight  = y2;
	m_level2Width = x3;
	m_level2Hight  = y3;
}


osg::Geometry* Thumbtack::getGeometry()
{
	return m_geometry.release();
}

void Thumbtack::triggerClick()
{
	if (m_click.size() != 0)
	{
		for (map<long, std::function<void(IThumbtack*)>>::iterator it = m_click.begin(); it != m_click.end(); it++)
		{
			(it->second)(this);
		}
	}
}

void Thumbtack::showDiffrentLevelThumbtack()
{
	if (m_scale != getScale())
	{
		if (getScale() == m_level0 )
		{
			setSize(m_level0Width, m_level0Hight);
			osg::ref_ptr<osg::Texture2D> cubemap4 = new osg::Texture2D;
			cubemap4->setImage(0, m_level0Image);
			if (m_geometry)
				m_geometry->getOrCreateStateSet()->setTextureAttributeAndModes(0, cubemap4.get(), osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
			m_scale = getScale();
		}
		else if (m_level1 == getScale())
		{
			setSize(m_level1Width, m_level1Hight);
			osg::ref_ptr<osg::Texture2D> cubemap4 = new osg::Texture2D;
			cubemap4->setImage(0, m_level1Image);
			if (m_geometry)
				m_geometry->getOrCreateStateSet()->setTextureAttributeAndModes(0, cubemap4.get(), osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
			m_scale = getScale();
		}
		else if (getScale()==m_level2)
		{
			setSize(m_level2Width, m_level2Hight);
			osg::ref_ptr<osg::Texture2D> cubemap4 = new osg::Texture2D;
			cubemap4->setImage(0, m_level2Image);
			if (m_geometry)
				m_geometry->getOrCreateStateSet()->setTextureAttributeAndModes(0, cubemap4.get(), osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
			m_scale = getScale();
		}

	}
}

float Thumbtack::getScale()
{
	return 0.5;
}
