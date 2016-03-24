#ifndef __IMEASURING_LINE_LENGTH_H__
#define __IMEASURING_LINE_LENGTH_H__
#include <string>
namespace distanceofpoint_measuringlinelength_imeasuringlinelength
{
	enum class Alignments
	{
		Left,
		Center,
		Right
	};

	class IMeasuringLineLength
	{
	public:
		/// @fn	virtual void setStartPoint(float x, float y) = 0;
		///
		/// @brief 	<�����߶����>
		///
		/// @author	Admin
		/// @date	2016/3/14
		///
		/// @param	x		 	<������>
		/// @param	y		 	<������>
		virtual void setStartPoint(float x, float y) = 0;

		/// @fn	virtual void setEndPoint(float x, float y) = 0;
		///
		/// @brief 	<�����߶��յ�>
		///
		/// @author	Admin
		/// @date	2016/3/14
		///
		/// @param	x		 	<������>
		/// @param	y		 	<������>
		virtual void setEndPoint(float x, float y) = 0;

		// TODO: �Ժ󹫿���������ӿ�
		//virtual void setLabelText(string name, float x, float y, float z) = 0;

		/// @fn	virtual void setLabel(std::string name, Alignments method) = 0;
		///
		/// @brief 	<���ñ�ע>
		///
		/// @author	Admin
		/// @date	2016/3/14
		///
		/// @param	name		 	<��ע����>
		/// @param	method		<��ע���뷽ʽ�����󡢾��С�����>
		virtual void setLabelText(std::string name, Alignments method) = 0;

		/// @fn	virtual float getDistance() = 0;
		///
		/// @brief 	<��ȡ�߶γ���>
		///
		/// @author	Admin
		/// @date	2016/3/14
		///
		/// @return	<�����߶γ���>
		virtual float getDistance() = 0;

		/// @fn	virtual void getStartPoint(float& x, float& y, float& z) = 0;
		///
		/// @brief 	<����߶����λ��>
		///
		/// @author	Admin
		/// @date	2016/3/14
		///
		/// @param [out]	x	<�������>
		/// @param [out]	y	<��������>
		/// @param [out]	z	<��߶�>
		virtual void getStartPoint(float& x, float& y, float& z) = 0;

		/// @fn	virtual void getEndPoint(float& x, float& y, float& z) = 0;
		///
		/// @brief 	<����߶��յ�λ��>
		///
		/// @author	Admin
		/// @date	2016/3/14
		///
		/// @param [out]	x	<�������>
		/// @param [out]	y	<��������>
		/// @param [out]	z	<��߶�>
		virtual void getEndPoint(float& x, float& y, float& z) = 0;
	};
}


#endif