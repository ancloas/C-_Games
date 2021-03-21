/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
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
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"

class poo {
public: 
	//member functions
    poo(int X, int Y, int vx, int vy);
	poo();
	void draw(Graphics & gfx);
	void colloide_boundaries(Graphics & gfx);
	void calculate_pos(Graphics &gfx);
 	//member variables
	int x;
	int y;
	int dx;
	int dy;
	bool isEaten=false;
	static const int width = 24;
	static const int height = 24;
	 
};
class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	void drawFace(int x, int y);
	void drawPoo(int x, int y);
	int clampScreenX(int x, int width);
	int clampScreenY(int y, int hight);
	bool IsColliding(int x0, int y0, int width0, int height0, 
		int x1, int y1, int width1, int height1);
	void DrawGameOver(int x, int y);
	void DrawTitleScreen(int x, int y);
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	int dudeX = 400;
	int dudeY=300;
	int dudewidth = 20;
	int dudehight = 20;
	poo poo0;
	poo poo1;
	poo poo2;
	bool gameOver=false;
	bool isStarted = false;
	/********************************/
};