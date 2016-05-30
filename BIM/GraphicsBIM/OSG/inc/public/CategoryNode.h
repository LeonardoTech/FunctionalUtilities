////////////
//    created by 孙庆号
////////////

#ifndef __CATEGORY_NODE_H__
#define __CATEGORY_NODE_H__

#include <string>
#include <vector>
#include "MultiStringKey.h"
#include "config.h"

// protected member export warning
#pragma warning (disable : 4251)

namespace bimWorld
{
	class YIZHU_EXPORT CategoryNode
	{
	public:
		CategoryNode(const std::string& value);

		//  note: you should add top parent first,
		// otherwise you 
		void addParent(CategoryNode& parent);
		
		bool hasParent() const;
		
		const std::vector<CategoryNode> Parents() const;
		
		std::string Value() const;

		bool getCategoryKey(std::vector<bimWorld::MultiStringKey>& outKeys) const;

	protected:
		std::string m_value;
		std::vector<CategoryNode> _parents;

		// pass param; obsolete, using CategoryQueryKey instead.
		void addValue(const std::string& value);
		std::vector<std::string> _categoryValues;
	};
}

#endif // __CATEGORY_NODE_H__