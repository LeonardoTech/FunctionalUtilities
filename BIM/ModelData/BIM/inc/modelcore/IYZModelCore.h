#ifndef __YZIModelCore_H__
#define __YZIModelCore_H__

#include "Stone.h"

namespace YZ
{
	/*
	注意：PreProcessBIMFile()和OpenBIMFile()调用完成必须调用CloseBIMFile()释放数据
	*/
	//预处理BIM文件，通过原始数据生成完整数据
	//下载完数据库后调用一次
	//dirUtf8，dirWide为文件所在目录，路径使用/作为分隔符
	//前者为utf8编码（Sqlite3）给数据库使用，后者为宽字节（fstream中文路径问题）给二进制流使用
	//byFloor已经摒弃，生成的文件格式一样
	CORE_API ResultState PreProcessBIMFile(const std::string& dirUtf8, bool byFloor = false);

	//打开BIM文件
	//dirUtf8，dirWide为文件所在目录，路径使用/作为分隔符
	//前者为utf8编码（Sqlite3）给数据库使用，后者为宽字节（fstream中文路径问题）给二进制流使用
	//loadAll=true加载全部数据到内存并同步内存数据
	//loadAll=false只加载公共数据到内存
	CORE_API ResultState OpenBIMFile(const std::string& dirUtf8, bool loadAll = true);

	//关闭BIM文件
	//saveDB=true保存所有改动数据到数据库
	//saveDB=false不保存改动数据
	CORE_API bool CloseBIMFile(bool saveDB = false);

	//保存BIM文件
	CORE_API bool SaveBIMFile(void);

	//根据楼层名称加载数据
	CORE_API bool LoadComponentByFloorName(const std::string& name);

	//根据楼层名称加载数据
	CORE_API bool LoadComponentByFloorName(const std::vector<std::string>& name);

	//根据楼层名称卸载数据
	CORE_API bool UnloadComponentByFloorName(const std::string& name);

	//根据楼层名称卸载数据
	CORE_API bool UnloadComponentByFloorName(const std::vector<std::string>& name);

	CORE_API bool isInitialized();
}
#endif