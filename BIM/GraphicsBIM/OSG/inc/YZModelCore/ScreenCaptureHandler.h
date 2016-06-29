////////////
//    created by 孙庆号
////////////

#ifndef __SCREEN_CAPTURE_HANDLER_H__
#define __SCREEN_CAPTURE_HANDLER_H__
#include <iostream>
#include <osg/Camera>
#include <osg/RenderInfo>
#include <osgDB/WriteFile>
#include <osg/GL>
#include <mutex>

class ScreenCaptureHandler : public osg::Camera::DrawCallback
{
public:

	ScreenCaptureHandler(const char* file, unsigned char** buffer, int width, int height, int &channels, GLenum pixelFormat, int x = 0, int y = 0) :
		file_name(file),
		m_buffer(buffer),
		m_width(width),
		m_height(height),
		m_x(x),
		m_y(y),
		m_channels(&channels),
		m_pixelFormat(pixelFormat)
	{
	}

	void capture(osg::Camera* camera) const
	{

		std::mutex _lock;
		_lock.lock();
		//        GLenum buffer = camera->getDrawBuffer();
		//        if(camera->getGraphicsContext()->getTraits()->doubleBuffer)
		//        {
		//            if(buffer == GL_BACK)
		//                buffer = GL_FRONT;
		//            else
		//                buffer = GL_BACK;
		//        }

		//		        GLenum buffer = camera->getGraphicsContext()->getTraits()->doubleBuffer ? GL_BACK : GL_FRONT;
		//		        camera->setReadBuffer(GL_FRONT);
		//        camera->setReadBuffer(buffer);
		camera->setReadBuffer(GL_NONE);

		glReadPixels(m_x, m_y, m_width, m_height, m_pixelFormat, GL_UNSIGNED_BYTE, *m_buffer);

		_lock.unlock();
}

	void	operator() (osg::RenderInfo &renderInfo) const
	{
		osg::Camera * camera = renderInfo.getCurrentCamera();
		capture(camera);

		//		osg::ref_ptr< ::osg::Image> image = new ::osg::Image();
		//		image->readPixels(0, 0, width, height, GL_RGB, GL_UNSIGNED_BYTE);
		//		osg::notify(osg::NOTICE) << "Read pixels done." << std::endl;
		//		if (osgDB::writeImageFile(*image, file_name))
		//		{
		//			osg::notify(osg::NOTICE) << "Saved screen image to '" << file_name << "'" << std::endl;
		//		}
		//		else
		//		{
		//			osg::notify(osg::FATAL) << "Could not save image!" << std::endl;
		//		}
	}

protected:
	const char* file_name;
	mutable unsigned char** m_buffer;
	int m_width;
	int m_height;
	int m_x, m_y;
	mutable int* m_channels;
	GLenum m_pixelFormat;
	//    mutable OpenThreads::Mutex  _mutex;
};

#endif // __SCREEN_CAPTURE_HANDLER_H__