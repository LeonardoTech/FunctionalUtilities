////////////
//    created by 孙庆号
////////////

#ifndef __PICK_H__
#define __PICK_H__
//#include <osg/StateSet>
//#include <osg/ref_ptr>
#include "YZModelCoreModule.h"
#include "DataModel.h"
namespace bimWorld
{
	typedef std::vector<ModelViewerListener*> ListenerSet;

	class YIZHU_EXPORT Pick
	{
	public:
		Pick();
	protected:
		// <拾取状态>
		//osg::ref_ptr<osg::StateSet> m_selectionRenderMode;

		// <视图监听器集合>
		ListenerSet m_modelViewerListeners;
	private:
	};
}
#endif // __PICK_H__