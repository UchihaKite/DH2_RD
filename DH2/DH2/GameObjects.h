#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <vector>


class Engine;

class GameObject
{
public:

	GameObject(std::string texturePath, sf::Vector2f pos, sf::Vector2f size);
	virtual void Draw(sf::RenderWindow* window);
	virtual void Update(sf::RenderWindow* window, float dt);

	sf::Vector2f m_pos;
	sf::Vector2f m_size;

private:
	sf::Texture m_texture;
};
