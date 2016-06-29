////////////
//    created by 孙庆号
////////////

#ifndef __CATEGORY_RELATION_TREE_H__
#define __CATEGORY_RELATION_TREE_H__

#include <string>
#include <vector>
#include "CategoryNode.h"

namespace bimWorld
{
	class CategoryRelationTree
	{
	public:
		CategoryRelationTree(const std::vector<CategoryNode>& children);
	protected:
	private:
	};
}

#endif // __CATEGORY_RELATION_TREE_H__