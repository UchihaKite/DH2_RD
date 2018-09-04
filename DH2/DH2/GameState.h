#pragma once
#include "State.h"

class GameState : public State
{
public:
	GameState(StateMachine* Machine);
	~GameState();

	virtual void Update(sf::RenderWindow* Window, float DeltaTime);
	virtual void Draw(sf::RenderWindow* Window);
	virtual void OnEnter(); // Behavior performed as state takes focus
	virtual void OnExit(); // Cleanup behavior or anything else needed before a state change
protected:
};