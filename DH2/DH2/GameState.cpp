#include "GameState.h"

GameState::GameState(StateMachine* Machine) : State(Machine)
{
}


GameState::~GameState()
{
}

void GameState::Update(sf::RenderWindow* Window, float DeltaTime)
{
}

void GameState::Draw(sf::RenderWindow* Window)
{
}

void GameState::OnEnter()
{
}

void GameState::OnExit()
{
}