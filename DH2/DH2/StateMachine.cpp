#include "StateMachine.h"

StateMachine::StateMachine() : m_CurrentState(new State(this))
{
	m_States = std::map<std::string, State*>();
	m_StateStack = std::vector<State*>();
}

void StateMachine::Update(sf::RenderWindow* Window, float DeltaTime)
{
	m_CurrentState->Update(Window, DeltaTime);
}

void StateMachine::Draw(sf::RenderWindow* Window)
{
	m_CurrentState->Draw(Window);
}

void StateMachine::ChangeState(std::string StateName)
{
	m_CurrentState->OnExit();
	m_CurrentState = m_States[StateName];
	m_CurrentState->OnEnter();
}

void StateMachine::AddState(std::string StateName, State* State)
{
	m_States[StateName] = State;
}

void StateMachine::PushState(std::string Name)
{
	State* s_State = m_States[Name];
	m_StateStack.push_back(s_State);
}

void StateMachine::PopState()
{
	return m_StateStack.pop_back();
}