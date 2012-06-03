
// MemoryTesterDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MemoryTester.h"
#include "MemoryTesterDlg.h"
#include "afxdialogex.h"
#include "d3dtester.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif




// CMemoryTesterDlg dialog




CMemoryTesterDlg::CMemoryTesterDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMemoryTesterDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMemoryTesterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMemoryTesterDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_DESTROY()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CREATEONETEXTURE, &CMemoryTesterDlg::OnBnClickedCreateonetexture)
	ON_BN_CLICKED(IDC_CLEARALL, &CMemoryTesterDlg::OnBnClickedClearall)
END_MESSAGE_MAP()


// CMemoryTesterDlg message handlers

BOOL CMemoryTesterDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// init d3d window
	// init d3d tester
	CWnd* pD3DWindow = GetDlgItem(IDC_D3DWINDOW);
	D3DTester::initD3D(pD3DWindow->m_hWnd);

	return TRUE;  // return TRUE  unless you set the focus to a control

}

void CMemoryTesterDlg::OnDestroy()
{
	D3DTester::destroyD3D();
	CDialogEx::OnDestroy();
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMemoryTesterDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMemoryTesterDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMemoryTesterDlg::OnBnClickedCreateonetexture()
{
	D3DTester::createTempD3DTexture();
}


void CMemoryTesterDlg::OnBnClickedClearall()
{
	D3DTester::clearAllTempResources();
}
