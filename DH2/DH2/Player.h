#pragma once
#include <vector>
#include "PlayerCharacter.h"

class Player
{
public:
	Player();
	~Player();

	void DrawParty(sf::RenderWindow* window);
	void UpdateParty(sf::RenderWindow* window, float dt);

	void AddCharacter(PlayerCharacter* Character); // This will add a character to the AvailableCharacter List
	void AddToParty(PlayerCharacter* Character); // This will add a character in the AvailableCharacter list to the Party list
	void RemoveFromParty(PlayerCharacter* Character); //This will remove the character from the party
	void RemoveFromCharacterList(PlayerCharacter* Character); //This function will remove the character from the AvailableCharacter list on Death

private:

	int m_Gold;
	bool bShouldDrawParty;
	std::vector<PlayerCharacter*> m_AvailableCharacters; //This will hold all characters
	std::vector<PlayerCharacter*> m_CurrentParty; //This holds the party the player will bring into combat
};

