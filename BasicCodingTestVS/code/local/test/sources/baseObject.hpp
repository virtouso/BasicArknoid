#pragma once

#include <SDL2/SDL.h>
class  baseObject
{
public:

	SDL_Rect* rect;

	baseObject(int x, int y, int w, int h) : rect(new SDL_Rect())
	{
		rect->x = x;
		rect->y = y;
		rect->w = w;
		rect->h = h;
	}



	virtual void Update() = 0;


};



class Ball :public baseObject
{

public:
	Ball(int x, int y) :baseObject(x, y, 5, 5) {  }

	void Update() override
	{

	}



};

class Paddle :public baseObject
{


public:
	Paddle(int x, int y) : baseObject(x, y, 5, 20) {  }

	void Update() override
	{
		
	}

};

class Brick :public baseObject
{

public:
	Brick(int x, int y, int w, int h) :baseObject(x, y, w, y) {  }

	void Update() override
	{
		
	}

};
