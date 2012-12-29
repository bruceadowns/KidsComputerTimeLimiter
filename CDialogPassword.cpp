// CDialogPassword.cpp : implementation file
//

#include "stdafx.h"
#include "KidsComputerTimeLimiter.h"
#include "CDialogPassword.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDialogPassword dialog


CDialogPassword::CDialogPassword(CWnd* pParent /*=NULL*/)
	: CDialog(CDialogPassword::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDialogPassword)
	m_strPassword1 = _T("");
	m_strPassword2 = _T("");
	//}}AFX_DATA_INIT
}


void CDialogPassword::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialogPassword)
	DDX_Text(pDX, IDC_EDIT_PASSWORD_1, m_strPassword1);
	DDX_Text(pDX, IDC_EDIT_PASSWORD_2, m_strPassword2);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDialogPassword, CDialog)
	//{{AFX_MSG_MAP(CDialogPassword)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialogPassword message handlers

void CDialogPassword::OnOK() 
{
	UpdateData(TRUE);

	if (m_strPassword1 != m_strPassword2)
	{
		AfxMessageBox(
			L"Passwords do not match.",
			MB_ICONERROR);
	}
	else if (m_strPassword1.IsEmpty())
	{
		AfxMessageBox(
			L"Passwords are empty.",
			MB_ICONERROR);
	}
	else
	{
		CDialog::OnOK();
	}
}
