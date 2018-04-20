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
	ball(Vec2(400.0f,300.0f)),
	paddle(Vec2(400.0f,530.0f))
{
	Vec2 origin = { 20.0f,20.0f };
	int i = 0;
	for (int y = 0; y < bricksDown; ++y)
	{
		for (int x = 0; x < bricksAcross; ++x)
		{
			bricks[i] = Brick(Vec2(origin.x + x * (81.0f), origin.y + y * (25.0f)), Colors::Red);
			i++;
		}
				
	}
}

void Game::Go()
{
	gfx.BeginFrame();	
	float elapsedTime = ft.Mark();
	while (elapsedTime > 0.0f)
	{
		const float dt = std::min(0.0005f, elapsedTime);
		UpdateModel(dt);
		elapsedTime -= dt;
	}
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel(float dt)
{
	ball.Update(paddle.rect,dt);
	paddle.Update(wnd.kbd, dt);
	bool hasChangedVel = false;
	ball.IsColliding(paddle.rect, false);
	for (Brick& b : bricks)
	{
		if (!b.destroyed)
		{
			b.destroyed = ball.IsColliding(b.rect,hasChangedVel);
			if (b.destroyed)
			{
				hasChangedVel = true;
			}
		}
	} 
}

void Game::ComposeFrame()
{
	for (Brick& b: bricks)
	{
		if (!b.destroyed)
		{
			b.Draw(gfx);
		}
	} 
	paddle.Draw(gfx);
	ball.Draw(gfx);
}
