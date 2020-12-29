
#include <cstdio>
#include <cstdlib>
#include <ctime>

#include <iostream>
#include <memory>

#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include "game_object.h"

// Override base class with your custom functionality
class Snakes: public olc::PixelGameEngine
{

	private:

	std::vector<std::shared_ptr<GameObject> > game_objects; // drawable game objects

	float frame_per_second; // Virtual FPS of 100fps
	float accumulated_time;

	// uint32_t main_layer;

	std::shared_ptr<SnakeObject> snake;
	std::shared_ptr<BoardObject> board;
	Directions direction;
	

	public:

	Snakes():
		frame_per_second(1.0f / 10.0f),
		accumulated_time(0.0f)
	{
		// Name you application
		sAppName = "Snakes";
	}

	public:

	bool OnUserCreate() override
	{
		// Called once at the start, so create things here



		/*
		main_layer = CreateLayer();
		EnableLayer(main_layer, true);
		*/


		SetPixelMode(olc::Pixel::ALPHA);
		std::shared_ptr<olc::Sprite> snake_sprite(new olc::Sprite("../graphics/snake2.png"));

		snake.reset(new SnakeObject(30, 30, Directions::RIGHT,snake_sprite, snake_sprite->width/5 - 1, snake_sprite->height/4 - 1));
		board.reset(new BoardObject(ScreenWidth(), ScreenHeight(), snake_sprite));

		game_objects.push_back(board);
		game_objects.push_back(snake);

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

		
		// check if it's a proper frame
		if (check_frame(fElapsedTime)) return true;


		if (snake->check_seed(board->get_seed_x(), board->get_seed_y()))
		{
			snake->grow();
			board->put_seed(snake->get_body());
		}

		snake->move(direction);


		// SetDrawTarget(nullptr);
		Clear(olc::WHITE);

		// draw every object in the game
		update_game_objects();

		return true;
	}

	void update_game_objects()
	{
		for (auto& object : game_objects)
		{
			object->draw(*this);
		}
	}

	inline bool check_frame(float elapsed_time)
	{
		accumulated_time += elapsed_time;
		if (accumulated_time >= frame_per_second)
		{
			accumulated_time -= frame_per_second;
			elapsed_time = frame_per_second;
			return false;
		}
		else
			return true;
	}

};


int main()
{
	const int32_t width = 1800;
	const int32_t height = 1000;
	const int32_t pixel_width = 1;
	const int32_t pixel_height = 1;

	Snakes game;
	if (game.Construct(width, height, pixel_width, pixel_height))
		game.Start();

	return 0;
}



