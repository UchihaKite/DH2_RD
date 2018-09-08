#pragma once
#include <vector>
#include "PlayerCharacter.h"
class Combat
{
public:
	Combat(std::vector<PlayerCharacter*> characterList);
	~Combat();

	void StartCombat(); //Any setup that might need to be done during initialization.
	void EndCombat(); //End the combat, throw up lose screen if the player lost, otherwise assign XP and do any necessary cleanup.

	void StartTurn(); //Any turn setup that may be needed, set the attacker, etc.
	void EndTurn(); //Main purpose is to clear Attacker var to be reused

	void HandlePlayerLoss(); //Is this loss?

	void Attack(ICharacter* Attacker, ICharacter* Target);
	void Defend(ICharacter* Attacker);
	void UseItem(ICharacter* Attacker, ICharacter* Target);
	void UseSkill(ICharacter* Attacker, ICharacter* Target);

	void AssignExpToPlayerCharacters();

	ICharacter* CurrentAttacker;
	ICharacter* CurrentTarget;

	std::vector<PlayerCharacter*> m_playerGroup;
	std::vector<ICharacter*> m_enemyGroup;
};