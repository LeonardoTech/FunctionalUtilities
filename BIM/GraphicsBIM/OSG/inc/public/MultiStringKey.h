////////////
//    created by 孙庆号
////////////

#ifndef __CATEGORY_TYPE_KEY_H__
#define __CATEGORY_TYPE_KEY_H__
#include <vector>
#include <string>
#include <cstdarg>
#include "config.h"

namespace bimWorld
{
	class YIZHU_EXPORT MultiStringKey : public std::vector < std::string >
	{
		typedef std::vector<std::string> base;
	public:
		// usage: CategoryTypeKey({"floor", "systemType", "category"})
		MultiStringKey();

		MultiStringKey(size_t size);

		MultiStringKey(std::initializer_list<std::string> keys);

		MultiStringKey(const std::vector<std::string>& copy);


		bool operator==(const MultiStringKey& other);

		inline MultiStringKey operator()(std::initializer_list<std::string> keys);

		std::string toString();

#pragma region override

		void push_back(const std::string& str);

#if __cplusplus > 201103L || (defined(_MSC_VER) && (_MSC_VER >= 1800))
		iterator insert(const_iterator _Where, const std::string& _Val);

		void insert(const_iterator begin, const_iterator end);
#else
		iterator insert(iterator _Where, const std::string& _Val);

		void insert(iterator begin, iterator end);
#endif

#pragma endregion

	};
}

#endif // __CATEGORY_TYPE_KEY_H__