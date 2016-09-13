
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

void ball::create(float a_x, float a_y, float a_radius, unsigned int a_color)
{
	
	x = a_x;
	y = a_y;
	Velx = randRange(30, 35); //30, 35
	Vely = randRange(4, 7);		// 4,7
	radius = a_radius ;
	color = a_color;
	
}

void ball::drawBall()
{
	sfw::drawCircle(x, y, radius, 12, color);
}

void ball::updateBall(player &p1, player &p2)
{
	x += Velx;
	y += Vely;
	if (y > 600 - radius)
	{
		y = 600 - radius;
		Vely *= -1;
	}
	if (y < 0)
	{
		y = 0;
		Vely *= -1;
	}

	if (x < 0)
	{
		p1.score++;

		//printf("%d to %d \n", p1.score, p2.score);
		/*x = 30;
		y = 300;*/

		x = 750;
		y = 300;
	}
	if (x > 1200)
	{
		p2.score++;
		//printf("%d to %d \n", p1.score, p2.score);
	/*	x = 770;
		y = 300;*/

		x = 250;
		y = 300;
	}



	if (x - radius < p1.X && y > p1.Y && y < (p1.Y + p1.size))
	{
		Velx *= -1;
		x = p1.X + radius;
	}
	if (x + radius > p2.X && y > p2.Y && y < (p2.Y + p2.size))
	{
		Velx *= -1;
		x = p2.X - radius;
	}
}
void ball::updateLeftwall(player & p3)
{


	if (x - radius < p3.X && y > p3.Y && y < (p3.Y + p3.size))
	{
		Velx *= -1;
		x = p3.X + radius;
	}
	
	

}
void ball::updateRightwall(player & p4)
{
	if (x + radius > p4.X && y > p4.Y && y < (p4.Y + p4.size))
	{
		Velx *= -1;
		x = p4.X - radius;
	}
}
