////////////
//    created by 孙庆号
////////////

#ifndef __YZ_UNIFORM_UPDATER_H__
#define __YZ_UNIFORM_UPDATER_H__
#include "osg/Uniform"
#include "osg/NodeVisitor"
#include <functional>

class UniformUpdater : public osg::Uniform::Callback
{
public:
	UniformUpdater(std::function<void(osg::Uniform* uni, unsigned int frameNum)> func)
	{
		m_func = func;
	}

	~UniformUpdater()
	{
	}

	virtual void operator()(osg::Uniform* uniform,
		osg::NodeVisitor* nv)
	{
		const osg::FrameStamp* fs = nv->getFrameStamp();
		if (!fs) return;
		//float angle = osg::inDegrees((float)fs->getFrameNumber());
		//uniform->set(osg::Vec3(20.0f * cosf(angle), 20.0f * sinf(angle), 1.0f));
		//if (m_rendering)
		//{
		//	uniform->set(m_lastIsRenderingId);
		//}
		//else
		{
			//uniform->set(isRenderingId);
			m_func(uniform, fs->getFrameNumber());
		}
	}

protected:
	std::function<void(osg::Uniform*, unsigned int)> m_func;
};


#endif // __YZ_UNIFORM_UPDATER_H__