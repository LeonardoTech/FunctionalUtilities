#ifndef __YZIModelBS_H__
#define __YZIModelBS_H__
/*
BS-Binary Stream(内存模型数据与二进制流数据的交互)
*/
#include "Swallow.h"

namespace YZ
{
	class IModelMgr;
	class IModelBSMgr;
	class Element;
	class GeometryItem;

	//绑定数据模型和二进制序列化操作，用于模型数据和本地二进制文件之间的数据交互
	//传入值：dirWide为需要打开的译筑文件路径，modelMgr为要保存或读取的数据模型管理指针
	//返回值：modelBSMgr为创建的模型二进制流管理指针
	//在ModelBS模块中不会释放任何Model数据，BS只管理二进制流操作相关的数据和资源
	MODELBS_API bool boundModelBS(const std::string& dirWide, IModelMgr* modelMgr, IModelBSMgr*& modelBSMgr);

	//序列化
	MODELBS_API void serialzieElement(const Element* yz, char*& blob, unsigned int& size);
	MODELBS_API void serialzieGeometryItem(const GeometryItem* yz, char*& blob, unsigned int& size);

	//反序列化
	MODELBS_API void unserialzieElement(Element*& yz, char* blob, unsigned int size);
	MODELBS_API void unserialzieGeometryItem(GeometryItem*& yz, char* blob, unsigned int size);
}
#endif