// KidsComputerTimeLimiter.h : main header file for the KIDSCOMPUTERTIMELIMITER application
//

#if !defined(AFX_KIDSCOMPUTERTIMELIMITER_H__16E40C9E_136F_49FD_ACF6_24256D1922BD__INCLUDED_)
#define AFX_KIDSCOMPUTERTIMELIMITER_H__16E40C9E_136F_49FD_ACF6_24256D1922BD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CKidsComputerTimeLimiterApp:
// See KidsComputerTimeLimiter.cpp for the implementation of this class
//

class CKidsComputerTimeLimiterApp : public CWinApp
{
public:
	CKidsComputerTimeLimiterApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKidsComputerTimeLimiterApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CKidsComputerTimeLimiterApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KIDSCOMPUTERTIMELIMITER_H__16E40C9E_136F_49FD_ACF6_24256D1922BD__INCLUDED_)
