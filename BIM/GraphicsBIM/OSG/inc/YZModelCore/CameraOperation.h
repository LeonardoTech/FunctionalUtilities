////////////
//    created by 孙庆号
////////////

#ifndef __CAMERA_OPERATION_H__
#define __CAMERA_OPERATION_H__
#include "YZModelCoreModule.h"
#include "CameraOperationTypes.h"
#include "ICameraOperation.h"
#include <chrono>
#include "DataModel.h"
#include "osg/Geode"
#include <memory>
#include "LinePrimitive.h"

namespace bimWorld
{
	class BIMCameraManipulator;

	class YIZHU_EXPORT CameraOperation : public YZModelCoreModule, public ICameraOperation
	{
	public:
		CameraOperation(YZModelCoreInternal* host);

		bool beginMoveForward() override;
		bool endMoveForward() override;

		bool beginMoveLeft() override;
		bool endMoveLeft() override;

		bool beginMoveRight() override;
		bool endMoveRight() override;

		bool beginMoveBackward() override;
		bool endMoveBackward() override;

		void setMovingSpeed(double speed = 1.0) override;
		double getMovingSpeed() override;

		bool beginTurnLeft() override;
		bool endTurnLeft() override;

		bool beginTurnRight() override;
		bool endTurnRight() override;

		void setTurnSpeed(double speed = 1.0) override;
		double getTurnSpeed() override;

		bool beginRotateCameraWithSelectedCenter() override;
		bool endRotateCameraWithSelectedCenter() override;

		bool onHome() override;

		bool onZoomModel(const double eventTimeDelta, const float dx, const float dy) override;
		bool onPanModel(const double eventTimeDelta, const float dx, const float dy) override;
		bool onRotateCamera(const double eventTimeDelta, const float dx, const float dy) override;
		bool onRotateCameraWithSelectedCenter(const double eventTimeDelta, const float dx, const float dy) override;

		bool pauseRendering() override;

		bool orbitPick(const double x, const double y) override;

		void multiPickStart(const double x, const double y) override;

		bool multiPickEnd(const double x, const double y) override;

		void updateMultiPickRange(const double x, const double y) override;

		void beginCameraOperation() override;

		// internal:
		bool selectConstruct(const double x, const double y, bimWorld::ViewerMode mode, osg::Camera* camera);

		void onMoveForward(std::chrono::system_clock::time_point tick);

		void onMoveLeft(std::chrono::system_clock::time_point tick);

		void onMoveRight(std::chrono::system_clock::time_point tick);

		void onMoveBackward(std::chrono::system_clock::time_point tick);

		void onTurnLeft(std::chrono::system_clock::time_point tick);

		void onTurnRight(std::chrono::system_clock::time_point tick);

		void zoomForward(float delta, float frame);

		void zoomBackward(float delta, float frame);

		float getZoomDelta(float totalFrame);

		float getMoveFactor();

	protected:
		BIMCameraManipulator* _cameraManipulator();
		std::chrono::system_clock::time_point m_lastOnMoveBackwardTime;
		std::chrono::system_clock::time_point m_lastOnMoveForwardTime;
		std::chrono::system_clock::time_point m_lastOnMoveLeftTime;
		std::chrono::system_clock::time_point m_lastOnMoveRightTime;

		bool m_firstMoveForward;
		bool m_firstMoveBackward;
		bool m_firstMoveLeft;
		bool m_firstMoveRight;
		double m_movingSpeed;
		double m_turningSpeed;
		double _pickStartX;
		double _pickStartY;
		
		osg::ref_ptr<osg::Geode>			m_selectionRange;
		//osg::ref_ptr<osg::Vec3Array>		m_selectionRangeVertices;
		//osg::ref_ptr<osg::Geometry>			m_selectionRangeGeometry;
		std::unique_ptr<LinePrimitive[]> m_selectionRangeWireframe;
	};

}
#endif // __CAMERA_OPERATION_H__