// KidsComputerTimeLimiterDlg.h : header file
//

#if !defined(AFX_KIDSCOMPUTERTIMELIMITERDLG_H__240206A9_D03F_4FAF_881C_4BBE9FC0078E__INCLUDED_)
#define AFX_KIDSCOMPUTERTIMELIMITERDLG_H__240206A9_D03F_4FAF_881C_4BBE9FC0078E__INCLUDED_

#define IDT_TIMER_0 WM_USER + 200

/////////////////////////////////////////////////////////////////////////////
// CKidsComputerTimeLimiterDlg dialog

class CKidsComputerTimeLimiterDlg : public CDialog
{
// Construction
public:
	CKidsComputerTimeLimiterDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CKidsComputerTimeLimiterDlg)
	enum { IDD = IDD_KIDSCOMPUTERTIMELIMITER_DIALOG };
	CEdit	m_edtTimeLimit;
	CButton	m_btnStop;
	CButton	m_btnStart;
	COleDateTime	m_dtEndTime;
	COleDateTime	m_dtStartTime;
	long	m_lTimeLimitMins;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKidsComputerTimeLimiterDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CKidsComputerTimeLimiterDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	CString m_strPassword;

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KIDSCOMPUTERTIMELIMITERDLG_H__240206A9_D03F_4FAF_881C_4BBE9FC0078E__INCLUDED_)
