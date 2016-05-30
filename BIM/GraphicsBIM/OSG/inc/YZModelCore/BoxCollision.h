////////////
//    created by 孙庆号
////////////

#pragma once
#include "osg/Vec3"
#include "osg/Node"
class BoxCollision
{
public:
	BoxCollision();
	~BoxCollision();
	static bool collisionDetected(double xMin, double yMin, double xMax, double yMax, osg::Node* root);
};

