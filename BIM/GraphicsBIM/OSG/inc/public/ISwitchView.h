﻿////////////
//    created by 孙庆号
////////////

#ifndef __ISWITCH_VIEW_H__
#define __ISWITCH_VIEW_H__

namespace bimWorld
{
	class YIZHU_EXPORT ISwitchView
	{
	public:
		///-------------------------------------------------------------------------------------------------
		/// <summary>	切换到正视图. </summary>
		///
		/// <remarks>	Sqh, 2015/5/6. </remarks>
		///-------------------------------------------------------------------------------------------------

		virtual void switchToFrontView() = 0;


		///-------------------------------------------------------------------------------------------------
		/// <summary>	切换到后视图. </summary>
		///
		/// <remarks>	Sqh, 2015/5/6. </remarks>
		///-------------------------------------------------------------------------------------------------

		virtual void switchToBackView() = 0;


		///-------------------------------------------------------------------------------------------------
		/// <summary>	切换到左视图. </summary>
		///
		/// <remarks>	Sqh, 2015/5/6. </remarks>
		///-------------------------------------------------------------------------------------------------

		virtual void switchToLeftView() = 0;


		///-------------------------------------------------------------------------------------------------
		/// <summary>	切换到右视图. </summary>
		///
		/// <remarks>	Sqh, 2015/5/6. </remarks>
		///-------------------------------------------------------------------------------------------------

		virtual void switchToRightView() = 0;


		///-------------------------------------------------------------------------------------------------
		/// <summary>	切换到俯视图. </summary>
		///
		/// <remarks>	Sqh, 2015/5/6. </remarks>
		///-------------------------------------------------------------------------------------------------

		virtual void switchToTopView() = 0;


		///-------------------------------------------------------------------------------------------------
		/// <summary>	切换到仰视图. </summary>
		///
		/// <remarks>	Sqh, 2015/5/6. </remarks>
		///-------------------------------------------------------------------------------------------------

		virtual void switchToBottomView() = 0;
	protected:
	};
}
#endif // __ISWITCH_VIEW_H__