#pragma once

//#include "Paddle.h"

struct player;

struct ball
{
	float x = 300;
	float y = 300;
	float Velx;
	float Vely;
	float radius;
	unsigned int color;
};
ball create(float x, float y, float Velx, float Vely, float radius, unsigned int color);
void drawBall(const ball &b);
void updateBall(ball &b, player &p1, player &p2);