////////////
//    created by 孙庆号
////////////

#ifndef __IMOVING_CAMERA_H__
#define __IMOVING_CAMERA_H__

namespace bimWorld
{
	// <移动方向>
	enum class MovingDirection
	{
		Forward,
		Backward,
		Left,
		Right,
	};

	class YIZHU_EXPORT IMovingCamera
	{
	public:
        virtual void moveHorizontal(double distance) = 0;
        
        virtual void beginMoveVertical(double  distance) = 0;
        
        virtual void endMoveVertical() = 0;

		virtual void moveVertical(double  distance) = 0;

		virtual void moveUp(double distance) = 0;

		virtual void moveRight(double distance) = 0;

		virtual void translation(double startx, double starty, double endx, double endy) = 0;
		
		virtual void setMoveFactorScale(bimWorld::MovingDirection direction, float scale) = 0;

	protected:
	};
}
#endif // __IMOVING_CAMERA_H__