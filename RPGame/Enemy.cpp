#include "stdafx.h"
#include "Enemy.h"


Enemy::Enemy(
	CString newName,
	int health,
	int defence,
	int attack,
	int bitmap,
	int bitmapMask
) : m_CurHealth(health)
{
	m_Name = newName;
	m_Health = health;
	m_Defence = defence;
	m_Attack = attack;
	m_bitmap = bitmap;
	m_bitmapMask = bitmapMask;
}


Enemy::~Enemy()
{
}

int Enemy::calculateAttackValue(int heroDefence)
{
	srand(time(0));
	if (rand() % 100 + 1 < heroDefence)
	{
		return 0;
	}
	else
	{
		int result = m_Attack * ((float)(100 - heroDefence / 2) / 100);
		if (result < 0)
		{
			result = 0;
		}
		return result;
	}
}
