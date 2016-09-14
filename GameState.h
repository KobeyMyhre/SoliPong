#pragma once
#include "Paddle.h"
#include "Ball.h"
#include "sfwdraw.h"
#include "Score.h"
#include "menuestate.h"
class GameState
{
public:
	player p1, p2, p3, p4;
	ball b1, b2;
	int score;
	unsigned d, r;
	unsigned font;
	bool GameOver;
	int winner = -1;

	void createGameState();
	void updateGameState();
	void drawGameState();
	menueState GameState::nextAppState();
	bool isGameOver() { return GameOver; }
};













//struct GameState
//{
//	player p1, p2;
//	ball b1, b2;
//	int score;
//	unsigned f, d, r, u;
//	unsigned font;
//	bool GameOver;
//	int winner = -1;
//};
//
//GameState createGameState()
//{
//	GameState gs;
//
//	 gs.p1 = createPaddle(300, 10, 150, 'W', 'S', GREEN);
//	 gs.p2 = createPaddle(300, 590, 150, 'I', 'K', RED);
//	
//
//	 gs.b1 = create(400, 200, 2, 1, 20, CYAN);
//	 gs.b2 = create(200, 400, -1, -2, 20, WHITE);
//	 gs.f = sfw::loadTextureMap("./res/tonc_font.png", 16, 6);
//	 gs.d = sfw::loadTextureMap("./res/fontmap.png", 16, 16);
//	 gs.r = sfw::loadTextureMap("./res/background.jpg");
//	 gs.u = sfw::loadTextureMap("./res/crosshair.png");
//	 gs.p1.score;
//	 gs.p2.score;
//	 gs.GameOver = false;
//	 return gs;
//}
//
//void updateGameState(GameState &gs)
//{
//	updatPaddle(gs.p1);
//	updatPaddle(gs.p2);
//	updateBall(gs.b1, gs.b2 ,gs.p1, gs.p2);
//	collision(gs.b1, gs.b2 , gs.p1, gs.p2);
//
//	if (gs.p1.score >= 50)
//	{
//		gs.winner = 0;
//		gs.GameOver = true;
//	}
//
//	if (gs.p2.score >= 50)
//	{
//		gs.winner = 1;
//		gs.GameOver = true;
//	}
//}
//
//void drawGameState(const GameState &gs)
//{
//	
//
//
//	sfw::drawTexture(gs.r, 0, 600, 600, 600, 0, false, 0, YELLOW);
//	
//	drawScore(gs.d, gs.p1.score, gs.p2.score);
//	
//	if(gs.winner == 0)
//		drawWin(gs.d);
//	else if (gs.winner == 1)
//		drawWin2(gs.d);
//
//	drawPaddle(gs.p1);
//	drawPaddle(gs.p2);
//	drawBall(gs.b1);
//	drawBall(gs.b2);
//
//	
//		sfw::drawLine(300, 0, 300, 600,BLUE);
//	

	/*if (gs.p2.score >= 25)
	{
		sfw::drawLine(5, 220, 5, 380, BLUE);
	}
	if (gs.p1.score >= 25)
	{
		sfw::drawLine(595, 380, 595, 500, GREEN);
	}

	if (gs.p2.score >= 25)
	{
		sfw::drawLine(5, 380, 5, 500,RED);
	}
	if (gs.p1.score >= 25)
	{
		sfw::drawLine(595, 220, 595, 100, GREEN);
	}

	if (gs.p2.score >= 25)
	{
		sfw::drawLine(5, 220, 5, 100, RED);
	}
	
Boundary:
	x, y1, y2

	draw()

GameState:
	Boundary bounds[10]
	int nActiveBounds = 0


	init()
		bounds = {...}

	draw()
		for each bounds < nActiveBounds:
			bounds.draw()

	update()
		for each bounds < nActiveBounds:
			ball.checkBoundary(bounds)


ball:
	checkBoundary(bounds)



	could be tricky->
		
		lastX = pos.x-vel.x
		
		lastX < bounds.x && bounds.x < pos.x && between y's
	
	*/


//}
