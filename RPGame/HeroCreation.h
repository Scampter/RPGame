#pragma once

enum availableClasses {CLASS_WARRIOR, CLASS_ROGUE, CLASS_MAGE};

// HeroCreation dialog

class HeroCreation : public CDialog
{
	DECLARE_DYNAMIC(HeroCreation)

public:
	HeroCreation(CWnd* pParent = NULL);   // standard constructor
	virtual ~HeroCreation();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CREATE_HERO };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString username;
	int heroClass;
	afx_msg void OnBnClickedChoseWarrior();
	afx_msg void OnBnClickedChoseRogue();
	afx_msg void OnBnClickedChoseMage();
	afx_msg void OnEnChangeUsernameField();
};
