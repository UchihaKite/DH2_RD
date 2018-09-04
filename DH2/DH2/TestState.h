#pragma once
#include "GameState.h"

class TestState : public GameState
{
public:
	TestState(StateMachine* Machine);
	~TestState();

	void Update(sf::RenderWindow* Window, float DeltaTime);
	void Draw(sf::RenderWindow* Window);
	void OnEnter();
	void OnExit();
private:

};