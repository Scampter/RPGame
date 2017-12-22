
// RPGameDlg.h : header file
//

#pragma once
#include "afxwin.h"
#include "HuntiongOptions.h"
#include "Hunting.h"


// CRPGameDlg dialog
class CRPGameDlg : public CDialogEx
{
// Construction
public:
	CRPGameDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RPGAME_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CRect m_RectHealth;
	CRect m_RectExp;
	CStatic m_HeroAvatar;
	afx_msg void OnBnClickedActionHunt();
};
