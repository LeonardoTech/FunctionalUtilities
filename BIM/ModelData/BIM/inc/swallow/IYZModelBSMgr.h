#ifndef __YZIModelBSMgr_H__
#define __YZIModelBSMgr_H__
/*
模型二进制流交互管理接口类
*/
#include "Swallow.h"

namespace YZ
{
	class IProjectBSMgr;
	class ITemplateBSMgr;
	class IComponentBSMgr;
	class IComputeBSMgr;

	class IModelBSMgr
	{
	public:
		//获取二进制流交互管理指针
		virtual IProjectBSMgr* getProjectBSMgr(void) = 0;
		virtual ITemplateBSMgr* getTemplateBSMgr(void) = 0;
		virtual IComponentBSMgr* getComponentBSMgr(void) = 0;
		virtual IComputeBSMgr* getComputeBSMgr(void) = 0;

		//打开二进制流文件
		//openBinaryFile和closeBinaryFile必须成对出现，不能嵌套
		//对应fstream.open()和fstream.close()
		//read=true说明是从文件读数据到内存，false说明是从内存写数据到文件
		virtual bool openBinaryFile(const std::string& file, bool read) = 0;

		//关闭二进制流文件
		virtual void closeBinaryFile(void) = 0;

		//保存模型所有数据
		virtual bool saveModel(void) = 0;

		//读取模型所有数据
		virtual bool loadModel(void) = 0;

		//释放所有二进制流数据链接
		virtual void free(void) = 0;
	};
}
#endif