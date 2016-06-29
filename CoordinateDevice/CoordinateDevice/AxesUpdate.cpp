#include "AxesUpdate.h"

// brief	 <����˽�г�Ա���г�ʼ�������ô�������manip����ʾ��ǰ�Ļ���>
// param [in]	manip	If non-null, the manip.
AxesUpdate::AxesUpdate(osgGA::MultiTouchTrackballManipulator* manip)
{
	m_manip = manip;
}

// 	<�Դ�������manip���в���.�ô���HUD���������ϵ�ܹ����в���>
void AxesUpdate::operator()(osg::Node* node, osg::NodeVisitor* nv)
{
	auto trans = dynamic_cast<osg::MatrixTransform*>(node);
	rot = m_manip->getRotation();
	trans->setMatrix(osg::Matrix::rotate(rot));
	traverse(node, nv);
}

//  <���ݴ�����Axis��ö��ֵ����ȷ����ȡ�ĸ���Ľ��.>
osg::Vec3 AxesUpdate::getResult(Coordinate ax)
{

	if (ax == X_Coordinate)
	{
		osg::Vec3 xAxis(1, 0, 0);// <xAxis(1,0,0)������X��>
		result = rot *xAxis;
	}
	else if (ax == Y_Coordinate)
	{
		osg::Vec3 yAxis(0, 1, 0);// <yAxis(0,1,0)������Y��>
		result = rot*yAxis;
	}
	else if (ax == Z_Coordinate)
	{
		osg::Vec3 zAxis(0, 0, 1);// <zAxis(0,0,1)������Z��>
		result = rot*zAxis;
	}
	else
	{
		cout << "print false" << endl;
	}
	return result;
}

