#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <memory>

enum class Directions : uint8_t
{
    UP,
    DOWN,
    RIGHT,
    LEFT
};

enum class SnakeCurve : uint8_t
{
    NONE,
    DLRU, // down left or right up 
    DRLU, // down right or left up
    RDUL, // right down or up left
    LDUR, // left down or up right
};


class BodyPart
{
    public:
    inline BodyPart();

    inline void set_position(size_t x, size_t y, Directions direction, SnakeCurve curve = SnakeCurve::NONE);
    inline size_t get_x();
    inline size_t get_y();
    inline Directions get_direction();
    inline SnakeCurve get_curve();

    private:
    size_t _x;
    size_t _y;
    Directions _direction;
    SnakeCurve _curve;
};

BodyPart::BodyPart(): 
    _x(0),
    _y(0),
    _direction(Directions::RIGHT),
    _curve(SnakeCurve::NONE)
{

}

size_t BodyPart::get_x()
{
    return _x;
}

size_t BodyPart::get_y()
{
    return _y;
}

Directions BodyPart::get_direction()
{
    return _direction;
}

SnakeCurve BodyPart::get_curve()
{
    return _curve;
}

void BodyPart::set_position(size_t x, size_t y, Directions direction, SnakeCurve curve)
{
    _x = x;
    _y = y;
    _direction = direction;
    _curve = curve;
}



class Snake
{
    public:

    inline Snake(size_t x, size_t y, Directions direction, size_t x_offset = 0, size_t y_offset = 0);

    void move(Directions);

    inline void grow();
    inline bool check_seed(size_t x, size_t y);

    inline size_t get_length();
    inline std::vector<BodyPart>& get_body();

    protected:

    // an array of snake parts
    std::vector<BodyPart> snake_parts;

    size_t _x_offset;
    size_t _y_offset;
};

Snake::Snake(size_t x, size_t y, Directions direction, size_t x_offset, size_t y_offset)
    : _x_offset(x_offset),
      _y_offset(y_offset)
{
    BodyPart head;
    head.set_position(x, y, direction);
    snake_parts.push_back(head);

    grow();
}

bool Snake::check_seed(size_t x, size_t y)
{
    const size_t FIRST = 0;
    BodyPart& head = snake_parts[FIRST];
    return (head.get_x() >= x && head.get_x() <= x + 20 && head.get_y() >= y && head.get_y() <= y + 20);
}

size_t Snake::get_length()
{
    return snake_parts.size();
}

std::vector<BodyPart>& Snake::get_body()
{
    return snake_parts;
}

void Snake::grow()
{
    if (snake_parts.size() < 0)
        return;

    BodyPart& last = snake_parts[snake_parts.size()-1];

    BodyPart part;
    part.set_position(last.get_x(), last.get_y(), last.get_direction());

    snake_parts.push_back(part);
}

#endif