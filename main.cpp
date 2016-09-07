
#include "sfwdraw.h"
#include <random>
#include <iostream>
//using namespace sfw;
//using sfw::drawTexture;
//sfw::drawTexture();

struct ball
{
	float x = 300;
	float y = 300;
	float Velx;
	float Vely;
	float radius;
	unsigned int color;
};
ball create(float x, float y, float Velx, float Vely, float radius, unsigned int color)
{
	ball retval;
	retval.x = x;
	retval.y = y;
	retval.Velx = rand() % 40;
	retval.Vely = rand() % 40;
	retval.radius = radius;
	retval.color = color;
	return retval;
}

struct player
{
	float Y = 10;
	float X = 10;
	float size = 200;
	char up; 
	char down;
	unsigned int color;
	int score = 0;
};

player createPaddle(float Y, float X ,float size, char up, char down, unsigned int color)
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
void updateBall(ball &b, player &p1, player &p2 )
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

		printf("%d to %d /n", p1.score, p2.score);
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

void collision(ball &b, player &p1, player &p2)
{
	if (b.x - b.radius < p1.X && b.y > p1.Y && b.y < (p1.Y+ p1.size))
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
void drawBall(const ball &b)
{
	sfw::drawCircle(b.x, b.y, b.radius, 12, b.color);
}
void drawScore(unsigned font, int p1score , int p2score )
{
	char buffer[64] = { 0 };
	sprintf_s( buffer, "%d", p1score );
	sfw::drawString(font, buffer, 500, 550, 40, 40);

	sprintf_s( buffer, "%d", p2score);
	sfw::drawString(font, buffer, 100, 550, 40, 40);
}
void drawWin(unsigned font)
{
	sfw::drawString(font, "Game Over Player 1 Wins!", 160, 600, 20, 20);
}
void drawWin2(unsigned font)
{
	sfw::drawString(font, " Game Over Player 2 Wins!", 160, 600, 20, 20);
}

void main()
{


		


	sfw::initContext(600, 600, "NEVER WORKS I HATE THIS");
	sfw::setBackgroundColor(WHITE);

	unsigned f = sfw::loadTextureMap("./res/tonc_font.png", 16, 6);
	unsigned d = sfw::loadTextureMap("./res/fontmap.png", 16, 16);
	unsigned r = sfw::loadTextureMap("./res/background.jpg");
	unsigned u = sfw::loadTextureMap("./res/crosshair.png");

	//drawString(f, "Pong", 100, 600, 48, 48, 0, ' ');
	

	player p1 = createPaddle(300, 10,200, 'W', 'S', GREEN);
	player p2 = createPaddle(300, 590,200,'I', 'K', RED);
	ball b1 = create(300, 300, 1, 1, 15, CYAN);
	


	bool GameOver = false;

	while (sfw::stepContext())
	{	
		sfw::drawTexture(r, 0, 600, 600, 600, 0, false, 0, YELLOW);
		
		if (!GameOver)
		{
			updatPaddle(p1);
			updatPaddle(p2);
			updateBall(b1, p1, p2);
			collision(b1, p1, p2);
		}

		drawScore(d, p1.score, p2.score);

		if (p1.score >= 10)
		{
			GameOver = true;
			drawWin(d);
		}
		
		if (p2.score >= 10)
		{
			GameOver = true;
			drawWin2(d);
		}





		drawPaddle(p1);
		drawPaddle(p2);
		drawBall(b1);



	}
	
	
}







//{
//	sfw::initContext(800,600,"NSFW Draw");
//
//	unsigned f = sfw::loadTextureMap("./res/tonc_font.png", 16, 6);
//	unsigned d = sfw::loadTextureMap("./res/fontmap.png",16,16);
//	unsigned r = sfw::loadTextureMap("./res/background.jpg");
//	unsigned u = sfw::loadTextureMap("./res/crosshair.png");
//	
//	float acc = 0;
//	char c = '\0';
//
//	sfw::setBackgroundColor(BLUE);
//
//	while (sfw::stepContext())
//	{	
//		sfw::drawString(f, " !\"#$%&'()*+,./-\n0123456789:;<=>?\n@ABCDEFGHIJKLMNO\nPQRSTUVWXYZ[\\]^_\n`abcdefghijklmno\npqrstuvwxyz{|}~", 0, 600, 48, 48, 0, ' ');
//		sfw::drawTexture(r, 0, 600, 800, 600, 0, false,0, 0x88888888);
//
//		acc += sfw::getDeltaTime();
//		sfw::drawString(d, "YOU SUCK", 400, 300, 48, 48, -acc*24,'\0',BLACK);
//
//		
//
//		sfw::drawString(d, "FALSE", 400, 32, 24, 24);
//		sfw::drawString(d, "FALSE", 400, 600 - 32, 24, 24);
//		sfw::drawString(d, "TRUE", 655,300, 24, 24);
//		sfw::drawString(d, "TRUE", 32, 300, 24, 24);
//
//		if(sfw::getMouseButton(MOUSE_BUTTON_RIGHT))
//			sfw::drawTexture(u, sfw::getMouseX(), sfw::getMouseY(), sfw::getTextureWidth(u)/2.5, sfw::getTextureHeight(u)/2.5,45,true,0,0x88ffffff);
//		else sfw::drawTexture(u, sfw::getMouseX(), sfw::getMouseY(), sfw::getTextureWidth(u)/2, sfw::getTextureHeight(u)/2);
//	}
//
//	sfw::termContext();
