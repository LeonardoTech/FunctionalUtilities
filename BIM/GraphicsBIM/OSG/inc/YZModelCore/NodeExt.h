////////////
//    created by 孙庆号
////////////

#ifndef __NODE_EXT_H__
#define __NODE_EXT_H__
#include <osg/Group>

namespace bimWorld
{
	class NodeExt
	{
	public:
		static bool allParentsAreVisible(osg::Node* child)
		{
			if (!child)
			{
				return false;
			}
			auto parents = child->getParents();
			for (auto iter = parents.begin(); iter != parents.end(); iter++)
			{
				auto parent = *iter;
				if (parent->getNodeMask() == 0x0)
				{
					return false;
				}
				if (!allParentsAreVisible(parent))
				{
					return false;
				}
			}
			return true;
		}

		static void setVisibility(osg::Node* This, bool visibility)
		{
			if (!This)
			{
				return;
			}

			if (!visibility)
			{
				This->setNodeMask(0);
			}
			else
			{
				This->setNodeMask((unsigned int)(-1));
			}
		}

	protected:
	private:
	};
}

#endif // __NODE_EXT_H__