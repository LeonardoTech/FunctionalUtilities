////////////
//    created by 孙庆号
////////////

#ifndef __HIGHLIGHT_CALLBACK_H__
#define __HIGHLIGHT_CALLBACK_H__
#include <osg/NodeCallback>
#include <osg/Group>
#include "YZModelCoreInternal.h"

namespace bimWorld
{

	class HighlightCallback :public osg::NodeCallback
	{
	public:
		YZModelCoreInternal* m_host;
		HighlightCallback(bimWorld::YZModelCoreInternal* host)
		{
			m_host = host;
		}

		virtual void operator()(osg::Node* node, osg::NodeVisitor* nv)
		{
			if (hasHighlightedParents(node))
			{
				m_host->NodeControl()->highlight(node);
			}
			else
			{
				m_host->NodeControl()->unHighlight(node);
			}
			traverse(node, nv);
		}

		bool hasHighlightedParents(osg::Node* child)
		{
			if (!child)
			{
				return false;
			}
			auto parents = child->getParents();
			for each (auto parent in parents)
			{
				if (parent->getNodeMask() == 0x0)
				{
					return true;
				}
				if (!hasHighlightedParents(parent))
				{
					return false;
				}
			}
			return true;
		}
	};

}

#endif // __HIGHLIGHT_CALLBACK_H__