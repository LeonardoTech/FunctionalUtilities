#ifndef __YZCommon_H__
#define __YZCommon_H__
/*
	一些公共函数
*/
#include "YZPrerequire.h"
#include <objbase.h>
#include <sstream>

namespace YZ
{
	//自动创建GUID
	YZString CreateGUID(void)
	{
		YZString strTestGUID(_T(""));
#ifdef _UNICODE
		static wchar_t buf[64] = {0};
		GUID guid;
		CoInitialize(NULL);				
		if( S_OK == ::CoCreateGuid(&guid) )
		{
			_snwprintf_s(buf, sizeof(buf),
				_T("%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X"),
				guid.Data1,
				guid.Data2,
				guid.Data3,
				guid.Data4[0], guid.Data4[1],
				guid.Data4[2], guid.Data4[3],
				guid.Data4[4], guid.Data4[5],
				guid.Data4[6], guid.Data4[7]);
		}
		CoUninitialize();
		strTestGUID = buf;
#else
		static char buf[64] = {0};
		GUID guid;
		CoInitialize(NULL);
		if (S_OK == ::CoCreateGuid(&guid))
		{
			_snprintf_s(buf, sizeof(buf),
				"%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X",
				guid.Data1,
				guid.Data2,
				guid.Data3,
				guid.Data4[0], guid.Data4[1],
				guid.Data4[2], guid.Data4[3],
				guid.Data4[4], guid.Data4[5],
				guid.Data4[6], guid.Data4[7]);
		}
		CoUninitialize();
		strTestGUID = buf;
#endif
		return strTestGUID;
	}

/*	//自动创建名称
	class BIMWORLD_API NameGenerator
	{
	public:
		NameGenerator(const NameGenerator& generator)
			: m_prefix(generator.m_prefix), m_counter(generator.m_counter)
		{}

		NameGenerator(const YZString& prefix)
			: m_prefix(prefix), m_counter(1)
		{}

		/// Generate a new name
		YZString generate()
		{
			//OGRE_LOCK_AUTO_MUTEX
			std::ostringstream s;
			s << m_prefix << m_counter++;
			return s.str();
		}

		/// Reset the internal counter
		void reset()
		{
			//OGRE_LOCK_AUTO_MUTEX
			m_prefix = _T("");
			m_counter = 1;
		}

		//Manually set the internal counter (use caution)
		void setCounter(uLong counter)
		{
			//OGRE_LOCK_AUTO_MUTEX
			m_counter = counter;
		}

		//Get the internal counter
		uLong getCounter() const
		{
			// lock even on get because 64-bit may not be atomic read
			//OGRE_LOCK_AUTO_MUTEX
			return m_counter;
		}

	protected:
		YZString m_prefix;//前缀名称
		uLong m_counter;//计数器
		//OGRE_AUTO_MUTEX
	};*/
}

#endif // __YZCommon_H__