#ifndef __NODE_CALLBACK_UPDATER_H__
#define __NODE_CALLBACK_UPDATER_H__
#include "osg/NodeCallback"
#include <functional>

namespace bimWorld
{
	class NodeCallbackUpdater:public osg::NodeCallback
	{
	public:
		NodeCallbackUpdater(std::function<bool(osg::Node* node, osg::NodeVisitor* nv)> func)
		{
			m_func = func;
		}

		virtual void operator ()(osg::Node* node, osg::NodeVisitor* nv) override
		{
			if (m_func(node, nv))
				return;
			traverse(node, nv);
		}

	protected:
		std::function<bool(osg::Node* node, osg::NodeVisitor* nv)> m_func;
	};
}

#endif