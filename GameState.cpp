#include "GameState.h"

GameState::GameState()
{
    this->keyTime = 0.f;
    this->keyTimemax = 10.f;
    this->dt = 0.f;
    this->texture.loadFromFile("res/WALLSS.png");
    this->sprite.setTexture(this->texture);
    this->sprite.setTextureRect(sf::IntRect(45,20, 25, 80));
    this->timer = 5.f;
    this->dx = 0.f;
    this->dy = 0.08f;
    window = new sf::RenderWindow(sf::VideoMode(240, 400), "Tetris");
    this->shape.setSize(sf::Vector2f(240, 10)); this->shape.setPosition(0, 400);
    this->shape.setFillColor(sf::Color::Black);
    this->sprites.push_back(this->sprite); 
}

GameState::~GameState()
{
    delete this->window;
}

void GameState::update()
{
    this->dt = clock.restart().asSeconds();
    this->updateKeyTime();

    this->timer -= this->dt;
    this->updateInputs();

    if (this->isCollide())
    {
       this->sprites[this->sprites.size()-1].move(dx, dy);
    }

    if (this->timer <= 0.f)
    {        
        sprite.setPosition(0,0);
        sprite.setTextureRect(this->getRandomPrimitive());
        this->timer = 5.f;
        this->sprites.push_back(this->sprite);
    }
   
    dx = 0;
}

void GameState::render()
{
    window->clear();
    for (int i = 0; i < this->sprites.size(); i++)
    {
        window->draw(this->sprites[i]);
    }
    window->draw(this->shape);
    window->display();
}

int GameState::changeState()
{
    return -1;
}

void GameState::updateKeyTime()
{
    if (this->keyTime < this->keyTimemax)
        this->keyTime += 100.f * this->dt;
}

bool GameState::getKeyTime()
{
    if (this->keyTime > this->keyTimemax)
    {
        this->keyTime = 0.f;
        return true;
    }
    return false;
}

void GameState::updateInputs()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && this->getKeyTime())
    {
        dx = -20;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && this->getKeyTime())
    {
        dx = 20;
    }
}

bool GameState::isCollide()
{
    for (int i = 0; i < this->sprites.size() - 1; i++)
    {
        if ((this->sprites[i].getPosition().x / 20) == (this->sprites[this->sprites.size()-1].getPosition().x /20)&&  
            this->sprites[i].getGlobalBounds().intersects(this->sprites[this->sprites.size() - 1].getGlobalBounds()))
        {
            return false;
        }
    }

    if (this->shape.getGlobalBounds().intersects(this->sprites[this->sprites.size() - 1].getGlobalBounds()))
        return false;

    return true;
}

sf::IntRect GameState::getRandomPrimitive()
{
    sf::IntRect rect;
    int x, y, width, height;
    int a = rand() % 4;

    if (a == 1)
    {
        rect.height = 80;
        rect.width = 25;
        rect.top = 20;
        rect.left = 45;
    }
    else if (a == 2)
    {
        rect.left = 90;
        rect.top = 20;
        rect.height = 40;
        rect.width = 40;
    }
    else if (a == 3)
    {
        rect.left = 210;
        rect.top = 20;
        rect.height = 60;
        rect.width = 40;
    }

    return rect;
}
