#pragma execution_character_set("utf-8")

#include <QThread>
#include <QStandardItem>
#include <QMessageBox>
#include <QLayout>
#include <QGridLayout>
#include <excpt.h>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTreeWidget>
#include <QPalette>
#include <QMessageBox>
#include "treestructure.h"
#include "../../../ModelData/BIM/inc/modelcore/IYZComponentCore.h"
#include "../../../ModelData/BIM/inc/modelcore/IYZProjectCore.h"
#include "../../../ModelData/BIM/inc/modelcore/IYZTemplateCore.h"

TreeStructure::TreeStructure(QWidget *parent)
: QMainWindow(parent)
{
	timerStarted = false;
	ui.setupUi(this);

	m_pHightCheckItem = NULL;
	m_pHightCheckItem2 = NULL;

	m_qMyWidget = new QMyWidget();
	m_viewer = new bimWorld::ModelViewer(m_qMyWidget);
	m_qMyWidget->setOsgView(m_viewer);// <主要是为了QT事件操作模型>

	m_scale = 0.0;
	setCentralWidget(m_qMyWidget);


	// <启动定时器模型渲染>
	m_timer = new QTimer;
	connect(m_timer, &QTimer::timeout, this, &TreeStructure::frame);
	m_timer->setInterval(33);


	QObject::connect(ui.treeWidget, &QTreeWidget::itemPressed, this, &TreeStructure::itemSelectionClicked);
	QObject::connect(ui.treeWidget, &QTreeWidget::itemChanged, this, &TreeStructure::itemChanged);

	QObject::connect(ui.treeWidget_2, &QTreeWidget::itemPressed, this, &TreeStructure::itemSelectionClicked);
	QObject::connect(ui.treeWidget_2, &QTreeWidget::itemChanged, this, &TreeStructure::itemChanged);

	QObject::connect(ui.menuLoad, &QMenu::aboutToShow, this, &TreeStructure::LoadProject);
	

	m_viewer->TestModules()->test();
}


TreeStructure::~TreeStructure()
{

}


void TreeStructure::itemSelectionClicked(QTreeWidgetItem *pItem, int column)
{

	QTreeWidget * pDlg = qobject_cast<QTreeWidget*>(QObject::sender());
	if (pDlg == ui.treeWidget)
	{
		tree1ItemSelectionClicked(pItem, column);
	}
	else if (pDlg == ui.treeWidget_2)
	{
		tree2ItemSelectionClicked(pItem, column);
	}
}

void TreeStructure::itemChanged(QTreeWidgetItem * item, int column)
{
	QTreeWidget * pDlg = qobject_cast<QTreeWidget*>(QObject::sender());
	if (pDlg == ui.treeWidget)
	{
		tree1ItemChanged(item, column);
	}
	else if (pDlg == ui.treeWidget_2)
	{
		tree2ItemChanged(item, column);
	}
}




void TreeStructure::initFloorTree()
{
	std::vector<std::string> sFloorVect;
	YZ::getFloorName(sFloorVect);

	ui.treeWidget->setHeaderHidden(true);
	ui.treeWidget->setColumnCount(1);
	ui.treeWidget->clear();
	QStringList strRoot;
	strRoot << "楼层";
	QTreeWidgetItem* pRoot = new QTreeWidgetItem(ui.treeWidget, strRoot);

	pRoot->setCheckState(0, Qt::Checked);

	for (int i = 0; i < sFloorVect.size(); i++)
	{
		QStringList strdatalist;
		strdatalist << QString((sFloorVect[i]).c_str());
		QTreeWidgetItem* pTopI = new QTreeWidgetItem(strdatalist);
		pTopI->setCheckState(0, Qt::Checked);
		pRoot->addChild(pTopI);
	}
	pRoot->setExpanded(true);
	ui.treeWidget->addTopLevelItem(pRoot);
}

void TreeStructure::initComponentTree()
{
	ui.treeWidget_2->setHeaderHidden(true);
	ui.treeWidget_2->setColumnCount(1);
	ui.treeWidget_2->clear();
	QVector<SLeftTreeNodeInfo> sInfoVect;
	GetLeftTreeInfo(sInfoVect);
	for (int i = 0; i < sInfoVect.size(); i++)
	{
		QEntityTreeWidgetItem *pTopItem = CreatItemByInfo(sInfoVect[i]);
		pTopItem->setCheckState(0, Qt::Checked);
		ui.treeWidget_2->addTopLevelItem(pTopItem);
		pTopItem->setExpanded(true);
	}
}

void TreeStructure::GetLeftTreeInfo(QVector<SLeftTreeNodeInfo>& sInfoVect)
{
	// <获取专业，类型对应表>
	std::map<std::string, YZ::MapVecStdString> sDataMap;
	YZ::getDomainCategoryName(sDataMap);
	// <解析map>
	for (std::map<std::string, YZ::MapVecStdString>::const_iterator Itr = sDataMap.begin(); Itr != sDataMap.end(); Itr++)
	{
		SLeftTreeNodeInfo sNewCate;
		sNewCate.strName = QString::fromUtf8(Itr->first.c_str());
		sNewCate.iType = 1;

		for (YZ::MapVecStdString::const_iterator ItrSec = Itr->second.begin(); ItrSec != Itr->second.end(); ItrSec++)
		{
			SLeftTreeNodeInfo sNewBig;
			sNewBig.strName = QString::fromUtf8(ItrSec->first.c_str());
			sNewBig.iType = 2;

			for (int i = 0; i < ItrSec->second.size(); i++)
			{
				SLeftTreeNodeInfo sNewName;
				sNewName.strName = QString::fromUtf8(ItrSec->second[i].c_str());
				sNewName.iType = 3;
				sNewBig.cChildDataVect.push_back(sNewName);
			}

			sNewCate.cChildDataVect.push_back(sNewBig);
		}

		sInfoVect.push_back(sNewCate);
	}
}

QEntityTreeWidgetItem* TreeStructure::CreatItemByInfo(const SLeftTreeNodeInfo& strInfo)
{
	QStringList strTempList;
	strTempList << strInfo.strName;
	QEntityTreeWidgetItem *pTopItem = new QEntityTreeWidgetItem(NULL, strTempList);
	pTopItem->SetType(strInfo.iType);
	

	Qt::CheckState sTopItemState = Qt::Unchecked;
	if (strInfo.bIsChoice)
	{
		sTopItemState = Qt::Checked;
	}
	for (int i = 0; i < strInfo.cChildDataVect.size(); i++)
	{
		QTreeWidgetItem *pChildeItem = CreatItemByInfo(strInfo.cChildDataVect[i]);
		if (sTopItemState == Qt::Unchecked)
		{
			if (pChildeItem->checkState(0) == Qt::Checked)
			{
				sTopItemState = Qt::Checked;
			}
			else if (pChildeItem->checkState(0) == Qt::PartiallyChecked)
			{
				sTopItemState = Qt::PartiallyChecked;
			}
		}
		else if (sTopItemState == Qt::Checked)
		{
			if (pChildeItem->checkState(0) == Qt::Unchecked || pChildeItem->checkState(0) == Qt::PartiallyChecked)
			{
				sTopItemState = Qt::PartiallyChecked;
			}
		}

		pTopItem->addChild(pChildeItem);
	}
	pTopItem->setCheckState(0, sTopItemState);
	return pTopItem;
}

void TreeStructure::InitFloorTreeAndComponent()
{
	initFloorTree();
	initComponentTree();
	//QStringList sFloorVect;
	//GetYZModel()->GetData()->GetProjectFloorList(sFloorVect);
}


void  TreeStructure::LoadProject()
{
	// <加载模型>
	LoadModel();
	// <加载完模型之后显示右边的树>
 	InitFloorTreeAndComponent();
}

void TreeStructure::LoadModel()
{
	m_viewer->RenderingThread()->startRendering();
	int re = LoadFromFile("test");
	if (re == 1)
	{
		m_viewer->ZoomModel()->zoomRoot();
	}
}

int TreeStructure::LoadFromFile(QString stdDBDir)
{
	std::string strUtf8DBDir(stdDBDir.toUtf8());

	bimWorld::CategoryNode floor(YZ::YZ_FLOOR);

	bimWorld::CategoryNode major(YZ::YZ_DOMAIN);
	bimWorld::CategoryNode categories(YZ::YZ_CATEGORY);
	bimWorld::CategoryNode name(YZ::YZ_TEMPLATE_NAME);
	std::vector<bimWorld::CategoryNode> children;
	categories.addParent(major);
	name.addParent(categories);
	children.push_back(name);
	children.push_back(floor);

	int result = m_viewer->ModelLoader()->loadFromDAL(strUtf8DBDir, children);
	//YZ::changeBlockyComponentMemory();

	return result;
}

void TreeStructure::frame()
{
	
	__try
	{
		auto myObject = dynamic_cast<QGLWidget*>(m_qMyWidget)->context();
		myObject->doneCurrent();
		myObject->moveToThread(QThread::currentThread());
		bimWorld::IRenderingThreads* tt = m_viewer->RenderingThread();
		tt->loop();
	}
	__except (1)//std::exception& e
	{
		QMessageBox::critical(this, "警告", "刷新图形出错");
	}
	//m_scale = m_viewer->PlottingScales()->getScale();
}


void TreeStructure::tree1ItemSelectionClicked(QTreeWidgetItem *pItem, int column)
{
	QTreeWidgetItem* pParent = pItem->parent();
	if (pParent == NULL)
	{
		return;
	}

	if (m_pHightCheckItem == NULL)//没有高亮过
	{
		if (pItem->checkState(0) != Qt::Unchecked)
		{
			m_pHightCheckItem = pItem;
			//emit HighLightFloor(m_pHightCheckItem->text(0), true); // <发给谁的>
		}
	}
	else
	{
		if (m_pHightCheckItem == pItem) //高亮当前选中 再点击取消高亮
		{
			//emit HighLightFloor(m_pHightCheckItem->text(0), false);

			m_pHightCheckItem = NULL;
		}
		else
		{
			//高亮当前的
			//emit HighLightFloor(m_pHightCheckItem->text(0), false);
			if (pItem->checkState(0) != Qt::Unchecked)
			{
				m_pHightCheckItem = pItem;
				//emit HighLightFloor(m_pHightCheckItem->text(0), true);
			}
		}
	}
}


void TreeStructure::tree2ItemSelectionClicked(QTreeWidgetItem *pItem, int column)
{
	if (m_pHightCheckItem2 == NULL)//没有高亮过
	{
		if (pItem->checkState(0) != Qt::Unchecked)
		{
// 			m_pHightCheckItem2 = (QEntityTreeWidgetItem*)pItem;
// 			SetHighLight(true);
		}
	}
	else
	{
		//SetHighLight(false);
		if (m_pHightCheckItem2 == pItem) //高亮当前选中 再点击取消高亮
		{
			m_pHightCheckItem2 = NULL;
		}
		else
		{
			if (pItem->checkState(0) != Qt::Unchecked)
			{
// 				m_pHightCheckItem2 = (QEntityTreeWidgetItem*)pItem;
// 				SetHighLight(true);
			}
		}
	}
}



void TreeStructure::tree1ItemChanged(QTreeWidgetItem * pItem, int column)
{
	if (m_pCheckItem == NULL)
	{
		m_pCheckItem = pItem;
	}

	QTreeWidgetItem* pParent = pItem->parent();
	if (pParent)
	{
		if (m_pCheckItem == pItem)
		{
			//楼层节点
			bool bIsVisable(true);
			if (Qt::Unchecked == pItem->checkState(0))
			{
				bIsVisable = false;
			}
			QStringList strFloorList;
			strFloorList << pItem->text(0);
			//UpdateParentState();

			if (!m_bIsOutChange)
			{
				//emit FloorChanged(strFloorList, bIsVisable); // <发给谁>
			}

		}
	}
	else
	{
		//根节点
		if (m_pCheckItem == pItem)
		{
			QStringList strFloorList;
			bool bIsVisable;
			if (Qt::Checked == pItem->checkState(0))
			{
				bIsVisable = true;
				for (int i = 0; i < pItem->childCount(); i++)
				{
					strFloorList << pItem->child(i)->text(0);
					pItem->child(i)->setCheckState(0, Qt::Checked);
				}
			}
			else
			{
				bIsVisable = false;
				for (int i = 0; i < pItem->childCount(); i++)
				{
					strFloorList << pItem->child(i)->text(0);
					pItem->child(i)->setCheckState(0, Qt::Unchecked);
				}
			}
			if (!m_bIsOutChange)
			{
				//emit FloorChanged(strFloorList, bIsVisable);
			}
		}
	}
}

void TreeStructure::tree2ItemChanged(QTreeWidgetItem * pItem, int column)
{
	if (m_pCheckItem2 == NULL)
	{
		//m_pCheckItem2 = (QEntityTreeWidgetItem*)pItem;
	}
	if (m_pCheckItem2 == NULL)
	{
		return;
	}
	if (m_pCheckItem2 == pItem)
	{
		if (m_bIsOutChange2)
		{
			m_pCheckItem2 = NULL;
			return;
		}
		else
		{
			bool bIsVisable(true);
			if (Qt::Unchecked == m_pCheckItem2->checkState(0))
			{
				bIsVisable = false;
			}

			QString strText = m_pCheckItem2->text(0);
			int iType = 0;// m_pCheckItem2->GetType();
			if (iType == 1)
			{
// 				SystemChanged(m_pCheckItem2, bIsVisable);
// 				SystemChangedSlot(strText, bIsVisable);
			}
			else if (iType == 2)
			{

				QTreeWidgetItem * pParentItem = m_pCheckItem2->parent();
				if (pParentItem)
				{
// 					CateChanged(m_pCheckItem2, pParentItem->text(0), bIsVisable);
// 					SystemCateChangedSlot(pParentItem->text(0), strText, bIsVisable);
				}
			}
			else if (iType == 3)
			{
				QTreeWidgetItem * pParentItem = m_pCheckItem2->parent();
				if (pParentItem)
				{
					QTreeWidgetItem * pParentParentItem = pParentItem->parent();
					if (pParentParentItem)
					{
// 						NameParentChanged(pParentItem, bIsVisable);
// 						SystemCateAndNameChangedSlot(pParentParentItem->text(0), pParentItem->text(0), strText, bIsVisable);
					}
				}
			}
		}
	}
}

void TreeStructure::paintEvent(QPaintEvent* e)
{
	if (!timerStarted)
	{
		m_timer->start();
		timerStarted = true;
	}
}
