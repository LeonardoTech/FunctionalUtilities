#ifndef __YZPARAMETER_H__
#define __YZPARAMETER_H__
/*
属性数据
*/
#include "Dragon.h"

namespace YZ
{
	class MODEL_API Parameter
	{
	public:
		friend class ParameterList;

		Parameter(void);
		~Parameter(void);

		//void setGroupId(int id);
		//int getGroupId(void);
		void setGroup(const std::string& group);
		std::string getGroup(void);

		void setName(const std::string& name);
		std::string getName(void);

		void setValue(const std::string& value);
		std::string getValue(void);

	protected:
		//int m_groupId;
		std::string m_group;
		std::string m_name;
		std::string m_value;

		//ProjectType m_prjType;
		//UnitType m_unitType;
		//PropertyType m_ptyType;
	};
}
#endif