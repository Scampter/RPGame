// LevelUp.cpp : implementation file
//

#include "stdafx.h"
#include "RPGame.h"
#include "LevelUp.h"
#include "afxdialogex.h"


// LevelUp dialog

IMPLEMENT_DYNAMIC(LevelUp, CDialogEx)

LevelUp::LevelUp(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_LVL_UP, pParent)
	, m_PointsLeft(LvlupPoints)
{
	/*m_Intellegence = theApp.m_Hero.m_Intelligence;
	m_Strength     = theApp.m_Hero.m_Strength;
	m_Dexterity    = theApp.m_Hero.m_Dexterity;*/
}

LevelUp::~LevelUp()
{
}

void LevelUp::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_POINTS_LEFT, m_PointsLeft);
	DDX_Text(pDX, IDC_INTELLIGENCE_STAT, theApp.m_Hero.m_Intelligence);
	DDX_Text(pDX, IDC_STRENGTH_STAT, theApp.m_Hero.m_Strength);
	DDX_Text(pDX, IDC_DEXTERITY_STAT, theApp.m_Hero.m_Dexterity);
}


BEGIN_MESSAGE_MAP(LevelUp, CDialogEx)
	ON_BN_CLICKED(IDC_INTELLEGENCE_UP, &LevelUp::OnBnClickedIntellegenceUp)
	ON_BN_CLICKED(IDC_STRENGTH_UP, &LevelUp::OnBnClickedStrengthUp)
	ON_BN_CLICKED(IDC_DEXTERITY_UP, &LevelUp::OnBnClickedDexterityUp)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// LevelUp message handlers


void LevelUp::OnBnClickedIntellegenceUp()
{
	// TODO: Add your control notification handler code here
	if (m_PointsLeft > 0) {
		theApp.m_Hero.m_Intelligence++;
		m_PointsLeft--;
		Invalidate();
		UpdateWindow();
	}
	else
	{
		LevelUp::EndDialog(IDOK);
	}
}


void LevelUp::OnBnClickedStrengthUp()
{
	// TODO: Add your control notification handler code here
	if (m_PointsLeft > 0) {
		theApp.m_Hero.m_Strength++;
		m_PointsLeft--;
		Invalidate();
		UpdateWindow();
	}
	else
	{
		LevelUp::EndDialog(IDOK);
	}
}


void LevelUp::OnBnClickedDexterityUp()
{
	// TODO: Add your control notification handler code here
	if (m_PointsLeft > 0) {
		theApp.m_Hero.m_Dexterity++;
		m_PointsLeft--;
		Invalidate();
		UpdateWindow();
	}
	else
	{
		LevelUp::EndDialog(IDOK);
	}
}


void LevelUp::OnPaint()
{
	SetDlgItemInt(IDC_INTELLIGENCE_STAT, theApp.m_Hero.m_Intelligence);
	SetDlgItemInt(IDC_STRENGTH_STAT, theApp.m_Hero.m_Strength);
	SetDlgItemInt(IDC_DEXTERITY_STAT, theApp.m_Hero.m_Dexterity);

	SetDlgItemInt(IDC_POINTS_LEFT, m_PointsLeft);

	CPaintDC dc(this); // device context for painting
					   // TODO: Add your message handler code here
					   // Do not call CDialogEx::OnPaint() for painting messages
}
