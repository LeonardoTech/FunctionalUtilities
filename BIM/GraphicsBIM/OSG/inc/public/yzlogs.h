////////////
//    created by 孙庆号
////////////

#ifndef YZLOGS_H
#define YZLOGS_H

#include <string>
#include "config.h"

class YIZHU_EXPORT YZLogs
{
public:
	YZLogs(const std::string& author);
	~YZLogs();

	int ExcutionStart(const std::ostringstream& stream, const std::string& classPos, const std::string& funcPos) const;
	void ExcutionEnd(int excutionId) const;
	void Infos(const std::ostringstream& stream, const std::string& classPos, const std::string& funcPos);
	void Warn(const std::ostringstream& stream, const std::string& classPos, const std::string& funcPos);
	void Errors(const std::ostringstream& stream, const std::string& classPos, const std::string& funcPos);

protected:
	std::string m_author;
};

#endif // YZLOGS_H
