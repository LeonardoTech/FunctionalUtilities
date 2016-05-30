#ifndef __YZPROJECT_H__
#define __YZPROJECT_H__
/*
工程
*/
#include "YZElement.h"
#include "YZProjectType.h"

#define VESRION_PROJECT 1

namespace YZ
{
	class MODEL_API Project : public Element
	{
	public:
		friend class ProjectMgr;

		virtual std::string getStringValue(ModelDataType key);

		//工程类型
		void setType(ProjectType type);
		ProjectType getType(void) const;

		//工程信息
		void setInfo(const std::string& info);
		const std::string& getInfo(void) const;

		Project(void);
		Project(const std::string& uniqueID, ProjectType type);
		virtual ~Project(void);

	protected:
		//static
		ProjectType m_type;
		std::string m_info;
	};
}
#endif