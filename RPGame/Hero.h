#pragma once

#include "HeroCreation.h"
#include "LevelUp.h"

/*
* Class for storaging current information about Hero
*/
class Hero
{
public:
	Hero();
	Hero(CString newUsername, int newClass);
	~Hero();

public:
	CString username;
	int heroClass;		 
	int m_Level;

	// Hero stats
	int m_Intelligence;
	int m_Strength;
	int m_Dexterity;

	// Additional Hero stats
	int m_Expirience;  // Current amount of experience of Hero
	int m_CurrentHP;   // Current Health Points of Hero

	int calculateAttackValue(int enemyDefence);
	BOOL isLvlUp();
	void handleLevelUp();
};

