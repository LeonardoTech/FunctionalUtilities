////////////
//    created by 孙庆号
////////////

#ifndef __RECT_H__
#define __RECT_H__

#include "Point.h"

namespace bimWorld
{
	namespace GraphicsStructure
	{
		struct YIZHU_EXPORT Rect
		{
			int top, left;
			int bottom, right;

			Rect()
			{
				this->top = 0;
				this->left = 0;
				this->bottom = 0;
				this->right = 0;
			}

			Rect(int left, int right, int top, int bottom)
			{
				this->top = top;
				this->left = left;
				this->bottom = bottom;
				this->right = right;
			}

			Rect(Point p1, Point p2)
			{
				if (p1.x < p2.x)
				{
					left = p1.x;
					right = p2.x;
				}
				else
				{
					left = p2.x;
					right = p1.x;
				}

				if (p1.y < p2.y)
				{
					bottom = p1.y;
					top = p2.y;
				}
				else
				{
					bottom = p2.y;
					top = p1.y;
				}
			}

			Rect(const Rect& copy)
			{
				this->top = copy.top;
				this->left = copy.left;
				this->bottom = copy.bottom;
				this->right = copy.right;
			}

			bool operator == (const Rect& other)
			{
				return (this->top == other.top &&
					this->left == other.left &&
					this->bottom == other.bottom &&
					this->right == other.right);
			}

			int width()
			{
				return right - left;
			}

			int height()
			{
				return top - bottom;
			}

			int x()
			{
				return left;
			}

			int y()
			{
				return top;
			}
		};
	}
}

#endif // __RECT_H__