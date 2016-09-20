#pragma once

#include "menuestate.h"

class depart
{
private:
	int d;
	float timer;
	int w;
public:
	void init(int a_font);
	void play(int a_winner);
	void draw();
	void step();
	
	menueState next();
};