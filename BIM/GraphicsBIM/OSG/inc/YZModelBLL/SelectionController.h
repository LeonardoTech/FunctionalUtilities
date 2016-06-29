////////////
//    created by 孙庆号
////////////

#ifndef __SELECTION_CONTROLLER_H__
#define __SELECTION_CONTROLLER_H__
#include "YZModelBLLModule.h"
#include "ISelectionController.h"
#include "Event.h"

namespace bimWorld
{
	class YIZHU_EXPORT SelectionController :public YZModelBLLModule, public ISelectionController
	{
	public:
		SelectionController(IModelViewer* host);

		virtual ~SelectionController();

		virtual void onModelLoad() override;

		virtual void onSelect(const std::vector<std::string>& ids) override;

		virtual void onModelUnload() override;

		virtual void clearSelection() override;

		std::vector<std::string> getCurSelect() override;

		virtual void setCurrentSelect(std::vector<std::string> newSelection, bool needTransparent = false, bool needZoom = false) override;

		// Event
		//virtual core::IEvent<void(const std::vector<std::string>&)>& SelectEvent() override;

		virtual void registSelectEvent(std::function<void(const std::vector<std::string>&)> func, void* instance, const std::string& description) override;

	protected:
		std::vector<std::string> currentSelected;
		bool m_needZoom;
		bool m_isTransparentLastTime;

		core::Event<void(const std::vector<std::string>&)> m_selectEvent;
	};
}
#endif // __SELECTION_CONTROLLER_H__