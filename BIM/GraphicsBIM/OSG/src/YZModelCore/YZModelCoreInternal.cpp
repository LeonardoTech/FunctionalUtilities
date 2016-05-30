////////////
//    created by 孙庆号
////////////

#include "YZModelCoreInternal.h"
#include "osg/Notify"

bimWorld::YZModelCoreInternal::YZModelCoreInternal()
{
	osg::setNotifyLevel(osg::FATAL);
}

bimWorld::YZModelCoreInternal::~YZModelCoreInternal()
{

}

#ifdef USING_QT
QWidget* bimWorld::YZModelCoreInternal::getWidget()
{
	return _ViewerData()->getWidget();
}
#endif // USING_QT


