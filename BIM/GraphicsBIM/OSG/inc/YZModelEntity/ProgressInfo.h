////////////
//    created by 孙庆号
////////////

#ifndef __PROGRESS_INFO_H__
#define __PROGRESS_INFO_H__
#include "YZModelEntityModule.h"
#include "IProgressInfo.h"
#include <fstream>

namespace bimWorld
{
	class YIZHU_EXPORT ProgressInfo :public IProgressInfo, public YZModelEntityModule
	{
	public:
		ProgressInfo(YZModelEntityInternal* host);

		virtual long long getCurrentProgressInfo() override;

		virtual void resetProgress() override;
	protected:
		static long long count_size;
#ifdef WIN32
	public:

		template<typename Elem, typename Tr = std::char_traits< Elem > >
		class progress_streambuf :public std::basic_filebuf < Elem, Tr >
		{
		public:
			typedef std::basic_filebuf<Elem, Tr> base_type;
			explicit progress_streambuf(const std::string &filename)
				:base_type(), size_(0)
			{
				if (open(filename.c_str(), std::ios_base::in | std::ios_base::binary))
				{
					size_ += static_cast<long long>(pubseekoff(0, std::ios_base::end, std::ios_base::in));
					pubseekoff(0, std::ios_base::beg, std::ios_base::in);
				}

			}
		protected:
			virtual int_type uflow()
			{
				int_type v = base_type::uflow();
				ProgressInfo::count_size += (long long)(egptr() - gptr());
				return v;
			}
		private:
			long long size_;
		};
#endif

	};
#ifdef WIN32
	typedef bimWorld::ProgressInfo::progress_streambuf<char> probuf;
#endif // WIN32


}

#endif // __PROGRESS_INFO_H__