#include "GameState.h"


void GameState::createGameState()
{


	p1.createPaddle(300, 10, 150, 'W', 'S', GREEN);
	p2.createPaddle(300, 590, 150, 'I', 'K', RED);


	b1.create(400, 200, 20, CYAN);
	b2.create(200, 400, 20, WHITE);
	//f = sfw::loadTextureMap("./res/tonc_font.png", 16, 6);
	

	p1.score;
	p2.score;
	GameOver = false;
	
}

void GameState::updateGameState()
{
	p1.updatPaddle();
	p2.updatPaddle();
	b1.updateBall(p1,p2);
	b2.updateBall(p1, p2);
	

	if (p1.score >= 50)
	{
		winner = 0;
		GameOver = true;
	}

	if (p2.score >= 50)
	{
		winner = 1;
		GameOver = true;
	}
}

void GameState::drawGameState()
{



	sfw::drawTexture(r, 0, 600, 600, 600, 0, false, 0, YELLOW);

	drawScore(d, p1.score, p2.score);

	if (winner == 0)
		drawWin(d);
	else if (winner == 1)
		drawWin2(d);

	p1.drawPaddle();
	p1.drawPaddle();
	b1.drawBall();
	b2.drawBall();


	sfw::drawLine(300, 0, 300, 600, BLUE);


	/*if (p2.score >= 25)
	{
	sfw::drawLine(5, 220, 5, 380, BLUE);
	}
	if (p1.score >= 25)
	{
	sfw::drawLine(595, 380, 595, 500, GREEN);
	}

	if (p2.score >= 25)
	{
	sfw::drawLine(5, 380, 5, 500,RED);
	}
	if (p1.score >= 25)
	{
	sfw::drawLine(595, 220, 595, 100, GREEN);
	}

	if (p2.score >= 25)
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


}