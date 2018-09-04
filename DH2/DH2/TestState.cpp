#include "TestState.h"
#include <iostream>

TestState::TestState(StateMachine* Machine) : GameState(Machine)
{
}


TestState::~TestState()
{
}

void TestState::Update(sf::RenderWindow* Window, float DeltaTime)
{
}

void TestState::Draw(sf::RenderWindow* Window)
{
}

void TestState::OnEnter()
{
	std::cout << "You are Entering the Test State. Eat a Taco!" << std::endl;
}

void TestState::OnExit()
{
}