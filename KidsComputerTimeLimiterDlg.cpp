// KidsComputerTimeLimiterDlg.cpp : implementation file
//

#include "stdafx.h"
#include "KidsComputerTimeLimiter.h"
#include "KidsComputerTimeLimiterDlg.h"
#include "CDialogPassword.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CKidsComputerTimeLimiterDlg dialog

CKidsComputerTimeLimiterDlg::CKidsComputerTimeLimiterDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CKidsComputerTimeLimiterDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CKidsComputerTimeLimiterDlg)
	m_dtEndTime = COleDateTime::GetCurrentTime();
	m_dtStartTime = COleDateTime::GetCurrentTime();
	m_lTimeLimitMins = 30;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CKidsComputerTimeLimiterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CKidsComputerTimeLimiterDlg)
	DDX_Control(pDX, IDC_EDIT_TIME_LIMIT, m_edtTimeLimit);
	DDX_Control(pDX, IDCANCEL, m_btnStop);
	DDX_Control(pDX, IDOK, m_btnStart);
	DDX_Text(pDX, IDC_EDIT_END_TIME, m_dtEndTime);
	DDX_Text(pDX, IDC_EDIT_START_TIME, m_dtStartTime);
	DDX_Text(pDX, IDC_EDIT_TIME_LIMIT, m_lTimeLimitMins);
	DDV_MinMaxLong(pDX, m_lTimeLimitMins, 1, 1440);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CKidsComputerTimeLimiterDlg, CDialog)
	//{{AFX_MSG_MAP(CKidsComputerTimeLimiterDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CKidsComputerTimeLimiterDlg message handlers

BOOL CKidsComputerTimeLimiterDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CKidsComputerTimeLimiterDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CKidsComputerTimeLimiterDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CKidsComputerTimeLimiterDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CKidsComputerTimeLimiterDlg::OnOK() 
{
	if( ! UpdateData(TRUE) )
		return;

	CDialogPassword oCDialogPassword;
	if ( IDOK == oCDialogPassword.DoModal() )
	{
		m_strPassword = oCDialogPassword.GetPassword();
		m_dtStartTime = COleDateTime::GetCurrentTime();
		m_dtEndTime = m_dtStartTime + COleDateTimeSpan( 0, 0, m_lTimeLimitMins, 0 );
		UpdateData(FALSE);

		m_edtTimeLimit.SetReadOnly();
		m_btnStart.EnableWindow(FALSE);
		m_btnStop.EnableWindow();

		SetTimer(IDT_TIMER_0, 500, NULL);
	}

	// disregard default behavior
	// CDialog::OnOK();
}

void CKidsComputerTimeLimiterDlg::OnCancel() 
{
	if( m_strPassword.IsEmpty() )
	{
		CDialog::OnCancel();
	}
	else
	{
		CDialogPassword oCDialogPassword;
		if( IDOK == oCDialogPassword.DoModal() )
		{
			if( oCDialogPassword.GetPassword() == m_strPassword )
			{
				CDialog::OnCancel();
			}
			else
			{
				AfxMessageBox( L"Incorrect password." );
			}
		}
	}
}

void CKidsComputerTimeLimiterDlg::OnTimer(UINT nIDEvent) 
{
	COleDateTimeSpan dtSpan = COleDateTime::GetCurrentTime() - m_dtStartTime;
	if( dtSpan.GetTotalMinutes() >= m_lTimeLimitMins )
	{
		KillTimer(IDT_TIMER_0);

		HANDLE hToken = NULL;
		::OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken);

		TOKEN_PRIVILEGES tkp;
		memset( &tkp, 0, sizeof(TOKEN_PRIVILEGES) );
		::LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME, &tkp.Privileges[0].Luid);

		tkp.PrivilegeCount = 1;
		tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
		::AdjustTokenPrivileges( hToken, FALSE, &tkp, 0, NULL, 0 );

		BOOL bInitiateSystemShutdown = ::InitiateSystemShutdown(
			NULL,
			L"System shutdown from \"The Downs Kids' Computer Time Limiter\"",
			30,
			FALSE,
			FALSE );

		if( bInitiateSystemShutdown == 0 )
		{
			const DWORD cdwGetLastError = ::GetLastError();
			TCHAR tcGetLastError[10];
			::memset( &tcGetLastError, 0, sizeof( tcGetLastError ) );
			::_ultot( cdwGetLastError, tcGetLastError, 10 );
			AfxMessageBox(
				CString( L"Error initiating system shutdown. [") +
				CString( tcGetLastError ) + CString( L"]" ) );
		}
	}

	CDialog::OnTimer(nIDEvent);
}
