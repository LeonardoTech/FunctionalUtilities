#ifndef __YZDOMAINTYPE_H__
#define __YZDOMAINTYPE_H__

namespace YZ
{
	//专业
	enum DomainType
	{
		Domain_Unknown = 0,//未知
		Domain_Architecture,//建筑
		Domain_Structure,//结构
		Domain_WSD,//给排水
		Domain_HVAC,//暖通
		Domain_Electricity,//电气
		Domain_FireProtection,//消防
		//Domain_Decorate//装饰
	};

	//系统
	// 	enum SystemType
	// 	{
	// 		System_Unknown = 0,
	// 		System_Architecture,	//建筑
	// 		System_Structure,		//结构
	// 		System_MEP				//安装
	// 	};
}

#endif