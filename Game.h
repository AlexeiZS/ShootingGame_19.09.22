#pragma once
#include <SFML/Graphics.hpp>

class Game
{
public:
	Game();
	void run();                                 //запуск
	static float PlayerSpeed;                   //скорость игрока

private:
	void processEvents();                       //события процесса
	void handlePlayerInput(sf::Keyboard::Key key,
		bool isPressed);                        //обработчик ввода
	void update(sf::Time deltaTime);            //обновления
	void render();                              //рендеринг

private:
	sf::RenderWindow mWindow;

	sf::Texture mTexture;
	sf::Sprite mPlayer;

    sf::Time TimePerFrame = sf:: seconds(1.f / 60.f);
	bool mIsMovingUp;
	bool mIsMovingDown;
	bool mIsMovingLeft;
	bool mIsMovingRight;
};

