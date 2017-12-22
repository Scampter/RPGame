#pragma once

#include "HuntiongOptions.h"
#include "Enemy.h"
#include "afxwin.h"

int static ID_WIN = 35;
int static ID_DEFEAT = 42;

// Hunting dialog

class Hunting : public CDialogEx
{
	DECLARE_DYNAMIC(Hunting)

public:
	Hunting(Enemy Enemy, CWnd* pParent = NULL);   // standard constructor
	virtual ~Hunting();


// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_HUNTING };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	Enemy m_Enemy;
	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();
	CStatic m_HeroAvatar;
	CRect m_EnemyHealth;
	CRect m_HeroHealth;
	CStatic m_EnemyPic;
	void PaintUserAvatar();
	void PaintEnemyPicture();
	afx_msg void OnBnClickedAttack();
//	afx_msg void OnBnClickedCancel();
};
