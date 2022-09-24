#pragma once
#include <SFML/Graphics.hpp>

class Game
{
public:
	Game();
	void run();                                 //������
	static float PlayerSpeed;                   //�������� ������

private:
	void processEvents();                       //������� ��������
	void handlePlayerInput(sf::Keyboard::Key key,
		bool isPressed);                        //���������� �����
	void update(sf::Time deltaTime);            //����������
	void render();                              //���������

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

