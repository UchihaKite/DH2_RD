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

	m_player = new Player(); //Init our player

	//Testville USA ==================================================================================
	////==============================================================================================

	//Will want a different way to handle combat backgrounds etc... placeholder stuff
	m_background.setTexture(m_backgroundTex);
	m_background.setScale(1.0f, 1.15f);
	m_background.setPosition(0.f, 0.f);
	m_background.setOrigin(0.f, 0.f);

	//This will be shop functionality once they're created
	testerDude = CharacterCreator::getInstance().CreatePlayerCharacter();
	m_player->AddCharacter(testerDude);
	m_player->AddToParty(testerDude);

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
	m_player->DrawParty(Window);
}

void Engine::Update(sf::RenderWindow* Window, float DeltaTime)
{
	m_player->UpdateParty(Window, DeltaTime);
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