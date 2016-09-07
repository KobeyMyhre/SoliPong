#pragma once

struct ball;

struct player
{
	float Y = 10;
	float X = 10;
	float size = 150;
	char up;
	char down;
	unsigned int color;
	int score = 0;
};

player createPaddle(float Y, float X, float size, char up, char down, unsigned int color);
void updatPaddle(player &p);
void collision(ball &b, player &p1, player &p2);
void drawPaddle(const player &p);