#pragma once
#include <SFML/Graphics.hpp>
class Engine
{
public:
	Engine();
	~Engine();

	void Draw(sf::RenderWindow* Window);
	void Update(sf::RenderWindow* Window, float DeltaTime); // Update Engine Internals

private:
	
};