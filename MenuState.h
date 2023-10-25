#pragma once
#include"includer.h"

class MenuState
{
public:
	sf::RenderWindow* window;
	sf::Vector2f mousePosWindow;
	sf::Sprite background;
	sf::Texture backTexture;
	sf::Font font;
	sf::Text playText;
	sf::Text quitTxt;
	sf::RectangleShape playShape;
	sf::RectangleShape quitShape;

	MenuState();
	~MenuState();

	void update();
	void render();
	int changeState();
};

