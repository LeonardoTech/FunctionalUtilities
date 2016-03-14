#include "stdafx.h"
#include "CppUnitTest.h"
#include "ModelController.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:

		void gl3DefaultShader(osg::StateSet* stateSet)
		{
			const std::string vertexSource =
				"#version 330 \n"
				"uniform int colorMode;      \n"// 1:light, 2:no light texture, 3:color & texture, 4: with light & texture, 5: color, 6: color & texture
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
				"layout (location = 2) in vec4 osg_Color; \n"
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
				"    else if(colorMode == 5 || colorMode == 6 || colorMode == 7) \n"
				"		color = osg_Color; \n"//
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
				"uniform int colorMode;      \n"// 1:light, 2:no light texture, 3:light color & texture, 4: with light & texture, 5: color, 6: color & texture, 7: font
				"in vec4 color; \n"
				"in vec2 Texcoord; \n"
				"out vec4 fragData; \n"
				" \n"
				"void main() \n"
				"{ \n"
				"    if(colorMode == 1 || colorMode == 5) \n"
				"		fragData = color; \n"
				"    else if(colorMode == 2) \n"
				"		fragData = texture(gDiffuseMap, Texcoord); \n"
				"    else if(colorMode == 3 || colorMode == 4 || colorMode == 6) \n"
				"		fragData = color * texture(gDiffuseMap, Texcoord); \n"
				"    else if(colorMode == 7) \n"
				"		fragData = color * texture(gDiffuseMap, Texcoord).r; \n"
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
			stateSet->addUniform(new osg::Uniform("colorMode", 5));
		}

		TEST_METHOD(TestMethod1)
		{
			// TODO:  在此输入测试代码
			osg::ref_ptr<osg::Group> root = new osg::Group;
			osgViewer::Viewer view;

			auto manip = new osgGA::MultiTouchTrackballManipulator();
			view.setCameraManipulator(manip);
			osg::ref_ptr<osg::Geode> textGeode = new osg::Geode;
			osg::ref_ptr<osg::Camera> camera = createHUDCamera(0, 800, 0, 600);
			CoordinateAxis *axis = new CoordinateAxis(manip);
			osg::ref_ptr<osg::MatrixTransform>tran = axis->setAxis(180.0f, 180.0f, 40.0f, camera);
			/*axis->getAxisDirection(Y_Axis, x, y, z);
			cout << x << " " << y << " " << z << endl;*/
			osg::ref_ptr<osgText::Text>text = new osgText::Text;
			osg::ref_ptr<osgText::Font> g_font = osgText::readFontFile("fonts/arial.ttf");
			text->setFont(g_font.get());
			text->setCharacterSize(20.0f);
			text->setAxisAlignment(osgText::TextBase::XY_PLANE);
			text->setDataVariance(osg::Object::DYNAMIC);
			text->setPosition(osg::Vec3(750.0f, 700.0f, 0.0f));
			//camera->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::OFF);
			osg::ref_ptr<ModelController> ctrler = new ModelController(tran.get(), axis,text);
			textGeode->addDrawable(text);
			camera->addChild(textGeode);
			view.addEventHandler(ctrler.get());
			root->addChild(camera);
			gl3DefaultShader(root->getOrCreateStateSet());
			//root->getOrCreateStateSet()->setMode(GL_BLEND, osg::StateAttribute::ON);
			//root->getOrCreateStateSet()->setRenderingHint(osg::StateSet::TRANSPARENT_BIN);
			view.setSceneData(root.get());
			view.run();
		}

	};
}