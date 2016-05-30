////////////
//    created by 孙庆号
////////////

#ifndef __NODE_CONTROLLER_H__
#define __NODE_CONTROLLER_H__
#include <string>
#include <vector>
#include "YZModelCoreModule.h"
#include "config.h"
#include "INodeController.h"
#include <functional>
#include <osg/Node>
#include <osg/Vec4>
#include <osg/BlendFunc>

namespace bimWorld
{
	class YIZHU_EXPORT NodeController :public YZModelCoreModule, public INodeController
	{
	public:
		NodeController(bimWorld::YZModelCoreInternal* host);

		/////////////////////////////////////////////////////////////////////// <构件显示控制> //////////////////////////////////////////////////////////////////////////////////

		virtual void hideAll() override;
		
		virtual void unHideAll() override;
		
		virtual void hide(void *node) override;
		
		virtual void unHide(void *node) override;

		virtual void hide(const std::vector<void*>& nodes) override;

		virtual void unHide(const std::vector<void*>& nodes) override;
		
		virtual void hideOthers(void *node) override;
		
		virtual void unHideOthers(void *node) override;

		// <切换隐藏>
		virtual void toggleHide(void *node) override;

		virtual void toggleHide(const std::vector<void*>& nodes) override;
		
		// <判断构件可见性>
		virtual bool isVisible(void *node) override;

		////////////////////////////////////////////////////////节点高亮相关操作//////////////////////////////////////////////////////////////////////////////////

		virtual void highlight(void* node) override;

		virtual void unHighlight(void* node) override;

		virtual void transparentAll() override;

		virtual void unTransParentAll() override;

		//virtual void unTransparent(void* node) override;

		virtual void* getModelRoot() override;

		virtual bool revertColorOfNode(void* node) override;

		virtual bool revertColorOfNodes(const std::vector<void*>& nodes) override;

		virtual bool revertStateColorOfConstructs(void* ptr) override;

		virtual void setStateColorToConstructs(void* ptr, int red, int green, int blue) override;

		virtual IMeasuringLineLength* measuringLineLength() override;

	// internal:

		virtual std::string getName(void* node);

		virtual bool getChildren(void* pnode, std::vector<void*>& children);

	protected:
		void getCategoryGroups(bimWorld::YZString level, bimWorld::YZString category, std::vector<osg::Group*>& nodevec);
		//
		//bool traverseSubNodesAndFindFirst(osg::Node* node, std::function<bool(osg::Node*)> isGotCallBack, bool includeItsSelf);
		//
		//void traverseAllSubNodes(osg::Node* node, std::function<bool(osg::Node*)> callBack, bool includeItsSelf);
		//
		
	};
}

#endif // __NODE_CONTROLLER_H__