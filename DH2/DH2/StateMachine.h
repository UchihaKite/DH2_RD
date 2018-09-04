#pragma once
#include "State.h"
#include <vector>
#include <map>

/*
	Implemented to Take in States with a String Identifier
	Uses a Vector for Popping Irrelevant States
*/

class StateMachine
{
public:
	StateMachine();

	void Update(sf::RenderWindow* Window, float DeltaTime);
	void Draw(sf::RenderWindow* Window);

	//Add states to the machine
	void ChangeState(std::string StateName);
	void AddState(std::string StateName, State* State);

	//Add states to the stack
	void PushState(std::string Name);
	void PopState();
private:
	State * m_CurrentState; //Mark current state for updates and renders
	std::map<std::string, State*> m_States; // Map of all states and their identifier
	std::vector<State*> m_StateStack; //Stack for pushing in new states
};