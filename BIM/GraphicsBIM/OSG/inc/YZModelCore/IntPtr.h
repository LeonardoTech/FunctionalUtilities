////////////
//    created by 孙庆号
////////////

#ifndef __INT_PTR_H_
#define __INT_PTR_H_

#ifdef _WIN32
#include "yztools_global.h"
#endif
#include <osg/Group>
//#include "ConstructMaterialSet.h"

namespace util
{
	class IntPtr
	{
	public:
#define MaskKey "IntPtr:Mask"
#define MaskCode 342562346
		//IntPtr(void* value) :m_value(value){}
		//~IntPtr();
		static void* toVoidPtr(osg::Object* node)
		{
			node->setUserValue(MaskKey, MaskCode);
			return node;
		}

		static osg::Node* toNodePtr(void* ptr)
		{
			auto node = static_cast<osg::Node*>(ptr);
			int value;
			if (!node)
				return NULL;
			try
			{
				if (!node->getUserValue(MaskKey, value))
					return NULL;
			}
			catch (...)
			{
				return NULL;
			}

			if (value != MaskCode)
			{
				return NULL;
			}
			return node;
		}

		static osg::Group* toGroupPtr(void* ptr)
		{
			auto node = static_cast<osg::Group*>(ptr);
			int value;
			if (!node)
				return NULL;
			try
			{
				if (!node->getUserValue(MaskKey, value))
					return NULL;
			}
			catch (...)
			{
				return NULL;
			}
			if (value != MaskCode)
			{
				return NULL;
			}
			return node;
		}

		static bimWorld::MaterialState* toMatStatePtr(void* ptr)
		{
			auto node = static_cast<bimWorld::MaterialState*>(ptr);
			int value;
			if (!node)
				return NULL;
			try
			{
				if (!node->getUserValue(MaskKey, value))
					return NULL;
			}
			catch (...)
			{
				return NULL;
			}
			if (value != MaskCode)
			{
				return NULL;
			}
			return node;
		}

	protected:
	};
}
#endif // !__INT_PTR_H_
