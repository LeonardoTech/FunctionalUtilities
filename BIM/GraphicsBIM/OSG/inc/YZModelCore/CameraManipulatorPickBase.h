////////////
//    created by 孙庆号
////////////

#ifndef __CAMERA_MANIPULATOR_PICK_BASE_H__
#define __CAMERA_MANIPULATOR_PICK_BASE_H__

#include <osgViewer/Viewer>
#include "YZModelCoreModule.h"
//#include "fireSelectionEvent.h"
#include "DataModel.h"

namespace bimWorld
{

	class CameraManipulatoerPickBase: public YZModelCoreModule
	{
	public:
		CameraManipulatoerPickBase(YZModelCoreInternal *host, double selectionPrecision = 0.01);

		virtual bool polytopePick(const double x, const double y, osgViewer::Viewer* viewer);

		virtual bool lineSegmentPick(osgViewer::View* view, const osgGA::GUIEventAdapter& ea);

		/// Handles GUIEventAdapter::DRAG event.
		virtual bool handleMouseDrag(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& us);

		virtual bool handleMousePush(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& us);

		virtual bool handleMouseRelease(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& us);

		virtual void setMode(bimWorld::ViewerMode mode);

		virtual bool handleMouseMove(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& us);

	protected:
		// Store mouse x,y location for button press & move events.
		double		_mX, _mY;
		bool								lineSegmentSelect;
		bimWorld::ViewerMode				mode;
		double								selectionPrecision;
		osg::ref_ptr<osg::Geode>			selectionRange;
		osg::ref_ptr<osg::Vec3Array>		selectionRangeVertices;
		osg::ref_ptr<osg::Geometry>			selectionRangeGeometry;
	};

}

#endif // !__CAMERA_MANIPULATOR_PICK_BASE_H__

