#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <olcPixelGameEngine.h>
#include <snake.h>
#include <board.h>


class GameObject
{
	public:

	virtual void draw(olc::PixelGameEngine& engine) = 0;
};


class SnakeObject : public GameObject, public Snake
{
	public:

	SnakeObject(size_t, size_t);

	inline void draw(olc::PixelGameEngine& engine) override;
};

SnakeObject::SnakeObject(size_t x, size_t y)
	: Snake(x, y)

{
}

void SnakeObject::draw(olc::PixelGameEngine& engine)
{
	for (auto& part : snake_parts)
	{
		engine.Draw(part.get_x(), part.get_y(), olc::Pixel(olc::RED));
	}
}

class BoardObject : public GameObject, public Board
{
	public:

	BoardObject(size_t width, size_t height, std::shared_ptr<olc::Sprite> seed_sprite);
	inline void draw(olc::PixelGameEngine& engine) override;

	protected:

	std::shared_ptr<olc::Sprite> seed_sprite;

};

BoardObject::BoardObject(size_t width, size_t height, std::shared_ptr<olc::Sprite> seed_sprite)
	: Board(width, height)
	, seed_sprite(seed_sprite)
{
}


void BoardObject::draw(olc::PixelGameEngine& engine)
{
	// engine.Draw(seed_x, seed_y, olc::Pixel(olc::BLUE));

	engine.DrawSprite(olc::vi2d(0,0), seed_sprite.get());

	// engine.DrawCircle(seed_x, seed_y, 2, olc::Pixel(olc::BLUE));
}

#endif
