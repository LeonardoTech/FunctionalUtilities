////////////
//    created by 孙庆号
////////////

#ifndef __VISIBLE_CONTROL_CALLBACK_H__
#define __VISIBLE_CONTROL_CALLBACK_H__
#include <osg/NodeCallback>
#include "NodeExt.h"
#include "UserProperty.h"

namespace bimWorld
{
	struct DrawableCullCallback : public osg::Drawable::CullCallback
	{
		/** do customized cull code.*/
		virtual bool cull(osg::NodeVisitor*, osg::Drawable* drawable, osg::State* /*state*/) const
		{
            for(auto iter = drawable->getParents().begin(); iter!= drawable->getParents().end(); iter++)
			{
				if (!NodeExt::allParentsAreVisible(*iter))
				{
					return true;
				}
			}
			//std::cout << "Drawable cull callback " << drawable << std::endl;
			return false;
		}

	};
	class VisibleControlCallback :public osg::NodeCallback
	{
	public:
		VisibleControlCallback()
		{

		}

		virtual void operator()(osg::Node* node, osg::NodeVisitor* nv)
		{
			//if (NodeExt::allParentsAreVisible(node))
			auto com = dynamic_cast<YZ::Component*>(node);
			if (!com)
			{
				traverse(node, nv);
				return;
			}
			if (com->userProperty->getVisibility())
				//if (com->userProperty->allCategoryAreVisable())
			{
				//std::mutex _mutex;
				//_mutex.lock();
				//node->setNodeMask(-1);
				//_mutex.unlock();
				traverse(node, nv);
			}
			else
			{
				//std::mutex _mutex;
				//_mutex.lock();
				//node->setNodeMask(0);
				//_mutex.unlock();
			}
		}


	};

}

#endif // __VISIBLE_CONTROL_CALLBACK_H__