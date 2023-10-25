#pragma once
#include"includer.h"

class GameState
{
public:
	sf::RenderWindow* window;
	float keyTime;
	float keyTimemax;
	sf::Clock clock;
	sf::Texture texture;
	sf::Sprite sprite;
	float dt;
	std::vector<sf::Sprite> sprites;
	float timer;
	float dx, dy;
	sf::RectangleShape shape;

	GameState();
	~GameState();

	void update();
	void render();
	int changeState();
	void updateKeyTime();
	bool getKeyTime();
	void updateInputs();
	bool isCollide();
	sf::IntRect getRandomPrimitive();

};

