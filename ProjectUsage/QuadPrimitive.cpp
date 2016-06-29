#include "QuadPrimitive.h"

#include <osg/Geometry>
#include "UniformUpdater.h"
#include "osg/LineWidth"
#include <osg/Geode>
#include <osg/PolygonOffset>

QuadPrimitive::QuadPrimitive()
{

	m_center = { 0.0f, 0.0f, 0.0f };
	m_localX = { 0.0f, 0.0f, 0.0f };
	m_localX = { 0.0f, 0.0f, 0.0f };
	m_unitLength = { 0.0f, 0.0f };
	m_height = 0.0f;
	m_width = 0.0f;
	m_vertexArray = new osg::Vec3Array(4);
	_colors = new osg::Vec4Array(1);
	_root = new osg::Geode();

	initGeo();
	initOutLine();
}



void QuadPrimitive::setVertices(Vertex vet1, Vertex vet2, Vertex vet3, Vertex vet4)
{
	osg::Vec3 vertex1 = { vet1.getX(), vet1.getY(), vet1.getZ() };
	(*m_vertexArray)[0] = vertex1;

	osg::Vec3 vertex2 = { vet2.getX(), vet2.getY(), vet2.getZ() };
	(*m_vertexArray)[1] = vertex2;

	osg::Vec3 vertex3 = { vet3.getX(), vet3.getY(), vet3.getZ() };
	(*m_vertexArray)[2] = vertex3;

	osg::Vec3 vertex4 = { vet4.getX(), vet4.getY(), vet4.getZ() };
	(*m_vertexArray)[3] = vertex4;

	m_vertexArray->dirty();
	_geometry->dirtyBound();
	_outLine->dirtyBound();
}

void QuadPrimitive::getVertices(Vertex& vet1, Vertex& vet2, Vertex& vet3, Vertex& vet4)
{
	vet1.set((*m_vertexArray)[0].x(), (*m_vertexArray)[0].y(), (*m_vertexArray)[0].z());
	vet2.set((*m_vertexArray)[1].x(), (*m_vertexArray)[1].y(), (*m_vertexArray)[1].z());
	vet3.set((*m_vertexArray)[2].x(), (*m_vertexArray)[2].y(), (*m_vertexArray)[2].z());
	vet4.set((*m_vertexArray)[3].x(), (*m_vertexArray)[3].y(), (*m_vertexArray)[3].z());
}

// <length是宽高，先宽后高>
//QuadPrimitive::QuadPrimitive(const osg::Vec3& center, const osg::Vec2& length, const osg::Vec3& localX, const osg::Vec3& localY):
//QuadPrimitive::QuadPrimitive()
void QuadPrimitive::updateQuad(const osg::Vec3& center, const osg::Vec2& length, const osg::Vec3& localX, const osg::Vec3& localY)
{
	m_center = center;
	m_width = length.x();
	m_height = length.y();
	m_unitLength = length / 2.0f;
	m_localX = localX;
	m_localY = localY;


	(*m_vertexArray)[0].set(center - localX * m_unitLength.x() - localY * m_unitLength.y());
	(*m_vertexArray)[1].set(center + localX * m_unitLength.x() - localY * m_unitLength.y());
	(*m_vertexArray)[2].set(center + localX * m_unitLength.x() + localY * m_unitLength.y());
	(*m_vertexArray)[3].set(center - localX * m_unitLength.x() + localY * m_unitLength.y());

	if (!m_geoEffect.empty())
	{
		m_geoEffect.get()(_geometry);
		applyGeoShader(_geometry->getOrCreateStateSet());
		_geometry->getOrCreateStateSet()->setAttributeAndModes(new osg::PolygonOffset(1.0f, 1.0f));
	}
	if (!m_lineEffect.empty())
	{
		m_lineEffect.get()(_outLine);
		osg::ref_ptr <osg::LineWidth> lineWidth = new osg::LineWidth;
		lineWidth->setWidth(1);
		_outLine->getOrCreateStateSet()->setAttributeAndModes(lineWidth.get(), osg::StateAttribute::ON);

		applyLineShader(_outLine->getOrCreateStateSet());
	}
	m_vertexArray->dirty();
	//_geometry->dirtyBound();
	if (m_drawOutLine)
	{
		_outLine->setNodeMask((unsigned int)-1);
	}
	else
	{
		_outLine->setNodeMask(0);
	}
	//_outLine->dirtyBound();
	_root->dirtyBound();
}

void QuadPrimitive::setHeight(float height)
{
	m_height = height;
	updateQuad(m_center, osg::Vec2{ m_width, m_height }, m_localX, m_localY);
}

void QuadPrimitive::setWidth(float width)
{
	m_width = width;
	updateQuad(m_center, osg::Vec2{ m_width, m_height }, m_localX, m_localY);
}


void QuadPrimitive::setColor(float red, float green, float blue)
{
	osg::Vec4 color = { red, green, blue, 1.0f };
	(*_colors)[0] = color;
	_colors->dirty();
}

osg::Node* QuadPrimitive::getRoot()
{
	return _root;
}

osg::Geometry* QuadPrimitive::getGeometry()
{
	return _geometry;
}

osg::Geometry* QuadPrimitive::getOutLine()
{
	return _outLine;
}


void QuadPrimitive::setVertices(const VertexArray& arr)
{
	osg::Vec3 vec = { 0.0f, 0.0f, 0.0f };
	int i = 0;
	for ( i = 0; i < arr.size(); i++)
	{
		(*m_vertexArray)[i].set(arr[i].getX(),arr[i].getY(),arr[i].getZ());
		vec += {arr[i].getX(), arr[i].getY(), arr[i].getZ()};
	}
	m_center = vec / 4.0;
	m_height = ((*m_vertexArray)[1] - (*m_vertexArray)[0]).length();
	m_width = ((*m_vertexArray)[2] - (*m_vertexArray)[1]).length();

	m_vertexArray->dirty();
	_geometry->dirtyBound();
	_outLine->dirtyBound();
}



VertexArray QuadPrimitive::getVertices() const
{
	VertexArray arr(m_vertexArray->size());
	for (int i = 0; i < m_vertexArray->size(); i++)
	{
		std::vector<float> vf;
		vf.push_back((*m_vertexArray)[i].x());
		vf.push_back((*m_vertexArray)[i].y());
		vf.push_back((*m_vertexArray)[i].z());
		arr[i].setVertices(vf);
		(*m_vertexArray)[i].set(arr[i].getX(), arr[i].getY(), arr[i].getZ());
	}
	return arr;
}

void QuadPrimitive::setNeedDrawOutLine(bool draw)
{
	m_drawOutLine = draw;
}

void QuadPrimitive::setCenter(const osg::Vec3f& center)
{
	m_center = center;
	//updateQuad(m_center, osg::Vec2{ m_width, m_height }, m_localX, m_localY);
}

void QuadPrimitive::setSize(float width, float height)
{
	m_width = width;
	m_height = height;
	updateQuad(m_center, osg::Vec2{ m_width, m_height }, m_localX, m_localY);
}

void QuadPrimitive::applyGeoShader(osg::StateSet* stateSet)
{
	const std::string vertexSource =
		"#version 330 \n"
		" \n"
		"uniform vec3 center; \n"
		"uniform mat4 osg_ModelViewProjectionMatrix; \n"
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
		//"    vec3 ecNormal = normalize( osg_NormalMatrix * osg_Normal ); \n"
		//"    float diffuse = max( dot( ecLightDir, ecNormal ), 0. ); \n"
		//"    color = vec4( diffuse * mat_diffuse.rgb, mat_diffuse.a ); \n"//
		"    color = mat_diffuse; \n"//
		"    Texcoord = osg_Texcoord;\n"
		"    gl_Position = osg_ModelViewProjectionMatrix * (Position + vec4(center, 0)); \n"
		"} \n";
	osg::Shader* vShader = new osg::Shader(osg::Shader::VERTEX, vertexSource);

	const std::string fragmentSource =
		"#version 330 \n"
		//"uniform sampler2D gDiffuseMap;\n"
		"in vec4 color; \n"
		"in vec2 Texcoord; \n"
		"out vec4 fragData; \n"
		" \n"
		"void main() \n"
		"{ \n"
		"    fragData = color; \n"
		//"    fragData = color*texture(gDiffuseMap, Texcoord); \n"
		"} \n";
	osg::Shader* fShader = new osg::Shader(osg::Shader::FRAGMENT, fragmentSource);

	osg::Program* program = new osg::Program;
	program->addShader(vShader);
	program->addShader(fShader);
	stateSet->setAttribute(program);

	auto uni = new osg::Uniform("center", m_center);
	uni->setUpdateCallback(new UniformUpdater([this](osg::Uniform* uni, unsigned int /*frameNum*/){
		uni->set(m_center);
	}));
	stateSet->addUniform(uni);
}

void QuadPrimitive::applyLineShader(osg::StateSet* stateSet)
{
	const std::string vertexSource =
		"#version 330 \n"
		" \n"
		"uniform vec3 center; \n"
		"uniform mat4 osg_ModelViewProjectionMatrix; \n"
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
		//"    vec3 ecNormal = normalize( osg_NormalMatrix * osg_Normal ); \n"
		//"    float diffuse = max( dot( ecLightDir, ecNormal ), 0. ); \n"
		//"    color = vec4( diffuse * mat_diffuse.rgb, mat_diffuse.a ); \n"//
		"    color = osg_Color; \n"//
		"    Texcoord = osg_Texcoord;\n"
		"    gl_Position = osg_ModelViewProjectionMatrix * (Position + vec4(center, 0)); \n"
		"} \n";
	osg::Shader* vShader = new osg::Shader(osg::Shader::VERTEX, vertexSource);

	const std::string fragmentSource =
		"#version 330 \n"
		//"uniform sampler2D gDiffuseMap;\n"
		"in vec4 color; \n"
		"in vec2 Texcoord; \n"
		"out vec4 fragData; \n"
		" \n"
		"void main() \n"
		"{ \n"
		"    fragData = color; \n"
		//"    fragData = color*texture(gDiffuseMap, Texcoord); \n"
		"} \n";
	osg::Shader* fShader = new osg::Shader(osg::Shader::FRAGMENT, fragmentSource);

	osg::Program* program = new osg::Program;
	program->addShader(vShader);
	program->addShader(fShader);
	stateSet->setAttribute(program);

	auto uni = new osg::Uniform("center", m_center);
	uni->setUpdateCallback(new UniformUpdater([this](osg::Uniform* uni, unsigned int /*frameNum*/){
		uni->set(m_center);
	}));
	stateSet->addUniform(uni);
}

void QuadPrimitive::initGeo()
{
	osg::Vec2Array* texcoords = new osg::Vec2Array(4);
	(*texcoords)[0].set(0.0f, 0.0f);
	(*texcoords)[1].set(1.0f, 0.0f);
	(*texcoords)[2].set(1.0f, 1.0f);
	(*texcoords)[3].set(0.0f, 1.0f);

	osg::Vec3Array * normalArray = new osg::Vec3Array;
	normalArray->push_back(osg::Vec3(0, 1, 0));

	_geometry = new osg::Geometry();
	_geometry->setUseVertexBufferObjects(true);
	_geometry->setVertexArray(m_vertexArray);
	_geometry->setColorArray(_colors);
	_geometry->setColorBinding(osg::Geometry::BIND_OVERALL);
	_geometry->setNormalArray(normalArray, osg::Array::BIND_PER_PRIMITIVE_SET);
	_geometry->setTexCoordArray(0, texcoords, osg::Array::BIND_PER_VERTEX);
	_geometry->addPrimitiveSet(new osg::DrawArrays(GL_QUADS, 0, 4));
	
	if (!m_geoEffect.empty())
	{
		m_geoEffect.get()(_geometry);
	}
	applyGeoShader(_geometry->getOrCreateStateSet());
	_geometry->getOrCreateStateSet()->setAttributeAndModes(new osg::PolygonOffset(1.0f, 1.0f));
	_root->addChild(_geometry);
}

void QuadPrimitive::initOutLine()
{
	osg::Vec3Array * normalArray = new osg::Vec3Array;
	normalArray->push_back(osg::Vec3(0, 1, 0));
	//normalArray->setBinding(osg::Array::BIND_PER_PRIMITIVE_SET);
	//bufObj->addArray(normalArray);

	osg::Vec2Array* texcoords = new osg::Vec2Array(4);
	(*texcoords)[0].set(0.0f, 0.0f);
	(*texcoords)[1].set(1.0f, 0.0f);
	(*texcoords)[2].set(1.0f, 1.0f);
	(*texcoords)[3].set(0.0f, 1.0f);
	//texcoords->setBinding(osg::Array::BIND_PER_VERTEX);
	//bufObj->addArray(texcoords);

	osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array;		// <指定颜色，连成一条线的两个点需要用相同的颜色>
	colors->push_back(osg::Vec4(0.0f, 1.0f, 1.0f, 1.0f));

	_outLine = new osg::Geometry();
	_outLine->setUseVertexBufferObjects(true);
	_outLine->setVertexArray(m_vertexArray);
	_outLine->setColorArray(colors.get(), osg::Array::BIND_PER_PRIMITIVE_SET);
	_outLine->setNormalArray(normalArray, osg::Array::BIND_PER_PRIMITIVE_SET);
	_outLine->setTexCoordArray(0, texcoords, osg::Array::BIND_PER_VERTEX);
	_outLine->addPrimitiveSet(new osg::DrawArrays(GL_LINE_LOOP, 0, 4));

	osg::ref_ptr <osg::LineWidth> lineWidth = new osg::LineWidth;
	lineWidth->setWidth(1);
	_outLine->getOrCreateStateSet()->setAttributeAndModes(lineWidth.get(), osg::StateAttribute::ON);

	applyLineShader(_outLine->getOrCreateStateSet());
	if (!m_lineEffect.empty())
	{
		m_lineEffect.get()(_outLine);
	}
	_root->addChild(_outLine);
}

void QuadPrimitive::setGeoEffect(std::function<void(osg::Node*)> func)
{
	m_geoEffect = func;
}

void QuadPrimitive::setLineEffect(std::function<void(osg::Node*)> func)
{
	m_lineEffect = func;
}



