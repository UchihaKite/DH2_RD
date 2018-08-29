#include "CharacterCreator.h"

ICharacter * CharacterCreator::CreateEnemyCharacter()
{
	//The AICharacter will be created here when going into combat (maybe before if we pre-generate the enemies in a map)

	//Adding the old way we made characters for reference, but will be generated quite differently (trying to avoid this class needing headers for every class we make)
	//Also likely to be using the monster sprite sheets as well as the character ones to make as many "unique" fights as possible. Monsters may not follow the same ICharacter design though.. address later.

	/*int randNum = rand() % 5 + 1;


	switch (randNum)
	{
	case 1:
		tempCharacter = new Warrior("", sf::Vector2f(1.0f, 1.0f), sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 0.f));
		break;
	case 2:
		tempCharacter = new Wizard("", sf::Vector2f(1.0f, 1.0f), sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 0.f));
		break;
	case 3:
		tempCharacter = new Archer("", sf::Vector2f(1.0f, 1.0f), sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 0.f));
		break;
	case 4:
		tempCharacter = new Wolf("", sf::Vector2f(1.0f, 1.0f), sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 0.f));
		break;
	case 5:
		tempCharacter = new Robot("", sf::Vector2f(1.0f, 1.0f), sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 0.f));
		break;
	}*/

	return tempCharacter;
}
