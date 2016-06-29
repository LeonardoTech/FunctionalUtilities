////////////
//    created by 孙庆号
////////////

#ifndef __ICONTROL_BY_DATA_H__
#define __ICONTROL_BY_DATA_H__
#include <vector>
#include <string>
#include "config.h"
#include "ConstructKey.h"
#include "INodeController.h"
#include "IEvent.h"
#include "DataModel.h"
#include "CategoryQueryKey.h"

namespace bimWorld
{
	//=============================INodeEntityController============================
	/// @brief <实体构件显示控制>
	///
	/// <对该类进行详细描述>
	//================================================================================
	class YIZHU_EXPORT INodeEntityController:public INodeController
	{
	public:

		//=====================================hide()=====================================
		/// @brief <隐藏单个构件>
		///
		/// <隐藏单个构件>
		/// <succ?>
		/// @param [in] id <构件ID>
		///
		/// @return <void>
		//================================================================================
		virtual void hide(const std::string& id) = 0;

		//====================================unHide()====================================
		/// @brief <显示单个构件>
		///
		/// <显示单个构件>
		/// <succ?>
		/// @param [in] id <构件ID>
		///
		/// @return <void>
		//================================================================================
		virtual void unHide(const std::string& id) = 0;

		//===============================hideWithTopGroup()===============================
		/// @brief <隐藏构件所在的最顶层的组>
		/// <易混淆>
		/// <隐藏构件所在的最顶层的组>
		/// <succ?>
		/// @param [in] id <构件ID>
		///
		/// @return <void>
		//================================================================================
		virtual void hideWithTopGroup(const std::string& id) = 0;

		//==============================unHideWithTopGroup()==============================
		/// @brief <显示构件所在的最顶层的组>
		/// <易混淆>
		/// <显示构件所在的最顶层的组>
		/// <succ?>
		/// @param [in] id <构件ID>
		///
		/// @return <void>
		//================================================================================
		virtual void unHideWithTopGroup(const std::string& id) = 0;

		//==================================hideOthers()==================================
		/// @brief <隐藏构件之外的所有构件>
		///
		/// <隐藏构件之外的所有构件>
		/// <succ?>
		/// @param [in] id <构件ID>
		///
		/// @return <void>
		//================================================================================
		virtual void hideOthers(const std::string& id) = 0;

		//=================================unHideOthers()=================================
		/// @brief <显示构件之外的所有构件>
		///
		/// <显示构件之外的所有构件>
		/// <succ?>
		/// @param [in] id <构件ID>
		///
		/// @return <void>
		//================================================================================
		virtual void unHideOthers(const std::string& id) = 0;

		//==================================hideOthers()==================================
		/// @brief <隐藏本组构件之外的所有构件>
		///
		/// <隐藏本组构件之外的所有构件>
		/// <succ?>
		/// @param [in] ids <本组构件ID>
		///
		/// @return <void>
		//================================================================================
		virtual void hideOthers(const std::vector<std::string>& ids) = 0;

		//=================================unHideOthers()=================================
		/// @brief <显示本组构件之外的所有构件>
		///
		/// <显示本组构件之外的所有构件>
		/// <succ?>
		/// @param [in] ids <本组构件ID>
		///
		/// @return <void>
		//================================================================================
		virtual void unHideOthers(const std::vector<std::string>& ids) = 0;

		//==================================toggleHide()==================================
		/// @brief <切换隐藏>
		///
		/// <对单个构件切换隐藏>
		/// <succ?>
		/// @param [in] id <构件ID>
		///
		/// @return <void>
		//================================================================================
		virtual void toggleHide(const std::string& id) = 0;

		//// <透明node节点以外的所有节点>
		//virtual void setOtherNodeToTransparent(const std::string& id) = 0;

		//// <透明node节点以外的所有节点>
		//virtual void setOtherNodeToTransparent(const std::string* ids, int length) = 0;

		//================================getCategoryKey()================================
		/// @brief <获取指定构件的详细信息>
		///
		/// <获取指定构件的详细信息>
		///
		/// @param [in] id <指定构件的id>
		/// @param [out] outKey <要传出的构件信息>
		///
		/// @return <返回值为True说明获取成功， 否则失败。失败可能是由于id值非法或节点不再存在等原因造成。>
		//================================================================================
		virtual bool getCategoryKey(const std::string& id, ConstructKey& outKey) = 0;

		//===============================getCategoryKeys()==============================
		/// @brief <获取指定构件的详细信息>
		///
		/// <获取指定构件的详细信息>
		/// <succ?>
		/// @return <void>
		//================================================================================
		virtual std::vector<ConstructKey> getCategoryKeys() = 0;

		//================================getVisibility()===============================
		/// @brief <获取构件是否可见>
		///
		/// <获取构件是否可见>
		///
		/// @param [in] id <要查询的构件ID>
		/// @param [out] visible <传出构件的可见性>
		///
		/// @return <返回值为True说明获取成功， 否则失败。>
		//================================================================================
		virtual bool getVisibility(const std::string& id, bool& visible) = 0;

		//============================setHighLightByCategory()============================
		/// @brief <根据分类设置高亮>
		///
		/// <根据分类设置高亮>
		///
		/// @param [in] floor <楼层信息>
		/// @param [in] topCategory <第一项分类信息>
		/// @param [in] secondaryCategory <第二项分类信息>
		/// @param [in] isHighLight <是否设置高亮>
		///
		/// @return <返回值为True说明设置成功， 否则失败。>
		//================================================================================
		virtual bool setHighLightByCategory(const YZString& floor, const YZString& topCategory, const YZString& secondaryCategory, bool isHighLight) = 0;
		
		//============================setHighLightByCategory()============================
		/// @brief <根据分类设置高光>
		///
		/// <根据关键字查询设置高亮>
		///
		/// @param [in] queryKey <所设关键字>
		/// @param [in] isHighLight <是否设置高亮>
		///
		/// @return <返回值为True说明设置成功， 否则失败。>
		//================================================================================
		virtual bool setHighLightByCategory(const CategoryQueryKey& queryKey, bool isHighLight) = 0;

		//====================================getAll()====================================
		/// @brief <获取构件所有信息>
		///
		/// <获取构件所有信息>
		/// <succ?>
		/// @param [in] ids <所有要查询构件的ID>
		///
		/// @return <void>
		//================================================================================
		virtual void getAll(std::vector<std::string>& ids) const = 0;

		//=================================findIdByNode()=================================
		/// @brief <查询构件的ID>
		///
		/// <查询构件的ID>
		///
		/// @param [in] node <构件的指针>
		///
		/// @return <所查询构件的ID>
		//================================================================================
		virtual std::string findIdByNode(void* node) = 0;

		//=================================findNodeById()=================================
		/// @brief <根据构件ID来查询构件>
		///
		/// <对函数进行详细说明>
		///
		/// @param [in] id <所查询构件的ID>
		///
		/// @return <void>
		//================================================================================
		virtual void* findNodeById(const std::string& id) = 0;

		//virtual void setCategoryMaterial(const CategoryName& categoryName, const SystemType& systemType, const LevelName& levelName, const MaterialSetting& materialSetting, bool clear = false);
		//virtual void setCategoryMaterial(const ColorCategory& materialSetting);

		//virtual const MaterialSetting*		getCategoryMaterial(const CategoryName& categoryName) const;

		//// <按楼层隐藏>
		//virtual void setVisibleByFloor(const YZString& floor, bool visible) = 0;

		//// <按分类隐藏>
		//virtual void setVisibleByCategory(const YZString& category, bool visible) = 0;

		// <按楼层分类显示控制>
		//==========================setVisibleByFloorCategory()=========================
		/// @brief <根据层分类来设置可见性>
		///
		/// <根据层分类来设置可见性>
		/// <succ?>
		/// @param [in] floor <楼层信息>
		/// @param [in] category <分类信息>
		/// @param [in] visible <可见性设置>
		/// 
		/// @return <void>
		//================================================================================
		virtual void setVisibleByFloorCategory(const YZString& floor, const YZString& category, bool visible) = 0;
		
		//=============================setVisibleByCategory()=============================
		/// @brief <根据分类来设置可见性>
		///
		/// <根据类别关键字来设置可见性>
		/// <succ?>
		/// @param [in] queryKey <类别关键字>
		/// @param [in] visible <可见性设置>
		/// 
		/// @return <返回值为True说明设置成功， 否则失败。>
		//================================================================================
		virtual bool setVisibleByCategory(const CategoryQueryKey& queryKey, bool visible) = 0;

		//==================================setVisible()==================================
		/// @brief <设置单个构件可见性>
		///
		/// <设置单个构件可见性>
		/// <succ?>
		/// @param [in] id <构件ID>
		/// @param [in] visible <可见性设置>
		///
		/// @return <void>
		//================================================================================
		virtual void setVisible(const std::string& id, bool visible) = 0;

		//==================================setVisible()==================================
		/// @brief <设置多个构件可见性>
		///
		/// <设置多个构件可见性>
		/// <succ?>
		/// @param [in] ids <多个构件ID>
		/// @param [in] n <构件数目>
		/// @param [in] visible <可见性设置>
		///
		/// @return <void>
		//================================================================================
		virtual void setVisible(const std::string *ids, int n, bool visible) = 0;

		//==================================isVisible()=================================
		/// @brief <查询构件可见性>
		///
		/// <查询构件可见性>
		///
		/// @param [in] id <构件ID>
		///
		/// @return <如构件可见返回True，否则返回False>
		//================================================================================
		virtual bool isVisible(const std::string& id) = 0;

		///////////////////////////////////////节点高亮相关操作//////////////////////////////////////

		//==========================setStateColorToConstructs()=========================
		/// @brief <设置节点状态颜色>
		///
		/// <设置节点状态颜色>
		/// <succ?>
		/// @param [in, out] nodeId <节点ID>
		/// @param [in, out] red <颜色向量的R值>
		/// @param [in, out] green <颜色向量的G值>
		/// @param [in, out] blue <颜色向量的B值>
		///
		/// @return <void>
		//================================================================================
		virtual void setStateColorToConstructs(const std::string& nodeId, int red, int green, int blue) = 0;

		//=========================revertStateColorOfConstructs()=========================
		/// @brief <恢复节点状态颜色>
		///
		/// <恢复节点状态颜色>
		///
		/// @param [in] nodeId <节点ID>
		///
		/// @return <如恢复成功返回值为True,否则为False>
		//================================================================================
		virtual bool revertStateColorOfConstructs(const std::string& nodeId) = 0;

		//==================================highlight()=================================
		/// @brief <对节点设置高亮显示>
		///
		/// <对节点设置高亮显示>
		/// <succ?>
		/// @param [in] id <节点ID>
		///
		/// @return <void>
		//================================================================================
		virtual void highlight(const std::string& id) = 0;

		//=================================unHighlight()================================
		/// @brief <取消节点的高亮显示>
		///
		/// <取消节点的高亮显示>
		/// <succ?>
		/// @param [in] id <节点ID>
		///
		/// @return <void>
		//================================================================================
		virtual void unHighlight(const std::string& id) = 0;

		//============================highlightWithTopGroup()===========================
		/// @brief <高亮显示构件所在的最顶层的组>
		/// <易混淆>
		/// <高亮显示构件所在的最顶层的组>
		/// <succ?>
		/// @param [in] id <节点ID>
		///
		/// @return <void>
		//================================================================================
		virtual void highlightWithTopGroup(const std::string& id) = 0;

		//===========================unHighlightWithTopGroup()==========================
		/// @brief <非高亮显示构件所在的最顶层的组>
		/// <易混淆>
		/// <非高亮显示构件所在的最顶层的组>
		/// <succ?>
		/// @param [in] id <节点ID>
		///
		/// @return <void>
		//================================================================================
		virtual void unHighlightWithTopGroup(const std::string& id) = 0;

		//virtual void unTransparent(const std::string& id) = 0;

		//===============================setToTransparent()===============================
		/// @brief <将节点设置为透明>
		///
		/// <将节点设置为透明>
		/// <succ?>
		/// @param [in] id <节点ID>
		///
		/// @return <void>
		//================================================================================
		virtual void setToTransparent(const std::string& id) = 0;
		
		//===============================setCurrentDBPath()===============================
		/// @brief <设置当前数据库的路径>
		/// <弃用>
		/// <对函数进行详细说明>
		/// <succ?>
		/// @param [in] path <数据库路径>
		///
		/// @return <void>
		//================================================================================
		virtual void setCurrentDBPath(const std::string& path) = 0;

		//==============================revertColorOfNode()=============================
		/// @brief <恢复单个节点的颜色信息>
		///
		/// <恢复单个节点的颜色信息>
		///
		/// @param [in] id <节点ID>
		///
		/// @return <恢复成功返回值True,否则返回False>
		//================================================================================
		virtual bool revertColorOfNode(const std::string& id) = 0;

		//==============================revertColorOfNodes()==============================
		/// @brief <恢复一组节点的颜色信息>
		///
		/// <恢复一组节点的颜色信息>
		///
		/// @param [in] ids <所有恢复节点的ID>
		///
		/// @return <恢复成功返回值True,否则返回False>
		//================================================================================
		virtual bool revertColorOfNodes(const std::vector<std::string>& ids) = 0;
		
		//===============================SelectNodeEvent()==============================
		/// @brief <选择节点事件>
		///
		/// @return <void>
		//==============================================================================
		virtual core::IEvent<void(std::vector<std::string>, ViewerMode)>& SelectNodeEvent() = 0;

		//==============================setSelectedCenter()=============================
		/// @brief <把场景中心设为选中的构件中心>
		/// <succ?>
		/// <把场景中心设为选中的构件中心>
		/// <易混淆>
		/// @param [in] id <构件ID>
		///
		/// @return <void>
		//================================================================================
		virtual void setSelectedCenter(const std::string& id) = 0;

		//==============================setSelectedCenter()=============================
		/// @brief <把场景中心设为选中的构件组的中心>
		/// <succ?>
		/// <把场景中心设为选中的构件组的中心>
		/// <易混淆>
		/// @param [in] ids <节点ID>
		///
		/// @return <void>
		//================================================================================
		virtual void setSelectedCenter(const std::vector<std::string>& ids) = 0;

		//===============================setSelectedNodes()===============================
		/// @brief <设置一组选择节点>
		/// <succ?>
		/// <对函数进行详细说明>
		///
		/// @param [in] ids <节点ID>
		///
		/// @return <void>
		//================================================================================
		virtual void setSelectedNodes(const std::vector<std::string>& ids) = 0;
		
		//virtual int addBillboard(const std::vector<std::string>& ids, void(*clicked)(), const char* img_path_name = NULL) = 0;

		//============================getNodeCenterPosition()===========================
		/// @brief <获取节点中心位置>
		///
		/// <对函数进行详细说明>
		///
		/// @param [in] id <节点ID>
		/// @param [out] x <传出中心位置的X坐标>
		/// @param [out] y <传出中心位置的Y坐标>
		/// @param [out] z <传出中心位置的Z坐标>
		///
		/// @return <获取成功返回True,否则返回False>
		//================================================================================
		virtual bool getNodeCenterPosition(const std::string& id, float& x, float& y, float& z) = 0;
	};
}
#endif // __ICONTROL_BY_DATA_H__