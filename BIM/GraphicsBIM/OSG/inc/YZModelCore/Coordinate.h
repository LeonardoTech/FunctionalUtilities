////////////
//    created by 孙庆号
////////////

#ifndef __COORDINATE_H__
#define __COORDINATE_H__
#include "CoordinateHelper.h"
#include <osg/ref_ptr>
#include "YZModelCoreModule.h"
#include "ICoordinate.h"
#include "CoordinateAxis.h"
#include <memory>

namespace bimWorld
{
	class YIZHU_EXPORT Coordinate :public YZModelCoreModule, public ICoordinate
	{
	public:
		Coordinate(YZModelCoreInternal* host);
		
		virtual bool setAxis(float x, float y, float radius) override;

		virtual void setLabel(COORDINATE_AXIS axis, std::string label) override;// <设置标注>
		
		virtual void setLabelPosition(COORDINATE_AXIS axis, float x, float y, float z) override;// <设置标注出现的位置>
		
		virtual void setColor(COORDINATE_AXIS axis, float x, float y, float z) override;// <设置轴的颜色>
		
		virtual void setOriginPoint(float x, float y) override;// <设置原点>
		
		virtual void setRadius(float radius) override;// <设置半径>
		
		virtual void setDarkColor(COORDINATE_AXIS axis, float x, float y, float z) override;// <设置轴的渐变色的暗色>
		
		virtual void setLabelVisibility(COORDINATE_AXIS axis, bool bvisible) override;// <设置轴是否可见>
		
		virtual void setAxisWidth(float width) override;// <设置轴线的宽度>

		// <获取坐标轴方向>
		virtual void getAxisDirection3D(COORDINATE_AXIS ax, float &x, float &y, float &z) override;
		
		virtual void setEnableUpdate(bool enabled) override;// <设置轴是否需要更新>

		virtual void setVisibility(bool visibility) override;

		virtual void setCoordinateType(CoordinateTypes type) override;

		// <default :"fonts/arialbd.ttf">
		//virtual void setFontFile(const std::string& fontFile) override;
	
	// internal:
		virtual CoordinateAxis* CoordinateAxisHelper() /*override*/;
		virtual util::CoordinateHelper* CoordinateHelper() /*override*/;
		
	protected:
		osg::ref_ptr<util::CoordinateHelper> m_coordHelper;
		std::unique_ptr<CoordinateAxis> m_coordAxis;
		osg::MatrixTransform* m_axisNode;
	};
}
#endif // __COORDINATE_H__