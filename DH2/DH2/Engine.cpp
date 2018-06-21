#include "Engine.h"
#include <iostream>

Engine::Engine()
{
	if (!m_backgroundTex.loadFromFile("Sprites/BattleBackground.png"))
	{
		// If for whatever reason it fails to load
		std::cout << "Error loading background sprite" << std::endl;
	}

	m_background.setTexture(m_backgroundTex);
	m_background.setScale(1.0f, 1.15f);
	m_background.setPosition(0.f, 0.f);
	m_background.setOrigin(0.f, 0.f);

	testerDude = new ICharacter("Sprites/Characters/AdamShield.png", sf::Vector2f(200.f, 200.f), sf::Vector2f(2.0f, 2.0f));
}

Engine::~Engine()
{
}

void Engine::Draw(sf::RenderWindow* Window)
{
	
	Window->draw(m_background);
	testerDude->Draw(Window);
}

void Engine::Update(sf::RenderWindow* Window, float DeltaTime)
{
}