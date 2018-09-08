#include "Combat.h"



Combat::Combat(std::vector<PlayerCharacter*> characterList) : m_playerGroup(characterList)
{
}


Combat::~Combat()
{
}

void Combat::StartCombat()
{
	//Loop through players and enemies to determine turn order
	//Consider if we want it to be speed, or if we do all player characters, then all enemies
}

void Combat::EndCombat()
{
	if (m_playerGroup.size() == 0)
	{
		HandlePlayerLoss();
	}

	if (m_enemyGroup.size() == 0)
	{
		AssignExpToPlayerCharacters();
	}
}

void Combat::StartTurn()
{
}

void Combat::EndTurn()
{

	//At the end of the enemy turn, clean up the target and attacker
	CurrentTarget = nullptr; 
	CurrentAttacker = nullptr;
}

void Combat::HandlePlayerLoss()
{
}

void Combat::Attack(ICharacter* Attacker, ICharacter* Target)
{
	//Using essentially the pokemon dmg formula but took out the modifier till we figure that part out  |
	//The formula uses BP (base power) as a multiplier as well, but I replaced (for now) with this 5 --------------------------------------------V
	float Damage = (Attacker->GetCurrentStat("Level") + 10 / 250) * (Attacker->GetCurrentStat("Strength") / Target->GetCurrentStat("Defense")) * 5 + 2;

	//Here we would do any kind of dodge calculation to see if the attack actually strikes.
	bool ItDoesHit = true;

	if (ItDoesHit)
	{
		Target->TakeDamage(Damage);
	}
}

void Combat::Defend(ICharacter* Attacker)
{
	//This would mass raise the character's defense for the turn, blocking most of all incoming damage
}

void Combat::UseItem(ICharacter* Attacker, ICharacter* Target)
{
	//This will most likely require us to access the player's item pool, unless we're having characters have an inventory
}

void Combat::UseSkill(ICharacter* Attacker, ICharacter* Target)
{
}

void Combat::AssignExpToPlayerCharacters()
{
	for (unsigned int i = 0; i < m_playerGroup.size(); i++)
	{
		//Need to come up with whatever exp earning formula we want for gaining levels
		m_playerGroup[i]->GainExperience(100.f);
	}
}
