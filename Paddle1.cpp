#pragma once
#include "sfwdraw.h"
#include "Ball.h"
#include "Paddle.h"
#include <iostream>

player createPaddle(float Y, float X, float size, char up, char down, unsigned int color)
{
	player retval;
	retval.up = up;
	retval.down = down;
	retval.Y = Y;
	retval.X = X;
	retval.color = color;

	return retval;
}
void updatPaddle(player &p)
{


	if (sfw::getKey(p.up))
		p.Y += 10;
	if (sfw::getKey(p.down))
		p.Y -= 10;
	if (p.Y > 600 - p.size) p.Y = 600 - p.size;
	if (p.Y < 0) p.Y = 0;
}

void collision(ball &b, player &p1, player &p2)
{
	if (b.x - b.radius < p1.X && b.y > p1.Y && b.y < (p1.Y + p1.size))
	{
		b.Velx *= -1;
		b.x = p1.X + b.radius;
	}
	if (b.x + b.radius > p2.X && b.y > p2.Y && b.y < (p2.Y + p2.size))
	{
		b.Velx *= -1;
		b.x = p2.X - b.radius;
	}
}


void drawPaddle(const player &p)
{
	sfw::drawLine(p.X, p.size + p.Y, p.X, p.Y, p.color);
}
