////////////
//    created by 孙庆号
////////////

#ifndef __INTERACTION_DEFINE_H__
#define __INTERACTION_DEFINE_H__
#include <memory>

#define SHARED_PROPERTY(class_name, property_name, field_name, construct_param) \
	public:\
	std::shared_ptr<class_name> property_name()\
{\
		if (!field_name)\
																				{\
			field_name = std::make_shared<class_name>(construct_param);\
																				}\
		return field_name;\
}\
	protected:\
		std::shared_ptr<class_name> field_name;

#define IMPLEMENT_INTERFACE(interface_name, property_name, func_name) \
	public:\
	virtual std::shared_ptr<interface_name> func_name() override\
{\
	return property_name();\
}

#define SHARED_MODULE(class_name, property_name, field_name) \
	public:\
	std::shared_ptr<class_name> property_name()\
{\
		if (!field_name)\
																								{\
			field_name = std::make_shared<class_name>();\
																								}\
		return field_name;\
}\
	protected:\
		std::shared_ptr<class_name> field_name;

#endif // !__INTERACTION_DEFINE_H__
