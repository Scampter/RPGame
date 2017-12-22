// HuntiongOptions.cpp : implementation file
//

#include "stdafx.h"
#include "RPGame.h"
#include "HuntiongOptions.h"
#include "afxdialogex.h"

// HuntiongOptions dialog

IMPLEMENT_DYNAMIC(HuntiongOptions, CDialogEx)

HuntiongOptions::HuntiongOptions(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_HUNTING_OPTIONS, pParent)
	, m_ChosenType(_T(""))
{
}

HuntiongOptions::~HuntiongOptions()
{
}

void HuntiongOptions::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ANIMAL_TYPES, m_AnimalTypes);
	DDX_CBString(pDX, IDC_ANIMAL_TYPES, m_ChosenType);
}


BEGIN_MESSAGE_MAP(HuntiongOptions, CDialogEx)
	ON_CBN_SELCHANGE(IDC_ANIMAL_TYPES, &HuntiongOptions::OnCbnSelchangeAnimalTypes)
END_MESSAGE_MAP()


// HuntiongOptions message handlers


BOOL HuntiongOptions::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	for (auto iterator = animals.begin(); iterator != animals.end(); ++iterator)
	{
		m_AnimalTypes.AddString(iterator->first.c_str());
	}

	m_AnimalTypes.SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


void HuntiongOptions::OnCbnSelchangeAnimalTypes()
{
	// TODO: Add your control notification handler code here
	m_AnimalTypes.GetLBText(m_AnimalTypes.GetCurSel(), m_ChosenType);
}
