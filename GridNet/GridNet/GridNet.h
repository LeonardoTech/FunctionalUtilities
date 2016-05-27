
#ifndef  __GRIDNET_H__
#define  __GRIDNET_H__
#include <osg/Geometry>
#pragma comment(lib,"opengl32.lib") 
#pragma comment(lib,"glu32.lib") 

//====================================GridNet===================================
/// @brief <对该类进行简单描述>
///
/// <对该类进行详细描述>
//================================================================================
class GridNet
{
public:
	GridNet();
	//==================================createLine()==================================
	/// @brief <对函数进行概括说明>
	///
	/// <对函数进行详细说明>
	///
	///
	/// @return <返回值说明，可以配合使用DocGenList或DocGenTable>
	///
	/// @remark <函数特别说明>
	///
	/// @code
	///      <在此添加示例代码>
	/// @endcode
	///
	/// @sa <可以参考的类或函数，用空格分隔，函数名称后必须加()>
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
