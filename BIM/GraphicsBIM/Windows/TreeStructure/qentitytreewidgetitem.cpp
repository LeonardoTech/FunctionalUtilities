#include "qentitytreewidgetitem.h"

QEntityTreeWidgetItem::QEntityTreeWidgetItem(QTreeWidgetItem *parent, QStringList strInfo)
: QTreeWidgetItem(parent, strInfo)
{

}

QEntityTreeWidgetItem::~QEntityTreeWidgetItem()
{

}


int QEntityTreeWidgetItem::GetType()
{
	return m_iType;
}

void QEntityTreeWidgetItem::SetType(int iType)
{
	m_iType = iType;
}