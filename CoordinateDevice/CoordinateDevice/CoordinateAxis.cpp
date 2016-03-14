
#include "CoordinateAxis.h"
#include <osg/MatrixTransform>
#include "CoordinateUpdater.h"

/// @fn	osg::Geometry* createSimpleGeometry(float radius)
///
/// @brief ���ݲ�����ָ���İ뾶����һ������ϵ������һ��osg::Geometry*���͵ı���
/// 	   
/// @author	Admin
/// @date	2016/3/14
///
/// @param	radius	����ϵ�ı߳�.
///
/// @return	null if it fails, else the new simple geometry.
osg::Geometry* createSimpleGeometry(float radius)
{
	osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array(8);
	(*vertices)[0].set(0.0f, 0.0f, 0.0f);
	(*vertices)[1].set(radius, 0.0f, 0.0f);
	(*vertices)[2].set(0.0f, 0.0f, 0.0f);
	(*vertices)[3].set(0.0f, radius, 0.0f);
	(*vertices)[4].set(0.0f, 0.0f, 0.0f);
	(*vertices)[5].set(0.0f, 0.0f, radius);

	osg::ref_ptr<osg::DrawElementsUInt> indices = new osg::DrawElementsUInt(GL_LINES, 6);
	(*indices)[0] = 0; (*indices)[1] = 1; (*indices)[2] = 2; (*indices)[3] = 3;
	(*indices)[4] = 4; (*indices)[5] = 5;

	osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array;///ָ����ɫ������һ���ߵ���������Ҫ����ͬ����ɫ
	colors->push_back(osg::Vec4(0.0f, 0.0f, 1.0f, 0.5f));
	colors->push_back(osg::Vec4(0.0f, 0.0f, 1.0f, 0.5f));
	colors->push_back(osg::Vec4(0.0f, 1.0f, 0.0f, 0.5f));
	colors->push_back(osg::Vec4(0.0f, 1.0f, 0.0f, 0.5f));
	colors->push_back(osg::Vec4(1.0f, 0.0f, 0.0f, 0.5f));
	colors->push_back(osg::Vec4(1.0f, 0.0f, 0.0f, 0.5f));
	osg::ref_ptr<osg::Geometry> geom = new osg::Geometry;
	geom->setDataVariance(osg::Object::DYNAMIC);
	geom->setUseDisplayList(false);
	geom->setUseVertexBufferObjects(true);
	geom->setColorArray(colors.get());
	geom->setVertexArray(vertices.get());
	geom->setColorArray(colors.get());
	geom->setColorBinding(osg::Geometry::BIND_PER_VERTEX);//��Ҫ����ɫ�����ó�ÿ�������
	geom->addPrimitiveSet(indices.get());

	osg::ref_ptr <osg::LineWidth> LineSize = new osg::LineWidth;
	LineSize->setWidth(0.03f*radius);
	geom->getOrCreateStateSet()->setAttributeAndModes(LineSize.get(), osg::StateAttribute::ON);
	auto stateSet = geom->getOrCreateStateSet();
	stateSet->setMode(GL_LIGHTING, osg::StateAttribute::OFF);

	osgUtil::SmoothingVisitor::smooth(*geom);
	return geom.release();
}

void gl3FontShader(osg::StateSet* stateSet)
{
	const std::string vertexSource =
		"#version 330 \n"
		"uniform int colorMode;      \n"// 1:color, 2:mat color
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
		"    if(colorMode == 1) \n"
		"		color = osg_Color; \n"//
		"    else if(colorMode == 2) \n"
		"		color = mat_diffuse; \n"//
		"    Texcoord = osg_Texcoord;\n"

		"    gl_Position = osg_ModelViewProjectionMatrix * Position; \n"
		"} \n";
	osg::Shader* vShader = new osg::Shader(osg::Shader::VERTEX, vertexSource);

	const std::string fragmentSource =
		"#version 330 \n"
		"uniform sampler2D gDiffuseMap;\n"
		"in vec4 color; \n"
		"in vec2 Texcoord; \n"
		"out vec4 fragData; \n"
		" \n"
		"void main() \n"
		"{ \n"
		"    fragData = color * texture(gDiffuseMap, Texcoord).r; \n"
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
}

void gles2FontShader(osg::StateSet* stateSet)
{
	const std::string vertexSource =
		"uniform int colorMode;      \n"// 1:color, 2:mat color
		" \n"
		//"uniform mat4 osg_ModelViewProjectionMatrix; \n"
		//"uniform mat3 osg_NormalMatrix; \n"
		"uniform vec3 ecLightDir; \n"
		"uniform vec4 mat_diffuse; \n"
		" \n"
		"attribute vec4 osg_Position; \n"
		"attribute vec3 osg_Normal; \n"
		"attribute vec4 osg_Color; \n"
		//"attribute vec2 osg_Texcoord; \n"
		"varying vec4 color; \n"
		"varying vec2 Texcoord; \n"
		" \n"
		"void main() \n"
		"{ \n"
		"    vec3 ecNormal = normalize( gl_NormalMatrix * osg_Normal ); \n"
		"    float diffuse = max( dot( ecLightDir, ecNormal ), 0. ); \n"
		"    if(colorMode == 1) \n"
		"		color = osg_Color; \n"//
		"    else if(colorMode == 2) \n"
		"		color = mat_diffuse; \n"//
		"    Texcoord = gl_MultiTexCoord0;\n"//osg_Texcoord

		"    gl_Position = gl_ModelViewProjectionMatrix * osg_Position; \n"
		"} \n";
	osg::Shader* vShader = new osg::Shader(osg::Shader::VERTEX, vertexSource);

	const std::string fragmentSource =
		//"precision mediump float;                   \n"
		"uniform sampler2D gDiffuseMap;\n"
		"varying vec4 color; \n"//mediump
		"varying vec2 Texcoord; \n" //mediump
		" \n"
		"void main() \n"
		"{ \n"
		"    gl_FragColor = color * texture(gDiffuseMap, Texcoord).r; \n"//
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
}
/// @fn	osgText::Text* createText(const string name, const osg::Vec3 &position, const osg::Vec4 &color)
///
/// @brief	 ����Ļ�������֣�����ʾ������ָ�����ά����
///
/// @author	Admin
/// @date	2016/3/14
///
/// @param	name		��������ά����.
/// @param	position	�������ֵ�λ��.
/// @param	color   		���ֵ���ɫ.
///
/// @return	null if it fails, else the new text.

osgText::Text* createText(const string name, const osg::Vec3 &position, const osg::Vec4 &color){
	osg::ref_ptr<osgText::Text> Label = new osgText::Text();
	auto font = osgText::readFontFile("fonts/arial.ttf");//fonts/arial.ttf//SketchFlow Print.ttf
	Label->setFont(font);
	Label->setCharacterSize(size);//15.0f
	Label->setText(name);
	Label->setAxisAlignment(osgText::Text::SCREEN);
	Label->setDrawMode(osgText::Text::TEXT);
	//Label->setFontResolution(size, size);

	Label->setAlignment(osgText::Text::CENTER_CENTER);
	Label->setPosition(position);
	Label->setColor(color);
	gles2FontShader(Label->getOrCreateStateSet());
	return Label.release();
}
/// @fn	CoordinateAxis::CoordinateAxis(osgGA::MultiTouchTrackballManipulator* manip)
///
/// @brief	 ���캯������˽�б����ĳ�ʼ��
///
/// @author	Admin
/// @date	2016/3/14
///
/// @param [in,out]	manip	If non-null, the manip.

CoordinateAxis::CoordinateAxis(osgGA::MultiTouchTrackballManipulator* manip)
{
	m_manip = manip;
	update = new CoordinateUpdater(m_manip);
}

CoordinateAxis::~CoordinateAxis()
{
}

/// @fn	void CoordinateAxis::getAxisDirection(Axis ax, float &x, float &y, float &z)
///
/// @brief	 ͨ������ָ������������ȡ����
///
/// @author	Admin
/// @date	2016/3/14
///
/// @param	ax		 	The ax.
/// @param [in,out]	x	ָ���x����.
/// @param [in,out]	y	ָ���y����.
/// @param [in,out]	z	ָ���z����.
void CoordinateAxis::getAxisDirection(Axis ax, float &x, float &y, float &z) {
	osg::Vec3  result = update->getResult(ax);
	x = result._v[0];
	y = result._v[1];
	z = result._v[2];
}

/// @fn	osg::MatrixTransform* CoordinateAxis::setAxis(float x, float y, float radius, osg::Camera *camera)
///
/// @brief	ͨ��ָ���Ķ�ά��Ļ���껭������ϵ������ָ������ϵ�İ뾶���ȣ���Ҫ����Ļ�����Ϊ��������ȥ
///
/// @author	Admin
/// @date	2016/3/14
///
/// @param	x			  	��Ļ�Ķ�ά������.
/// @param	y			  	��Ļ�Ķ�ά������.
/// @param	radius		 ����ϵ �ı߳�.
/// @param [in]	camera	If non-null, the camera.
///
/// @return	null if it fails, else a pointer to an osg::MatrixTransform.
osg::MatrixTransform* CoordinateAxis::setAxis(float x, float y, float radius, osg::Camera *camera) {
	osg::ref_ptr<osg::Geode> geode = new osg::Geode;
	geode->addDrawable(createSimpleGeometry(radius));
	auto fontSize = radius * 0.5;
	auto  _xText = createText("x", osg::Vec3(radius + fontSize*0.6, 0.0f, 0.0f), osg::Vec4(0.0f, 0.0f, 1.0f, 1.0f), fontSize);
	auto  _yText = createText("y", osg::Vec3(0.0f, radius + fontSize*0.6, 0.0f), osg::Vec4(0.0f, 1.0f, 0.0f, 1.0f), fontSize);
	auto  _zText = createText("z", osg::Vec3(0.0f, 0.0f, radius + fontSize*0.6), osg::Vec4(1.0f, 0.0f, 0.0f, 1.0f), fontSize);
	
	osg::ref_ptr<osg::MatrixTransform> textGeode = new osg::MatrixTransform;
	
	auto transNode = new osg::MatrixTransform();

	transNode->setMatrix(osg::Matrix::translate(osg::Vec3(x, y, -100)));
	camera->addChild(transNode);
	transNode->addChild(textGeode.get());
	textGeode->addChild(geode.get());
	textGeode->addChild(_xText);
	textGeode->addChild(_yText);
	textGeode->addChild(_zText);

	textGeode->setUpdateCallback(update);
	return textGeode.release();

}