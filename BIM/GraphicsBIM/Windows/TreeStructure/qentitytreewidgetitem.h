#ifndef QENTITYTREEWIDGETITEM_H
#define QENTITYTREEWIDGETITEM_H

#include <QObject>
#include <QWidget>
#include <QTreeWidgetItem>

class QEntityTreeWidgetItem  : public QTreeWidgetItem
{

public:
	QEntityTreeWidgetItem(QTreeWidgetItem *parent , QStringList strInfo);
	~QEntityTreeWidgetItem();

public:
	int GetType();
	void SetType(int iType);
private:
	int m_iType;
};

#endif // QENTITYTREEWIDGETITEM_H
