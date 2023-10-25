#pragma once
#include"GameState.h"
#include"MenuState.h"

class Tetris
{
public:
	GameState* game;
	MenuState* menu;

	Tetris();
	~Tetris();

	void update();
};

