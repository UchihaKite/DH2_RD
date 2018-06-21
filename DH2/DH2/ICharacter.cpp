#include "ICharacter.h"

ICharacter::ICharacter(std::string FileLocation, sf::Vector2f pos, sf::Vector2f size) : GameObject(pos, size)
{
	m_Name = "BaseCharacter"; //Make a randomizer or let the Player type their desired name
	//m_Class = new Warrior();

	m_animator = new AnimationManager(FileLocation, sf::Vector2f(2.0f, 2.0f), pos, sf::Vector2f(0.f, 0.f));

	//All characters will start with a 5 base for regular stats and 20 health.
	//Their class will modify these stats, but the player will get to modify the base stats on level up
	m_Strength = new Stat("Strength", 5, 5);
	m_Defense = new Stat("Defense", 5, 5);
	m_Dexterity = new Stat("Dexterity", 5, 5);
	m_Magic = new Stat("Magic", 5, 5);
	m_Health = new Stat("Health", 20, 20);
	m_Exp = new Stat("Exp", 0, 100);
	m_Level = new Stat("Level", 1, 100);
}


ICharacter::~ICharacter()
{
	delete m_Strength;
	delete m_Defense;
	delete m_Dexterity;
	delete m_Magic;
	delete m_Health;
	delete m_Exp;
	delete m_Level;
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

void ICharacter::Attack()
{
	//Will Probably make an interface for skills, Actions/Reactions
	//Placing these as examples, but we might not want the character to care about anything other than holding stats
	//We want it plain enough for skill/class etc swapping if we so choose to implement
}

void ICharacter::Defend()
{
	//Will Probably make an interface for skills, Actions/Reactions
	//Placing these as examples, but we might not want the character to care about anything other than holding stats
	//We want it plain enough for skill/class etc swapping if we so choose to implement
}

void ICharacter::UseItem()
{
	//Will Probably make an interface for skills, Actions/Reactions
	//Placing these as examples, but we might not want the character to care about anything other than holding stats
	//We want it plain enough for skill/class etc swapping if we so choose to implement
}

void ICharacter::GainExperience(float earnedXp)
{
	//We need to account for if earnedXp goes above the cap,
	//Right now the Stat class will keep current at max if it tries to go over
	//So we'll subtract Max from Current and check it to earned xp and save off overflow to apply on the exp reset
	m_Exp->AddCurrent(earnedXp);

	if (m_Exp->GetCurrent() == m_Exp->GetMax())
	{
		//We've hit the cap, lets reset the exp and gain our level
		m_Level->AddCurrent(1.0f);
		m_Exp->SetCurrent(0.0f);
		m_Exp->SetMax(m_Exp->GetMax() + 50.0f); // Setting to go up by 50, we can balance it later
		LevelUp();
	}
}

void ICharacter::LevelUp()
{
	//Idea here is to get stat points to place into base stats, where it can be stored off
	//Then the player can assign them in some kinda level up page we would pop up here, or can save them for mass assigning later
	//Anything that can be applied to all types of characters can be applied here and called from the child
}