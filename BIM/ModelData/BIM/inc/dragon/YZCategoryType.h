#ifndef __YZCATEGORYTYPE_H__
#define __YZCATEGORYTYPE_H__
namespace YZ
{
	//构件类型
	enum CategoryType
	{
		Category_Unknown = 0,
		//其他
		Category_ModelGroup,

		//建筑
		Category_Wall = 100,//墙
		Category_Column,//柱
		Category_Beam,//梁
		Category_Door,//门
		Category_Window,//窗

		Category_Roof,//屋顶
		Category_Cutter,//檐沟
		Category_Fascia,//封檐带
		Category_EdgeSlab,//楼板边缘
		Category_RoofSoffit,//屋檐底板

		Category_StairsRailing,//栏杆扶手
		Category_Floor,//楼板
		Category_Stair,//楼梯
		Category_SpecialityEquipment,//专用设备
		Category_Mass,//体量
		Category_Parking,//停车场
		Category_Topography,//地形
		Category_Site,//场地
		Category_Ramp,//坡道
		Category_Ceiling,//天花板
		Category_Furniture,//家具
		Category_FurnitureSystem,//家具系统
		Category_GenericModel,//常规模型
		Category_Casework,//橱柜
		Category_CurtainWallMullion,//幕墙竖梃
		Category_CurtainWallPanel,//幕墙嵌板
		Category_CurtaSystem,//幕墙系统
		Category_Planting,//植物
		Category_Entourage,//环境
		Category_ShaftOpening,//竖井洞口
		Category_Roads,//道路
		//Category_Areas,//面积
		Category_Chimney,//烟囱

		//结构
		Category_StructuralFoundation = 200,//结构基础
		Category_StructuralColumn,//结构柱
		Category_StructuralTrus,//结构桁架
		Category_StructuralFraming,//结构框架
		Category_StructuralFramingSystem,//结构梁系统
		Category_StructConnection,//结构连接
		Category_Rebar,//结构钢筋
		//构件加强板
		//结构区域钢筋
		//结构路径钢筋
		//结构钢筋网
		//结构钢筋网区域
		Category_Plate,//钢板
		Category_Fastener,//螺栓
		Category_StructuralWall, //结构墙

		//安装
		Category_Pipe = 300,//管道
		Category_FlexPipeCurve,//软管
		Category_PipeFitting,//管件
		Category_PipeAccessory,//管路附件
		Category_Duct,//风管
		Category_FlexDuctCurve,//软风管
		Category_DuctFitting,//风管管件
		Category_DuctAccessory,//风管附件
		Category_DuctTerminal,//风道末端
		Category_CableTray,//电缆桥架
		Category_CableTrayFitting,//电缆桥架配件
		Category_Conduit,//线管
		Category_ConduitFitting,//线管配件
		Category_Wire,//导线

		Category_PlumbingFixture,//卫浴装置
		Category_Sprinkler,//喷头
		Category_SecurityDevice,//安全设备
		Category_NurseCallDevice,//护理呼叫设备
		Category_DataDevice,//数据设备
		Category_MechanicalEquipment,//机械设备
		Category_FireAlarmDevice,//火警设备
		Category_LightingDevice,//灯具
		Category_LightingFixture,//照明设备
		Category_ElectricalEquipment,//电气设备
		Category_ElectricalFixture,//电气装置
		Category_TelephoneDevice,//电话设备
		Category_CommunicationDevice,//通讯设备

		//
		Category_HVACDevice,//暖通设备
		Category_WSDDevice,//给排水设备
		Category_FireProtectionDevice,//消防设备
		Category_AirCondition,//空调机组
		Category_AirTerminalBox,//空气盒
		Category_Boiler,//锅炉
		Category_Burner,//燃烧器
		Category_Chiller,//冷水机组
		Category_Coil,//盘管
		Category_Compressor,//压缩机
		Category_Condenser,//冷凝器
		Category_CooledBeam,//冷梁
		Category_CoolingTower,//冷却塔
		Category_Damper,//风阀
		Category_DuctSilencer,//消声器
		Category_Engine,//发动机
		Category_Evaporator,//蒸发器
		Category_EvaporativeCooler,//蒸发式冷凝器
		Category_Fan,//通风机
		Category_Filter,//过滤器
		Category_Flowmeter,//流量计
		Category_HeatExchanger,//换热器
		Category_Humidifier,//加湿器
		Category_Pump,//水泵
		Category_SpaceHeater,//散热器（MagiCAD这么定义，可能不太对）
		Category_Tank,//水箱
		Category_TubeBundle,//管束
		Category_UnitaryEquipment,//单元设备
		Category_Valve,//水阀
		Category_VibrationIsolator,//隔振器
		Category_ElectricGenerator,//发电机
		Category_ElectricMotor,//电动机
		Cateogry_JunctionBox,//接线盒
		Category_Outlet,//插座
		Category_SwitchingDevice,//开关
		Category_ProtectiveDevice,//防护设备
		Category_Transformer,//变压器

		Category_PipeInsulation,//管道隔热层
		Category_DuctInsulation//风管隔热层
	};
}

#endif