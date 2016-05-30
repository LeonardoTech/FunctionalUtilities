#ifndef __YZIPROJECTMGR_H__
#define __YZIPROJECTMGR_H__
/*
	工程数据管理接口类
*/
#include "YZStorey.h"
#include "YZProject.h"

namespace YZ
{
	class IProjectMgr
	{
	public:
		typedef std::map<std::string, osg::ref_ptr<Project> > MapProject;
		typedef std::map<std::string, osg::ref_ptr<Storey> > MapStorey;

		//清空模型
		virtual void clearModel(void) = 0;

		//创建工程并加入当前管理
		virtual bool createProject(const std::string& uniqueID, ProjectType type, Project*& proj) = 0;

		//创建工程并不加入当前管理
		virtual Project* newProject(const std::string& uniqueID, ProjectType type) = 0;

		//添加工程到当前管理，如果有重复ID，删除以前指针后添加
		virtual bool addProject(Project* prj, bool autoID = false) = 0;

		//
		virtual const MapProject& getProject(void) = 0;

		//获取工程数目
		virtual int getProjectNumber(void) = 0;

		//根据ID获取工程
		virtual Project* getProjectByID(int ID) = 0;
		virtual Project* getProjectByUniqueID(const std::string& uniqueID) = 0;

		//删除工程，成功返回true，没有找到返回false
		virtual bool removeProjectByID(int ID) = 0;
		virtual bool removeProjectByUniqueID(const std::string& uniqueID) = 0;

		//清空所有工程数据
		virtual void clearProject(void) = 0;

		//创建楼层并加入当前管理
		virtual bool createStorey(const std::string& uniqueID, Storey*& flr) = 0;

		//创建楼层并不加入当前管理
		virtual Storey* newStorey(const std::string& uniqueID) = 0;

		//添加楼层到当前管理，如果有重复ID，删除以前指针后添加
		virtual bool addStorey(Storey* flr, bool autoID = false) = 0;

		//
		virtual const MapStorey& getStorey(void) = 0;

		//获取楼层数目
		virtual int getStoreyNumber(void) = 0;

		//根据ID获取楼层
		virtual Storey* getStoreyByID(int ID) = 0;
		virtual Storey* getStoreyByUniqueID(const std::string& uniqueID) = 0;

		//删除楼层，成功返回true，没有找到返回false
		virtual bool removeStoreyByID(int ID) = 0;
		virtual bool removeStoreyByUniqueID(const std::string& uniqueID) = 0;

		//清空所有楼层数据
		virtual void clearStorey(void) = 0;

		//根据楼层标高排序楼层
		//按标高由小到大升序排列
		virtual const std::vector<Storey*>& getStoreyByAscendingElevation(void) = 0;

		//根据标高获取楼层
		//priority为true当标高==楼层标高时，构件处于上一层底部，反之处于下一层顶部
		//offset为楼层判断误差偏移范围，priority=true当前楼层为【底-offset，顶-offset】，priority=false为【底+offset，顶+offset】
		virtual Storey* getStoreyByElevation(float elevation, bool upPriority = true, float offset = 0.01) = 0;

		//释放数据
		virtual void free(void) = 0;
	};
}
#endif