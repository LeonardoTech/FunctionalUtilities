////////////
//    created by 孙庆号
////////////

#ifndef __IBILLBOARD_H__
#define __IBILLBOARD_H__

#include "config.h"
#include "DataModel.h"
namespace bimWorld
{
	class YIZHU_EXPORT IBillboard
	{
	public:
		///-------------------------------------------------------------------------------------------------
		/// <summary>	添加广告牌. </summary>
		///
		/// <remarks>	Sqh, 2015/5/6. </remarks>
		///
		/// <param name="selectedConstruct">	The selected construct. </param>
		/// <param name="callback">				[in,out] If non-null, the callback. </param>
		/// <param name="img_path_name">		Full pathname of the image file. </param>
		/// <param name="externalData">			Information describing the external. </param>
		///-------------------------------------------------------------------------------------------------
		virtual int addBillboard(void* selectedConstruct[], const void(*callback)(BillboardData*, const void*), const char* img_path_name = NULL, const void* externalData = NULL) = 0;
		
		virtual int addBillboard(const std::vector<void*>& selectedConstruct, void(*callback)(), const char* img_path_name = NULL) = 0;
		
		virtual int addBillboard(float centerX, float centerY, float centerZ, void(*clicked)(), const char* img_path_name = NULL, float pointSize = 60.0f) = 0;

		virtual bool removeBillboard(int id) = 0;
	};

}
#endif // __IBILLBOARD_H__