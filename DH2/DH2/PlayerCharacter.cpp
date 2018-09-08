#include "PlayerCharacter.h"



PlayerCharacter::PlayerCharacter(std::string FileLocation, sf::Vector2f pos, sf::Vector2f size) : ICharacter(FileLocation, pos, size)
{
	//Player specific init shit
	m_Name = "PlayerCharacter";

	m_StatPoints = 0;
	m_SkillPoints = 0;
}


PlayerCharacter::~PlayerCharacter()
{
}

void PlayerCharacter::GainExperience(float earnedXp)
{
	//Should never be 0 or less, if for some reason it is, jump ship.
	if (earnedXp <= 0)
	{
		return;
	}

	//Store off excess XP so we can catch any overflow
	float excessXP = earnedXp - (GetMaxStat("Exp") - GetCurrentStat("Exp"));
	excessXP = excessXP >= 0 ? excessXP : 0.0f;

	//Then add the earned XP
	GetStat("Exp")->AddCurrent(earnedXp);

	//While we have overflow, loop and calculate until the overflow is gone
	while (GetCurrentStat("Exp") >= GetMaxStat("Exp"))
	{
		//We've hit the cap, lets reset the exp and gain our level
		GetStat("Level")->AddCurrent(1.0f);
		GetStat("Exp")->SetCurrent(0);
		GetStat("Exp")->SetMax(GetMaxStat("Exp") + (10.0f * GetCurrentStat("Level"))); 

		//Recalculate excessXP and make sure it's not negative
		excessXP = excessXP - GetMaxStat("Exp");
		excessXP = excessXP >= 0 ? excessXP : 0.0f;

		GetStat("Exp")->AddCurrent(excessXP);

		LevelUp();
	}
}

void PlayerCharacter::LevelUp()
{
	//Idea here is to get stat points to place into base stats, where it can be stored off
	//Then the player can assign them in some kinda level up page we would pop up here, or can save them for mass assigning later
	//Anything that can be applied to all types of characters can be applied here and called from the child

	m_StatPoints += 5;
	m_SkillPoints += 2;
}