
#include "sfwdraw.h"
#include <random>
#include <iostream>
#include <time.h>
#include "Paddle.h"
#include "Ball.h"
#include "Score.h"
#include "GameState.h"
#include "menuestate.h"
#include "option.h"
#include "splash.h"
#include "depart.h"
#include "Instruct.h"
//using sfw::drawTexture;
//sfw::drawTexture();



void main()
{
	sfw::initContext(1200, 600, "PUNISHMENT PONG");
	int	d = sfw::loadTextureMap("./res/fontmap.png", 16, 16);
	//int r = sfw::loadTextureMap("./res/PongBackground.png");

	GameState gs;

	splash splash;
	depart depart;
	option option;
	instruct instruct;

	splash.init(d);
	depart.init(d);
	option.init(d);
	instruct.init(d);

	menueState state = Enter_Splash;
	gs.createGameState();

	gs.font = d;
	gs.d = d;
	/*gs.r = r;*/


	gs.createGameState();

	while (sfw::stepContext())
	{
		switch (state)
		{
			
		case Enter_Option:
			option.play();
		case Option:
			option.step();
			option.draw();
			state = option.next();
			break;

		case Enter_Splash:
			splash.play();
		case Splash:
			splash.step();
			splash.draw();
			state = splash.next();
			break;

		case Enter_Instruct:
			instruct.play();
		case Instruct:
			instruct.step();
			instruct.draw();
			state = instruct.next();
			break;

		case Enter_Depart:
			depart.play(gs.winner);
		case Depart:
			depart.step();
			depart.draw();
			state = depart.next();
			break;


		case Enter_Game:
			//gs.isGameOver();
			gs.createGameState();
		case Game:
			gs.updateGameState();
			gs.drawGameState();
			state = gs.nextAppState();
		}

	}
		/*if (gs.GameOver == false)
		{
			gs.updateGameState();


			gs.drawGameState();
		}
		else
		{
			sfw::setBackgroundColor(BLACK);
			sfw::drawString(d, "PLEASE INSERT 50 CREDITS TO CONTINUE", 330, 300, 15, 15,BLUE,0, GREEN);
		}
	}*/
	sfw::termContext();
}













//
//
//void main()
//{
//
//	sfw::initContext(600, 600, "PUNISHMENT PONG");
//	sfw::setBackgroundColor(WHITE);
//
//	unsigned f = sfw::loadTextureMap("./res/tonc_font.png", 16, 6);
//	unsigned d = sfw::loadTextureMap("./res/fontmap.png", 16, 16);
//	unsigned r = sfw::loadTextureMap("./res/background.jpg");
//	unsigned u = sfw::loadTextureMap("./res/crosshair.png");
//
//	//drawString(f, "Pong", 100, 600, 48, 48, 0, ' ');
//	
//	
//
	

	/*while (sfw::stepContext())
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

		if (p1.score >= 50)
		{
			GameOver = true;
			drawWin(d);
		}
		
		if (p2.score >= 50)
		{
			GameOver = true;
			drawWin2(d);
		}





		drawPaddle(p1);
		drawPaddle(p2);
		drawBall(b1);



	}
	
	
}*/







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
