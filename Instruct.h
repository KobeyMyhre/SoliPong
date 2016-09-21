
#pragma once
#include "menuestate.h"

class instruct
{
private:
	int d;
	float timer;
public:
	void init(int a_font);
	void play();
	void draw();
	void step();

	menueState next();
};