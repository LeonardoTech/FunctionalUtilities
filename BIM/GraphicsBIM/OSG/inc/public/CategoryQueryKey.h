////////////
//    created by 孙庆号
////////////

#ifndef __CATEGORY_QUERY_KEY_H__
#define __CATEGORY_QUERY_KEY_H__
#include <map>
#include <vector>
#include "MultiStringKey.h"
#include "config.h"

namespace bimWorld
{
	class YIZHU_EXPORT CategoryQueryKey
	{
	public:
		// usage: CategoryQueryKey key({ "floor", "category" }, { "2ndF", "pipeline" });
		CategoryQueryKey(const MultiStringKey& types, const MultiStringKey& keys);

		// <获取查询的类型键>
		const MultiStringKey getTypes() const;
		
		// <获取查询的键>
		const MultiStringKey getKeys() const;
	protected:
		MultiStringKey _types;
		MultiStringKey _keys;
	};
}
#endif // __CATEGORY_QUERY_KEY_H__