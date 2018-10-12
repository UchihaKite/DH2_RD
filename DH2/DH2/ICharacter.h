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

	std::string GetName() const { return m_Name; }
	void SetName(std::string name) { m_Name = name; }
	
	float GetCurrentStat(std::string desiredStat); 
	float GetMaxStat(std::string desiredStat);

	Stat* GetStat(std::string desiredStat);

	AnimationType GetCurrentAnimationType() { return m_CurrentAnim; }

	void SetCurrentStat(std::string desiredStat, float desiredValue);
	void SetMaxStat(std::string desiredStat, float desiredValue);

	CharacterClass* GetCharacterClass() { return m_Class; }
	void SetCharacterClass(CharacterClass* newClass) { m_Class = newClass; }

	void PrintStats() // Temp implementation. This will eventually grab stats for UI readouts or whatever, but not print to logs unless we really want to.
	{
		std::cout << "Name: " << GetName() << std::endl;
		std::cout << "Health: " << GetCurrentStat("Health") << std::endl;

		if (m_Class != NULL)
		{
			std::cout << "Class: " << m_Class->GetClassName() << std::endl;
		}

		std::cout << "Strength: " << GetCurrentStat("Strength") << std::endl;
		std::cout << "Defense: " << GetCurrentStat("Defense") << std::endl;
		std::cout << "Magic: " << GetCurrentStat("Magic") << std::endl;
		std::cout << "Dexterity: " << GetCurrentStat("Dexterity") << std::endl;
		std::cout << "Level: " << GetCurrentStat("Level") << std::endl;
	}

	void TakeDamage(float dmg);
	void Die();

	void SetIdle();

	//Checking against only name might not be enough, might need to make this more robust later
	inline bool operator==(const ICharacter& checker) { return checker.GetName() == this->GetName(); }

	AnimationManager* m_animator;

protected:

	std::string m_Name;
	CharacterClass* m_Class;

	AnimationType m_CurrentAnim;

	std::map<std::string, Stat> m_stats;
};

