#include "MenuState.h"

MenuState::MenuState()
{
	window =  new sf::RenderWindow(sf::VideoMode(1920, 1080), "Tetris");

	this->backTexture.loadFromFile("res/Menu.jpg");
	this->background.setTexture(this->backTexture);

	this->font.loadFromFile("res/FONT.ttf");

	this->playText.setFont(this->font);
	this->playText.setString("Play");
	this->playText.setPosition(500, 470);
	this->playText.setCharacterSize(50);
	this->playText.setFillColor(sf::Color::White);

	this->quitTxt.setFont(this->font);
	this->quitTxt.setString("Quit");
	this->quitTxt.setPosition(500, 700);
	this->quitTxt.setCharacterSize(50);
	this->quitTxt.setFillColor(sf::Color::White);

	this->playShape.setFillColor(sf::Color(10, 10, 10, 220));
	this->playShape.setPosition(0, 400);
	this->playShape.setSize(sf::Vector2f(1080, 200));

	this->quitShape.setFillColor(sf::Color(10, 10, 10, 220));
	this->quitShape.setPosition(0, 650);
	this->quitShape.setSize(sf::Vector2f(1080, 200));
}

MenuState::~MenuState()
{
	delete this->window;
}

void MenuState::update()
{
	this->mousePosWindow = sf::Vector2f(sf::Mouse::getPosition(*window));
}

void MenuState::render()
{
	window->clear();
	window->draw(this->background);
	window->draw(this->playShape);
	window->draw(this->quitShape);
	window->draw(this->playText);
	window->draw(this->quitTxt);
	window->display();
}

int MenuState::changeState()
{
	if (this->quitShape.getGlobalBounds().contains(this->mousePosWindow) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		window->close();
		return 0;
	}
	if (this->playText.getGlobalBounds().contains(this->mousePosWindow) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		window->close();
		return 1;
	}

	return -1;
}
