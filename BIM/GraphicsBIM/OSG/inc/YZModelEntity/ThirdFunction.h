#pragma once
#include <osgViewer/Viewer>
#include <osg/Group> 
#include <osg/Node> 
#include <osg/PositionAttitudeTransform>  
#include <osg/Camera>
#include <osg/Geode>
#include <osg/ShapeDrawable>
#include "IShader.h" 
#include <osg/MatrixTransform>

using namespace bimWorld;

class ThirdFunction
{
public:
	ThirdFunction();
	~ThirdFunction(void);
	//创建导航相机模块
	osg::ref_ptr<osg::Group>  CreateBirdHud(osg::ref_ptr<osgViewer::Viewer> viewer,
		const std::string& fileName,
		int x, int y, int width, int heigth,
		osg::Vec3d vecFlagScale = osg::Vec3(1.0, 1.0, 1.0), IShader* myShaderColor = NULL);
	//创建标志信息模块 
	osg::ref_ptr<osg::Group>  CreateGroupNode(IShader* myShaderColor = NULL);
	osg::ref_ptr<osg::Group>  CreateFontNode(IShader* myShaderFont = NULL);
	osg::ref_ptr<osg::MatrixTransform>  CreateBiaoZhiNode(const float(&_vecPos)[3], const float(&q_angle)[3], IShader* myShaderColor = NULL, IShader* myShaderFont = NULL);

};
