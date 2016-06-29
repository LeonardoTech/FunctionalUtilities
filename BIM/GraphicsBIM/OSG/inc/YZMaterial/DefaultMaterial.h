////////////
//    created by 孙庆号
////////////

#ifndef __DEFAULT_MATERIAL_H__
#define __DEFAULT_MATERIAL_H__

#include "config.h"
#include <osg/StateSet>
#include <osg/Material>

namespace bimWorld
{
	class YIZHU_EXPORT DefaultMaterial// :public osg::Material
	{
	public:
		DefaultMaterial();

		void apply(osg::StateSet* set, osg::StateAttribute::OverrideValue value = osg::StateAttribute::ON);

		// osg::Material

		inline void setColorMode(osg::Material::ColorMode mode) { m_Mat->setColorMode(mode); }
		inline osg::Material::ColorMode getColorMode() const { return m_Mat->getColorMode(); }

		void setAmbient(osg::Material::Face face, const osg::Vec4& ambient){ m_Mat->setAmbient(face, ambient); }
		const osg::Vec4& getAmbient(osg::Material::Face face) const{ return m_Mat->getAmbient(face); }
		inline bool getAmbientFrontAndBack() const { return m_Mat->getAmbientFrontAndBack(); }

		void setDiffuse(osg::Material::Face face, const osg::Vec4& diffuse){ m_Mat->setDiffuse(face, diffuse); }
		const osg::Vec4& getDiffuse(osg::Material::Face face) const{ return m_Mat->getDiffuse(face); }
		inline bool getDiffuseFrontAndBack() const { return m_Mat->getDiffuseFrontAndBack(); }

		/** Set specular value of specified face(s) of the material,
		* valid specular[0..3] range is 0.0 to 1.0.
		*/
		void setSpecular(osg::Material::Face face, const osg::Vec4& specular){ m_Mat->setSpecular(face, specular); }

		/** Get the specular value for specified face. */
		const osg::Vec4& getSpecular(osg::Material::Face face) const{ return m_Mat->getSpecular(face); }

		/** Return whether specular values are equal for front and back faces
		* or not.
		*/
		inline bool getSpecularFrontAndBack() const { return m_Mat->getSpecularFrontAndBack(); }

		/** Set emission value of specified face(s) of the material,
		* valid emission[0..3] range is 0.0 to 1.0.
		*/
		void setEmission(osg::Material::Face face, const osg::Vec4& emission){ m_Mat->setEmission(face, emission); }

		/** Get the emission value for specified face. */
		const osg::Vec4& getEmission(osg::Material::Face face) const{ return m_Mat->getEmission(face); }

		/** Return whether emission values are equal for front and back faces
		* or not.
		*/
		inline bool getEmissionFrontAndBack() const { return m_Mat->getEmissionFrontAndBack(); }

		/** Set shininess of specified face(s) of the material.
		* valid shininess range is 0.0 to 128.0.
		*/
		void setShininess(osg::Material::Face face, float shininess){ m_Mat->setShininess(face, shininess); }

		/** Get the shininess value for specified face. */
		float getShininess(osg::Material::Face face) const{ return m_Mat->getShininess(face); }

		/** Return whether shininess values are equal for front and back faces
		* or not.
		*/
		inline bool getShininessFrontAndBack() const { return m_Mat->getShininessFrontAndBack(); }

		/** Set the alpha value of ambient, diffuse, specular and emission
		* colors of specified face, to 1-transparency.
		* Valid transparency range is 0.0 to 1.0.
		*/
		void setTransparency(osg::Material::Face face, float trans){ m_Mat->setTransparency(face, trans); }

		/** Set the alpha value of ambient, diffuse, specular and emission
		* colors. Valid transparency range is 0.0 to 1.0.
		*/
		void setAlpha(osg::Material::Face face, float alpha){ m_Mat->setAlpha(face, alpha); }

	protected:

		osg::ref_ptr<osg::Material> m_Mat;
	};
}

#endif // __DEFAULT_MATERIAL_H__