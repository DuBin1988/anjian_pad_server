#if !defined(AFX_HJIC_H__0A78B1B2_3733_49FE_939E_52E781DFDA23__INCLUDED_)
#define AFX_HJIC_H__0A78B1B2_3733_49FE_939E_52E781DFDA23__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// HJIC.h : main header file for HJIC.DLL

#if !defined( __AFXCTL_H__ )
	#error include 'afxctl.h' before including this file
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CHJICApp : See HJIC.cpp for implementation.

class CHJICApp : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HJIC_H__0A78B1B2_3733_49FE_939E_52E781DFDA23__INCLUDED)
