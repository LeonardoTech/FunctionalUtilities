////////////
//    created by 孙庆号
////////////

#ifndef __LINE_COLLISION_H__
#define __LINE_COLLISION_H__
#include "osg/Vec3"
#include "osg/Node"
#include <functional>

namespace bimWorld
{
	class LineCollision
	{
	public:
		static bool collisionDetected(const osg::Vec3& start, const osg::Vec3& end, osg::Node* root);

		static bool collisionDetected(const osg::Vec3& start, const osg::Vec3& end, osg::Node* root, std::function<void(osg::Node*)> func);
	protected:
	private:
	};
}

#endif // __LINE_COLLISION_H__