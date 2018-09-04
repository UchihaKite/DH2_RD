#pragma once
#include "SFML\Graphics.hpp"

class StateMachine; // Forward Dec.

class State
{
public:
	State(StateMachine* Machine);

	virtual void Update(sf::RenderWindow* Window, float DeltaTime);
	virtual void Draw(sf::RenderWindow* Window);
	virtual void OnEnter(); // Behavior performed as State is Entered
	virtual void OnExit(); // Cleanup behavior or anything else needed before a state change

protected:
	StateMachine * m_Machine;
};