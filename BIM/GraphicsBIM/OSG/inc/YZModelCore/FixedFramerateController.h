////////////
//    created by 孙庆号
////////////


//
//  FixedFramerateController.h
//  ModelViewer
//
//  Created by yizhu on 15-2-13.
//  Copyright (c) 2015骞?dion chen. All rights reserved.
//

#ifndef __FIXED_FRAMERATE_CONTROLLER_H__
#define __FIXED_FRAMERATE_CONTROLLER_H__
#include <osg/Node>
#include <osg/Geode>
#include <osg/NodeVisitor>
#include <osg/Geometry>
#include <osg/ValueObject>
#include <vector>
#include <algorithm>
#include "UserDataDefine.h"
namespace bimWorld
{
	struct NodeStat
	{
		osg::Node		*node;
		unsigned int	primitiveSetCount;
		unsigned int	primitiveCount;
		NodeStat(osg::Node *node = NULL, unsigned int primitiveSetCount = 0, unsigned int primitiveCount = 0)
			: node(node), primitiveCount(primitiveCount), primitiveSetCount(primitiveSetCount)
		{}

		bool operator<(const NodeStat& nodeStat) const
		{
			//primitiveCount / primitiveSetCount < nodeStat.primitiveCount / nodeStat.primitiveSetCount
			return primitiveCount * nodeStat.primitiveSetCount < nodeStat.primitiveCount * primitiveSetCount;
		}
	};

#define VALIDATION_MASK 423789273
	class FixedFramerateController
	{
		std::vector<NodeStat>		nodeStats;
		std::vector<unsigned int>	triangeAccumulated;
		unsigned int				splitIndex;
		unsigned int				currentIndex;
	public:
		FixedFramerateController() : splitIndex(0), currentIndex(0), m_isHidden(false), m_validMask(VALIDATION_MASK)
		{
		}
		FixedFramerateController(std::vector<NodeStat>& nodeStats);

		bool isValid()
		{
			return m_validMask == VALIDATION_MASK;
		}

		void setNodeStats(std::vector<NodeStat>& nodeStats);
		void setMask(int mask, unsigned int split)
		{
			for (unsigned int i = 0; i < nodeStats.size() && i < split; ++i)
			{
				bool visible = mask == -1;
				if (visible)
					continue;
				nodeStats[i].node->setNodeMask(mask);
			}
		}
		bool hide();
		void unHide()
		{
			if (!m_isHidden)
				return;
			setMask(-1, nodeStats.size());
			currentIndex = 0;
			m_isHidden = false;
		}
		void clearNodeStats();
	private:
		bool m_isHidden;
		int m_validMask;
	};
	class CollectNodeStats : public osg::NodeVisitor
	{
	public:
		CollectNodeStats() : osg::NodeVisitor(osg::NodeVisitor::TRAVERSE_ALL_CHILDREN)
		{
		}
		void apply(osg::Geode &geode);
		std::vector<NodeStat> nodeStats;
	};
}
#endif /* defined(__FIXED_FRAMERATE_CONTROLLER_H__) */
