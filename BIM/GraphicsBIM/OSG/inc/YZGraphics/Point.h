////////////
//    created by 孙庆号
////////////

#ifndef __POINT_H__
#define __POINT_H__
#include "config.h"

namespace bimWorld
{
	namespace GraphicsStructure
	{
		struct YIZHU_EXPORT Point
		{
			int x, y;

			Point()
			{
				x = 0;
				y = 0;
			}

			Point(int pointX, int pointY)
			{
				x = pointX;
				y = pointY;
			}

			Point(const Point& copy)
			{
				x = copy.x;
				y = copy.y;
			}

			bool operator == (const Point& other)
			{
				return (this->x == other.x && this->y == other.y);
			}
		};
	}
}

#endif // __POINT_H__