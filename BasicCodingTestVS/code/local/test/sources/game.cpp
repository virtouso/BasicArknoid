#include "game.hpp"
#include "renderer.hpp"
#include "baseObject.hpp"
#include <vector>





Brick* bricks[Game::ROW][Game::COL];
Ball* ball;
Paddle* paddle;

int liveCount = 3;




float waitTimer = 0;
float waiteTime = 3;

void resetBricks()
{

	for (int i = 0; i < Game::ROW; i++) {

		for (int j = 0; j < Game::COL; j++) {
			bricks[i][j]->alive = true;
		}
	}
	liveCount = 3;


	ball->rect->x = Game::WIDTH / 2;
	ball->rect->y = paddle->rect->y - 40;
	ball->velocityY = Game::YinitVelocityMag;

}

void setBricks()
{


	int xoffset = 100;
	int yoffset = 150;
	for (int i = 0; i < Game::ROW; i++)
	{
		for (int j = 0; j < Game::COL; j++) {

			bricks[i][j]->rect->x = xoffset + (i * 70);
			bricks[i][j]->rect->y = yoffset + (j * 20);

		}
	}


}





Game::Game() : m_x(0.5f), m_y(0.5f), m_time(0)
{
	std::cout << "Lives:" + liveCount;

	paddle = new Paddle(WIDTH / 2, HEIGHT - 80);
	ball = new Ball(WIDTH / 2, paddle->rect->y - 40);
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < Game::COL; j++) {
			auto brick = new Brick(100, 200, 60, 9, true);
			bricks[i][j] = (brick);
		}
	}

	ball->velocityX = XinitValocityMag;
	ball->velocityY = YinitVelocityMag;

	setBricks();

	changeToWait();

}


void Game::playState(float timeStep)
{

	ball->Update();
	paddle->Update();



	bool reset = 1;
	for (size_t i = 0; i < Game::ROW; i++)
	{
		for (int j = 0; j < Game::COL; j++) {
			setBricks();
			if (SDL_HasIntersection(ball->rect, bricks[i][j]->rect) && bricks[i][j]->alive) {
				bricks[i][j]->alive = 0;
				if (ball->velocityX >= bricks[i][j]->rect->x) {
					ball->velocityX = -ball->velocityX;
				
				}
				else	if (ball->rect->x <= bricks[i][j]->rect->x) {
					ball->velocityX = -ball->velocityX;
				
				}
				else	if (ball->rect->y <= bricks[i][j]->rect->y) {
					ball->velocityY = -ball->velocityY;
			
				}
				else	if (ball->rect->y >= bricks[i][j]->rect->y) {
					ball->velocityY = -ball->velocityY;
			
				}



			}

			if (bricks[i][j]->alive) {
				reset = 0;
			}
		}
	}

	if (ball->rect->x >= Game::WIDTH || ball->rect->x <= 0)
		ball->velocityX = -ball->velocityX;

	if (ball->rect->y <= 0)
		ball->velocityY = -ball->velocityY;

	if (ball->rect->y > Game::HEIGHT)
	{
		liveCount--;
		std::cout << "Lives:" << liveCount << "\n";

		ball->rect->x = Game::WIDTH / 2;
		ball->rect->y = paddle->rect->y - 40;
		ball->velocityY = Game::YinitVelocityMag;

		if (liveCount <= 0)
		{
			std::cout << "You Lost\n";
			resetBricks();
		}
		changeToWait();
	}

	if (SDL_HasIntersection(ball->rect, paddle->rect)) {
		ball->velocityY = -ball->velocityY;
	}

	if (reset) {
		std::cout << "You Won";
		changeToWait();
		resetBricks();
	}
}

void Game::waitState(float timeStep)
{
	waitTimer -= timeStep;
	if (waitTimer <= 0)
		Game::currentState = &Game::playState;
}

void  Game::changeToPlay()
{
	Game::currentState = &Game::playState;
}

void Game::changeToWait()
{
	waitTimer = waiteTime;
	Game::currentState = &Game::waitState;
}


void Game::update(float timeStep, float mouseX, float mouseY, bool pressed) {




	//if (Game::currentState)
	(this->*currentState)(timeStep);



}



void Game::drawOneFrame(Renderer& renderer)
{
	renderer.drawRect(ball->rect, Renderer::BLUE);
	renderer.drawRect(paddle->rect, Renderer::GREEN);


	for (int i = 0; i < Game::ROW; i++)
	{
		for (int j = 0; j < Game::COL; j++) {
			if (!bricks[i][j]->alive) continue;
			renderer.drawRect(bricks[i][j]->rect, Renderer::GREY);
		}
	}
}

void Game::render(Renderer& renderer)
{
	drawOneFrame(renderer);
}







