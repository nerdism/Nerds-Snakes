
#include "snake.h"


void Snake::move(Directions direction)
{
    

    const size_t FIRST = 0;
    BodyPart& head = snake_parts[FIRST];
    Directions head_dir = head.get_direction();

    size_t x = head.get_x();
    size_t y = head.get_y();

    

    SnakeCurve curve = SnakeCurve::NONE;

    if (direction == Directions::UP && head_dir == Directions::DOWN)
        direction = Directions::DOWN;
    else if (direction == Directions::DOWN && head_dir == Directions::UP)
        direction = Directions::UP;
    else if (direction == Directions::RIGHT && head_dir == Directions::LEFT)
        direction = Directions::LEFT;
    else if (direction == Directions::LEFT && head_dir == Directions::RIGHT)
        direction = Directions::RIGHT;

    

    if (head_dir == Directions::UP || head_dir == Directions::LEFT)
    {
        if (direction == Directions::RIGHT || direction == Directions::DOWN)
            curve = SnakeCurve::LDUR;
    }
    if (head_dir == Directions::UP || head_dir == Directions::RIGHT)
    {
        if (direction == Directions::LEFT || direction == Directions::DOWN)
            curve = SnakeCurve::RDUL;
    }
    if (head_dir == Directions::DOWN || head_dir == Directions::RIGHT)
    {
        if (direction == Directions::UP || direction == Directions::LEFT)
            curve = SnakeCurve::DLRU;
    }
    if (head_dir == Directions::DOWN || head_dir == Directions::LEFT)
    {
        if (direction == Directions::UP || direction == Directions::RIGHT)
            curve = SnakeCurve::DRLU;
    }

    for (size_t index = snake_parts.size()-1; index > 0; --index)
    {
        BodyPart& part = snake_parts[index-1];
        if (index == 1)
            snake_parts[index].set_position(part.get_x(), part.get_y(), part.get_direction(), curve);
        else if (index == snake_parts.size()-1)
            snake_parts[index].set_position(part.get_x(), part.get_y(), part.get_direction(), part.get_curve());
        else
            snake_parts[index].set_position(part.get_x(), part.get_y(), part.get_direction(), part.get_curve());
    }

    switch (direction)
    {
    case Directions::UP :
        head.set_position(x, y-1-_y_offset, Directions::UP);
        break;
    case Directions::DOWN :
        head.set_position(x, y+1+_y_offset, Directions::DOWN);
        break;
    case Directions::LEFT :
        head.set_position(x-1-_x_offset, y, Directions::LEFT);
        break;
    case Directions::RIGHT :
        head.set_position(x+1+_x_offset, y, Directions::RIGHT);
        break;
    }

}

//TODO: write check_seed function

