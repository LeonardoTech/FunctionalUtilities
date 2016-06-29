////////////
//    created by 孙庆号
////////////

#include "StringExt.h"
#include "ConstructKey.h"


bimWorld::ConstructKey::ConstructKey(const CategoryName& categoryName, const SystemType& sysTp, const LevelName& lvNm)
	: systemType(sysTp), levelName(lvNm)
{
	std::vector<YZString> outResult;
	YZString splitStr;
#ifdef YIZHU_BIMWORLD_USE_WCHAR
	splitStr = L"\\";
#else
	splitStr = "\\";
#endif
	if (util::StringExtension::split(categoryName, splitStr, outResult) && outResult.size() == 2)
	{
		topCategory = outResult[0];
		secondaryCategory = outResult[1];
	}
	else
	{
		topCategory = categoryName;
		YZString temp;
		secondaryCategory = temp;
	}
}

void bimWorld::ConstructKey::toString(YZString& outString) const
{
	outString.clear();
	//if (!levelName.empty())
	{
		outString += levelName;
#ifdef YIZHU_BIMWORLD_USE_WCHAR
		outString += L"\\";
#else
		outString += "\\";
#endif
	}

	//if (!topCategory.empty())
			{
				outString += topCategory;
#ifdef YIZHU_BIMWORLD_USE_WCHAR
				outString += L"\\";
#else
				outString += "\\";
#endif
			}

	//if (!secondaryCategory.empty())
			{
				outString += secondaryCategory;
			}
}
