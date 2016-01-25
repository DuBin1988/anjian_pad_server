// JYZW.h : main header file for the JYZW DLL
//

#if !defined(AFX_JYZW_H__CA47251C_16E9_4454_AAB4_41A1E7C6A1E9__INCLUDED_)
#define AFX_JYZW_H__CA47251C_16E9_4454_AAB4_41A1E7C6A1E9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CJYZWApp
// See JYZW.cpp for the implementation of this class
//

class CJYZWApp : public CWinApp
{
public:
	CJYZWApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CJYZWApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CJYZWApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JYZW_H__CA47251C_16E9_4454_AAB4_41A1E7C6A1E9__INCLUDED_)
