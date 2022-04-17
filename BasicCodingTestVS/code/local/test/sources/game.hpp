#ifndef GAME_HPP
#define GAME_HPP

#include "gamebase.hpp"

class Game : public GameBase {
public:

	int static const WIDTH = 620;
	int static const HEIGHT = 720;

	int static const COL = 2;
	int static const ROW = 6;


	int static const XinitValocityMag = 3;
	int static const YinitVelocityMag = -3;



	Game();
	virtual void update(float timeStep, float mouseX, float mouseY, bool pressed);
	virtual void render(Renderer& renderer);

private:
	float	m_x, m_y, m_time;
	void (Game::*currentState)(float);
	void	playState(float timeStep);
	void waitState(float waitStep);
	void changeToWait();
	void changeToPlay();
	void drawOneFrame(Renderer& renderer);
};

#endif
