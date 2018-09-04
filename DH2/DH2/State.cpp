#include "State.h"

State::State(StateMachine* Machine) : m_Machine(Machine)
{
	//No behavior for base state
}

void State::Update(sf::RenderWindow* Window, float DeltaTime)
{
	//No behavior for base state
}

void State::Draw(sf::RenderWindow* Window)
{
	//No behavior for base state
}

void State::OnEnter()
{
	//No behavior for base state
}

void State::OnExit()
{
	//No behavior for base state
}