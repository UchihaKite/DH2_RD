#include "ICharacter.h"

ICharacter::ICharacter(std::string FileLocation, sf::Vector2f pos, sf::Vector2f size) : GameObject(pos, size)
{
	m_Name = "BaseCharacter"; //Make a randomizer or let the Player type their desired name

	m_animator = new AnimationManager(FileLocation, sf::Vector2f(2.0f, 2.0f), pos, sf::Vector2f(0.f, 0.f));

	m_stats = 
	{
		{"Strength", Stat(5,5)},
		{ "Defense", Stat(5,5) },
		{ "Dexterity", Stat(5,5) },
		{ "Magic", Stat(5,5) },
		{ "Health", Stat(20,20) },
		{ "Exp", Stat(0,100) },
		{ "Level", Stat(1,100) }
	};
}


ICharacter::~ICharacter()
{
	m_stats.clear();
	delete m_animator;
}

void ICharacter::Draw(sf::RenderWindow * window)
{
	m_animator->Draw(window);
}

void ICharacter::Update(sf::RenderWindow * window, float dt)
{
	m_animator->Update(dt);
}

float ICharacter::GetCurrentStat(std::string desiredStat)
{
	return m_stats.find(desiredStat)->second.GetCurrent();
}

float ICharacter::GetMaxStat(std::string desiredStat)
{
	return m_stats.find(desiredStat)->second.GetMax();
}

Stat* ICharacter::GetStat(std::string desiredStat)
{
	return &m_stats.find(desiredStat)->second;
}

void ICharacter::SetCurrentStat(std::string desiredStat, float desiredValue)
{
	if (desiredValue < 0)
		return;

	m_stats.find(desiredStat)->second.SetCurrent(desiredValue);
}

void ICharacter::SetMaxStat(std::string desiredStat, float desiredValue)
{
	if (desiredValue < 0)
		return;

	m_stats.find(desiredStat)->second.SetMax(desiredValue);
}

void ICharacter::TakeDamage(float dmg)
{
	GetStat("Health")->SubtractCurrent(dmg);

	if (GetCurrentStat("Health") <= 0.f) //Stat should Clamp to 0 but to be sure
	{
		Die();
	}
}

void ICharacter::Die()
{
	//If we drop to 0, kill this fucker
	delete this; // probably shouldn't do it like this haha thug life
}