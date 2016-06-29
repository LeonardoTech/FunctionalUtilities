////////////
//    created by 孙庆号
////////////

#ifndef __IPROGRESS_INFO_H__
#define __IPROGRESS_INFO_H__

namespace bimWorld
{
	class YIZHU_EXPORT IProgressInfo
	{
	public:
		virtual long long getCurrentProgressInfo() = 0;

		virtual void resetProgress() = 0;
	};
}

#endif // __IPROGRESS_INFO_H__