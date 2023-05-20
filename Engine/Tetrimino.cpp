#include "Tetrimino.h"


Tetrimino::Tetrimino(Location in_locCell[4], Color in_c)
{
	for (int i = 0; i < 4; ++i)
		locCell[i] = in_locCell[i];
	
	c = in_c;
}

void Tetrimino::Draw(Grid& grid)
{
	for (int i = 0; i < 4; ++i)
		grid.DrawCell(locCell[i], c, Colors::White);
}


void Tetrimino::Move(Keyboard& kbd, Grid& grid, int speedY)
{
	for (int i = 0; i < 4; ++i)
		locCell[i].y += speedY;

	if (kbd.KeyIsPressed(VK_LEFT))
	{
		for (int i = 0; i < 4; ++i)
			locCell[i].x -= 1;
	}

	else if (kbd.KeyIsPressed(VK_RIGHT))
	{
		for (int i = 0; i < 4; ++i)
			locCell[i].x += 1;
	}

	if (kbd.KeyIsPressed(VK_DOWN))
	{
		for (int i = 0; i < 4; ++i)
			locCell[i].y += 1;
	}



}

