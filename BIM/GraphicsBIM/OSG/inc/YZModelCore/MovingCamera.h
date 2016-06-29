////////////
//    created by 孙庆号
////////////

#ifndef __MOVING_CAMERA_H__
#define __MOVING_CAMERA_H__
#include "YZModelCoreModule.h"
#include "IMovingCamera.h"

namespace bimWorld
{
	class YIZHU_EXPORT MovingCamera :public YZModelCoreModule, public IMovingCamera
	{
	public:

		MovingCamera(YZModelCoreInternal* host);

		virtual void moveHorizontal(double distance) override;

        virtual void beginMoveVertical(double  distance) override;
        
        virtual void endMoveVertical() override;
        
        virtual void moveVertical(double  distance) override;

		virtual void moveUp(double distance) override;

		virtual void moveRight(double distance) override;

		virtual void translation(double startx, double starty, double endx, double endy) override;

		void setMoveFactorScale(bimWorld::MovingDirection direction, float scale) override;

	protected:
	private:
	};

}
#endif // __MOVING_CAMERA_H__