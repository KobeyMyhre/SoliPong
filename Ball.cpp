
#include "sfwdraw.h"
#include "Ball.h"
#include "Paddle.h"
#include <random>
#include <time.h>
float randRange(int start, int end)
{
	
	return rand() % (end - start + 1) - start;
}
void ball::updateBallcolor()
{
	if (color == GREEN)
		color = YELLOW;
	else if (color == YELLOW)
		color = RED;
	else if (color == RED)
		color = CYAN;
	else if (color == CYAN)
		color = MAGENTA;
	else if (color == MAGENTA)
		color = WHITE;
	else
		color = GREEN;
}
void ball::TricksAndShit()
{
	if (sfw::getKey(' '))
	{
		Vely *= -1;
		Velx *= -1;
	}
		
}

void ball::InitSpawnTwo()
{
	initBallRespawn -= sfw::getDeltaTime();
	if (color == BLACK)
	{
		/*x = 900;
		y = 300;*/
		Velx = 0;
		Vely = 0;
		if (initBallRespawn <= 0.0f)
		{
			Velx = randRange(20, 25);
			Vely = randRange(10, 15);
			ballRespawn = 1.0f;
			color = RED;
			
		}

	}
}

void ball::InitSpawnOne()
{
	initBallRespawn -= sfw::getDeltaTime();
	if (color == BLACK)
	{
		/*x = 300;
		y = 300;*/
		Velx = 0;
		Vely = 0;
		if (initBallRespawn <= 0.0f)
		{
			Velx = randRange(20, 25);
			Vely = randRange(10, 15);
			
			color = RED;
			
		}

	}
}

void ball::create(float a_x, float a_y, float a_radius, unsigned int a_color)
{
	
	x = a_x;
	y = a_y;
	Velx = randRange(20, 25); 
	Vely = randRange(10, 15);		
	radius = a_radius ;
	color = a_color;
	
}

void ball::drawBall()
{
	sfw::drawCircle(x, y, radius, 12, color);
}

void ball::updateBall(player &p1, player &p2)
{
	




	if (isScored == true) { ballRespawn -= sfw::getDeltaTime(); color = BLUE; }
	
	x += Velx;
	y += Vely;
	if (y > 600 - radius)
	{
		y = 600 - radius;
		Vely *= -1;
		updateBallcolor();

	}
	if (y < 0)
	{
		y = 0;
		Vely *= -1;
		updateBallcolor();
	}

	if (x < 0)
	{
		p1.score++;
		Velx = randRange(-20, -25);
		Vely = randRange(10, 15);
		//printf("%d to %d \n", p1.score, p2.score);
		/*x = 30;
		y = 300;*/
		color = BLUE;
		whichBall = 1;
		if (whichBall == 1){isScored = true;}
			x = 300;
			y = 300;
			
	}
	if (x > 1200)
	{
		p2.score++;
		Velx = randRange(20, 25);
		Vely = randRange(10, 15);
		//printf("%d to %d \n", p1.score, p2.score);
	/*	x = 770;
		y = 300;*/
		color = BLUE;
		whichBall = 2;
		if (whichBall == 2) { isScored = true; }
		x = 900;
		y = 300;
			
	}
	if (color == BLUE && whichBall == 1 && isScored == true)
	{
		x = 300;
		y = 300;
		Velx = 0;
		Vely = 0;
		if (ballRespawn <= 0.0f)
		{
			Velx = randRange(-20, -25);
			Vely = randRange(10, 15);
			ballRespawn = 1.0f;
			color = RED;
			isScored = false;
		}
		
	}
	if (color == BLUE && whichBall == 2 && isScored == true)
	{
		x = 900;
		y = 300;
		Velx = 0;
		Vely = 0;
		if (ballRespawn <= 0.0f)
		{
			Velx = randRange(20, 25);
			Vely = randRange(10, 15);
			ballRespawn = 1.0f;
			color = RED;
			isScored = false;
		}
		

	}


	if (x - radius < p1.X && y > p1.Y && y < (p1.Y + p1.size))
	{
		Velx = randRange(20, 25);
		Vely = randRange(10, 15);
		Velx *= -1;
		x = p1.X + radius; 
		updateBallcolor();
		p1.updatePaddlecolor();
		
		
	}
	if (x + radius > p2.X && y > p2.Y && y < (p2.Y + p2.size))
	{
		Velx *= -1;
		x = p2.X - radius;
		updateBallcolor();
		p2.updatePaddlecolor();
		Velx = randRange(20, 25);
		Vely = randRange(10, 15);
	}
}
void ball::updateLeftwall(player & p3)
{


	if (x - radius < p3.X && y > p3.Y && y < (p3.Y + p3.size))
	{
		Velx *= -1;
		x = p3.X + radius;
		p3.updatePaddlecolor();
	}
	
	

}
void ball::updateRightwall(player & p4)
{
	if (x + radius > p4.X && y > p4.Y && y < (p4.Y + p4.size))
	{
		Velx *= -1;
		x = p4.X - radius;
		p4.updatePaddlecolor();
	}
}
