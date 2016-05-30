#ifndef __YZITemplateBSMgr_H__
#define __YZITemplateBSMgr_H__
/*
模板构件二进制流交互管理接口类
*/
#include "Swallow.h"

namespace YZ
{
	class ITemplateBSMgr
	{
	public:
		//保存模板构件
		virtual bool saveTemplate(void) = 0;

		//读取模板构件
		virtual bool loadTemplate(void) = 0;

		//释放数据
		virtual void free(void) = 0;
	};
}
#endif