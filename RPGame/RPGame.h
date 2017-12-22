
// RPGame.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols
#include "Hero.h"
#include "HeroCreation.h"


// CRPGameApp:
// See RPGame.cpp for the implementation of this class
//

class CRPGameApp : public CWinApp
{
public:
	CRPGameApp();
	Hero m_Hero;
	/*CString username;
	int heroClass;
	int m_Intelligence;
	int m_Strength;
	int m_Dexterity;
	int m_Expirience;
	int m_CurrentHP;*/

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CRPGameApp theApp;