#pragma once
#include "ICharacter.h"
#include "CharacterCreator.h"

#include "StateMachine.h"

class Engine
{
public:
	Engine();
	~Engine();

	void Draw(sf::RenderWindow* Window);
	void Update(sf::RenderWindow* Window, float DeltaTime); // Update Engine Internals

	void StateSetUp();
private:
	
	sf::Texture m_backgroundTex;
	sf::Sprite m_background;

	ICharacter* testerDude;

	StateMachine* m_StateMachine;
};