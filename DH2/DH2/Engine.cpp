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

	//Testville USA ==================================================================================
	////==============================================================================================

	testerDude = CharacterCreator::getInstance().CreatePlayerCharacter();

	testerDude->PrintStats(); //Check to see if the new class is set right (working = traveler, not = newcomer)

	testerDude->m_animator->SetSheetPosition(sf::Vector2i(96, 0));
	testerDude->m_animator->SetAnimationLength(4);
	testerDude->m_animator->SetAnimationCap(4);
	testerDude->m_animator->SetUpFrames(AnimationType::IDLE);
	testerDude->m_animator->AnimationControl(true);
	////==============================================================================================
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
	testerDude->m_animator->PlayAnimation(AnimationType::IDLE, DeltaTime);
}