#pragma once
#include "GameObjects.h"
#include "Stat.h"
#include <iostream>
#include "CharacterClass.h"
#include "AssetManagers.h"

//This may become abstract, making as plain as possible while I work out exact design
//Should never make an ICharacter directly though I am right now for testing ... whoops
//could probably abstract for that reason. But to make a new character you'll call for most likely PlayerCharacter or something of that nature, then AICharacter. 
class ICharacter : public GameObject
{
public:
	ICharacter(std::string FileLocation, sf::Vector2f pos, sf::Vector2f size);
	~ICharacter();

	virtual void Draw(sf::RenderWindow* window);
	virtual void Update(sf::RenderWindow* window, float dt);
	
	float GetLevel() { return m_Level->GetCurrent(); }
	float GetStrength() { return m_Strength->GetCurrent(); }
	float GetDefense() { return m_Defense->GetCurrent(); }
	float GetMagic() { return m_Magic->GetCurrent(); }
	float GetDexterity() { return m_Dexterity->GetCurrent(); }
	float GetHealth() { return m_Health->GetCurrent(); }

	void TakeDamage(float dmg);
	void Die();

	void GainExperience(float earnedXp);
	virtual void LevelUp();

protected:

	std::string m_Name;
	CharacterClass* m_Class;

	AnimationManager* m_animator;

	//Better as an array, May rework how they're created/fetched to allow easier creation
	Stat* m_Strength;
	Stat* m_Defense;
	Stat* m_Dexterity;
	Stat* m_Magic;
	Stat* m_Health;
	Stat* m_Exp;
	Stat* m_Level;
};

