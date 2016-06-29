////////////
//    created by 孙庆号
////////////

#ifndef __GET_ID_VISITIOR_H__
#define __GET_ID_VISITIOR_H__
#include <osg/Group>
#include <osg/Geode>
#include <osg/Drawable>
#include <osg/Geometry>
#include <osg/PolygonMode>
#include <osg/MatrixTransform>
#include <osg/Material>
#include <osg/LineWidth>
#include <osgUtil/SmoothingVisitor>
#include <osg/ValueObject>
#include "config.h"
#include <iostream>
#include <algorithm>
namespace
{
	//template<class T, class Tname>
	class GetFBXIdVisitor : public osg::NodeVisitor
	{
	
	public:
		GetFBXIdVisitor() :osg::NodeVisitor(osg::NodeVisitor::TRAVERSE_ALL_CHILDREN) //osg::NodeVisitor::TRAVERSE_ALL_CHILDREN 
		{}
		virtual void apply(osg::Node& node)
		{
	
			bool bClass(false);//是分类节点
			std::string strFloor;
			std::string revitName("0");
			std::string  entName;
			if (node.asGroup())
			{
				revitName = node.getName();
				int iSize = node.asGroup()->getNumChildren();
				
				for (int i = 0; i < iSize; i++)
				{
					osg::Node* pChildNode = node.asGroup()->getChild(i);
					std::string  entName= pChildNode->getName();	
				}
			}
			else
			{
				std::string  entName = node.getName();
			}

			traverse(node);
		}
	};

	template<class T, class Tname>
	class GetIdVisitor : public osg::NodeVisitor
	{
		T *idMap;
		Tname *m_NameMap;
	public:
		GetIdVisitor(T *idMap, Tname *NameMap) :osg::NodeVisitor(osg::NodeVisitor::TRAVERSE_ALL_CHILDREN), idMap(idMap), m_NameMap(NameMap)
		{}

		virtual void apply(osg::Node& node)
		{
			//if(node.asGroup() != NULL){

			bool bClass(false);//是分类节点
			std::string strFloor;
			const std::string& name = node.getName();
			if (node.asGroup())
			{
				osg::Node::ParentList pList = node.getParents();
				for (int i = 0; i < pList.size(); i++)
				{

					int iKey;
					//std::string strFlr("floor:");
					//	pList[i]->getName();
					//pList[i]->getUserValue("floor",iKey);
					osg::Node::ParentList ppList = pList[i]->getParents();
					for (int pp = 0; pp < ppList.size(); pp++)
					{

						if (ppList[i]->getName() == std::string("root"))
						{
							strFloor = pList[i]->getName();
							bClass = true;
							break;
						}
					}
					if (bClass)
					{
						break;
					}
				}

#ifdef YIZHU_BIMWORLD_USE_WCHAR
				std::string encoding = "utf-8";
				bimWorld::YZString strTemp = boost::locale::conv::to_utf<wchar_t>(name, encoding);
				if (bClass)
				{
					bimWorld::YZString strFlr = boost::locale::conv::to_utf<wchar_t>(strFloor + std::string("\\"), encoding);
					strTemp = strFlr + strTemp;
					std::cout << "大小类:" << strTemp.c_str() << std::endl;
				}
				else
				{
					std::cout << "其他分类:" << strTemp.c_str() << std::endl;
				}
				m_NameMap->insert(make_pair(strTemp, &node));
#else
				if(bClass)
				{
					m_NameMap->insert(make_pair(strFloor+"\\"+name,&node));
				}
				else
				{
					m_NameMap->insert(make_pair(name,&node));
				}
#endif
			}
			int start = 0, end = name.size();

			int temp = end - 1;
			for (; temp >= 0 && name[temp] != ']'; --temp);
			if (temp >= 0)
			{
				end = temp;
				temp = end - 1;
				for (; temp >= 0 && name[temp] != '['; --temp);
				if (temp >= 0){
					start = temp + 1;
				}
			}

			//bool isNegative = false;
			//if (name[start] == '-')
			//{
			//	isNegative = true;
			//	++start;
			//}
			if (start < end)
			{
				std::string id = name;
				while (start < end){
					// guid 是 md5 编码格式
					if ((name[start] >= '0' && name[start] <= '9') || (name[start] >= 'a' && name[start] <= 'z') || name[start] == '-')
					{
						//id = id * 10 + (name[start] - '0');
						++start;
					}
					else
					{
						id = "";
						break;
					}
				}
				//if (isNegative)
				//	id = -id;
				if (!id.empty())
				{
					if (idMap->right.find(id) != idMap->right.end() && idMap->right.find(id)->second != &node)
					{
						std::cout << "duplicate id in models :" << id << std::endl;
						std::cout << "value 1: " << idMap->right.find(id)->second << ", value 2 : " << &node << std::endl;
					}
					idMap->insert(typename T::value_type(&node, id));
					std::ostringstream os;
					os << id;
					node.setName(os.str().c_str());
				}
			}
			//}
			//node.setName(NULL);
			traverse(node);
		}
	};

	template<class T, class Tname>
	class RemoveIdVisitor : public osg::NodeVisitor
	{
		T *idMap;
		Tname *m_NameMap;
	public:
		RemoveIdVisitor(T *idMap, Tname *NameMap) :osg::NodeVisitor(osg::NodeVisitor::TRAVERSE_ALL_CHILDREN), idMap(idMap), m_NameMap(NameMap)
		{}

		virtual void apply(osg::Node& node)
		{

			bool bClass(false);//是分类节点
			std::string strFloor;
			const std::string& name = node.getName();
			if (node.asGroup())
			{
				osg::Node::ParentList pList = node.getParents();
				for (int i = 0; i < pList.size(); i++)
				{

					int iKey;
					osg::Node::ParentList ppList = pList[i]->getParents();
					for (int pp = 0; pp < ppList.size(); pp++)
					{

						if (ppList[i]->getName() == std::string("root"))
						{
							strFloor = pList[i]->getName();
							bClass = true;
							break;
						}
					}
					if (bClass)
					{
						break;
					}
				}

#ifdef YIZHU_BIMWORLD_USE_WCHAR
				std::string encoding = "utf-8";
				bimWorld::YZString strTemp = boost::locale::conv::to_utf<wchar_t>(name, encoding);
				if (bClass)
				{
					bimWorld::YZString strFlr = boost::locale::conv::to_utf<wchar_t>(strFloor + std::string("\\"), encoding);
					strTemp = strFlr + strTemp;
					std::cout << "大小类:" << strTemp.c_str() << std::endl;
				}
				else
				{
					std::cout << "其他分类:" << strTemp.c_str() << std::endl;
				}
				auto nameMapIter = m_NameMap->find(strTemp);
				if(nameMapIter!=m_NameMap->end())
					m_NameMap->erase(nameMapIter);
#else
				if (bClass)
				{
					//m_NameMap->erase(make_pair(strFloor + "\\" + name, &node));
					auto nameMapIter = m_NameMap->find(strFloor + "\\" + name);
					if(nameMapIter!=m_NameMap->end())
						m_NameMap->erase(nameMapIter);
				}
				else
				{
					//m_NameMap->erase(make_pair(name, &node));
					auto nameMapIter = m_NameMap->find(name);
					if (nameMapIter != m_NameMap->end())
						m_NameMap->erase(nameMapIter);
			}
#endif
		}
			auto idMapIter = idMap->left.find(&node);
			if (idMapIter != idMap->left.end())
				idMap->left.erase(idMapIter);
			//int start = 0, end = name.size();

			//int temp = end - 1;
			//for (; temp >= 0 && name[temp] != ']'; --temp);
			//if (temp >= 0)
			//{
			//	end = temp;
			//	temp = end - 1;
			//	for (; temp >= 0 && name[temp] != '['; --temp);
			//	if (temp >= 0){
			//		start = temp + 1;
			//	}
			//}

			//bool isNegative = false;
			//if (name[start] == '-')
			//{
			//	isNegative = true;
			//	++start;
			//}
			//if (start < end)
			//{
				//int id = 0;
				//while (start < end){
				//	if (name[start] < '0' || name[start] > '9')
				//	{
				//		id = 0;
				//		break;
				//	}
				//	id = id * 10 + (name[start] - '0');
				//	++start;
				//}
				//if (isNegative)
				//	id = -id;
				//if (id != 0)
				//{
				//	if (idMap->right.find(id) != idMap->right.end() && idMap->right.find(id)->second != &node)
				//	{
				//		std::cout << "duplicate id in models :" << id << std::endl;
				//		std::cout << "value 1: " << idMap->right.find(id)->second << ", value 2 : " << &node << std::endl;
				//	}
				//	idMap->erase(typename T::value_type(&node, id));
				//	std::ostringstream os;
				//	os << id;
				//	node.setName(os.str().c_str());
				//}
			//}
			traverse(node);
	}
};

	template<class Set, class Value>
	bool addToSet(Set& set, const Value& v)
	{
		typename Set::iterator pos = std::find(set.begin(), set.end(), v);
		if (pos != set.end())
			return false;
		set.push_back(v);
		return true;
	}

	template<class Set, class Value>
	bool removeFromSet(Set& set, const Value& v)
	{
		typename Set::iterator pos = std::find(set.begin(), set.end(), v);
		if (pos != set.end())
			return false;
		set.push_back(v);
		return true;
	}

	std::vector<bimWorld::ModelViewerListener*> defaultModelListener;
}
#endif // __GET_ID_VISITIOR_H__