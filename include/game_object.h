#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <olcPixelGameEngine.h>
#include <snake.h>
#include <board.h>


class GameObject
{
	public:

	virtual void draw(olc::PixelGameEngine& engine) = 0;

	protected:

	olc::vi2d block;
};


class SnakeObject : public GameObject, public Snake
{
	public:

	SnakeObject(size_t, size_t, Directions direction, std::shared_ptr<olc::Sprite>, size_t x_offset = 0, size_t y_offset = 0);

	inline void draw(olc::PixelGameEngine& engine) override;

	std::shared_ptr<olc::Sprite> snake_sprite;
};

SnakeObject::SnakeObject(size_t x, size_t y, Directions direction, std::shared_ptr<olc::Sprite> snake_sprite, size_t x_offset, size_t y_offset)
	: Snake(x, y, direction, x_offset, y_offset)
	, snake_sprite(snake_sprite)
{

	block = olc::vi2d(snake_sprite->width / 5, snake_sprite->height / 4);
}

void SnakeObject::draw(olc::PixelGameEngine& engine)
{


	for (size_t index = 0; index < snake_parts.size(); ++index)
	{

		auto part = snake_parts[index];
		if (index == 0)
		{
			olc::vi2d head;
			if (part.get_direction() == Directions::UP)
				head = olc::vi2d(3, 0);
			else if (part.get_direction() == Directions::DOWN)
				head = olc::vi2d(4, 1);
			else if (part.get_direction() == Directions::LEFT)
				head = olc::vi2d(3, 1);
			else
				head = olc::vi2d(4, 0);

			engine.DrawPartialSprite(olc::vi2d(part.get_x(), part.get_y()), snake_sprite.get(), head*block, block);

		}
		else if (index == snake_parts.size() - 1)
		{
			olc::vi2d tail;
			Directions tail_direction = snake_parts[snake_parts.size() - 2].get_direction();

			if (tail_direction == Directions::UP)
				tail = olc::vi2d(3, 2);
			else if (tail_direction == Directions::DOWN)
				tail = olc::vi2d(4, 3);
			else if (tail_direction == Directions::LEFT)
				tail = olc::vi2d(3, 3);
			else
				tail = olc::vi2d(4, 2);

			engine.DrawPartialSprite(olc::vi2d(part.get_x(), part.get_y()), snake_sprite.get(), tail*block, block);
		}
		else
		{
			olc::vi2d body;
			if (part.get_curve() == SnakeCurve::NONE)
			{
				if (part.get_direction() == Directions::UP || part.get_direction() == Directions::DOWN)
					body = olc::vi2d(2, 1);
				else
					body = olc::vi2d(1, 0);
			}
			else {
				if (part.get_curve() == SnakeCurve::DLRU)
					body = olc::vi2d(2, 2);
				else if (part.get_curve() == SnakeCurve::DRLU)
					body = olc::vi2d(0, 1);
				else if (part.get_curve() == SnakeCurve::LDUR)
					body = olc::vi2d(0, 0);
				else if (part.get_curve() == SnakeCurve::RDUL)
					body = olc::vi2d(2, 0);


			}

			engine.DrawPartialSprite(olc::vi2d(part.get_x(), part.get_y()), snake_sprite.get(), body*block, block);
		}
		//engine.Draw(part.get_x(), part.get_y(), olc::Pixel(olc::RED));
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

	block = olc::vi2d(seed_sprite->width / 5, seed_sprite->height / 4);
}


void BoardObject::draw(olc::PixelGameEngine& engine)
{
	// engine.Draw(seed_x, seed_y, olc::Pixel(olc::BLUE));

	// engine.DrawSprite(olc::vi2d(0,0), seed_sprite.get());
	engine.DrawPartialSprite(olc::vi2d(seed_x, seed_y), seed_sprite.get(), olc::vi2d(0, 3)*block, block);
	// engine.DrawCircle(seed_x, seed_y, 2, olc::Pixel(olc::BLUE));
}

#endif
