#pragma once
#include <SFML/Graphics.hpp>
#include "ICharacter.h"

class Engine
{
public:
	Engine();
	~Engine();

	void Draw(sf::RenderWindow* Window);
	void Update(sf::RenderWindow* Window, float DeltaTime); // Update Engine Internals

private:
	
	sf::Texture m_backgroundTex;
	sf::Sprite m_background;

	ICharacter* testerDude;
};