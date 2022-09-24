#include "Game.h"

float Game::PlayerSpeed = 50.f;

Game::Game()
	:mWindow(sf::VideoMode(640, 480), "SFML Application")
	, mTexture(), mPlayer()
{
	if (!mTexture.loadFromFile("D:\\zimov\\C++\\ShootingGame_19.09.22\\pngegg.png"))
	{
		//Handle loading error
	}
	mPlayer.setTexture(mTexture);
	mPlayer.setPosition(100.f, 100.f);
}

//"D:\zimov\C++\ShootingGame_19.09.22\pngegg.png"
//основной (игровой) цикл
void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (mWindow.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			processEvents();
		    update(TimePerFrame);
		}

		render();
	}
}

//обрабатывает пользовательский ввод (событие)
void Game::processEvents()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::KeyPressed:
			handlePlayerInput(event.key.code, true);
			break;
		case sf::Event::KeyReleased :
			handlePlayerInput(event.key.code, false);
			break;
		case sf::Event::Closed :
			mWindow.close();
			break;
		}
	}
}

void Game::handlePlayerInput(sf::Keyboard::Key key,
	bool isPressed)
{
	if (key == sf::Keyboard::W)
	     mIsMovingUp = isPressed;
	else if (key == sf::Keyboard::S)
		 mIsMovingDown = isPressed;
	else if (key == sf::Keyboard::A)
		 mIsMovingLeft = isPressed;
	else if (key == sf::Keyboard::D)
		 mIsMovingRight = isPressed;
}

//обновляет игровую логику
void Game::update(sf::Time deltaTime)
{
	sf::Vector2f movement(0.f, 0.f);
	if (mIsMovingUp)
		movement.y -= PlayerSpeed;
	if (mIsMovingDown)
		movement.y += PlayerSpeed;
	if (mIsMovingLeft)
		movement.x -= PlayerSpeed;
	if (mIsMovingRight)
		movement.x += PlayerSpeed;
	mPlayer.move(movement * deltaTime.asSeconds());
}

//выводит игру на экран
void Game::render()
{
	mWindow.clear();
	mWindow.draw(mPlayer);
	mWindow.display();
}







//sf::Texture texture;
//if (!texture.loadfromfile("path/to/file.png"))
//{
//	//Handle loading error
//}
//sf::Sprite sprite(texture);
//sprite.setPosition(100.f, 100.f);
//window.clear();
//window.draw(sprite);
//window.display();
