
#include "sfwdraw.h"
#include "Ball.h"
#include "Paddle.h"
#include <random>
#include <time.h>
float randRange(int start, int end)
{
	srand(time(0));
	return rand() % (end - start + 1) - start;
}

ball create(float x, float y, float Velx, float Vely, float radius, unsigned int color)
{
	ball retval;
	retval.x = x;
	retval.y = y;
	retval.Velx = randRange(35, 45);
	retval.Vely = randRange(4, 7);
	retval.radius = radius;
	retval.color = color;
	return retval;
}

void drawBall(const ball &b)
{
	sfw::drawCircle(b.x, b.y, b.radius, 12, b.color);
}

void updateBall(ball &b, player &p1, player &p2)
{
	b.x += b.Velx;
	b.y += b.Vely;
	if (b.y > 600 - b.radius)
	{
		b.y = 600 - b.radius;
		b.Vely *= -1;
	}
	if (b.y < 0)
	{
		b.y = 0;
		b.Vely *= -1;
	}

	if (b.x < 0)
	{
		p1.score++;

		printf("%d to %d \n", p1.score, p2.score);
		b.x = 30;
		b.y = 300;

		b.x = 300;
		b.y = 300;
	}
	if (b.x > 600)
	{
		p2.score++;
		printf("%d to %d \n", p1.score, p2.score);
		b.x = 770;
		b.y = 300;

		b.x = 300;
		b.y = 300;
	}




}
