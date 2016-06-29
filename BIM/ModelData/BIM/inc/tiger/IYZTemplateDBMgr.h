#ifndef __YZITemplateDBMgr_H__
#define __YZITemplateDBMgr_H__
/*
模板构件数据库管理接口类
*/
#include "Tiger.h"

namespace YZ
{
	class ITemplateDBMgr
	{
	public:
		//释放数据
		virtual void free(void) = 0;

		//保存模板构件
		virtual bool saveTemplate(void) = 0;

		//读取模板构件
		virtual bool loadTemplate(void) = 0;

		//清空模板构件
		virtual bool clearTemplate(void) = 0;
	};
}
#endif