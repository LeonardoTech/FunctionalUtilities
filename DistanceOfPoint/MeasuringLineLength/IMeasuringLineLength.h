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
		/// @brief 	<设置线段起点>
		///
		/// @author	Admin
		/// @date	2016/3/14
		///
		/// @param	x		 	<横坐标>
		/// @param	y		 	<纵坐标>
		virtual void setStartPoint(float x, float y) = 0;

		/// @fn	virtual void setEndPoint(float x, float y) = 0;
		///
		/// @brief 	<设置线段终点>
		///
		/// @author	Admin
		/// @date	2016/3/14
		///
		/// @param	x		 	<横坐标>
		/// @param	y		 	<纵坐标>
		virtual void setEndPoint(float x, float y) = 0;

		// TODO: 以后公开出来这个接口
		//virtual void setLabelText(string name, float x, float y, float z) = 0;

		/// @fn	virtual void setLabel(std::string name, Alignments method) = 0;
		///
		/// @brief 	<设置标注>
		///
		/// @author	Admin
		/// @date	2016/3/14
		///
		/// @param	name		 	<标注名称>
		/// @param	method		<标注对齐方式：居左、居中、居右>
		virtual void setLabelText(std::string name, Alignments method) = 0;

		/// @fn	virtual float getDistance() = 0;
		///
		/// @brief 	<获取线段长度>
		///
		/// @author	Admin
		/// @date	2016/3/14
		///
		/// @return	<返回线段长度>
		virtual float getDistance() = 0;

		/// @fn	virtual void getStartPoint(float& x, float& y, float& z) = 0;
		///
		/// @brief 	<获得线段起点位置>
		///
		/// @author	Admin
		/// @date	2016/3/14
		///
		/// @param [out]	x	<点横坐标>
		/// @param [out]	y	<点纵坐标>
		/// @param [out]	z	<点高度>
		virtual void getStartPoint(float& x, float& y, float& z) = 0;

		/// @fn	virtual void getEndPoint(float& x, float& y, float& z) = 0;
		///
		/// @brief 	<获得线段终点位置>
		///
		/// @author	Admin
		/// @date	2016/3/14
		///
		/// @param [out]	x	<点横坐标>
		/// @param [out]	y	<点纵坐标>
		/// @param [out]	z	<点高度>
		virtual void getEndPoint(float& x, float& y, float& z) = 0;
	};
}


#endif