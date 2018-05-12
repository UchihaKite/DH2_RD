#include "Engine.h"

#define WindowRes_X 1028
#define WindowRes_Y 720

int main()
{
	sf::RenderWindow Window(sf::VideoMode(WindowRes_X, WindowRes_Y), "DH2 Part 2");
	Engine s_Engine;

	sf::Clock s_Clock;
	while (Window.isOpen())
	{
		sf::Time s_Time = s_Clock.restart();
		float DeltaTimeAsSeconds = s_Time.asSeconds();

		sf::Event s_Event;
		while (Window.pollEvent(s_Event))
		{
			if (s_Event.type == sf::Event::KeyPressed)
			{
				if (s_Event.key.code == sf::Keyboard::Escape)
				{
					Window.close();
				}
			}
			if (s_Event.type == sf::Event::Closed)
			{
				Window.close();
			}
		}

		Window.clear();
		s_Engine.Update(&Window, DeltaTimeAsSeconds);
		s_Engine.Draw(&Window);
		Window.display();
	}

	return 0;
}