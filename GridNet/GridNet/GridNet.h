
#ifndef  __GRIDNET_H__
#define  __GRIDNET_H__
#include <osg/Geometry>
#pragma comment(lib,"opengl32.lib") 
#pragma comment(lib,"glu32.lib") 

//====================================GridNet===================================
/// @brief <�Ը�����м�����>
///
/// <�Ը��������ϸ����>
//================================================================================
class GridNet
{
public:
	GridNet();
	//==================================createLine()==================================
	/// @brief <�Ժ������и���˵��>
	///
	/// <�Ժ���������ϸ˵��>
	///
	///
	/// @return <����ֵ˵�����������ʹ��DocGenList��DocGenTable>
	///
	/// @remark <�����ر�˵��>
	///
	/// @code
	///      <�ڴ����ʾ������>
	/// @endcode
	///
	/// @sa <���Բο�����������ÿո�ָ����������ƺ�����()>
	//================================================================================
	osg::Geometry* createLine();
	
	osg::Geode* createCircle(float radius);
	
	void setCircleRadius(float num);
	
	osg::Geode* createText();
	
	osg::Group* createTemplate();

	osg::Group* createNode();
private:
	float _circleRadius;

};




#endif // ! __GRIDNET_H__
