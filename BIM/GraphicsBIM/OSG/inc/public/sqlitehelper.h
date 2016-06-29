////////////
//    created by 孙庆号
////////////

#ifndef CONFIGHELPER_H
#define CONFIGHELPER_H
#pragma execution_character_set("utf-8")

#include "config.h"
//#include <QObject>
#include <map>
#include <string>
#include <vector>
//#include <mutex>

class YIZHU_EXPORT SqliteHelper// : public QObject
{
	//Q_OBJECT
public:
	//	SqliteHelper* getInstance();
	//protected:
	SqliteHelper(const char* dbPath);
	~SqliteHelper();
	friend
		int callback(void *externData, int columnNum, char **data, char **columnNames);
protected:
	bool init();
	void close();
	void handleSelectCallBack(SqliteHelper* sender, int columnNum, char **data, char **columnNames);
public:
	bool exec(const std::string& sql, std::vector<std::map<std::string, std::string> >& result);
	bool execNoneQuery(const std::string& sql);
private:
	static std::vector<std::map<std::string, std::string> >* m_selectResult;
	void *m_dataBase;
	std::string m_path;
};

#endif // CONFIGHELPER_H
