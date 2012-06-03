
// MemoryTesterDlg.h : header file
//

#pragma once


// CMemoryTesterDlg dialog
class CMemoryTesterDlg : public CDialogEx
{
// Construction
public:
	CMemoryTesterDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MEMORYTESTER_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnDestroy();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCreateonetexture();
	afx_msg void OnBnClickedClearall();
};
