#pragma once
#include"includer.h"


class tetris {
public:
	sf::Sprite sprite[4];


	tetris(sf::Sprite sprite,int type,int x,int y,int width,int height)
	{
		if (type == 1)
		{
			this->sprite[0] = sprite;
			this->sprite[0].setTextureRect(sf::IntRect(x,y,20,20));
			this->sprite[1] = sprite;
			this->sprite[1].setTextureRect(sf::IntRect(x, y, 20, 20));
			this->sprite[1].setPosition(this->sprite[0].getPosition().x, this->sprite[0].getPosition().y + 20);
			this->sprite[2] = sprite;
			this->sprite[2].setTextureRect(sf::IntRect(x, y, 20, 20));
			this->sprite[2].setPosition(this->sprite[1].getPosition().x, this->sprite[1].getPosition().y + 20);
			this->sprite[3] = sprite;
			this->sprite[3].setTextureRect(sf::IntRect(x, y, 20, 20));
			this->sprite[3].setPosition(this->sprite[2].getPosition().x, this->sprite[2].getPosition().y + 20);
		}
		if (type == 2)
		{
			this->sprite[0] = sprite;
			this->sprite[0].setTextureRect(sf::IntRect(x, y, 20, 20));
			this->sprite[1] = sprite;
			this->sprite[1].setTextureRect(sf::IntRect(x, y, 20, 20));
			this->sprite[1].setPosition(this->sprite[0].getPosition().x, this->sprite[0].getPosition().y + 20);
			this->sprite[2] = sprite;
			this->sprite[2].setTextureRect(sf::IntRect(x, y , 20, 20));
			this->sprite[2].setPosition(this->sprite[1].getPosition().x+20, this->sprite[1].getPosition().y);
			this->sprite[3] = sprite;
			this->sprite[3].setTextureRect(sf::IntRect(x, y, 20, 20));
			this->sprite[3].setPosition(this->sprite[2].getPosition().x, this->sprite[2].getPosition().y - 20);
		}
		if (type == 3)
		{
			this->sprite[0] = sprite;
			this->sprite[0].setTextureRect(sf::IntRect(x, y, 20, 20));
			this->sprite[1] = sprite;
			this->sprite[1].setTextureRect(sf::IntRect(x, y , 20, 20));
			this->sprite[1].setPosition(this->sprite[0].getPosition().x, this->sprite[0].getPosition().y + 20);
			this->sprite[2] = sprite;
			this->sprite[2].setTextureRect(sf::IntRect(x, y , 20, 20));
			this->sprite[2].setPosition(this->sprite[1].getPosition().x, this->sprite[1].getPosition().y + 20);
			this->sprite[3] = sprite;
			this->sprite[3].setTextureRect(sf::IntRect(x, y , 20, 20));
			this->sprite[3].setPosition(this->sprite[1].getPosition().x+20, this->sprite[1].getPosition().y);
		}
		if (type == 4)
		{
			this->sprite[0] = sprite;
			this->sprite[0].setTextureRect(sf::IntRect(x, y, 20, 20));
			this->sprite[1] = sprite;
			this->sprite[1].setTextureRect(sf::IntRect(x, y , 20, 20));
			this->sprite[1].setPosition(this->sprite[0].getPosition().x, this->sprite[0].getPosition().y + 20);
			this->sprite[2] = sprite;
			this->sprite[2].setTextureRect(sf::IntRect(x, y , 20, 20));
			this->sprite[2].setPosition(this->sprite[1].getPosition().x, this->sprite[1].getPosition().y + 20);
			this->sprite[3] = sprite;
			this->sprite[3].setTextureRect(sf::IntRect(x, y , 20, 20));
			this->sprite[3].setPosition(this->sprite[2].getPosition().x +20, this->sprite[2].getPosition().y);
		}
	}

	int getSpriteX(int x)
	{
		return this->sprite[x].getPosition().x / 20;
	}
	int getSpriteY(int x)
	{
		return this->sprite[x].getPosition().y / 20;
	}
};

class GameState
{
public:
	int a;
	sf::RenderWindow* window;
	float keyTime;
	float keyTimemax;
	sf::Clock clock;
	sf::Texture texture;
	sf::Sprite sprite;
	float dt;
	std::vector<tetris*> sprites;
	float timer;
	float dx, dy;
	sf::RectangleShape shape;

	GameState();
	~GameState();

	void update();
	void render();
	void updateKeyTime();
	bool getKeyTime();
	void updateInputs();
	bool isCollide();
	sf::IntRect getRandomPrimitive();
	void cleanRow();
	bool isGameEnd();

};

