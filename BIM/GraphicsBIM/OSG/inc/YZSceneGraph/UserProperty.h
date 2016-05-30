////////////
//    created by 孙庆号
////////////

#ifndef __USER_PROPERTY_H__
#define __USER_PROPERTY_H__

#include <map>
#include "osg/Node"

namespace YZ
{
	class UserProperty
	{
	public:
		UserProperty(osg::Node* host);
		~UserProperty();

		void updateCategoryVisibility(osg::Node*, bool visible);

		bool allCategoryAreVisable();

		bool getVisibility();

	protected:
		std::map<osg::Node*, bool> categoryVisibility;
		osg::Node* m_host;
		//bool visibility;
		//std::map<std::string, bool> categoryHighlighted;
	};

}
#endif // __USER_PROPERTY_H__