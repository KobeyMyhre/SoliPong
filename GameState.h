#pragma once
#include "Paddle.h"
#include "Ball.h"
#include "sfwdraw.h"
struct GameState
{
	player p1, p2;
	int score;
	
};

GameState createGameState()
{
	player p1 = createPaddle(300, 10, 200, 'W', 'S', GREEN);
	player p2 = createPaddle(300, 590, 200, 'I', 'K', RED);
	ball b1 = create(300, 300, 1, 1, 15, CYAN);
}

void updateGameStat(GameState &gs)
{
	updatPaddle(p1);
	updatPaddle(p2);
	updateBall(b1, p1, p2);
	collision(b1, p1, p2);
}
void drawGameState(const GameState &gs);
{
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