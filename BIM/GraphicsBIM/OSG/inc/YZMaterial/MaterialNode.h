////////////
//    created by 孙庆号
////////////

#pragma once
#include "osg/Node"
#include "osg/Drawable"

struct MatNode
{
	osg::Node* node = 0;
	osg::Drawable* drawble = 0;
};

class MaterialNode
{
public:
	MaterialNode(void* node);

	~MaterialNode();

	void setStateSet(osg::StateSet* stateSet);

	void setUserData(osg::Referenced* obj);

	void setUserValue(const std::string& key, const std::string& value);

protected:

private:
	MatNode			m_Node;

};


