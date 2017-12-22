#pragma once
class Enemy
{
public:
	Enemy(CString newName, int health, int defence, int attack, int bitmap, int bitmapMask);
	~Enemy();

public:
	CString m_Name;
	int m_Health;
	int m_Defence;
	int m_Attack;
	int m_CurHealth;
	int m_bitmap;
	int m_bitmapMask;
	int calculateAttackValue(int heroDefence);
};

