#include "stdafx.h"
#include "Hero.h"


// Create Hero with base username and class
Hero::Hero()
{
	username = "Player001";
	heroClass = CLASS_WARRIOR;
}

// Create Hero with specific username and class
Hero::Hero(
	CString newUsername = "Player001",
	int newClass        = CLASS_WARRIOR
)
{
	username       = newUsername;

	switch (newClass)
	{
	case 0: heroClass = CLASS_WARRIOR; break;
	case 1: heroClass = CLASS_ROGUE; break;
	case 2: heroClass = CLASS_MAGE; break;
	default: heroClass = CLASS_WARRIOR; break;
	}

	m_Intelligence = (heroClass == CLASS_MAGE ? 15 : 10);
	m_Strength     = (heroClass == CLASS_WARRIOR ? 15 : 10);
	m_Dexterity    = (heroClass == CLASS_ROGUE ? 15 : 10);

	m_Level		   = 1;
	m_Expirience   = 0;
	m_CurrentHP    = 100;
}


Hero::~Hero()
{
}

/*
*  Calculates amount of damage which hero inflicted
*/
int Hero::calculateAttackValue(int enemyDefence)
{
	int result = (m_Strength / 2) - enemyDefence;
	if (result < 0)
	{
		result = 0;
	}
	return result;
}

/*
* Checks if experience bar is full
*/
BOOL Hero::isLvlUp()
{
	if (m_Expirience >= 100)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

/*
*  Handle level up action
*/
void Hero::handleLevelUp()
{
	m_Expirience = m_Expirience - 100;
	m_CurrentHP  = 100;
	m_Level     += 1;
	LevelUp LevelUpDlg;
	if (LevelUpDlg.DoModal() == IDOK)
	{
		return;
	}
}