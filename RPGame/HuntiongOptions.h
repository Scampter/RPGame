#pragma once
#include "afxwin.h"
#include "Enemy.h"
#include <map>

struct Triple
{
	int stats[3];
};

// Map of animals: {Name, [attack, defence, health]}
static std::map<std::string, Enemy> animals = {
	{ "Wolf", Enemy("Wolf", 20, 2, 2, IDB_WOLF, IDB_WOLF_MASK)},
	{ "Boar", Enemy("Boar", 30, 4, 5, IDB_BOAR, IDB_BOAR_MASK)},
	{ "Slime", Enemy("Slime", 15, 0, 1, IDB_SLIME, IDB_SLIME_MASK)},
	{ "Hawk", Enemy("Hawk", 15, 2, 3, IDB_HAWK, IDB_HAWK_MASK)},
	{ "Bear", Enemy("Bear", 40, 10, 10, IDB_BEAR, IDB_BEAR_MASK)}
};
// HuntiongOptions dialog

class HuntiongOptions : public CDialogEx
{
	DECLARE_DYNAMIC(HuntiongOptions)

public:
	HuntiongOptions(CWnd* pParent = NULL);   // standard constructor
	virtual ~HuntiongOptions();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_HUNTING_OPTIONS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CComboBox m_AnimalTypes;
	CString m_ChosenType;
	afx_msg void OnCbnSelchangeAnimalTypes();
};
