////////////
//    created by 孙庆号
////////////

#ifndef __YZ_SIMPLE_PLANE_H__
#define __YZ_SIMPLE_PLANE_H__

#include "osg/Geometry"
#include "osg/MatrixTransform"
#include "osg/LineWidth"
#include "osg/PolygonOffset"
#include "Nullable.h"
#include "QuadPrimitive.h"

	typedef QuadPrimitive SimplePlane;
namespace bimWorld
{
	//class ModifiedCallback :public osg::BufferData::ModifiedCallback
	//{
	//public:
	//	static ModifiedCallback* create(std::function<void(osg::BufferData*)> func)
	//	{
	//		auto callBack = new ModifiedCallback();
	//		callBack->m_func = func;
	//		return callBack;
	//	}

	//	virtual void modified(osg::BufferData* bufferData) const override {
	//		m_func(bufferData);
	//	}

	//protected:
	//	std::function<void(osg::BufferData*)> m_func;
	//};

	//class SimplePlane/* : public Geometry*/
	//{
	//public:
	//	SimplePlane(bool drawOutLine = false) /*:Geometry()*/
	//	{
	//		m_drawOutLine = drawOutLine;
	//	}

	//	void setGeoEffect(std::function<void(osg::Node*)> func)
	//	{
	//		m_geoEffect = func;
	//	}

	//	void setLineEffect(std::function<void(osg::Node*)> func)
	//	{
	//		m_lineEffect = func;
	//	}

	//	void setNeedDrawOutLine(bool draw)
	//	{
	//		m_drawOutLine = draw;
	//	}

	//	//osg::Node* createGeo(const osg::Vec3& center, const osg::Vec3& normal, const osg::Vec2& length);
	//	//osg::Node* createGeo(const osg::Vec3& center, const osg::Vec4& normal, const osg::Vec2& length);
	//	osg::Node* createGeo(const osg::Vec3& center, const osg::Vec3& localX, const osg::Vec3& localY, const osg::Vec2& length);

	//	void setCenter(const osg::Vec3f& center)
	//	{
	//		m_center = center;
	//	//	mat = osg::Matrix::translate(m_center);
	//	//	group->setMatrix(mat);
	//	//	//updateVertexArray();
	//		//createGeo(center, m_localX, m_localY, m_unitLength);
	//	}

	//	void setSize(float size)
	//	{
	//		//m_size = size;
	//		m_unitLength.set(size, size);
	//	}

	//protected:
	//	void applyGeoShader(osg::StateSet* stateSet)
	//	{
	//		const std::string vertexSource =
	//			"#version 330 \n"
	//			" \n"
	//			"uniform vec3 center; \n"
	//			"uniform mat4 osg_ModelViewProjectionMatrix; \n"
	//			"uniform vec4 mat_diffuse; \n"
	//			" \n"
	//			"layout (location = 0) in vec4 Position; \n"
	//			"layout (location = 1) in vec3 osg_Normal; \n"
	//			"layout (location = 3) in vec2 osg_Texcoord; \n"
	//			"out vec4 color; \n"
	//			"out vec2 Texcoord; \n"
	//			" \n"
	//			"void main() \n"
	//			"{ \n"
	//			//"    vec3 ecNormal = normalize( osg_NormalMatrix * osg_Normal ); \n"
	//			//"    float diffuse = max( dot( ecLightDir, ecNormal ), 0. ); \n"
	//			//"    color = vec4( diffuse * mat_diffuse.rgb, mat_diffuse.a ); \n"//
	//			"    color = mat_diffuse; \n"//
	//			"    Texcoord = osg_Texcoord;\n"
	//			"    gl_Position = osg_ModelViewProjectionMatrix * (Position + vec4(center, 0)); \n"
	//			"} \n";
	//		osg::Shader* vShader = new osg::Shader(osg::Shader::VERTEX, vertexSource);

	//		const std::string fragmentSource =
	//			"#version 330 \n"
	//			//"uniform sampler2D gDiffuseMap;\n"
	//			"in vec4 color; \n"
	//			"in vec2 Texcoord; \n"
	//			"out vec4 fragData; \n"
	//			" \n"
	//			"void main() \n"
	//			"{ \n"
	//			"    fragData = color; \n"
	//			//"    fragData = color*texture(gDiffuseMap, Texcoord); \n"
	//			"} \n";
	//		osg::Shader* fShader = new osg::Shader(osg::Shader::FRAGMENT, fragmentSource);

	//		osg::Program* program = new osg::Program;
	//		program->addShader(vShader);
	//		program->addShader(fShader);
	//		stateSet->setAttribute(program);

	//		auto uni = new osg::Uniform("center", m_center);
	//		uni->setUpdateCallback(new UniformUpdater([this](osg::Uniform* uni, unsigned int /*frameNum*/){
	//			uni->set(m_center);
	//		}));
	//		stateSet->addUniform(uni);
	//	}

	//	void applyLineShader(osg::StateSet* stateSet)
	//	{
	//		const std::string vertexSource =
	//			"#version 330 \n"
	//			" \n"
	//			"uniform vec3 center; \n"
	//			"uniform mat4 osg_ModelViewProjectionMatrix; \n"
	//			"uniform vec4 mat_diffuse; \n"
	//			" \n"
	//			"layout (location = 0) in vec4 Position; \n"
	//			"layout (location = 1) in vec3 osg_Normal; \n"
	//			"layout (location = 2) in vec4 osg_Color; \n"
	//			"layout (location = 3) in vec2 osg_Texcoord; \n"
	//			"out vec4 color; \n"
	//			"out vec2 Texcoord; \n"
	//			" \n"
	//			"void main() \n"
	//			"{ \n"
	//			//"    vec3 ecNormal = normalize( osg_NormalMatrix * osg_Normal ); \n"
	//			//"    float diffuse = max( dot( ecLightDir, ecNormal ), 0. ); \n"
	//			//"    color = vec4( diffuse * mat_diffuse.rgb, mat_diffuse.a ); \n"//
	//			"    color = osg_Color; \n"//
	//			"    Texcoord = osg_Texcoord;\n"
	//			"    gl_Position = osg_ModelViewProjectionMatrix * (Position + vec4(center, 0)); \n"
	//			"} \n";
	//		osg::Shader* vShader = new osg::Shader(osg::Shader::VERTEX, vertexSource);

	//		const std::string fragmentSource =
	//			"#version 330 \n"
	//			//"uniform sampler2D gDiffuseMap;\n"
	//			"in vec4 color; \n"
	//			"in vec2 Texcoord; \n"
	//			"out vec4 fragData; \n"
	//			" \n"
	//			"void main() \n"
	//			"{ \n"
	//			"    fragData = color; \n"
	//			//"    fragData = color*texture(gDiffuseMap, Texcoord); \n"
	//			"} \n";
	//		osg::Shader* fShader = new osg::Shader(osg::Shader::FRAGMENT, fragmentSource);

	//		osg::Program* program = new osg::Program;
	//		program->addShader(vShader);
	//		program->addShader(fShader);
	//		stateSet->setAttribute(program);

	//		auto uni = new osg::Uniform("center", m_center);
	//		uni->setUpdateCallback(new UniformUpdater([this](osg::Uniform* uni, unsigned int /*frameNum*/){
	//			uni->set(m_center);
	//		}));
	//		stateSet->addUniform(uni);
	//	}

	//	void updateVertexArray()
	//	{
	//		(*m_vertexArray)[0] = osg::Vec3(m_center - m_localX * m_unitLength.x() - m_localY * m_unitLength.y());
	//		(*m_vertexArray)[1] = osg::Vec3(m_center + m_localX * m_unitLength.x() - m_localY * m_unitLength.y());
	//		(*m_vertexArray)[2] = osg::Vec3(m_center + m_localX * m_unitLength.x() + m_localY * m_unitLength.y());
	//		(*m_vertexArray)[3] = osg::Vec3(m_center - m_localX * m_unitLength.x() + m_localY * m_unitLength.y());
	//	}

	//	osg::Geometry* createGeometry(const osg::Vec3& center, const osg::Vec2& length, const osg::Vec3& localX, const osg::Vec3& localY)
	//	{
	//		m_quad.createQuad(center, length, localX, localY);
	//		return m_quad.getGeometry();

	//		m_center = center;
	//		m_unitLength = length / 2.0f;
	//		m_localX = localX;
	//		m_localY = localY;
	//		m_vertexArray = new osg::Vec3Array;
	//		m_vertexArray->push_back(/*center*/ -localX * m_unitLength.x() - localY * m_unitLength.y());
	//		m_vertexArray->push_back(/*center*/ /*+*/ localX * m_unitLength.x() - localY * m_unitLength.y());
	//		m_vertexArray->push_back(/*center*/ /*+*/ localX * m_unitLength.x() + localY * m_unitLength.y());
	//		m_vertexArray->push_back(/*center*/ -localX * m_unitLength.x() + localY * m_unitLength.y());
	//		//osg::BufferData::ModifiedCallback
	//		//m_vertexArray->setModifiedCallback(ModifiedCallback::create([](osg::BufferData* data){
	//		//	auto vertexArray = dynamic_cast<osg::Vec3Array*>(data);
	//		//	auto s = vertexArray->at(0);
	//		//}));
	//		//vertexArray->push_back(center + osg::Vec3(-1.0f, 0, -1.0f)*length);
	//		//vertexArray->push_back(center + osg::Vec3(1.0f, 0, -1.0f)*length);
	//		//vertexArray->push_back(center + osg::Vec3(1.0f, 0, 1.0f)*length);
	//		//vertexArray->push_back(center + osg::Vec3(-1.0f, 0, 1.0f)*length);
	//		//m_vertexArray->setDataVariance(osg::Object::DYNAMIC);
	//		//vertexArray->setBinding(osg::Array::BIND_PER_VERTEX);
	//		//bufObj->addArray(vertexArray);

	//		osg::Vec3Array * normalArray = new osg::Vec3Array;
	//		normalArray->push_back(osg::Vec3(0, 1, 0));
	//		//normalArray->push_back(osg::Vec3(0, 1, 0));
	//		//normalArray->push_back(osg::Vec3(0, 1, 0));
	//		//normalArray->push_back(osg::Vec3(0, 1, 0));
	//		//normalArray->setBinding(osg::Array::BIND_PER_PRIMITIVE_SET);
	//		//bufObj->addArray(normalArray);

	//		osg::Vec2Array* texcoords = new osg::Vec2Array(4);
	//		(*texcoords)[0].set(0.0f, 0.0f);
	//		(*texcoords)[1].set(1.0f, 0.0f);
	//		(*texcoords)[2].set(1.0f, 1.0f);
	//		(*texcoords)[3].set(0.0f, 1.0f);
	//		//texcoords->setBinding(osg::Array::BIND_PER_VERTEX);
	//		//bufObj->addArray(texcoords);

	//		osg::ref_ptr<osg::Geometry> geometry = new osg::Geometry();
	//		geometry->setUseVertexBufferObjects(true);
	//		geometry->setVertexArray(m_vertexArray);
	//		geometry->setNormalArray(normalArray, osg::Array::BIND_PER_PRIMITIVE_SET);
	//		geometry->setTexCoordArray(0, texcoords, osg::Array::BIND_PER_VERTEX);
	//		geometry->addPrimitiveSet(new osg::DrawArrays(GL_QUADS, 0, 4));

	//		if (!m_geoEffect.empty())
	//		{
	//			m_geoEffect.get()(geometry);
	//		}
	//		applyGeoShader(geometry->getOrCreateStateSet());
	//		geometry->getOrCreateStateSet()->setAttributeAndModes(new osg::PolygonOffset(1.0f, 1.0f));
	//		return geometry.release();
	//	}

	//	osg::Geometry* createOutLine(const osg::Vec3& center, const osg::Vec2& length, const osg::Vec3& localX, const osg::Vec3& localY)
	//	{
	//		m_center = center;
	//		m_unitLength = length / 2.0f;
	//		m_localX = localX;
	//		m_localY = localY;
	//		m_vertexArray = new osg::Vec3Array;
	//		m_vertexArray->push_back(/*center*/ -localX * m_unitLength.x() - localY * m_unitLength.y());
	//		m_vertexArray->push_back(/*center*/ /*+*/ localX * m_unitLength.x() - localY * m_unitLength.y());
	//		m_vertexArray->push_back(/*center*/ /*+*/ localX * m_unitLength.x() + localY * m_unitLength.y());
	//		m_vertexArray->push_back(/*center*/ -localX * m_unitLength.x() + localY * m_unitLength.y());

	//		osg::Vec3Array * normalArray = new osg::Vec3Array;
	//		normalArray->push_back(osg::Vec3(0, 1, 0));
	//		//normalArray->setBinding(osg::Array::BIND_PER_PRIMITIVE_SET);
	//		//bufObj->addArray(normalArray);

	//		osg::Vec2Array* texcoords = new osg::Vec2Array(4);
	//		(*texcoords)[0].set(0.0f, 0.0f);
	//		(*texcoords)[1].set(1.0f, 0.0f);
	//		(*texcoords)[2].set(1.0f, 1.0f);
	//		(*texcoords)[3].set(0.0f, 1.0f);
	//		//texcoords->setBinding(osg::Array::BIND_PER_VERTEX);
	//		//bufObj->addArray(texcoords);

	//		osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array;		// <指定颜色，连成一条线的两个点需要用相同的颜色>
	//		colors->push_back(osg::Vec4(0.0f, 1.0f, 1.0f, 1.0f));

	//		osg::ref_ptr<osg::Geometry> geometry = new osg::Geometry();
	//		geometry->setUseVertexBufferObjects(true);
	//		geometry->setVertexArray(m_vertexArray);
	//		geometry->setColorArray(colors.get(), osg::Array::BIND_PER_PRIMITIVE_SET);
	//		geometry->setNormalArray(normalArray, osg::Array::BIND_PER_PRIMITIVE_SET);
	//		geometry->setTexCoordArray(0, texcoords, osg::Array::BIND_PER_VERTEX);
	//		geometry->addPrimitiveSet(new osg::DrawArrays(GL_LINE_LOOP, 0, 4));

	//		osg::ref_ptr <osg::LineWidth> lineWidth = new osg::LineWidth;
	//		lineWidth->setWidth(1);
	//		geometry->getOrCreateStateSet()->setAttributeAndModes(lineWidth.get(), osg::StateAttribute::ON);

	//		applyLineShader(geometry->getOrCreateStateSet());
	//		if (!m_lineEffect.empty())
	//		{
	//			m_lineEffect.get()(geometry);
	//		}
	//		return geometry.release();
	//	}

	//	osg::Vec2 m_unitLength;

	//	osg::Vec3 m_center;

	//	float m_size;

	//	osg::Vec3Array * m_vertexArray;

	//	osg::Vec3 m_localX, m_localY;
	//	osg::Matrix mat;
	//	//osg::ref_ptr<osg::Geode> geode;
	//	QuadPrimitive m_quad;
	//	bool m_drawOutLine;

	//	Nullable<std::function<void(osg::Node*)>> m_geoEffect;
	//	Nullable<std::function<void(osg::Node*)>> m_lineEffect;
	//};

	//osg::Node* SimplePlane::createGeo(const osg::Vec3& center, const osg::Vec3& localX, const osg::Vec3& localY, const osg::Vec2& length)
	//{
	//	m_quad.createQuad(center, length, localX, localY);
	//	return m_quad.getGeometry();
	//	////geometry->setDataVariance(osg::Object::DYNAMIC);
	//	//if (geode)
	//	//{
	//	//	geode->removeDrawables(0, geode->getNumDrawables());
	//	//}
	//	//else
	//	//{
	//	//	geode = new osg::Geode();
	//	//	geode->setDataVariance(osg::Object::DYNAMIC);
	//	//}
	//	//osg::Geometry* geometry = createGeometry(center, length, localX, localY);

	//	//geode->addDrawable(geometry);
	//	//if (m_drawOutLine)
	//	//{
	//	//	auto outLine = createOutLine(center, length, localX, localY);
	//	//	geode->addDrawable(outLine);
	//	//}
	//	////group = new osg::MatrixTransform();
	//	////mat = osg::Matrix::translate(m_center);
	//	////group->setMatrix(mat);
	//	////group->addChild(node.get());
	//	//return geode.get();
	//}

	//osg::Node* SimplePlane::createGeo(const osg::Vec3& center, const osg::Vec4& normal, const osg::Vec2& length)
	//{
	//	return NULL;
	//}

	//osg::Node* SimplePlane::createGeo(const osg::Vec3& center, const osg::Vec3& normal, const osg::Vec2& length)
	//{
	//	return createGeo(center, osg::Vec4(normal, 1), length);
	//}

}

#endif // __YZ_SIMPLE_PLANE_H__