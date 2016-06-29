﻿////////////
//    created by 孙庆号
////////////

#ifndef __SWITCH_VIEW_H__
#define __SWITCH_VIEW_H__
#include "YZModelCoreModule.h"
#include "ISwitchView.h"

namespace bimWorld
{

	class YIZHU_EXPORT SwitchView :public YZModelCoreModule, public ISwitchView
	{
	public:
		SwitchView(YZModelCoreInternal* host);

		///-------------------------------------------------------------------------------------------------
		/// <summary>	切换到正视图. </summary>
		///
		/// <remarks>	Sqh, 2015/5/6. </remarks>
		///-------------------------------------------------------------------------------------------------

		virtual void switchToFrontView() override;


		///-------------------------------------------------------------------------------------------------
		/// <summary>	切换到后视图. </summary>
		///
		/// <remarks>	Sqh, 2015/5/6. </remarks>
		///-------------------------------------------------------------------------------------------------

		virtual void switchToBackView() override;


		///-------------------------------------------------------------------------------------------------
		/// <summary>	切换到左视图. </summary>
		///
		/// <remarks>	Sqh, 2015/5/6. </remarks>
		///-------------------------------------------------------------------------------------------------

		virtual void switchToLeftView() override;


		///-------------------------------------------------------------------------------------------------
		/// <summary>	切换到右视图. </summary>
		///
		/// <remarks>	Sqh, 2015/5/6. </remarks>
		///-------------------------------------------------------------------------------------------------

		virtual void switchToRightView() override;


		///-------------------------------------------------------------------------------------------------
		/// <summary>	切换到俯视图. </summary>
		///
		/// <remarks>	Sqh, 2015/5/6. </remarks>
		///-------------------------------------------------------------------------------------------------

		virtual void switchToTopView() override;


		///-------------------------------------------------------------------------------------------------
		/// <summary>	切换到仰视图. </summary>
		///
		/// <remarks>	Sqh, 2015/5/6. </remarks>
		///-------------------------------------------------------------------------------------------------

		virtual void switchToBottomView() override;

	protected:
	private:
	};

}
#endif // __SWITCH_VIEW_H__