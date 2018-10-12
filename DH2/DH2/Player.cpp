#include "Player.h"



Player::Player() : m_Gold(500)
{
	bShouldDrawParty = true; //Kinda dirtay, but we can flip this on and off when characters are going to be seen, that way we're not animating needlessly
}


Player::~Player()
{
}

void Player::DrawParty(sf::RenderWindow * window)
{
	for (unsigned int i = 0; i < m_CurrentParty.size(); i++)
	{
		if (bShouldDrawParty)
		{
			m_CurrentParty[i]->Draw(window);
		}
	}
}

void Player::UpdateParty(sf::RenderWindow* window, float dt)
{
	for (unsigned int i = 0; i < m_CurrentParty.size(); i++)
	{
		PlayerCharacter* current = m_CurrentParty[i];

		current->Update(window, dt);

		if (bShouldDrawParty)
		{
			current->m_animator->PlayAnimation(current->GetCurrentAnimationType(), dt);
		}
	}
}

void Player::AddCharacter(PlayerCharacter* Character)
{
	m_AvailableCharacters.push_back(Character);
}

void Player::AddToParty(PlayerCharacter* Character)
{
	m_CurrentParty.push_back(Character);
}

void Player::RemoveFromParty(PlayerCharacter* Character)
{
	for (unsigned int i = 0; i < m_CurrentParty.size(); i++)
	{
		if (m_CurrentParty[i] == Character)
		{
			m_CurrentParty.erase(m_CurrentParty.begin() + i); //Test this, it might need to be i - 1 to get the right index.
		}
	}
}

void Player::RemoveFromCharacterList(PlayerCharacter* Character)
{
	for (unsigned int i = 0; i < m_AvailableCharacters.size(); i++)
	{
		if (m_AvailableCharacters[i] == Character)
		{
			m_AvailableCharacters.erase(m_AvailableCharacters.begin() + i); //Test this, it might need to be i - 1 to get the right index.
		}
	}
}
