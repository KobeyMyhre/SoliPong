#pragma once

//#include "Paddle.h"

class player;

//struct ball
//{
//	float x = 300;
//	float y = 300;
//	float Velx;
//	float Vely;
//	float radius;
//	unsigned int color;
//};
//ball create(float x, float y, float Velx, float Vely, float radius, unsigned int color);
//void drawBall(const ball &b);
//void updateBall(ball &b, ball &b2 ,player &p1, player &p2);


class ball
{
public:
	float x ;
	float y ;
	float Velx;
	float Vely;
	float radius;
	unsigned int color;
	float ballRespawn = 1.f;
	int whichBall;
	bool isScored = false;
	float initBallRespawn = 1.f;

	void create(float x, float y, float radius, unsigned int color);
	void drawBall();
	void updateBall(player &p1, player &p2);
	void updateLeftwall(player &p3);
	void updateRightwall(player &p4);
	void updateBallcolor();
	void TricksAndShit();
	void InitSpawnOne();
	void InitSpawnTwo();
};