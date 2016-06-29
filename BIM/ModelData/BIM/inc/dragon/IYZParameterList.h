#ifndef __YZIPARAMETERLIST_H__
#define __YZIPARAMETERLIST_H__
/*
属性数据管理接口类
*/
#include "YZParameter.h"

namespace YZ
{
	class IParameterList
	{
	public:
		typedef std::map<std::string, Parameter* > MapParameter;

		virtual const MapParameter& getParameter(void) const = 0;

		virtual void getParameter(MapMapStdString& result) const = 0;

		//virtual std::vector<Parameter*> getPropertyByGroup(int group) = 0;

		virtual bool addParameter(Parameter* pty) = 0;

		virtual void clearParameter(void) = 0;

		virtual bool empty(void) = 0;

		//释放数据
		virtual void free(void) = 0;
	};
}
#endif