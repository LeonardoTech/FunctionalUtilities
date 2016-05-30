#ifndef __YZELEMENT_H__
#define __YZELEMENT_H__
/*
构件基类，这里的类型是需要在软件中以OSG形式展现的数据，包括需要显示的或者需要构建节点的
*/
#include "Dragon.h"
#include <osg/Group>
#include <osg/Geode>

#define VESRION_ELEMENT 1

namespace YZ
{
	class IParameterList;

	class MODEL_API Element : public osg::Group
	{
	public:
		//根据类型获取内容
		virtual std::string getStrValue(std::string strKey);

		//获取对应类型的字符串值
		virtual std::string getStringValue(ModelDataType key);

		//预处理数据时，几何数据的同步
		virtual void presync(void){}

		//加载数据时 从ID到指针同步
		virtual void sync(void);

		//卸载数据时 指针数据取消关联
		virtual void unsync(void){}

		//同步标识，避免多次同步
		bool needSync(void){ return m_needSync; }

		//
		const osg::BoundingBox& getBoundingBox();

		//ID，唯一标识符
		void setUniqueID(const std::string& id);
		const std::string& getUniqueID(void) const;

		//ID，整数ID，工程唯一
		void setID(int id);
		int getID(void) const;

		//名称
		void setYZName(const std::string& name);
		std::string getYZName(void) const;

		//属性
		IParameterList* getParameterList(void);

		Element(void);//默认构造函数在读取数据库时使用，其填充数据不需要逻辑
		Element(const std::string& uniqueID);//管理类使用的构造函数
		virtual ~Element(void);

	protected:
		//
		virtual void computeBoundindBox(void){}

	protected:
		//static
		std::string m_UniqueID;//构件字符串ID
		int m_ID;//构件数字ID
		std::string m_name;//构件名称

		//dynamic
		IParameterList* m_parameterList;//当前构件的属性列表

		//构件是否需要同步数据
		//多次的加载卸载楼层，内存中会有多余的数据并不需要同步
		bool m_needSync;

		//OSG
		bool m_boundingBoxComputed;//
		osg::BoundingBox m_boundingBox;//外包盒子
	};
}
#endif