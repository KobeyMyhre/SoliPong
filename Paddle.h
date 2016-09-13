#pragma once

class ball;

//struct player
//{
//	float Y = 10;
//	float X = 10;
//	float size = 200;
//	char up;
//	char down;
//	unsigned int color;
//	int score = 0;
//};
//
//player createPaddle(float Y, float X, float size, char up, char down, unsigned int color);
//void updatPaddle(player &p);
//void collision(ball &b,ball &b2, player &p1, player &p2);
//void drawPaddle(const player &p);

class player
{
public:
	float Y;
	float X;
	float size;
	char up;
	char down;
	unsigned int color;
	int score = 0;

	/*void score();*/
	void createPaddle(float Y, float X, float size, char up, char down, unsigned int color);
	void updatPaddle();
	void drawPaddle();
};