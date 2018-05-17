#pragma once
#include "GameObjects.h"
#include "Stat.h"
#include <iostream>

//This may become abstract, making as plain as possible while I work out exact design
class ICharacter : public GameObject
{
public:
	ICharacter(sf::Vector2f pos, sf::Vector2f size);
	~ICharacter();

	//These may get moved into other interfaces
	void Attack();
	void Defend();
	void UseItem();
	void GainExperience(float earnedXp);
	void LevelUp();

private:

	std::string m_Name;
	std::string m_Class;

	//Better as an array, May rework how they're created/fetched to allow easier creation
	Stat* m_Strength;
	Stat* m_Defense;
	Stat* m_Dexterity;
	Stat* m_Magic;
	Stat* m_Health;
	Stat* m_Exp;
	Stat* m_Level;
};

