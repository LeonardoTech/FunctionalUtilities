////////////
//    created by 孙庆号
////////////

#ifndef __IVIEWER_DATA_SET_H__
#define __IVIEWER_DATA_SET_H__
#include <osgViewer/Viewer>
#include <osg/Group>
#include <OpenThreads/Mutex>
#include <osg/MatrixTransform>

#include "DataModel.h"
#include <functional>
#include "IEvent.h"

#ifdef USING_QT
#include "QtWidgets/QWidget"
//#include "osgQt/GraphicsWindowQt"
#endif

namespace bimWorld
{

	class YIZHU_EXPORT IViewerDataModel
	{
	public:

		virtual osgViewer::Viewer* ModelViewer() = 0;

#if defined(Android)
		virtual void initOSG(int x,int y,int width,int height) = 0;

#elif defined(USING_QT)
		//virtual void initOSG(QWidget* widget) = 0;
		virtual void initOSG(std::function<void(osg::GraphicsContext::Traits* traits)> initGraphicContext) = 0;
#else
		virtual void initOSG(std::function<void(osg::GraphicsContext::Traits* traits)> initGraphicContext) = 0;
#endif // Android

#ifdef USING_QT
		virtual QWidget* getWidget() = 0;
#endif

		virtual osg::Group* TopRoot() = 0;

		// <顶层根节点的回调函数集合>
		virtual std::map<osg::ref_ptr<osg::Node>, const void(*)()>& TopMostCallback() = 0;

		virtual std::map<int, osg::ref_ptr<osg::Node> >& TopMostSet() = 0;

		/************************************************************************************************
		* @fn	bool isTopMostNode(osg::Node* node);
		*
		* @brief	Query if 'node' is top most node.
		*
		* @author	Sqh
		* @date	2015/5/13
		*
		* @param [in,out]	node	If non-null, the node.
		*
		* @return	true if top most node, false if not.
		*
		* ### remarks	Sqh, 2015/5/6.
		**************************************************************************************************/
		virtual bool isTopMostNode(osg::Node* node) = 0;

		// <屏幕视图>
		virtual osg::Group* getSceneRoot() = 0;

		virtual void setSceneRoot(osg::Group* root) = 0;

		virtual bool validateSceneRoot() = 0;

		// <模型视图>
		virtual osg::MatrixTransform* getModelRoot() = 0;

		virtual void setModelRoot(osg::MatrixTransform* transformNode) = 0;

		virtual bool validateModelRoot() = 0;

		// <屏幕相机>
		virtual osg::Camera* getWindowSpace() = 0;

		virtual osg::Camera* getTopRoot() = 0;

		virtual osg::Camera* getBackGroundRoot() = 0;

		//// <视图监听器集合>
		//bimWorld::ListenerSet& ModelViewerListeners();

		// <是否完成>
		virtual bool isDone() = 0;

		// <线程互斥锁>
		virtual OpenThreads::Mutex& Mutex() = 0;

		virtual bool isLoaded() = 0;

		virtual void setLoaded(bool isLoaded) = 0;

		virtual bool getCameraPerspective(CameraPerspective& perspective) = 0;
		
		virtual core::IEvent<void(std::vector<void*>, ViewerMode)>& SelectNodeEvent() = 0;

		// <获取模型中心>
		virtual osg::Vec3 getModelRootCenter() = 0;

	};

}

#endif // __IVIEWER_DATA_SET_H__