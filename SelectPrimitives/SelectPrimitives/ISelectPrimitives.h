#ifndef __ISELECT_PRIMITIVES_H__
#define __ISELECT_PRIMITIVES_H__
#include "IDrawElement.h"

/// @class	ISelectPrimitives
///
/// @brief	 <ѡ��㡢�ߡ���Ľӿ���>.
///
/// @author	Admin
/// @date	2016/3/23
class ISelectPrimitives
{
public:

	/// @fn	virtual IDrawElement* ISelectPrimitives::select(float x, float y) = 0;
	///
	/// @brief	 <������Ļ�ϵ�λ����ȷ��ѡ�����Ʒ>.
	///
	/// @author	Admin
	/// @date	2016/3/23
	///
	/// @param	x	<ѡ��λ�õ�X������>.
	/// @param	y	<ѡ��λ�õ�Y������>.
	///
	/// @return	null if it fails, else a pointer to an IDrawElement.
	virtual IDrawElement* select(float x, float y) = 0;

	/// @fn	virtual IDrawElement* ISelectPrimitives::getSelection() const = 0;
	///
	/// @brief <����ѡ���λ�ã���������Ӧ�����꣬>.
	///  <ѡ��㷵�ص����ά����>
	///  <ѡ���߷����ߵ������˵����ά����>
	///  <ѡ���淵����������˵����ά����>
	/// 
	/// @author	Admin
	/// @date	2016/3/23
	///
	/// @return	<����IDrawElement���͵Ķ˵�ļ���>
	virtual IDrawElement* getSelection() const = 0;
};

#endif // __ISELECT_PRIMITIVES_H__
