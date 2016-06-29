#include "CppUnitTest.h"
#include <osgViewer/Viewer>
#include<iostream>
#include <gl/GL.h>
#include  "IplottingScale.h"
#include "PlottingScale.h"
#include <osgText/Text>
#include <osgDB/ReadFile>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ScaleUnitTest
{
	void configerShader(osg::StateSet* stateSet)
	{
		const std::string vertexSource =
			"#version 330 \n"
			"uniform int colorMode;      \n"// 1:color, 2:no light texture, 3:color & texture, 4: with light & texture
			" \n"
			"uniform vec4 clip_plane_xPositive = vec4(1.0, 0.0, 0.0, 0.49);\n"
			"uniform vec4 clip_plane_xNegative = vec4(-1.0, 0.0, 0.0, 0.49);\n"
			"uniform vec4 clip_plane_yPositive = vec4(0.0, 1.0, 0.0, 0.49);\n"
			"uniform vec4 clip_plane_yNegative = vec4(0.0, -1.0, 0.0, 0.49);\n"
			"uniform vec4 clip_plane_zPositive = vec4(0.0, 0.0, 1.0, 0.49);\n"
			"uniform vec4 clip_plane_zNegative = vec4(0.0, 0.0, -1.0, 0.49);\n"
			" \n"
			"uniform mat4 osg_ModelViewProjectionMatrix; \n"
			"uniform mat3 osg_NormalMatrix; \n"
			"uniform vec3 ecLightDir; \n"
			"uniform vec4 mat_diffuse; \n"
			" \n"
			"layout (location = 0) in vec4 Position; \n"
			"layout (location = 1) in vec3 osg_Normal; \n"
			"layout (location = 3) in vec2 osg_Texcoord; \n"
			"out vec4 color; \n"
			"out vec2 Texcoord; \n"
			" \n"
			"void main() \n"
			"{ \n"
			"    vec3 ecNormal = normalize( osg_NormalMatrix * osg_Normal ); \n"
			"    float diffuse = max( dot( ecLightDir, ecNormal ), 0. ); \n"
			"    if(colorMode == 4) \n"
			"		color = vec4( diffuse, diffuse, diffuse, 1 ); \n"//
			"    else \n"
			"		color = vec4( diffuse * mat_diffuse.rgb, mat_diffuse.a ); \n"//
			"    Texcoord = osg_Texcoord;\n"

			"    gl_ClipDistance[0] = dot(Position, clip_plane_xPositive);"
			"    gl_ClipDistance[1] = dot(Position, clip_plane_xNegative);"
			"    gl_ClipDistance[2] = dot(Position, clip_plane_yPositive);"
			"    gl_ClipDistance[3] = dot(Position, clip_plane_yNegative);"
			"    gl_ClipDistance[4] = dot(Position, clip_plane_zPositive);"
			"    gl_ClipDistance[5] = dot(Position, clip_plane_zNegative);"

			"    gl_Position = osg_ModelViewProjectionMatrix * Position; \n"
			"} \n";
		osg::Shader* vShader = new osg::Shader(osg::Shader::VERTEX, vertexSource);

		const std::string fragmentSource =
			"#version 330 \n"
			"uniform sampler2D gDiffuseMap;\n"
			"uniform int colorMode;      \n"// 1:color, 2:no light texture, 3:color & texture, 4: with light & texture
			"in vec4 color; \n"
			"in vec2 Texcoord; \n"
			"out vec4 fragData; \n"
			" \n"
			"void main() \n"
			"{ \n"
			"    if(colorMode == 1) \n"
			"		fragData = color; \n"
			"    else if(colorMode == 2) \n"
			"		fragData = texture(gDiffuseMap, Texcoord); \n"
			"    else if(colorMode == 3 || colorMode == 4) \n"
			"		fragData = color * texture(gDiffuseMap, Texcoord); \n"
			"} \n";
		osg::Shader* fShader = new osg::Shader(osg::Shader::FRAGMENT, fragmentSource);

		osg::Program* program = new osg::Program;
		program->addShader(vShader);
		program->addShader(fShader);
		stateSet->setAttribute(program);

		osg::Vec3f lightDir(0., 0.5, 1.);
		lightDir.normalize();
		stateSet->addUniform(new osg::Uniform("ecLightDir", lightDir));
		stateSet->addUniform(new osg::Uniform("gDiffuseMap", 0));
		stateSet->addUniform(new osg::Uniform("colorMode", 1));
		stateSet->addUniform(new osg::Uniform("mat_diffuse", osg::Vec4(1, 1, 1, 1)));
	}

	//std::function<void(IPlottingScale*)
	void funName(IPlottingScale* iplottingscale)
	{
		double Scale = 0.0;
		Scale = iplottingscale->getScale();
		std::cout << Scale << std::endl;
	}
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestMethod1)
		{
			// TODO:  在此输入测试代码
			//FacePrimitive *face = new FacePrimitive;
			//face->setColor(1.0f, 1.0f, 0.0f);
			//face->setPosition(10.0f, 1.0f, 0.0f, 5.0f, 10.0f, 10.0f, 25.0f, 26.0f, 0.0f);
			//osg::ref_ptr<osg::Geometry> geom = face->getGeometry();

			osg::ref_ptr<osg::Node> geode =  osgDB::readNodeFile("cow.osg");
			//geode->addDrawable(geom);
			osgViewer::Viewer viewer;
			auto manip = new osgGA::MultiTouchTrackballManipulator();
			viewer.setCameraManipulator(manip);
			osg::ref_ptr<osg::MatrixTransform>trans = new osg::MatrixTransform();
			PlottingScale *scale = new PlottingScale(manip, geode);// <这个是在堆栈里面，手动释放>


			trans->addChild(geode);


			osg::ref_ptr<osg::Group>root = new osg::Group;
			root->addChild(geode);

			viewer.setSceneData(root.get());
			viewer.run();
		}

	};
}