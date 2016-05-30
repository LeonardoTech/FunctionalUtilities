#ifndef __YZStringUtil_H__
#define __YZStringUtil_H__
/*
	字符串工具
*/
#include "YZPrerequire.h"
#include <stdarg.h>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

namespace YZ
{
	class StringUtil
	{
	public:
		//
		static std::vector<std::string> split(const std::string& value, const std::string& delims = "\t\n")
		{
			std::vector<std::string> result;
			size_t start, pos;
			start = 0;
			do
			{
				pos = value.find_first_of(delims, start);
				if (pos == start)
				{
					start = pos + 1;
				}
				else if (pos == std::string::npos)
				{
					result.push_back(value.substr(start));
					break;
				}
				else
				{
					result.push_back(value.substr(start, pos - start));
					start = pos + 1;
				}
				start = value.find_first_not_of(delims, start);
			} while (pos != std::string::npos);
			return result;
		}

		//释放数据
		static void release(const std::vector<std::vector<char*> >& vectorData)
		{
			std::vector<std::vector<char*> >::size_type i = 0;
			for (; i < vectorData.size(); i++)
			{
				for (std::vector<char*>::size_type j = 0; j < vectorData[i].size(); j++)
				{
					delete[] vectorData[i][j];
				}
			}
		}

		//释放数据
		static void release(const std::list<std::vector<char*> >& listData)
		{
			std::list<std::vector<char*> >::const_iterator it = listData.begin();
			for (; it != listData.end(); it++)
			{
				std::vector<char*> vctChar = *it;
				for (std::vector<char*>::size_type j = 0; j < vctChar.size(); j++)
				{
					delete[] vctChar[j];
				}
			}
		}
	};

    //浮点数转字符串，delEndZero确定是否去除末尾无效0
//    static std::string toStdUTF8String(float d, bool delEndZero)
//    {
//		std::string strValue = "";
//#ifdef _WIN32
//		char buf[256] = { '\0' };
//		sprintf_s(buf, "%f", d);
//		strValue = buf;
//#else
//		strValue = std::to_string(d);
//#endif
//        if (delEndZero && strValue.find('.') != -1)
//        {
//            int nCount = (int)strValue.length();
//            while (nCount--)
//            {
//                char c = strValue[nCount];
//				if (c == '0' || c == '.')
//                {
//                    strValue.erase(nCount);
//                    if (c == '.')
//                        break;
//                }
//                else
//                    break;
//            }
//        }
//		return _u8(strValue.c_str());
//    }
    
    //整型转字符串
//	static std::string toStdUTF8String(int i)
//    {
//		std::string strValue = "";
//#ifdef _WIN32
//		char buf[256] = { '\0' };
//		sprintf_s(buf, "%d", i);
//		strValue = buf;
//#else
//		strValue = std::to_string(i);
//#endif
//		return _u8(strValue.c_str());
//    }

// 	static std::string toStdString(float d, bool delEndZero)
// 	{
// #ifdef UNICODE
// 		return UnicodeToAnsi(toStdUTF8String(d, delEndZero));
// #else
// 		return toStdUTF8String(d, delEndZero);
// #endif
// 	}

// 	static std::string toStdString(int i)
// 	{
// #ifdef UNICODE
// 		return UnicodeToAnsi(toStdUTF8String(i));
// #else
// 		return toStdUTF8String(i);
// #endif
// 	}
}

#endif //__YZStringUtil_H__