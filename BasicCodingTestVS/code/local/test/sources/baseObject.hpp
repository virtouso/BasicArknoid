#pragma once

#include <SDL2/SDL.h>
#include<iostream>
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

	int velocityX, velocityY;


	Ball(int x, int y) :baseObject(x, y, 5, 5) {  }

	void Update() override
	{
		rect->x += velocityX;
		rect->y += velocityY;

	//	std::cout << rect->x<<"\n";
	}



};

class Paddle :public baseObject
{


public:
	Paddle(int x, int y) : baseObject(x, y, 50, 10) {  }


	int speed = 5;

	void Update() override
	{
		const Uint8* keystates = SDL_GetKeyboardState(NULL);


		if (keystates[SDL_SCANCODE_LEFT]) {
			if (rect->x > 0)
				rect->x -= speed;
		}
		if (keystates[SDL_SCANCODE_RIGHT]) {
			if (rect->x < Game::WIDTH )
				rect->x += speed;

		}

	}

};

class Brick :public baseObject
{

public:

	bool alive;

	Brick(int x, int y, int w, int h, int a) :baseObject(x, y, w, h)
	{
		alive = a;
	}

	void Update() override
	{

	}

};
