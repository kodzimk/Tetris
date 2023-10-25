#include "Tetris.h"

Tetris::Tetris()
{
	menu = new MenuState();
}

Tetris::~Tetris()
{
	delete this->menu;
	delete this->game;
}

void Tetris::update()
{
	while (game != nullptr || menu!= nullptr)
	{
		if (game != nullptr)
		{
			game->update();
			game->render();
			if (game->changeState() == 1)
			{
				game = nullptr;
				menu = new MenuState();
			}
			else if(game->changeState() == 0)
			{
				game = nullptr;
			}
		}
		else if (menu != nullptr)
		{
			menu->update();
			menu->render();
			if (menu->changeState() == 1)
			{
				menu = nullptr;
				game = new GameState();
			}
			else if(menu->changeState() == 0)
			{
				menu = nullptr;
			}
		}
	}
}
