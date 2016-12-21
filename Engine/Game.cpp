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
#include "SpriteCodex.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	board(gfx, BOARD_SIZE),
	rng((unsigned int)time(0)),
	snake({ 40,30 }),
	goal(rng, board, snake, BOARD_SIZE)
	
	
	
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
	if (!gameIsOver)
	{
		if (wnd.kbd.KeyIsPressed(VK_UP)) { delta_location = { 0,-1 }; }
		else if (wnd.kbd.KeyIsPressed(VK_DOWN)) { delta_location = { 0, 1 }; }
		else if (wnd.kbd.KeyIsPressed(VK_LEFT)) { delta_location = { -1, 0 }; }
		else if (wnd.kbd.KeyIsPressed(VK_RIGHT)) { delta_location = { 1, 0 }; }

		++_snakeMoveCounter;
		if (_snakeMoveCounter > SNAKE_MOVE_RATE)
		{

			_snakeMoveCounter = 0;
			const Location next = snake.getNextHeadPos(delta_location);
			if (!board.isInsideBoard(next) || snake.isInTileExceptEnd(next)) { gameIsOver = true; }
			else
			{
				const bool eating = next ==  goal.getLocation();
				if (eating)
				{
					snake.grow();
					
				}
				snake.moveBy(delta_location);
				if(eating) { goal.respawn(rng,board, snake, BOARD_SIZE); }
				
			}
		}
	}
}

void Game::ComposeFrame()
{
	
	snake.draw(board);
	goal.draw(board);
	if (gameIsOver) { SpriteCodex::DrawGameOver(200, 200, gfx); }
}
