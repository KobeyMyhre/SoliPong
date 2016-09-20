#include "GameState.h"


void GameState::createGameState()
{


	p1.createPaddle(300, 10, 150, 'W', 'S', GREEN,3,'X');
	p2.createPaddle(300, 1190, 150, 'I', 'K', RED,3, 'M');
	p3.createPaddle(300, 595, 600,'Y' ,'Y' ,BLUE,0, 'Y');
	p4.createPaddle(300, 605, 600, 'Y', 'Y', MAGENTA,0, 'Y');

	b1.create(300, 300, 20, CYAN);
	b2.create(900, 300, 20, WHITE);
	//f = sfw::loadTextureMap("./res/tonc_font.png", 16, 6);
	

	p1.score;
	p2.score;
	GameOver = false;
	
}

void GameState::updateGameState()
{
	p1.updatePaddle();
	p2.updatePaddle();
	p3.updatePaddle();
	p4.updatePaddle();
	b1.updateBall(p1, p2);
	b2.updateBall(p1, p2);
	b1.updateLeftwall(p3);
	b2.updateRightwall(p4);
	b1.TricksAndShit();
	b2.TricksAndShit();
	p1.TricksAndShitBallOne(b1);
	p2.TricksAndShitBallTwo(b2);
	if (p1.score >= 25)
	{
		winner = 0;
		GameOver = true;
	}

	if (p2.score >= 25)
	{
		winner = 1;
		GameOver = true;
	}
}

void GameState::drawGameState()
{



	//sfw::drawTexture(r, 0, 600, 1200, 600, 0, false, 0, WHITE);

	drawScore(d, p1.score, p2.score);

	/*if (winner == 0)
		drawWin(d);
	else if (winner == 1)
		drawWin2(d);*/

	p1.drawPaddle();
	p2.drawPaddle();
	p3.drawPaddle();
	p4.drawPaddle();
	b1.drawBall();
	b2.drawBall();
}
	menueState GameState::nextAppState()
	{
		if (GameOver)
			return Enter_Depart;
		else return Game;
	}

	//sfw::drawLine(600, 0, 600, 600, BLUE);


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


