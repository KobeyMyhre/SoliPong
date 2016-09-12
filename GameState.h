#pragma once
#include "Paddle.h"
#include "Ball.h"
#include "sfwdraw.h"
#include "Score.h"
struct GameState
{
	player p1, p2;
	ball b1;
	int score;
	unsigned f, d, r, u;
	unsigned font;
};

GameState createGameState()
{
	GameState gs;

	 gs.p1 = createPaddle(300, 10, 200, 'W', 'S', GREEN);
	 gs.p2 = createPaddle(300, 590, 200, 'I', 'K', RED);
	 gs.b1 = create(300, 300, 1, 1, 15, CYAN);
	 gs.f = sfw::loadTextureMap("./res/tonc_font.png", 16, 6);
	 gs.d = sfw::loadTextureMap("./res/fontmap.png", 16, 16);
	 gs.r = sfw::loadTextureMap("./res/background.jpg");
	 gs.u = sfw::loadTextureMap("./res/crosshair.png");
	 gs.font;
	 gs.p1.score;
	 gs.p2.score;
	 return gs;
}

void updateGameState(GameState &gs)
{
	updatPaddle(gs.p1);
	updatPaddle(gs.p2);
	updateBall(gs.b1, gs.p1, gs.p2);
	collision(gs.b1, gs.p1, gs.p2);
}

void drawGameState(const GameState &gs)
{
	


	sfw::drawTexture(gs.r, 0, 600, 600, 600, 0, false, 0, YELLOW);
	bool GameOver = false;
	drawScore(gs.font, gs.p1.score, gs.p2.score);

	if (gs.p1.score >= 50)
	{
		GameOver = true;
		drawWin(gs.font);
	}

	if (gs.p2.score >= 50)
	{
		GameOver = true;
		drawWin2(gs.font);
	}





	drawPaddle(gs.p1);
	drawPaddle(gs.p2);
	drawBall(gs.b1);

}