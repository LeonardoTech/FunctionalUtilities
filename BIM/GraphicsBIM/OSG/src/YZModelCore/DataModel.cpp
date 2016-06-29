////////////
//    created by 孙庆号
////////////

#include "DataModel.h"
#include <algorithm>
//#include <boost/locale.hpp>
#include <sstream>
#include "StringExt.h"

namespace
{
#ifdef YIZHU_BIMWORLD_USE_WCHAR
	const static bimWorld::YZString floorParamName(L"LevelName");
	const static bimWorld::YZString categoryParamName(L"Category");
	const static bimWorld::YZString systemTypeParamName(L"SystemType");
#define DEFINE_MAT_NAME(name) const YZString& MaterialName::name(){\
    const static YZString color = L#name;\
    return color;\
			  }
#else
	const static bimWorld::YZString floorParamName("LevelName");
	const static bimWorld::YZString categoryParamName("Category");
	const static bimWorld::YZString systemTypeParamName("SystemType");
#define DEFINE_MAT_NAME(name) const YZString& MaterialName::name(){\
    const static YZString color = #name;\
    return color;\
			  }
#endif
#define SET_ATTRIBUTE(element, setting, name) {\
  int count = 0;\
  const double*values = setting.get(MaterialName::name(), &count);\
  if(values != NULL){\
    std::ostringstream os;\
    for(int i = 0;i < count;++ i){\
      if(i > 0)\
        os << ' ';\
      os.precision(6);\
      os << values[i];\
			    }\
    element->SetAttribute(#name, os.str().c_str());\
        }\
			}
#define SET_MATERIAL(element, setting, name){\
  const char *valueStr = element->Attribute(#name);\
  if(valueStr != NULL && *valueStr){\
    std::istringstream valueStream(valueStr);\
    double values[4]={0, 0, 0, unit};\
    if(valueStream >> values[0]){\
      valueStream >> values[1] >> values[2];\
      if(valueStream){\
        valueStream >> values[3];\
	  	  	        }\
      for(int i = 0;i < 4;++ i)\
        values[i] /= unit;\
      setting->set(MaterialName::name(), values);\
			    }\
        }\
			}
}

