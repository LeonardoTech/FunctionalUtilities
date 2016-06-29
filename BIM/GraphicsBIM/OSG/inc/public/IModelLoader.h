////////////
//    created by 孙庆号
////////////

#ifndef __IMODEL_LOADER_H__
#define __IMODEL_LOADER_H__
#include <vector>
#include "config.h"
#include "IEvent.h"
#include "CategoryNode.h"

namespace bimWorld
{
	//==================================IModelLoader==================================
	/// @brief <加载模型>
	///
	/// <模型加载类>
	//================================================================================
	class YIZHU_EXPORT IModelLoader
	{
	public:
		//=================================loadFromDAL()================================
		/// @brief <从数据访问层加载>
		///
		/// <对函数进行详细说明>
		///
		/// @param [in] dbDir <数据库目录>
		/// @param [out] children <要传出的信息>
		///
		/// @return <返回ResultState的枚举值>
		//================================================================================
		virtual int loadFromDAL(const std::string& dbDir, std::vector<bimWorld::CategoryNode> children) = 0;

		virtual core::IEvent<void()>& UnLoadEvent() = 0;

		virtual core::IEvent<void(void)>& LoadEvent() = 0;

		virtual core::IEvent<void(const std::string[], int)>& SelectionEvent() = 0;

		//==================================connectDAL()==================================
		/// @brief <连接数据访问层>
		///
		/// <连接数据访问层>
		///
		/// @param [in] dbDir <数据库目录>
		///
		/// @return <返回ResultState的枚举值>
		//================================================================================
		virtual int connectDAL(const std::string& dbDir) = 0;
        
        //==============================setGraphStructure()=============================
        /// @brief <设置场景图结构>
        ///
        /// <设置场景图结构>
        /// <succ?>
		/// @param [in] children <图节点>
		/// 
		/// @return <void>
        //================================================================================
        virtual void setGraphStructure(std::vector<bimWorld::CategoryNode> children) = 0;
        
        //==============================loadFloorsFromDAL()=============================
        /// @brief <加载楼层信息>
        ///
        /// <从数据访问层加载楼层信息>
        ///
        /// @param [in] floorNames <要加载的楼层名称>
        ///
        /// @return <返回值为True说明加载成功， 否则失败。>
        //================================================================================
        virtual bool loadFloorsFromDAL(const std::vector<std::string>& floorNames) = 0;
        
        //=============================unloadFloorsFromDAL()============================
        /// @brief <卸载楼层信息>
        ///
        /// <从数据访问层卸载楼层信息>
        ///
        /// @param [in] floorNames <要卸载的楼层名称>
        ///
        /// @return <返回值为True说明卸载成功， 否则失败。>
        //================================================================================
        virtual bool unloadFloorsFromDAL(const std::vector<std::string>& floorNames) = 0;

		//============================loadSingleFloorFromDAL()============================
		/// @brief <加载单个楼层信息>
		///
		/// <从数据访问层加载单个楼层信息>
		///
		/// @param [in] floorName <要加载的楼层名称>
		///
		/// @return <返回值为True说明加载成功， 否则失败。>
		//================================================================================
		virtual bool loadSingleFloorFromDAL(const std::string& floorName) = 0;
		
		//===========================unloadSingleFloorFromDAL()===========================
		/// @brief <卸载单个楼层信息>
		///
		/// <从数据访问层卸载单个楼层信息>
		///
		/// @param [in] floorName <要卸载的楼层名称>
		///
		/// @return <返回值为True说明卸载成功， 否则失败。>
		//================================================================================
		virtual bool unloadSingleFloorFromDAL(const std::string& floorName) = 0;
		
		//=================================loadFromFile()=================================
		/// @brief <从文件中加载>
		///
		/// <指定加载数据的文件并加载数据>
		///
		/// @param [in] fileName <文件的名称>
		///
		/// @return <返回值为True说明加载成功， 否则失败。>
		//================================================================================
		virtual bool loadFromFile(const std::string& fileName) = 0;

		// <加载图形，使用模型颜色通道>
		//============================loadFromFileWithColor()===========================
		/// @brief <使用模型颜色通道加载模型>
		///
		/// <使用模型颜色通道加载模型>
		///
		/// @param [in] fileName <文件名称>
		///
		/// @return <如果成功返回True,否则返回False>
		//================================================================================
		virtual bool loadFromFileWithColor(const std::string& fileName) = 0;

		//==================================saveToFile()==================================
		/// @brief <保存至文件>
		///
		/// <将数据保存至文件>
		///
		/// @param [in] fileName <文件名称>
		///
		/// @return <返回值为True说明保存成功， 否则失败。>
		//================================================================================
		virtual bool saveToFile(const std::string& fileName) = 0;
		
		//=============================saveToOptimizedFile()============================
		/// @brief <保存精简后的模型>
		///
		/// <对函数进行详细说明>
		///
		/// @param [in] fileName <文件名称>
		///
		/// @return <返回值为True说明保存成功， 否则失败。>
		//================================================================================
		virtual bool saveToOptimizedFile(const std::string& fileName) = 0;
		
		///////////////////////////////////////////////////////////////////////模型数据加载/////////////////////////////////////////////////////////////////////////////////
		// <加载图形>
		//=====================================load()=====================================
		/// @brief <加载模型>
		///
		/// <从文件中加载模型>
		/// <succ?>
		/// @param [in] file <文件路径>
		///
		/// @return <void>
		//================================================================================
		virtual void load(const char *file) = 0;

		//===================================loadBox()==================================
		/// @brief <加载模型包围盒>
		///
		/// <加载模型包围盒>
		/// <succ?>
		///
		/// @return <返回值说明，可以配合使用DocGenList或DocGenTable>
		//================================================================================
		virtual void loadBox() = 0;

		//===================================loadBox()==================================
		/// @brief <加载模型包围盒>
		///
		/// <对函数进行详细说明>
		/// <succ?>
		/// @param [in] length <传入包围盒的长>
		/// @param [in] width <传入包围盒的宽>
		/// @param [in] height <传入包围盒的高>
		///
		/// @return <void>
		//================================================================================
		virtual void loadBox(float length, float width, float height) = 0;

		//==================================loadDxfHud()==================================
		/// @brief <加载DXF图纸>
		///
		/// <对函数进行详细说明>
		/// <succ?>
		/// @param [in] fileName <要加载的文件名>
		/// @param [in] x <设置x坐标>
		/// @param [in] y <设置y坐标>
		/// @param [in] width <设置宽>
		/// @param [in] height <设置高>
		///
		/// @return <void>
		//================================================================================
		virtual void loadDxfHud(const std::string& fileName, int x, int y, int width, int height) = 0;

		//=====================================load()=====================================
		/// @brief <加载多个文件>
		///
		/// <加载多个文件>
		/// <succ?>
		/// @param [in] *files <文件全路径指针>
		/// @param [in] n <加载文件数目>
		///
		/// @return <void>
		//================================================================================
		virtual void load(const char **files, int n) = 0;
		//===================================loadAll()==================================
		/// @brief <加载图形及构件参数>
		/// <弃用>
		/// <对函数进行详细说明>
		/// <succ?>
		/// @param [in, out] baseDir <数据库路径>
		/// @param [in, out] metaFileName <构件文件>
		///
		/// @return <void>
		//================================================================================
		virtual void loadAll(const char *baseDir, const char *metaFileName) = 0;

		//===============================loadBySingleFlr()==============================
		/// @brief <单层加载>
		///
		/// <单层加载模式,加载本层不会卸载掉之前楼层>
		///
		/// @param [in] files <ive文件全路径>
		/// @param [in] dEngineeringLevel <此楼层的工程标高>
		/// @param [out] outFloorName <此楼层的标识名>
		///
		/// @return <返回值0表示加载成功，返回 -1表示加载失败，返回1表示改楼层已经加载过不能重复加载>
		///
		//================================================================================
		virtual int  loadBySingleFlr(const char *files, double dEngineeringLevel, long& outFloorNode) = 0;

		//==============================unLoadBySingleFlr()=============================
		/// @brief <单层卸载>
		///
		/// <单层卸载模式>
		///
		/// @param [in] floorNode <卸载楼层的标识名>
		///
		/// @return <返回值True表示加载成功，否则表示加载失败>
		//================================================================================
		virtual bool  unLoadBySingleFlr(long floorNode) = 0;

		//==================================unLoadAll()=================================
		/// @brief <全部卸载>
		///
		/// <对函数进行详细说明>
		///
		/// <succ?>
		/// @return <void>
		//================================================================================
		virtual void unLoadAll() = 0;

		// no "YZ::CloseBIMFile();" compare to unLoadAll().
		virtual void clearAllGraphics() = 0;

		//===============================loadByMultiFlr()==============================
		/// @brief <多层加载>
		///
		/// <多层加载模式,加载本层不会卸载掉之前楼层>
		///
		/// @param [in] files		<ive文件全路径指针>
		/// @param [in] ifileSize	<楼层文件个数>
		/// @param [in] dEngineeringLevelvec <楼层的工程标高数组>
		/// @param [in] vecresut	 <楼层名称与实际楼层>
		/// @return <返回值0表示加载成功，返回 -1表示加载失败，返回n表示n个楼层已经加载过不能重复加载>
		/// @ <后两个参数暂时不用调用>
		//================================================================================
		virtual int	  loadByMultiFlr(const char **files,
			int ifileSize,
			std::vector<double>& dEngineeringLevelvec,
			std::vector<std::pair<bimWorld::YZString, std::string> >& vecresut) = 0;

		//===========================void	readNodeByMultiFle()==========================
		/// @brief <从多个文件中读取节点信息>
		///
		/// <从多个文件中读取节点信息明>
		/// <succ?>
		/// @param [in] *files <文件全路径指针>
		/// @param [in fileNum <文件个数>
		///
		/// @return <void>
		//================================================================================
		virtual  void	readNodeByMultiFle(const char **files, int fileNum) = 0;

		//===========================virtual	void	updateMode()==========================
		/// @brief <更新模型视图>
		///
		/// <更新模型视图>
		/// <succ?>
		/// @return <void>
		//================================================================================
		virtual	void	updateMode() = 0;

	};
}

#endif