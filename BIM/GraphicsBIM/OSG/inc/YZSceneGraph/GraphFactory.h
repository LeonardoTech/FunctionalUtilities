////////////
//    created by 孙庆号
////////////

#pragma once
#include "../../../../ModelData/BIM/inc/dragon/YZComponent.h"
#include <vector>
#include <string>
#include "CategoryNode.h"
#include "YZModelCoreInternal.h"
#include "CategoryQueryKey.h"
#include "config.h"

namespace bimWorld
{
	class YIZHU_EXPORT GraphFactory
	{
	public:
		GraphFactory(YZModelCoreInternal* core);
		~GraphFactory();

		//// <设置分类和父子关系集合>
		//// <参数：categories 中里面的vector按父子顺序存储关联关系，外面的vector存储独立的关系>
		//// <如： [ [楼层，大类，小类], [专业] ] >
		//void setCategoryAndRelation(const std::vector<std::vector<std::string> >& categories);

#pragma region 不使用这种方式
/*
		// <根据传进来的树结构构件场景树>
		void generateLevelOrderList(const std::vector<CategoryNode>& children);
		void constructTree(const std::vector<CategoryNode>& children);
		// <构建完场景树将其中的节点填充到树里>
		void fillTree();*/
#pragma endregion

		void constructGroupTree(const std::vector<YZ::Component*>& groups);
		
		void constructVolumeTree(const std::vector<YZ::Component*>& order);

		void constructTree(const std::vector<YZ::Component*>& constructs, const std::vector<CategoryNode>& children);

		void addToGroupTree(const std::vector<YZ::Component*>& constructs);
		
		//void constructTree(const std::vector<std::vector<std::string> >& categories, const std::vector<YZ::Component*>& constructs);

		osg::Group* select(const CategoryQueryKey& queryKey);

		void clear();

	protected:
		void AddGroups(CategoryNode child, YZ::Component* com, osg::Group* tree);
		
		YZModelCoreInternal* m_host;

		//std::vector<std::vector<std::string> > m_levelOrderSet;

		typedef std::map<MultiStringKey, osg::ref_ptr<osg::Group> > QueryGroupMap;
		// <存储查询key和场景树节点的字典>
		//QueryGroupMap m_queryGroup;

		std::map<MultiStringKey, QueryGroupMap> m_queryMap;
		osg::ref_ptr<osg::Group> m_groupTree;
		std::map<std::string, osg::ref_ptr<osg::Group>> m_controlTree;

		//std::map<std::string, osg::Group*> m_treeCategoryGroup;
		//void fillTree(osg::Group* tree, const std::map<std::string, bimWorld::YZString>& construct);

		//void fillTree(const std::vector<YZ::Component*>& constructs);
	};

}
