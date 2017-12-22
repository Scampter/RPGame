// HeroCreation.cpp : implementation file
//

#include "stdafx.h"
#include "RPGame.h"
#include "HeroCreation.h"
#include "afxdialogex.h"


// HeroCreation dialog

IMPLEMENT_DYNAMIC(HeroCreation, CDialog)

HeroCreation::HeroCreation(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_CREATE_HERO, pParent)
	, username(_T(""))
	, heroClass(0)
{

}

HeroCreation::~HeroCreation()
{
}

void HeroCreation::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_USERNAME_FIELD, username);
	DDX_Radio(pDX, IDC_CHOSE_WARRIOR, heroClass);
}


BEGIN_MESSAGE_MAP(HeroCreation, CDialog)
	ON_BN_CLICKED(IDC_CHOSE_WARRIOR, &HeroCreation::OnBnClickedChoseWarrior)
	ON_BN_CLICKED(IDC_CHOSE_ROGUE, &HeroCreation::OnBnClickedChoseRogue)
	ON_BN_CLICKED(IDC_CHOSE_MAGE, &HeroCreation::OnBnClickedChoseMage)
	ON_EN_CHANGE(IDC_USERNAME_FIELD, &HeroCreation::OnEnChangeUsernameField)
END_MESSAGE_MAP()


// HeroCreation message handlers


void HeroCreation::OnBnClickedChoseWarrior()
{
	// TODO: Add your control notification handler code here
	if (IsDlgButtonChecked(IDC_CHOSE_WARRIOR))
	{
		heroClass = CLASS_WARRIOR;
	}
}


void HeroCreation::OnBnClickedChoseRogue()
{
	// TODO: Add your control notification handler code here
	if (IsDlgButtonChecked(IDC_CHOSE_ROGUE))
	{
		heroClass = CLASS_ROGUE;
	}
}


void HeroCreation::OnBnClickedChoseMage()
{
	// TODO: Add your control notification handler code here
	if (IsDlgButtonChecked(IDC_CHOSE_MAGE))
	{
		heroClass = CLASS_MAGE;
	}
}


void HeroCreation::OnEnChangeUsernameField()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	GetDlgItemText(IDC_USERNAME_FIELD, username);
}
