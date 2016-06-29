////////////
//    created by 孙庆号
////////////

#ifndef __CONSTRUCT_KEY_H__
#define __CONSTRUCT_KEY_H__
#include "config.h"

namespace bimWorld
{
	typedef YZString				CategoryName;	//分类名
	typedef YZString				SystemType;		//系统类型
	typedef YZString				LevelName;		//楼层名
	// <构件的键>
	struct YIZHU_EXPORT ConstructKey
	{
		//typedef _T1 first_type;    ///<  @c first_type is the first bound type
		//typedef _T2 second_type;   ///<  @c second_type is the second bound type

		// <一级分类（大类）>
		CategoryName topCategory;
		// <二级分类（小类）>
		CategoryName secondaryCategory;
		// <系统类型>
		SystemType systemType;
		// <层级名称（楼层）>
		LevelName levelName;

		// _GLIBCXX_RESOLVE_LIB_DEFECTS
		// 265.  std::ConstructKey::ConstructKey() effects overly restrictive
		/** The default constructor creates @c first and @c second using their
		*  respective default constructors.  */
		ConstructKey()
			: topCategory(), secondaryCategory(), systemType(), levelName() { }

		/** Two objects may be passed to a @c ConstructKey constructor to be copied.  */
		ConstructKey(const CategoryName& topCat, const CategoryName& secCat, const SystemType& sysTp, const LevelName& lvNm)
			: topCategory(topCat), secondaryCategory(secCat), systemType(sysTp), levelName(lvNm) { }

		ConstructKey(const CategoryName& categoryName, const SystemType& sysTp, const LevelName& lvNm);

		/** There is also a templated copy ctor for the @c ConstructKey class itself.  */
		ConstructKey(const ConstructKey& __p)
			: topCategory(__p.topCategory), secondaryCategory(__p.secondaryCategory), systemType(__p.systemType), levelName(__p.levelName) { }

		void toString(YZString& outString) const;
	};

	struct YIZHU_EXPORT ConstructMatKey :public ConstructKey
	{
		// <子材质的序号>
		int subMaterialNumber;

		ConstructMatKey()
			: ConstructKey(), subMaterialNumber(-1) { }
		/** Two objects may be passed to a @c ConstructKey constructor to be copied.  */
		ConstructMatKey(const CategoryName& topCat, const CategoryName& secCat, const SystemType& sysTp, const LevelName& lvNm, int subMatNum)
			: ConstructKey(topCat, secCat, sysTp, lvNm), subMaterialNumber(subMatNum) { }

		ConstructMatKey(const CategoryName& categoryName, const SystemType& sysTp, const LevelName& lvNm, int subMatNum)
			:ConstructKey(categoryName, sysTp, lvNm), subMaterialNumber(subMatNum) { }

		ConstructMatKey(const ConstructKey& constructKey, int subMatNum)
			:ConstructKey(constructKey), subMaterialNumber(subMatNum) { }

		/** There is also a templated copy ctor for the @c ConstructKey class itself.  */
		ConstructMatKey(const ConstructMatKey& __p)
			: ConstructKey(__p), subMaterialNumber(__p.subMaterialNumber) { }

		void toConstructKey(ConstructKey& outKey)
		{
			outKey.levelName = this->levelName;
			outKey.secondaryCategory = this->secondaryCategory;
			outKey.systemType = this->systemType;
			outKey.topCategory = this->topCategory;
		}
	};

#pragma region ConstructKey
	/// Two pairs of the same type are equal if their members are equal.
	inline bool
		operator==(const ConstructKey& __x, const ConstructKey& __y)
	{
		return __x.topCategory == __y.topCategory && __x.secondaryCategory == __y.secondaryCategory && __x.systemType == __y.systemType && __x.levelName == __y.levelName;
	}

	inline bool
		operator<(const ConstructKey& __x, const ConstructKey& __y)
	{
		return (__x.levelName < __y.levelName ||
			!(__y.levelName < __x.levelName) && __x.topCategory < __y.topCategory ||
			!(__y.levelName < __x.levelName) && !(__y.topCategory < __x.topCategory) && __x.secondaryCategory < __y.secondaryCategory ||
			!(__y.levelName < __x.levelName) && !(__y.topCategory < __x.topCategory) && !(__y.secondaryCategory < __x.secondaryCategory) && __x.systemType < __y.systemType);
	}

	/// Uses @c operator== to find the result.
	inline bool
		operator!=(const ConstructKey& __x, const ConstructKey& __y)
	{
		return !(__x == __y);
	}

	/// Uses @c operator< to find the result.
	inline bool
		operator>(const ConstructKey& __x, const ConstructKey& __y)
	{
		return __y < __x;
	}

	/// Uses @c operator< to find the result.
	inline bool
		operator<=(const ConstructKey& __x, const ConstructKey& __y)
	{
		return !(__y < __x);
	}

	/// Uses @c operator< to find the result.
	inline bool
		operator>=(const ConstructKey& __x, const ConstructKey& __y)
	{
		return !(__x < __y);
	}
#pragma endregion


#pragma region ConstructMatKey

	/// Two pairs of the same type are equal if their members are equal.
	inline bool
		operator==(const ConstructMatKey& __x, const ConstructMatKey& __y)
	{
		return __x.topCategory == __y.topCategory && __x.secondaryCategory == __y.secondaryCategory && __x.systemType == __y.systemType && __x.levelName == __y.levelName && __x.subMaterialNumber == __y.subMaterialNumber;
	}

	inline bool
		operator<(const ConstructMatKey& __x, const ConstructMatKey& __y)
	{
		return (__x.levelName < __y.levelName ||
			!(__y.levelName < __x.levelName) && __x.topCategory < __y.topCategory ||
			!(__y.levelName < __x.levelName) && !(__y.topCategory < __x.topCategory) && __x.secondaryCategory < __y.secondaryCategory ||
			!(__y.levelName < __x.levelName) && !(__y.topCategory < __x.topCategory) && !(__y.secondaryCategory < __x.secondaryCategory) && __x.systemType < __y.systemType ||
			!(__y.levelName < __x.levelName) && !(__y.topCategory < __x.topCategory) && !(__y.secondaryCategory < __x.secondaryCategory) && !(__y.systemType < __x.systemType) && __x.subMaterialNumber < __y.subMaterialNumber);
	}

	/// Uses @c operator== to find the result.
	inline bool
		operator!=(const ConstructMatKey& __x, const ConstructMatKey& __y)
	{
		return !(__x == __y);
	}

	/// Uses @c operator< to find the result.
	inline bool
		operator>(const ConstructMatKey& __x, const ConstructMatKey& __y)
	{
		return __y < __x;
	}

	/// Uses @c operator< to find the result.
	inline bool
		operator<=(const ConstructMatKey& __x, const ConstructMatKey& __y)
	{
		return !(__y < __x);
	}

	/// Uses @c operator< to find the result.
	inline bool
		operator>=(const ConstructMatKey& __x, const ConstructMatKey& __y)
	{
		return !(__x < __y);
	}

#pragma endregion

}
#endif // __CONSTRUCT_KEY_H__