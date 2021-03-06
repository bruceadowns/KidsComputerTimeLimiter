#if !defined(AFX_CDIALOGPASSWORD_H__581EB5BD_EE47_4913_A1B9_9EE8BFF47CD2__INCLUDED_)
#define AFX_CDIALOGPASSWORD_H__581EB5BD_EE47_4913_A1B9_9EE8BFF47CD2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CDialogPassword.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDialogPassword dialog

class CDialogPassword : public CDialog
{
// Construction
public:
	CDialogPassword(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDialogPassword)
	enum { IDD = IDD_DIALOG_PASSWORD };
	CString	m_strPassword1;
	CString	m_strPassword2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialogPassword)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDialogPassword)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	inline CString CDialogPassword::GetPassword() const
	{ return m_strPassword1; }

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CDIALOGPASSWORD_H__581EB5BD_EE47_4913_A1B9_9EE8BFF47CD2__INCLUDED_)
