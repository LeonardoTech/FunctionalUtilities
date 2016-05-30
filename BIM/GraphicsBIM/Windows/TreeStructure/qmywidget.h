#ifndef QMYWIDGET_H
#define QMYWIDGET_H


#include <osgQt/GraphicsWindowQt>
#include <QMouseEvent>
#include "ModelViewer.h"

class QMyWidget : public osgQt::GLWidget
{
	Q_OBJECT

public:
	QMyWidget(QWidget *parent=NULL);
	~QMyWidget();

	void setOsgView(bimWorld::ModelViewer* osgViewer);
	void PanModel(QMouseEvent* event);// <ƽ��ģ��>
	void RotateModel(QMouseEvent* event);// <��תģ��>
	void GetXYValue(QMouseEvent* event, double& dX, double& dY);

protected:
	virtual void mouseMoveEvent(QMouseEvent* event);
	virtual void wheelEvent(QWheelEvent* event);
	void mousePressEvent(QMouseEvent * event);
private:
	bimWorld::ModelViewer* ��_osgViewer;
	double m_dCurrentX;
	double m_dCurrentY;
	std::string  m_id;
	std::string  m_oldId;
};

#endif // QMYWIDGET_H
