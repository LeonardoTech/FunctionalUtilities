////////////
//    created by 孙庆号
////////////

#ifndef __ICAMERA_OPERATION_H__
#define __ICAMERA_OPERATION_H__
#include "config.h"

namespace bimWorld
{
	class YIZHU_EXPORT ICameraOperation
	{
	public:

		virtual bool beginMoveForward() = 0;
		virtual bool endMoveForward() = 0;
		
		virtual bool beginMoveLeft() = 0;
		virtual bool endMoveLeft() = 0;
		
		virtual bool beginMoveRight() = 0;
		virtual bool endMoveRight() = 0;
		
		virtual bool beginMoveBackward() = 0;
		virtual bool endMoveBackward() = 0;

		virtual void setMovingSpeed(double speed = 1.0) = 0;
		virtual double getMovingSpeed() = 0;
		
		virtual bool beginTurnLeft() = 0;
		virtual bool endTurnLeft() = 0;
		
		virtual bool beginTurnRight() = 0;
		virtual bool endTurnRight() = 0;

		virtual void setTurnSpeed(double speed = 1.0) = 0;
		virtual double getTurnSpeed() = 0;

		virtual bool beginRotateCameraWithSelectedCenter() = 0;
		virtual bool endRotateCameraWithSelectedCenter() = 0;
		
		virtual bool onHome() = 0;
		
		virtual bool onZoomModel(const double eventTimeDelta, const float dx, const float dy) = 0;
		virtual bool onPanModel(const double eventTimeDelta, const float dx, const float dy) = 0;
		virtual bool onRotateCamera(const double eventTimeDelta, const float dx, const float dy) = 0;
		virtual bool onRotateCameraWithSelectedCenter(const double eventTimeDelta, const float dx, const float dy) = 0;
		
		virtual void beginCameraOperation() = 0;
		
		virtual bool pauseRendering() = 0;
		
		virtual bool orbitPick(const double x, const double y) = 0;

		virtual void multiPickStart(const double x, const double y) = 0;

		virtual bool multiPickEnd(const double x, const double y) = 0;

		virtual void updateMultiPickRange(const double x, const double y) = 0;

	};

}
#endif // __ICAMERA_OPERATION_H__