
// RPGameDlg.cpp : implementation file
//

#include "stdafx.h"
#include "RPGame.h"
#include "RPGameDlg.h"
#include "afxdialogex.h"
#include <string>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

DWORD HealthColor[3] = {
	RGB(255, 0, 0), // Red
	RGB(255, 230, 0), // Yellow
	RGB(0, 128, 0) // Green
};

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CRPGameDlg dialog



CRPGameDlg::CRPGameDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_RPGAME_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRPGameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_AVATAR, m_HeroAvatar);
}

BEGIN_MESSAGE_MAP(CRPGameDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ACTION_HUNT, &CRPGameDlg::OnBnClickedActionHunt)
END_MESSAGE_MAP()


// CRPGameDlg message handlers

BOOL CRPGameDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	HeroCreation HeroCreationDlg;

	HeroCreationDlg.username = "Player001";
	HeroCreationDlg.heroClass = CLASS_WARRIOR;

	if (HeroCreationDlg.DoModal() == IDOK)
	{
		theApp.m_Hero = Hero(HeroCreationDlg.username, HeroCreationDlg.heroClass);
	}

	SetDlgItemText(IDC_USERNAME, theApp.m_Hero.username);
	m_HeroAvatar.ModifyStyle(0, SS_BITMAP);

	GetDlgItem(IDC_HEALTH)->GetWindowRect(&m_RectHealth);
	ScreenToClient(&m_RectHealth);
	m_RectHealth.InflateRect(-10, -15, -10, -6);

	GetDlgItem(IDC_EXPERIENCE)->GetWindowRect(&m_RectExp);
	ScreenToClient(&m_RectExp);
	m_RectExp.InflateRect(-10, -15, -10, -6);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CRPGameDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CRPGameDlg::OnPaint()
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
		// Show Stats
		SetDlgItemText(IDC_INTELLIGENCE_STAT, std::to_string(theApp.m_Hero.m_Intelligence).c_str());
		SetDlgItemText(IDC_STRENGTH_STAT, std::to_string(theApp.m_Hero.m_Strength).c_str());
		SetDlgItemText(IDC_DEXTERITY_STAT, std::to_string(theApp.m_Hero.m_Dexterity).c_str());
		SetDlgItemText(IDC_LEVEL, std::to_string(theApp.m_Hero.m_Level).c_str());

		// Show avatar of hero
		CRect rect;
		CBrush BorderBrush(RGB(0, 0, 0));
		// Load background Image
		CBitmap backBmp;
		backBmp.LoadBitmap(IDB_BACKGROUND);
		BITMAP backB;
		backBmp.GetObject(sizeof(BITMAP), &backB);

		// Copy coordinates of heroAvatar area
		m_HeroAvatar.GetClientRect(&rect);

		// Load bitmap resource
		CBitmap bmp;
		switch (theApp.m_Hero.heroClass)
		{
		case CLASS_WARRIOR:
			bmp.LoadBitmap(IDB_WARRIOR);
			break;
		case CLASS_ROGUE:
			bmp.LoadBitmap(IDB_ROGUE);
			break;
		case CLASS_MAGE:
			bmp.LoadBitmap(IDB_MAGE);
			break;
		default:
			break;
		}
		CBitmap bmpMask;
		switch (theApp.m_Hero.heroClass)
		{
		case CLASS_WARRIOR:
			bmpMask.LoadBitmap(IDB_WARRIOR_MASK);
			break;
		case CLASS_ROGUE:
			bmpMask.LoadBitmap(IDB_ROGUE_MASK);
			break;
		case CLASS_MAGE:
			bmpMask.LoadBitmap(IDB_MAGE_MASK);
			break;
		default:
			break;
		}
		
		BITMAP b, bMask;
		bmp.GetObject(sizeof(BITMAP), &b);
		bmpMask.GetObject(sizeof(BITMAP), &bMask);

		CPaintDC dc(&m_HeroAvatar);

		CDC memdc;
		memdc.CreateCompatibleDC(&dc);

		// Place background
		memdc.SelectObject(&backBmp);
		dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &memdc,
			0, 0, backB.bmWidth, backB.bmHeight, SRCCOPY);

		// place image mask
		memdc.SelectObject(&bmpMask);
		dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &memdc,
			0, 0, bMask.bmWidth, bMask.bmHeight, SRCAND);

		// Copy bmp image into area cached in memdc
		memdc.SelectObject(&bmp);
		dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &memdc,  
			0, 0, b.bmWidth, b.bmHeight, SRCINVERT);
		dc.FrameRect(rect, &BorderBrush);

		// Show Health
		CString rectText;
		CBrush Brush(RGB(0, 128, 0));
		CPaintDC dcDlg(this);
		CRect FilledRect;
		// Choses health bar color by current hp percent
		if (theApp.m_Hero.m_CurrentHP < 60 && theApp.m_Hero.m_CurrentHP > 30)
		{
			Brush.DeleteObject();
			Brush.CreateSolidBrush(HealthColor[1]);
		}
		else if (theApp.m_Hero.m_CurrentHP < 30)
		{
			Brush.DeleteObject();
			Brush.CreateSolidBrush(HealthColor[0]);
		} 
		else
		{
			Brush.DeleteObject();
			Brush.CreateSolidBrush(HealthColor[2]);
		}
		// Show health bar by current hp percent
		FilledRect.SetRect(
			m_RectHealth.left,
			m_RectHealth.top,
			m_RectHealth.left + m_RectHealth.Width() * ((float)theApp.m_Hero.m_CurrentHP / 100),
			m_RectHealth.bottom
		);
		dcDlg.FillRect(&FilledRect, &Brush);
		//Print text with current health amount on health bar
		SetBkMode(dcDlg, TRANSPARENT);
		rectText.Format("%d/100", theApp.m_Hero.m_CurrentHP);
		dcDlg.DrawText(rectText, &m_RectHealth, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		SetBkMode(dcDlg, OPAQUE);
		// Print border around health bar
		dcDlg.FrameRect(&m_RectHealth, &BorderBrush);


		// Show Exp
		// Set color of experience bar
		Brush.DeleteObject();
		Brush.CreateSolidBrush(RGB(240, 240, 0));
		// Show experience bar
		FilledRect.SetRect(
			m_RectExp.left,
			m_RectExp.top,
			m_RectExp.left + m_RectExp.Width() * ((float)theApp.m_Hero.m_Expirience / 100),
			m_RectExp.bottom
		);
		dcDlg.FillRect(&FilledRect, &Brush);
		// Print text with current amount of experience on bar
		SetBkMode(dcDlg, TRANSPARENT);
		rectText.Format("%d/100", theApp.m_Hero.m_Expirience);
		dcDlg.DrawText(rectText, &m_RectExp, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		SetBkMode(dcDlg, OPAQUE);
		// Print border around experience bar
		dcDlg.FrameRect(&m_RectExp, &BorderBrush);

		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CRPGameDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CRPGameDlg::OnBnClickedActionHunt()
{
	// TODO: Add your control notification handler code here
	// Show new dialog with types of animals for hunt
	HuntiongOptions HuntiongOptionsDlg;

	if (HuntiongOptionsDlg.DoModal() == IDOK)
	{
		Hunting HuntingDlg(animals.find(std::string((LPCTSTR)HuntiongOptionsDlg.m_ChosenType))->second);
		int response = HuntingDlg.DoModal();
		if (response == ID_WIN)
		{
			if (theApp.m_Hero.isLvlUp())
			{
				MessageBox(_T("Congrats!\nYou're level up!"), _T("Level Up"), MB_OK | MB_ICONINFORMATION);
				theApp.m_Hero.handleLevelUp();
			}
			RedrawWindow(&m_RectHealth);
			RedrawWindow(&m_RectExp);
		}
		else if (response == ID_DEFEAT)
		{
			theApp.m_Hero.m_CurrentHP = 0;
			srand(time(0));
			int lastTry = rand() % 3 + 1;
			if (lastTry == 2) {
				theApp.m_Hero.m_CurrentHP = 1;
				MessageBox(_T("Congrats! You don't dead.\n"), _T("The Game Will Continue"), MB_OK | MB_ICONINFORMATION);
			} 
			else
			{
				MessageBox(_T("Sorry, you're dead!\nGood luck next time!"), _T("Game Over"), MB_OK | MB_ICONINFORMATION);
				CRPGameDlg::EndDialog(IDCANCEL);
			}
			RedrawWindow(&m_RectHealth);
		}
		else
		{
			RedrawWindow(&m_RectHealth);
		}
	}
}
