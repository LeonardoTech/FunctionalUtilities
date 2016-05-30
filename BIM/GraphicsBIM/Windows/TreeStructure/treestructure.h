#ifndef TREESTRUCTURE_H
#define TREESTRUCTURE_H
#include <vector>
#include <QTimer>
#include <QTreeWidgetItem>
#include <QtWidgets/QMainWindow>
#include "ui_treestructure.h"
#include "qmywidget.h"
#include "ModelViewer.h"
#include "qentitytreewidgetitem.h"

class TreeStructure : public QMainWindow
{
	Q_OBJECT

protected:
	struct SLeftTreeNodeInfo
	{
		SLeftTreeNodeInfo()
		{
			strName = "";
			bIsChoice = true;
			iType = 0;
		}
		QString strName;
		bool bIsChoice;
		int iType;//0 系统 1 类别 2 构件名称
		QVector<SLeftTreeNodeInfo> cChildDataVect;
	};
	
	void paintEvent(QPaintEvent* e);

public:
	TreeStructure(QWidget *parent = 0);
	~TreeStructure();
	void InitFloorTreeAndComponent();
	void initFloorTree();
	void initComponentTree();
	void LoadProject();
	void LoadModel();
	int LoadFromFile(QString stdDBDir);
	void frame();
	void tree1ItemSelectionClicked(QTreeWidgetItem *pItem, int column);
	void tree2ItemSelectionClicked(QTreeWidgetItem *pItem, int column);
	void tree1ItemChanged(QTreeWidgetItem * pItem, int column);
	void tree2ItemChanged(QTreeWidgetItem * pItem, int column);
	void GetLeftTreeInfo(QVector<SLeftTreeNodeInfo>& sInfoVect);
	QEntityTreeWidgetItem* CreatItemByInfo(const SLeftTreeNodeInfo& strInfo);
protected slots:
	void itemSelectionClicked(QTreeWidgetItem *pItem, int column);
	void itemChanged(QTreeWidgetItem * item, int column);

private:
	Ui::TreeStructureClass ui;
	bimWorld::ModelViewer* m_viewer;
	QMyWidget* m_qMyWidget;
	QTimer* m_timer;
	QTreeWidgetItem* m_pHightCheckItem;
	QTreeWidgetItem* m_pHightCheckItem2;
	QTreeWidgetItem* m_pCheckItem;
	QTreeWidgetItem* m_pCheckItem2;
	bool m_bIsOutChange;
	bool m_bIsOutChange2;
	 float m_scale ;
	int m_iTypeComponent;
	bool timerStarted;
};

#endif // TREESTRUCTURE_H
