////////////
//    created by 孙庆号
////////////

#ifndef __ENTITY_HELPER_H__
#define __ENTITY_HELPER_H__

//#include <QString>
//#include <QVector>
//#include <QMap>
#include <string>
#include <vector>
#include <map>
#include "config.h"


//// <实体构件层级信息>
//struct SEntityDBClass
//{
//	QString strLevelName;
//	QString strSysTemType;
//	QString strCategory;
//	QString strName;
//	QString strId; // <设备编号>
//	QString strGroupId;
//};


class YIZHU_EXPORT EntityHelper
{
public:
	//static void getEntityproperties(const char* dbPath, QVector<QMap<QString, QString> >& result);

	//// <返回值类型>: map[构件ID] -> pair<组ID, 组名>
	//static bool getEntityGroups(const char* dbPath, QString entityId, QMap<QString, QPair<QString, QString> >& outResult);

	//static bool GetAllEntityClassInfo(QString strDBPath, QMap<QString, SEntityDBClass>& outResult);
	//static bool GetEntityAttInfo(QString strDBPath, QString strEntityId, QMap<QString, QString>& outResult);
	static bool getAllCategory(const char* dbPath, std::vector<std::map<std::string, std::string> >& queryResult);
	//static void getIdMaterialMap(const char * dbPath, QVector<QMap<QString, QString>>& queryResult);
	//static bool getGroupsByCategory(const char * dbPath, const QString& levelName, const QString& topCategory, const QString& secCategory, QVector<QMap<QString, QString>>& queryResult);
	//static bool getNodesByCategory(const char * dbPath, const QString& levelName, const QString& topCategory, const QString& secCategory, QVector<QMap<QString, QString>>& queryResult);
};

#endif // __ENTITY_HELPER_H__

