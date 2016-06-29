////////////
//    created by 孙庆号
////////////

#ifndef __NODE_SEARCHER_H__
#define __NODE_SEARCHER_H__
#include<functional>
#include <osg/Group>
//#include <mutex>

class YIZHU_EXPORT NodeSearcher
{
public:

	// @param callBack: return false to stop traverse this node.
	static void traverseAllSubNodes(osg::Node* node, std::function<bool(osg::Node*)> callBack, bool includeItsSelf)
	{
		//OpenThreads::ScopedLock<OpenThreads::Mutex> lock(m_mutex);
		if (!node)
			return;

		if (includeItsSelf)
		{
			if (!callBack(node))
				return;
		}

		auto group = node->asGroup();
		if (!group)
			return;
		unsigned int num = group->getNumChildren();
		if (node->asGeode())
			return;

		for (unsigned int i = 0; i < num; i++)
		{
			osg::Node* n = NULL;
			n = group->getChild(i);

			if (!n)
				continue;
			traverseAllSubNodes(n, callBack, true);
		}
	}

	static bool traverseSubNodesAndFindFirst(osg::Node* node, std::function<bool(osg::Node*)> isGotCallBack, bool includeItsSelf)
	{
		if (!node)
			return false;

		if (includeItsSelf)
		{
			if (isGotCallBack(node))
				return true;
		}

		auto group = node->asGroup();
		if (!group)
			return false;
		unsigned int num = group->getNumChildren();
		if (node->asGeode())
			return false;

		for (unsigned int i = 0; i < num; i++)
		{
			osg::Node* n = NULL;
			n = group->getChild(i);

			if (!n)
				continue;
			if (isGotCallBack(node))
				return true;
		}

		for (unsigned int i = 0; i < num; i++)
		{
			auto n = group->getChild(i);
			if (!n)
			{
				continue;
			}

			if (traverseSubNodesAndFindFirst(n, isGotCallBack, false))
				return true;
		}
		return false;
	}

	static void traverseThreeLayer(osg::Group* currentGroup, int currentLayer/* = 0*/, std::function<void(osg::Group*)> callBack)
	{
		if (!currentGroup || currentLayer > 3)
		{
			return;
		}
		callBack(currentGroup);
		auto num = currentGroup->getNumChildren();
		for (unsigned int j = 0; j < num; j++)
		{
			auto node = currentGroup->getChild(j);
			if (!node)
				continue;
			auto group = node->asGroup();
			if (!group)
			{
				continue;
			}
			traverseThreeLayer(group, currentLayer + 1, callBack);
		}
	}

protected:
};
#endif // __NODE_SEARCHER_H__