////////////
//    created by 孙庆号
////////////

#ifndef __POINTER_ACCESS_H__
#define __POINTER_ACCESS_H__

#ifdef _WIN32 
#pragma warning(disable: 4100 4115 4201 4214 4514) 
#include <windows.h> 
#pragma warning(default: 4100 4115 4201 4214) 
#else 
#include <setjmp.h> 
#include <signal.h> 
#ifndef	__MSC_VER__
typedef	int	BOOL;
typedef	unsigned int	UINT;
typedef	unsigned char	BYTE;
#define	TRUE	1
#define	FALSE	0
#define  NULL 0
#endif	//	__MSC_VER__
static BOOL g_bPtrTestInstalled;
static jmp_buf g_PtrTestJmpBuf;
BOOL IsBadWritePtr(const void *lp, size_t ucb);

void /*__cdecl*/ PtrTestHandler(int nSig);

BOOL IsBadReadPtr(void* lp, size_t cb);

#endif 

#endif // !__POINTER_ACCESS_H__

