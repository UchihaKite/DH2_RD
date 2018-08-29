#pragma once
#include "ICharacter.h"
#include "ClassTraveler.h"
/*
	Use this class for any character creation needs. 
	This will set the base class and any mods needed, as well as a name
	Need to figure out how we're going to determine which sprite sheet we should be needing

	To test going to throw this into the engine, this will likely be called only in combat for creating enemies
	and also in the character store when we want to purchase new characters.

	Possiblilty to add a slider to pay more gold for a higher character after reaching a certain place in the game
*/
class CharacterCreator
{
public:

	static CharacterCreator& getInstance()
	{
		static CharacterCreator instance;
							  
		return instance;
	}

	ICharacter* CreatePlayerCharacter()
	{
		//Once PlayerCharacter and AICharacter classes are created, we'll create here instead of calling the interface class
		tempCharacter = new ICharacter("Sprites/Characters/AdamShield.png", sf::Vector2f(200.f, 200.f), sf::Vector2f(2.0f, 2.0f));
		tempCharacter->SetCharacterClass(new ClassTraveler);
		return tempCharacter;
	}

	ICharacter* CreateEnemyCharacter();

private:

	CharacterCreator() {}
	CharacterCreator(CharacterCreator const&); // Don't Implement
	void operator=(CharacterCreator const&); // Don't implement

	ICharacter* tempCharacter;
};


