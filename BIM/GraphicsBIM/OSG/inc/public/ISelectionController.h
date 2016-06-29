////////////
//    created by 孙庆号
////////////

#ifndef __ISELECTION_CONTROLLER_H__
#define __ISELECTION_CONTROLLER_H__
#include <vector>
#include "config.h"
#include "IEvent.h"

namespace bimWorld
{
	class YIZHU_EXPORT ISelectionController
	{
	public:

		virtual void onModelLoad() = 0;

		virtual void onSelect(const std::vector<std::string>& ids) = 0;

		virtual void onModelUnload() = 0;

		virtual void clearSelection() = 0;

		virtual std::vector<std::string> getCurSelect() = 0;

		virtual void setCurrentSelect(std::vector<std::string> newSelection, bool needTransparent = false, bool needZoom = false) = 0;

		// Event
		//virtual core::IEvent<void(const std::vector<std::string>& ids)>& SelectEvent() = 0;
		
		virtual void registSelectEvent(std::function<void(const std::vector<std::string>&)> func, void* instance, const std::string& description) = 0;
	};
}
#endif // __SELECTION_CONTROLLER_H__