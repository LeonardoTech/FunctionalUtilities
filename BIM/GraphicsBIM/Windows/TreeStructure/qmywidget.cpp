#include "qmywidget.h"
#include <qdebug.h>

QMyWidget::QMyWidget(QWidget *parent)
	: GLWidget(parent)
	, m_dCurrentX(0)
	, m_dCurrentY(0)
	, m_id("")
	, m_oldId("")
{
	��_osgViewer = NULL;
}

QMyWidget::~QMyWidget()
{

}

void QMyWidget::setOsgView(bimWorld::ModelViewer* osgViewer)
{
	��_osgViewer = osgViewer;
}

void QMyWidget::mouseMoveEvent(QMouseEvent* event)
{
	if (event->buttons() & Qt::MidButton)// <����м�Ĺ���>
	{
		PanModel(event);
	}
	else if ((event->buttons() & Qt::RightButton))
	{
		RotateModel(event);
	}
	osgQt::GLWidget::mouseMoveEvent(event);
}

void QMyWidget::wheelEvent(QWheelEvent* event)
{
	double dZoom(0.1);
	if (event->delta() < 0)
	{
		dZoom = -0.1;
	}
	��_osgViewer->CameraOperation()->beginCameraOperation();
	��_osgViewer->ZoomModel()->zoom(dZoom);
	osgQt::GLWidget::wheelEvent(event);
	��_osgViewer->RenderingThread()->updateSeveralTimes();
}



void QMyWidget::PanModel(QMouseEvent* event)
{
	double dX(0.0), dY(0.0);
	GetXYValue(event, dX, dY);
	qDebug() << QString("dx=%1 dy=%2 m_dCurrentX=%3 m_dCurrentY=%4").arg(dX).arg(dY).arg(m_dCurrentX).arg(m_dCurrentY);
	��_osgViewer->CameraOperation()->beginCameraOperation();
	��_osgViewer->CameraOperation()->onPanModel(1, (dX - m_dCurrentX) * 0.5, (dY - m_dCurrentY) * 0.5);
	m_dCurrentX = dX;
	m_dCurrentY = dY;
	��_osgViewer->RenderingThread()->updateSeveralTimes();
}

void QMyWidget::RotateModel(QMouseEvent* event)
{
	double dX(0.0), dY(0.0);
	GetXYValue(event, dX, dY);

	��_osgViewer->CameraOperation()->beginCameraOperation();
	��_osgViewer->CameraOperation()->onRotateCamera(1, (dX - m_dCurrentX), (dY - m_dCurrentY));
	m_dCurrentX = dX;
	m_dCurrentY = dY;
}

void QMyWidget::GetXYValue(QMouseEvent* event, double& dX, double& dY)
{
	dX = (double(event->x()) - double(width()) / 2) / double((width()) / 2);
	dY = (double(-event->y()) + double(height()) / 2) / double((height()) / 2);
	qDebug() << "dX: " << dX << "dY: " << dY;
}



void QMyWidget::mousePressEvent(QMouseEvent * event)
{
	if ((event->buttons() & Qt::RightButton))
	{
		double dX(0.0), dY(0.0);
		GetXYValue(event, dX, dY);

		m_dCurrentX = dX;
		m_dCurrentY = dY;
	}
	else if ((event->buttons() & Qt::LeftButton))
	{
		double w = width();
		double h = height();
		double mx = event->x();
		double my = event->y();
		double rtanslateX = 0.0;
		double rtanslateY = 0.0;
		qDebug() << "width: " << w << "height: " << h;
		qDebug() << "mousex: " << mx << "mousey: " << my;
		if (mx < w / 2 && my < h / 2) //��һ����
		{
			double newx = mx / (w / 2);
			std::cout << "newx :" << newx << std::endl;
			rtanslateX = (double)(mx / (w / 2)) - (double)1.0;
			rtanslateY = 1.0 - (double)(my / (h / 2));
		}
		else if ((w / 2 < mx && mx < w) && my < h / 2)//��2����
		{
			rtanslateX = (double)((mx - (w / 2)) / (w / 2));
			rtanslateY = 1.0 - (double)(my / (h / 2));
		}
		else if (mx < w / 2 && (h / 2 < my&&my < h))//��3����
		{
			rtanslateX = (double)(mx / (w / 2)) - (double)1.0;
			rtanslateY = -(double)((my - (h / 2)) / (h / 2));
		}
		else if ((w / 2 < mx && mx < w) && (h / 2 < my&&my < h))//��4����
		{
			rtanslateX = (double)((mx - (w / 2)) / (w / 2));
			rtanslateY = -(double)((my - (h / 2)) / (h / 2));
		}

		std::cout << "rtanslateX :" << rtanslateX << endl;
		std::cout << "rtanslateY :" << rtanslateY << endl;
		//qDebug() << "rtanslateX: " << rtanslateX << "rtanslateY: " << rtanslateY;


		bool selected = ��_osgViewer->CameraOperation()->orbitPick(rtanslateX, rtanslateY);
		if (selected)
		{
			if (!m_oldId.empty())
			{
				��_osgViewer->NodeControl()->unHighlight(m_oldId);
			}
			auto set = ��_osgViewer->SelectionController()->getCurSelect();
			m_id = set[0];
			��_osgViewer->NodeControl()->highlight(m_id);
			//	modelViewer->ZoomModel()->zoomTo(m_id, false);
			m_oldId = m_id;
		}
		else// <ûѡ��ʱ��ȡ������>
		{
			if (m_id != "" && m_id == m_oldId)
				��_osgViewer->NodeControl()->unHighlight(m_oldId);
		}
	}
}
