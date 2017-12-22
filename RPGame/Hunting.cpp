// Hunting.cpp : implementation file
//

#include "stdafx.h"
#include "RPGame.h"
#include "RPGameDlg.h"
#include "Hunting.h"
#include "afxdialogex.h"

DWORD HealthBarColor[3] = {
	RGB(255, 0, 0), // Red
	RGB(255, 230, 0), // Yellow
	RGB(0, 128, 0) // Green
};

// Hunting dialog

IMPLEMENT_DYNAMIC(Hunting, CDialogEx)

Hunting::Hunting(Enemy Enemy, CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_HUNTING, pParent)
	, m_Enemy(Enemy)
{

}

Hunting::~Hunting()
{

}

void Hunting::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_ENEMY_NAME, m_Enemy.m_Name);
	DDX_Control(pDX, IDC_AVATAR_ON_HUNT, m_HeroAvatar);
	DDX_Control(pDX, IDC_ENEMY_PICTURE, m_EnemyPic);
}


BEGIN_MESSAGE_MAP(Hunting, CDialogEx)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_ATTACK, &Hunting::OnBnClickedAttack)
END_MESSAGE_MAP()


// Hunting message handlers

BOOL Hunting::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	SetDlgItemText(IDC_USERNAME_ON_HUNT, theApp.m_Hero.username);
	m_HeroAvatar.ModifyStyle(0, SS_BITMAP);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}

void Hunting::OnPaint()
{
	GetDlgItem(IDC_HEALTH_ON_HUNT)->GetWindowRect(&m_HeroHealth);
	ScreenToClient(&m_HeroHealth);
	m_HeroHealth.InflateRect(0, -7, -1, 0);
	Hunting::PaintUserAvatar();

	GetDlgItem(IDC_ENEMY_HEALTH_HUNT)->GetWindowRect(&m_EnemyHealth);
	ScreenToClient(&m_EnemyHealth);
	m_EnemyHealth.InflateRect(0, -7, -1, 0);
	Hunting::PaintEnemyPicture();
	
	// Show Health
	CBrush BorderBrush(RGB(0, 0, 0));
	CString rectText;
	CBrush Brush(RGB(0, 128, 0));
	CPaintDC dcDlg(this);
	CRect FilledRect;
	// Choses health bar color by current hp percent
	if (theApp.m_Hero.m_CurrentHP < 60 && theApp.m_Hero.m_CurrentHP > 30)
	{
		Brush.DeleteObject();
		Brush.CreateSolidBrush(HealthBarColor[1]);
	}
	else if (theApp.m_Hero.m_CurrentHP < 30)
	{
		Brush.DeleteObject();
		Brush.CreateSolidBrush(HealthBarColor[0]);
	}
	else
	{
		Brush.DeleteObject();
		Brush.CreateSolidBrush(HealthBarColor[2]);
	}
	// Show health bar by current hp percent
	FilledRect.SetRect(
		m_HeroHealth.left,
		m_HeroHealth.top,
		m_HeroHealth.left + m_HeroHealth.Width() * ((float)theApp.m_Hero.m_CurrentHP / 100),
		m_HeroHealth.bottom
	);
	dcDlg.FillRect(&FilledRect, &Brush);
	//Print text with current health amount on health bar
	SetBkMode(dcDlg, TRANSPARENT);
	rectText.Format("%d/100", theApp.m_Hero.m_CurrentHP);
	dcDlg.DrawText(rectText, &m_HeroHealth, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
	SetBkMode(dcDlg, OPAQUE);
	// Print border around health bar
	dcDlg.FrameRect(&m_HeroHealth, &BorderBrush);

	// Choses health bar color by current hp percent
	if (m_Enemy.m_CurHealth <= (float)m_Enemy.m_Health / 100 * 60 && m_Enemy.m_CurHealth >(float)m_Enemy.m_Health / 100 * 30)
	{
		Brush.DeleteObject();
		Brush.CreateSolidBrush(HealthBarColor[1]);
	}
	else if (m_Enemy.m_CurHealth <= (float)m_Enemy.m_Health / 100 * 30)
	{
		Brush.DeleteObject();
		Brush.CreateSolidBrush(HealthBarColor[0]);
	}
	else
	{
		Brush.DeleteObject();
		Brush.CreateSolidBrush(HealthBarColor[2]);
	}
	// Show health bar by current hp percent
	FilledRect.SetRect(
		m_EnemyHealth.left,
		m_EnemyHealth.top,
		m_EnemyHealth.left + m_EnemyHealth.Width() * ((float)m_Enemy.m_CurHealth / m_Enemy.m_Health),
		m_EnemyHealth.bottom
	);
	dcDlg.FillRect(&FilledRect, &Brush);
	//Print text with current health amount on health bar
	SetBkMode(dcDlg, TRANSPARENT);
	rectText.Format("%d/%d", m_Enemy.m_CurHealth, m_Enemy.m_Health);
	dcDlg.DrawText(rectText, &m_EnemyHealth, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
	SetBkMode(dcDlg, OPAQUE);
	// Print border around health bar
	dcDlg.FrameRect(&m_EnemyHealth, &BorderBrush);
}

/*
*  Paint User avatar on hero picture control
*/
void Hunting::PaintUserAvatar()
{
	CBrush BorderBrush(RGB(0, 0, 0));
	CBitmap backBmp;
	backBmp.LoadBitmap(IDB_BACKGROUND);

	BITMAP backB;
	backBmp.GetObject(sizeof(BITMAP), &backB);

	// Show avatar of hero
	CRect rect;

	// Copy coordinates of heroAvatar area
	m_HeroAvatar.GetClientRect(&rect);

	// Load bitmap resource of avatar
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
	// Load bitmap resource of mask of avatar
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

	CPaintDC dcHero(&m_HeroAvatar);

	CDC memdc;
	memdc.CreateCompatibleDC(&dcHero);

	// Place background
	memdc.SelectObject(&backBmp);
	dcHero.StretchBlt(0, 0, rect.Width(), rect.Height(), &memdc,
		0, 0, backB.bmWidth, backB.bmHeight, SRCCOPY);

	// Place image mask
	memdc.SelectObject(&bmpMask);
	dcHero.StretchBlt(0, 0, rect.Width(), rect.Height(), &memdc,
		0, 0, bMask.bmWidth, bMask.bmHeight, SRCAND);

	// Copy bmp image into area cached in memdc
	memdc.SelectObject(&bmp);
	dcHero.StretchBlt(0, 0, rect.Width(), rect.Height(), &memdc,
		0, 0, b.bmWidth, b.bmHeight, SRCINVERT);
	dcHero.FrameRect(rect, &BorderBrush);
}

/*
*  Paint Enemy picture on enemy picture control
*/
void Hunting::PaintEnemyPicture()
{
	CBrush BorderBrush(RGB(0, 0, 0));
	CBitmap backBmp;
	backBmp.LoadBitmap(IDB_BACKGROUND);

	BITMAP backB;
	backBmp.GetObject(sizeof(BITMAP), &backB);

	CRect rect;

	m_EnemyPic.GetClientRect(&rect);

	CBitmap enemyBmp;
	enemyBmp.LoadBitmap(m_Enemy.m_bitmap);
	CBitmap enemyMask;
	enemyMask.LoadBitmap(m_Enemy.m_bitmapMask);

	BITMAP enemyB;
	enemyBmp.GetObject(sizeof(BITMAP), &enemyB);
	BITMAP enemyM;
	enemyMask.GetObject(sizeof(BITMAP), &enemyM);

	CPaintDC dcEnemy(&m_EnemyPic);

	CDC enemyMem;
	enemyMem.CreateCompatibleDC(&dcEnemy);

	enemyMem.SelectObject(&backBmp);
	dcEnemy.StretchBlt(0, 0, rect.Width(), rect.Height(), &enemyMem,
		0, 0, backB.bmWidth, backB.bmHeight, SRCCOPY);

	enemyMem.SelectObject(&enemyMask);
	dcEnemy.StretchBlt(0, 0, rect.Width(), rect.Height(), &enemyMem,
		0, 0, enemyM.bmWidth, enemyM.bmHeight, SRCAND);

	enemyMem.SelectObject(&enemyBmp);
	dcEnemy.StretchBlt(0, 0, rect.Width(), rect.Height(), &enemyMem,
		0, 0, enemyB.bmWidth, enemyB.bmHeight, SRCINVERT);
	dcEnemy.FrameRect(rect, &BorderBrush);
}

void Hunting::OnBnClickedAttack()
{
	// TODO: Add your control notification handler code here
	m_Enemy.m_CurHealth -= theApp.m_Hero.calculateAttackValue(m_Enemy.m_Defence);
	theApp.m_Hero.m_CurrentHP -= m_Enemy.calculateAttackValue(theApp.m_Hero.m_Dexterity);

	if (theApp.m_Hero.m_CurrentHP <= 0)
	{
		Hunting::EndDialog(ID_DEFEAT);
	}

	if (m_Enemy.m_CurHealth <= 0)
	{
		theApp.m_Hero.m_Expirience += m_Enemy.m_Attack + m_Enemy.m_Defence + m_Enemy.m_Health / 2;
		Hunting::EndDialog(ID_WIN);
	}

	RedrawWindow(&m_HeroHealth);
	RedrawWindow(&m_EnemyHealth);
}