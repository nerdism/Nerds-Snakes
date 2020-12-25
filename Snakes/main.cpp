
#include <cstdio>
#include <cstdlib>
#include <ctime>

#include <iostream>
#include <memory>

#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include "snake.h"
#include "board.h"

// Override base class with your custom functionality
class Snakes: public olc::PixelGameEngine
{

	private:

	float frame_per_second; // Virtual FPS of 100fps
	float accumulated_time;

	std::shared_ptr<Snake> snake;
	std::shared_ptr<Board> board;
	Directions direction;
	

	public:

	Snakes():
		frame_per_second(1.0f / 20.0f),
		accumulated_time(0.0f)
	{
		// Name you application
		sAppName = "Snakes";
	}

	public:

	bool OnUserCreate() override
	{
		// Called once at the start, so create things here
		snake.reset(new Snake(10, 10));
		board.reset(new Board(ScreenWidth(), ScreenHeight()));

		board->put_seed(snake->get_body());

		direction = Directions::RIGHT;

		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		
		if (GetKey(olc::Key::LEFT).bReleased) direction = Directions::LEFT;
		else if (GetKey(olc::Key::RIGHT).bReleased) direction = Directions::RIGHT;
		else if (GetKey(olc::Key::UP).bReleased) direction = Directions::UP;
		else if (GetKey(olc::Key::DOWN).bReleased) direction = Directions::DOWN;

		accumulated_time += fElapsedTime;
		if (accumulated_time >= frame_per_second)
		{
			accumulated_time -= frame_per_second;
			fElapsedTime = frame_per_second;
		}
		else
			return true;

		Clear(olc::WHITE);
		std::vector<BodyPart>& parts =  snake->get_body();

		for (auto part : parts)
		{
			Draw(part.get_x(), part.get_y(), olc::Pixel(255, 10, 10));
		}

		Draw(board->get_seed_x(), board->get_seed_y(), olc::Pixel(10, 10, 255));

		if (snake->check_seed(board->get_seed_x(), board->get_seed_y()))
		{
			snake->grow();
			board->put_seed(snake->get_body());
		}

		snake->move(direction);

		return true;
	}
};


int main()
{
	Snakes game;
	if (game.Construct(100, 60, 10, 10))
		game.Start();
	return 0;
}





