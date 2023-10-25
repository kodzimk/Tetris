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
    this->dy = 0.05f;
    window = new sf::RenderWindow(sf::VideoMode(240, 400), "Tetris");
    this->shape.setSize(sf::Vector2f(240, 10)); this->shape.setPosition(0, 400);
    this->shape.setFillColor(sf::Color::White);
    this->sprites.push_back(new tetris(this->sprite,1,45,20,25,80)); 
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
        for(int i = 0;i<4;i++)
           this->sprites[this->sprites.size()-1]->sprite[i].move(dx, dy);
    }
    else
    {
        this->cleanRow();
    }

    if (this->timer <= 0.f)
    {        
       
        sf::IntRect rect = this->getRandomPrimitive();
        if (a > 0 && a < 5)
        {
            sprite.setPosition(0, 0);
            sprite.setTextureRect(this->getRandomPrimitive());
            this->timer = 5.f;
            this->sprites.push_back(new tetris(this->sprite, this->a, rect.left, rect.top, rect.width, rect.height));
        }
    }
 
    dx = 0;
}

void GameState::render()
{
    window->clear();
    for (int i = 0; i < this->sprites.size(); i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
                window->draw(this->sprites[i]->sprite[j]);
            
        }
    }
    window->draw(this->shape);
    window->display();
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
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                if ((this->sprites[i]->sprite[j].getPosition().x/20)==(this->sprites[this->sprites.size()-1]->sprite[k].getPosition().x/20)&&
                    this->sprites[i]->sprite[j].getGlobalBounds().intersects(this->sprites[this->sprites.size()-1]->sprite[k].getGlobalBounds()))
                {
                    return false;
                }
            }
        }
    }

    for (size_t i = 0; i < 4; i++)
    {
        if (this->shape.getGlobalBounds().intersects(this->sprites[this->sprites.size() - 1]->sprite[i].getGlobalBounds())) {
            return false;
        }
    }

    return true;
}

sf::IntRect GameState::getRandomPrimitive()
{
    sf::IntRect rect;
    int x, y, width, height;

     a = rand() % 5;

   
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
    else if (a == 4)
    {
        rect.left = 150;
        rect.top = 20;
        rect.height = 60;
        rect.width = 40;
      
    }

    return rect;
}

void GameState::cleanRow()
{
    int count1 = 0,count2=0;

    for (int i = 0; i < this->sprites.size(); i++)
    {
        for (int j = 0; j < 4; j++)
        {
           
            if (this->sprites[i]->getSpriteY(j) == 19)
            {
                count1++;
            }
            if (this->sprites[i]->getSpriteY(j) == 18)
            {
                count2++;
            }
        }
    }

    if (count1 == 12)
    {
        for (int i = 0; i < this->sprites.size(); i++)
        {
            for (int j = 0; j < 4; j++) {
                if (this->sprites[i]->getSpriteY(j) < 19)
                {
                    this->sprites[i]->sprite[j].setPosition(this->sprites[i]->sprite[j].getPosition().x, this->sprites[i]->sprite[j].getPosition().y + 20);
                }
            }
        }

        for (size_t i = 0; i < this->sprites.size(); i++)
        {
            for (int j = 0; j < 4; j++) {
                if (this->sprites[i]->getSpriteY(j) == 19)
                {
                    this->sprites[i]->sprite->setScale(0, 0);
                }
            }
        }
    }
    if (count2 == 12)
    {
        for (int i = 0; i < this->sprites.size(); i++)
        {
            for (int j = 0; j < 4; j++) {
                if (this->sprites[i]->getSpriteY(j) < 18)
                {
                    this->sprites[i]->sprite[j].setPosition(this->sprites[i]->sprite[j].getPosition().x, this->sprites[i]->sprite[j].getPosition().y + 20);
                }
            }
        }

        for (size_t i = 0; i < this->sprites.size(); i++)
        {
            for (int j = 0; j < 4; j++) {
                if (this->sprites[i]->getSpriteY(j) == 18)
                {
                    this->sprites[i]->sprite->setScale(0, 0);
                }
            }
        }
    }
}

bool GameState::isGameEnd()
{
    for (int i = 0; i < this->sprites.size(); i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (!this->isCollide() &&this->sprites[i]->getSpriteY(j) < 2)
            {
                window->close();
                return true;
            }
        }
    }
    return false;
}

