////////////
//    created by 孙庆号
////////////

#ifndef __CAMERA_OPERATION_TYPES_H__
#define __CAMERA_OPERATION_TYPES_H__

namespace bimWorld
{

	enum CameraOperationTypes
	{
		emptyOperation,
		beginMoveForward,
		endMoveForward,
		beginMoveBackward,
		endMoveBackward,
		beginMoveLeft,
		endMoveLeft,
		beginMoveRight,
		endMoveRight,
		beginTurnLeft,
		endTurnLeft,
		beginTurnRight,
		endTurnRight,
		onHome,
		onZoomModel,
		onPanModel,
		onRotateCamera,
	};
}
#endif // __CAMERA_OPERATION_TYPES_H__