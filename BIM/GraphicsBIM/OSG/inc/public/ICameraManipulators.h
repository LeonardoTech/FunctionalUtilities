////////////
//    created by 孙庆号
////////////

#ifndef __ICAMERA_MANIPULATORS_H__
#define __ICAMERA_MANIPULATORS_H__
#include "config.h"
#include "ManipulatorType.h"
#include "DataModel.h"
#include "IZoomModel.h"
#include <memory>
#include "MouseKeySymbol.h"
#include "CameraOperationTypes.h"
#include <functional>
//#include "ICameraAnimation.h"

namespace bimWorld
{
	typedef std::vector<bimWorld::ModelViewerListener*> ListenerSet;

	class YIZHU_EXPORT ICameraManipulators
	{
	public:
		///-------------------------------------------------------------------------------------------------
		/// <summary>	切换漫游器. </summary>
		///
		/// <remarks>	Sqh, 2015/5/6. </remarks>
		///
		/// <param name="emanip">	The emanip. </param>
		///-------------------------------------------------------------------------------------------------
		virtual void switchMatrixManipulator(ManipulatorType emanip) = 0;

		virtual bimWorld::ViewerMode getCameraManipulatorMode() = 0;

		virtual void enableFirstPersonControl() = 0;

		virtual void disableFirstPersonControl() = 0;

		virtual void setCollisionEnabled(bool enabled) = 0;

		virtual void setGravityEnabled(bool enabled) = 0;

		////////////////////////////////////////////////////////视图模式//////////////////////////////////////////////////////////////////////////////////
		virtual void setViewerMode(bimWorld::ViewerMode viewerMode) = 0;

		virtual std::shared_ptr<bimWorld::IZoomModel> ZoomModel() = 0;

		virtual const bimWorld::ListenerSet& getListeners() const = 0;

		virtual void clearSelection() = 0;

		virtual void updateModelSize() = 0;

		virtual void setModelCenter(void* node) = 0;

		virtual void setModelCenterKeepViewPoint(void* node) = 0;

		virtual void bindKeyUpEvent(bimWorld::KeySymbol key, bimWorld::CameraOperationTypes operation) = 0;

		virtual void bindKeyDownEvent(bimWorld::KeySymbol key, bimWorld::CameraOperationTypes operation) = 0;

		virtual void bindMouseEvent(bimWorld::MouseButtonMask mouse, bimWorld::CameraOperationTypes operation) = 0;

		virtual void unbindKeyUpEvent(bimWorld::KeySymbol key) = 0;

		virtual void unbindKeyDownEvent(bimWorld::KeySymbol key) = 0;

		virtual void unbindMouseEvent(bimWorld::MouseButtonMask mouse) = 0;

		virtual void bindButtonUpEvent(int btnId, bimWorld::CameraOperationTypes operation) = 0;

		virtual void unbindButtonUpEvent(int btnId) = 0;

		virtual void bindButtonDownEvent(int btnId, bimWorld::CameraOperationTypes operation) = 0;

		virtual void unbindButtonDownEvent(int btnId) = 0;

		// should run down/up function with try catch.
		virtual void addButton(int& outBtnId, std::function<void()>& outDownFunc, std::function<void()>& outUpFunc) = 0;

		virtual void pushForward(const float dy) = 0;

		virtual void panModel(const float dx, const float dy, const float dz = 0) = 0;

		virtual void pushSide(const float dx, const float dy, const float dz = 0) = 0;

		virtual void zoomModel(const float dy, bool pushForwardIfNeeded = true) = 0;

		virtual void zoomModelLocally(const float pointX, const float pointY, const float dy, bool pushForwardIfNeeded = true) = 0;

		virtual void zoomModelWithSelectedCenter(const float dy, bool pushForwardIfNeeded = true) = 0;

		//virtual std::shared_ptr<bimWorld::ICameraAnimation> CameraAnimation() = 0;
	};

}
#endif // __ICAMERA_MANIPULATORS_H__