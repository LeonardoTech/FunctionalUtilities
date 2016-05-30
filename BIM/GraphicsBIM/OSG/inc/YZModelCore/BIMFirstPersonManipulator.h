////////////
//    created by 孙庆号
////////////

#ifndef __BIM_FIRST_PERSON_MANIPULATOR
#define __BIM_FIRST_PERSON_MANIPULATOR

#include "CameraManipulatorPickBase.h"
#include "BIMCameraManipulator.h"
#include "osgGA/FirstPersonManipulator"

namespace bimWorld
{

	class YIZHU_EXPORT BIMFirstPersonManipulator :public osgGA::FirstPersonManipulator, public CameraManipulatoerPickBase
	{
	public:
		typedef osgGA::FirstPersonManipulator Super;
		typedef CameraManipulatoerPickBase PickBase;

		BIMFirstPersonManipulator(YZModelCoreInternal *host, double selectionPrecision = 0.01);

		bool performMovementLeftMouseButton(const double eventTimeDelta, const double dx, const double dy);

		bool performMovementRightMouseButton(const double eventTimeDelta, const double dx, const double dy);

		virtual bool performMouseDeltaMovement(const float dx, const float dy);

		bool handleMouseDrag(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& us);

		bool handleMousePush(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& us);

		bool handleMouseRelease(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& us);

		bool handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa);
	
	protected:
		BIMCameraManipulator m_cameraManip;

	};
}
#endif // !__BIM_FIRST_PERSON_MANIPULATOR


