#ifndef _hosttype_H
#define _hosttype_H
/**
	NI CONFIDENTIAL
	© Copyright 1990-2001 by National Instruments Corp.
	All rights reserved.

	@author	brian.powell, greg.richardson
	@file	hosttype.h
	@brief	Host specific definitions, etc.
*/

#define rcsid_hosttype "$Id: //labview/branches/Jupiter/dev/source/mgcore/hosttype.h#1 $"

#if Mac // use forward includes to define types needed for managerp.h
struct EventRecord;
struct RGBColor;
typedef struct Palette *PalettePtr, **PaletteHandle;
typedef struct Cursor *CursPtr, **CursHandle;
typedef struct Picture  *PicPtr, **PicHandle;
typedef struct GDevice *GDPtr, **GDHandle;
typedef struct OpaqueWindowPtr *WindowPtr;
typedef struct OpaqueMenuRef *MenuRef,  *MenuHandle;
typedef struct OpaqueGrafPtr *GrafPtr, *CGrafPtr, *GWorldPtr;
struct BitMap;
struct Pattern;
#include <stdio.h>

#endif	/* Mac */

#if Unix
#include <stdio.h>
#include <string.h>
#if XWindows
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#endif /* XWindows */
#endif /* Unix */

#if MSWin
#ifdef TRUE
#undef TRUE
#endif
#ifdef FALSE
#undef FALSE
#endif

#define _WIN32_WINNT 0x0400
#ifndef NOMINMAX
#define NOMINMAX 1	//ensures that macros defined in windef.h for max & min don't affect usage of std::max & std::min
#endif // ndef NOMINMAX
#pragma warning (push)
#pragma warning (disable : 4701) /* local variable 'XXX' may be used without having been initialized */
#include <windows.h>
#include <ole2.h>
#pragma warning (pop)
#pragma warning (disable : 4001) /* nonstandard extension 'single line comment' was used */

#ifdef TRUE
#undef TRUE
#endif
#define TRUE 1L
#ifdef FALSE
#undef FALSE
#endif
#define FALSE 0L
#if VCI_RTX
	#include <io.h>
	#include "manager/rtxsyscall.h"
	#include <rtapi.h>
#endif
#endif /* MSWin */

#endif /* _hosttype_H */
