#include "Engine.h"
#include "TestState.h"
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

	// For Testing StateMachine
	m_StateMachine = new StateMachine();
	StateSetUp(); // Setup Our States
	m_StateMachine->ChangeState("TestState");
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

void Engine::StateSetUp()
{
	/*
	Set up all the Necessary States for the Game StateMachine.
	May need another Function to Implement a Stack for the Purpose of Pausing (etc).
	^ Unless a better way is found.

	Feel free to add comments, as necessary, for all upcoming states.

	Future States that Inherit from Gamestate will Require a Reference to StateMachine and
	possibly the Engine.
	*/

	m_StateMachine->AddState("TestState", new TestState(m_StateMachine)); // Only for Testing Purposes
}