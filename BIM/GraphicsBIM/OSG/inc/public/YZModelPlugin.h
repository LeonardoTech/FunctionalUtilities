////////////
//    created by 孙庆号
////////////

#ifndef __YZ_MODEL_PLUGIN_H__
#define __YZ_MODEL_PLUGIN_H__

#include <iostream>
#include <atomic>

namespace bimWorld
{
	template <class T>
	class YZModelPlugin
	{
	public:
		YZModelPlugin(T* host)
		{
			m_initialized = false;
			if (!host)
			{
#if _DEBUG
				std::cout << "No host in YZModelPlugin. Could cause error." << std::endl;
#endif
				return;
			}
			m_host = host;
		}
	protected:
		T* m_host;

		// is initialize finished
		std::atomic_bool m_initialized;
	};
}

#endif // __YZ_MODEL_PLUGIN_H__