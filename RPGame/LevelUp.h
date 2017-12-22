#pragma once

int static LvlupPoints = 5;

// LevelUp dialog

class LevelUp : public CDialogEx
{
	DECLARE_DYNAMIC(LevelUp)

public:
	LevelUp(CWnd* pParent = NULL);   // standard constructor
	virtual ~LevelUp();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LVL_UP };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedIntellegenceUp();
	int m_PointsLeft;
	afx_msg void OnBnClickedStrengthUp();
	afx_msg void OnBnClickedDexterityUp();
	int m_Intellegence;
	int m_Strength;
	int m_Dexterity;
	afx_msg void OnPaint();
};
