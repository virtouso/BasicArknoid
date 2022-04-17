#include "game.hpp"
#include "renderer.hpp"
#include "baseObject.hpp"


int const WIDTH = 620;
int const HEIGHT = 720;
int const SPEED = 9;
int const FONT_SIZE = 32;
int const BALL_SPEED = 12;
int const SIZE = 16;
int const COL = 13;
int const ROW = 6;
float const PI = 3.1415926f;
int const SPACING = 0;




//Brick* bricks[];
Ball* ball;
//Paddle* paddle;


Game::Game() : m_x(0.5f), m_y(0.5f), m_time(0)
{
	
	ball = new Ball( 100 ,200 );
	


}

void Game::update(float timeStep, float mouseX, float mouseY, bool pressed) {
	

	ball->Update();

}


void Game::render(Renderer& renderer)
{
//	float w = ( float )sin( m_time ) * 20 + 25;
//
//	float h = ( float )cos( m_time ) * 20 + 25;
//	renderer.drawRect(m_x - w / 2, m_y - h / 2, w, h, Renderer::DARK_GREEN);

	//ball->Draw(render(renderer));
	renderer.drawRect(ball->rect,Renderer::BLUE);
}







