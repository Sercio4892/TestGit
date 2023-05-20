/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	rgbDist(0, 255),
	grid(gfx, 
		10, 15, 
		2, {50*2, 50},
		30, 30, 1),
	gridNextPuzzle(gfx,
		4, 4,
		2, { 50 * 11, 80 },
		30, 30, 1),
	gridScore(gfx,
		10, 7,
		2, { 50 * 11, 90*3 },
		8, 8, 1)
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
}

void Game::ComposeFrame()
{

	grid.DrawBorder(Colors::Cyan);
	gridNextPuzzle.DrawBorder(Colors::Cyan);
	gridScore.DrawBorder(Colors::Cyan);

	for (int j = 0; j < grid.GetHeight(); ++j)
	{
		for (int i = 0; i < grid.GetWidth(); ++i)
		{
			grid.DrawCell({ i, j }, Colors::MakeRGB(rgbDist(rng), rgbDist(rng), rgbDist(rng)), Colors::Black);
		}
	}

	for (int j = 0; j < gridNextPuzzle.GetHeight(); ++j)
	{
		for (int i = 0; i < gridNextPuzzle.GetWidth(); ++i)
		{
			gridNextPuzzle.DrawCell({ i, j }, Colors::Black, Colors::White);
		}
	}

	for (int j = 0; j < gridScore.GetHeight(); ++j)
	{
		for (int i = 0; i < gridScore.GetWidth(); ++i)
		{
			gridScore.DrawCell({ i, j }, Colors::Black, Colors::White);
		}
	}

	//grid.DrawCell({ 0, 0 }, Colors::White, Colors::Black);
	//grid.DrawCell({ grid.GetWidth() - 1, 0}, Colors::White, Colors::Black);
	//grid.DrawCell({ 0, grid.GetHeight() - 1 }, Colors::White, Colors::Black);
	//grid.DrawCell({ grid.GetWidth() - 1, grid.GetHeight() - 1 }, Colors::White, Colors::Black);
}
