#ifndef __YZIModelDB_H__
#define __YZIModelDB_H__
/*
DB-Data Base(内存模型数据与数据库的交互)
*/
#include "Tiger.h"

namespace YZ
{
	class IModelMgr;
	class IModelDBMgr;

	//绑定数据模型和数据库操作，用于模型数据和数据库之间的数据交互
	//传入值：yzFile为需要打开的译筑文件路径，modelMgr为要保存或读取的数据模型管理指针
	//返回值：modelDBMgr为创建的模型数据库管理指针
	//在ModelDB模块中不会释放任何Model数据，DB只管理数据库操作相关的数据和资源
	MODELDB_API bool boundModelDB(const std::string& yzFile, IModelMgr* modelMgr, IModelDBMgr*& modelDBMgr);
}
#endif