#pragma once
#include "ICharacter.h"
class PlayerCharacter : public ICharacter
{
public:
	PlayerCharacter(std::string FileLocation, sf::Vector2f pos, sf::Vector2f size);
	~PlayerCharacter();

	void GainExperience(float earnedXp);
	virtual void LevelUp();

private:

	int m_StatPoints;
	int m_SkillPoints; //Skill points might be a part of class, since classes are interchangeable and will level seperately. Could warrant discussion
};

