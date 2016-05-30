////////////
//    created by 孙庆号
////////////

#include "SelectionController.h"
#include "ModelViewer.h"

bimWorld::SelectionController::SelectionController(IModelViewer* host) :
bimWorld::YZModelBLLModule(host)
{
	std::function<void()> func1 = std::bind(&bimWorld::SelectionController::onModelUnload, this);
	core::InstanceFunction<void()> insfunc1(func1, this, "onModelUnload");
	host->ModelLoader()->UnLoadEvent() += insfunc1;

	std::function<void()> func2 = std::bind(&bimWorld::SelectionController::onModelLoad, this);
	core::InstanceFunction<void()> insfunc2(func2, this, "onModelLoad");
	host->ModelLoader()->LoadEvent() += insfunc2;

	std::function<void(std::vector<std::string> ids, bimWorld::ViewerMode)> func3 = std::bind(&bimWorld::SelectionController::onSelect, this, std::placeholders::_1);
	core::InstanceFunction<void(std::vector<std::string> ids, bimWorld::ViewerMode)> insfunc3(func3, this, "onSelect");
	host->NodeControl()->SelectNodeEvent() += insfunc3;

	currentSelected.clear();
	m_needZoom = false;

	m_initialized = true;
}

bimWorld::SelectionController::~SelectionController()
{
	//m_host->ModelLoader()->UnLoadEvent() -= core::FunctionKey(this, "onModelUnload");
	//m_host->ModelLoader()->LoadEvent() -= core::FunctionKey(this, "onModelLoad");
	//m_host->NodeControl()->SelectNodeEvent() -= core::FunctionKey(this, "onSelect");
}


void bimWorld::SelectionController::onModelUnload()
{
	if (!m_initialized || !m_host)
	{
		return;
	}
	currentSelected.clear();
}

void bimWorld::SelectionController::onModelLoad()
{
	if (!m_initialized || !m_host)
	{
		return;
	}
	currentSelected.clear();

}

void bimWorld::SelectionController::onSelect(const std::vector<std::string>& ids)
{
	if (!m_initialized || !m_host)
	{
		return;
	}

	std::vector<std::string> nodes;
	auto n = ids.size();

	if (!m_host || n <= 0)
		setCurrentSelect(nodes);

	// <Orbit 模式下只能单选>
	if (m_host->CameraManipulator()->getCameraManipulatorMode() == Orbit)
	{
		n = 1;
		nodes.push_back(ids[0]);
		setCurrentSelect(nodes);
	}
	else
	{
		setCurrentSelect(ids);
	}

	core_Event_Trigger(m_selectEvent, currentSelected);
}

void bimWorld::SelectionController::clearSelection()
{
	if (!m_initialized || !m_host)
	{
		return;
	}

	// cancel last highlighted nodes.
	//for (int i = 0; i < currentSelected.size(); i++)
	//{
	//	m_host->NodeControl()->unHighlightWithTopGroup(currentSelected[i]);
	//}
	currentSelected.clear();
}

void bimWorld::SelectionController::setCurrentSelect(std::vector<std::string> newSelection, bool needTransparent /*= false*/, bool needZoom /*= false*/)
{
	if (!m_initialized || !m_host)
	{
		return;
	}

	m_needZoom = needZoom;
	//m_isTransparentThisTime = needTransparent;
	if (needTransparent)
	{
		m_host->NodeControl()->transparentAll();
	}

	// if same return;
	if (newSelection.size() == currentSelected.size())
	{
		for (int i = 0; i < newSelection.size(); i++)
		{
			bool has = false;
			for (int j = 0; j < currentSelected.size(); j++)
			{
				if (newSelection[i] == currentSelected[j])
				{
					has = true;
					break;
				}
			}
			if (!has)
				break;
		}
	}

	if (m_needZoom)
	{
		if (m_host->CameraManipulator()->getCameraManipulatorMode() == Orbit)
		{
			if (newSelection.size()>0)
			{
				m_host->ZoomModel()->zoomTo(newSelection[0]);
			}
		}
		else
			m_host->ZoomModel()->zoomTo(newSelection);
	}
	// cancel last highlighted nodes.
	clearSelection();

	//// highlight current nodes.
	//for (int i = 0; i < newSelection.size(); i++)
	//{
	//	m_host->NodeControl()->highlightWithTopGroup(newSelection[i]);
	//}
	//m_host->CameraManipulator()->setModelCenter(newSelection[0]);
	m_host->NodeControl()->setSelectedCenter(newSelection);

	m_host->NodeControl()->setSelectedNodes(newSelection);

	currentSelected = newSelection;

	m_isTransparentLastTime = needTransparent;
}

std::vector<std::string> bimWorld::SelectionController::getCurSelect()
{
	if (!m_initialized || !m_host)
	{
		return std::vector<std::string>();
	}

	return currentSelected;
}

//core::Event<void(const std::vector<std::string>&)>& bimWorld::SelectionController::SelectEvent()
//{
//	return m_selectEvent;
//}

void bimWorld::SelectionController::registSelectEvent(std::function<void(const std::vector<std::string>&)> func, void* instance, const std::string& description)
{
	if (!m_initialized || !m_host)
	{
		return;
	}
	core::InstanceFunction<void(const std::vector<std::string>&)> select(func, instance, description);
	m_selectEvent += select;
}

