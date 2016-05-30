////////////
//    created by 孙庆号
////////////

#include <functional>
#include "osg/Group"

class GroupExt
{
public:
	static bool containsChild(osg::Group* This, std::function<bool(osg::Node*)> func, osg::Node*& outfirstChild)
	{
		for (unsigned int i = 0; i < This->getNumChildren();i++)
		{
			if (func(This->getChild(i)))
			{
				outfirstChild = This->getChild(i);
				return true;
			}
		}
		return false;
	}

	static void for_each(osg::Group* This, std::function<void(osg::Node*)> func)
	{
		for (unsigned int i = 0; i < This->getNumChildren(); i++)
		{
			func(This->getChild(i));
		}
	}
};