////////////
//    created by 孙庆号
////////////

#ifndef __BILLBOARD_H__
#define __BILLBOARD_H__

#include "IBillboard.h"
#include "DataModel.h"
//#include <DataModel.h>
#include <osg/Node>
#include "YZModelCoreModule.h"

namespace bimWorld
{
	class YIZHU_EXPORT Billboard : public YZModelCoreModule, public IBillboard
	{
	public:
		Billboard(YZModelCoreInternal* host);

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

		virtual int addBillboard(void* selectedConstruct[], const void(*callback)(BillboardData*, const void*), const char* img_path_name = NULL, const void* externalData = NULL) override;
		
		virtual int addBillboard(const std::vector<void*>& selectedConstruct, void(*callback)(), const char* img_path_name = NULL) override;
		
		virtual int addBillboard(float centerX, float centerY, float centerZ, void(*clicked)(), const char* img_path_name = NULL, float pointSize = 60.0f) override;

		virtual bool removeBillboard(int id) override;

	//internal:
		/**********************************************************************************************//**
		* @fn	void triggerBillboardCallback(osg::Node* node);
		*
		* @brief	Callback, called when the trigger billboard.
		*
		* @author	Sqh
		* @date	2015/5/13
		*
		* @param [in,out]	node	If non-null, the node.
		*
		* ### remarks	Sqh, 2015/5/6.
		**************************************************************************************************/
		void triggerBillboardCallback(osg::Node* node);

	protected:
		osg::Node* createBillboard(osg::Vec3 position, osg::Geometry * geometry, osg::Image * image);

		// <广告牌的数据集合>
		std::map<osg::ref_ptr<osg::Node>, BillboardData*> m_billboardDataSet;
		// <广告牌的额外数据集合>
		std::map<osg::ref_ptr<osg::Node>, const void*> m_billboardExternalDataSet;
		
		int m_newId;
	};
}
#endif // __BILLBOARD_H__