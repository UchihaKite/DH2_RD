
#include "GameObjects.h"
#include <iostream>


GameObject::GameObject(std::string texturePath, sf::Vector2f pos, sf::Vector2f size) 
	:m_pos(pos), m_size(size)
{
	
}

void GameObject::Draw(sf::RenderWindow * window)
{
}

void GameObject::Update(sf::RenderWindow * window, float dt)
{
}