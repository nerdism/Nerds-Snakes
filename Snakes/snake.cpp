
#include "snake.h"


void Snake::move(Directions direction)
{

    const size_t FIRST = 0;
    BodyPart& head = snake_parts[FIRST];

    size_t x = head.get_x();
    size_t y = head.get_y();

    for (size_t index = snake_parts.size()-1; index > 0; --index)
    {
        BodyPart& part = snake_parts[index-1];
        snake_parts[index].set_position(part.get_x(), part.get_y());
    }

    switch (direction)
    {
    case Directions::UP :
        head.set_position(x, y-1);
        break;
    case Directions::DOWN :
        head.set_position(x, y+1);
        break;
    case Directions::LEFT :
        head.set_position(x-1, y);
        break;
    case Directions::RIGHT :
        head.set_position(x+1, y);
        break;
    }

}

//TODO: write check_seed function

