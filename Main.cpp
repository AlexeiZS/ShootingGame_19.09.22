#include  <SFML/Graphics.hpp>
#include "Game.h"
#include "TextureHolder.h"


int main()
{
	Game game;
	game.run();
	










	/*sf::RenderWindow window(sf::VideoMode(640, 480), "SFML Aplication");
	sf::CircleShape shape;
	shape.setRadius(40.f);
	shape.setPosition(280.f, 200.f);
	shape.setFillColor(sf::Color::Cyan);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		window.draw(shape);
		window.display();
	}*/

	return 0;
}