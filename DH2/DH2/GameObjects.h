#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class GameObject
{
public:

	GameObject(sf::Vector2f pos, sf::Vector2f size);
	virtual void Draw(sf::RenderWindow* window);
	virtual void Update(sf::RenderWindow* window, float dt);

	//Getters
	sf::Vector2f GetPosition() { return m_pos; }
	sf::Vector2f GetSize() { return m_size; }

	//Setters
	void SetPosition(sf::Vector2f newPos) { m_pos = newPos; }
	void SetSize(sf::Vector2f newSize) { m_size = newSize; }

private:
	sf::Vector2f m_pos;
	sf::Vector2f m_size;
};
