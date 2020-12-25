#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <memory>

class BodyPart
{
    public:
    inline BodyPart();

    inline void set_position(size_t x, size_t y);
    inline size_t get_x();
    inline size_t get_y();

    private:
    size_t _x;
    size_t _y;
};

BodyPart::BodyPart(): 
    _x(0),
    _y(0)
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

void BodyPart::set_position(size_t x, size_t y)
{
    _x = x;
    _y = y;
}

enum class Directions
{
    UP,
    DOWN,
    RIGHT,
    LEFT
};

class Snake
{
    public:

    inline Snake(size_t x, size_t y);

    void move(Directions);

    inline void grow();
    inline bool check_seed(size_t x, size_t y);

    inline size_t get_length();
    inline std::vector<BodyPart>& get_body();

    private:

    std::vector<BodyPart> snake_parts;
};

Snake::Snake(size_t x, size_t y)
{
    BodyPart head;
    head.set_position(x, y);
    snake_parts.push_back(head);
}

bool Snake::check_seed(size_t x, size_t y)
{
    const size_t FIRST = 0;
    BodyPart& head = snake_parts[FIRST];
    return (head.get_x() == x && head.get_y() == y);
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
    BodyPart& last = snake_parts[snake_parts.size()-1];
    BodyPart part;
    part.set_position(last.get_x(), last.get_y());

    snake_parts.push_back(part);
}

#endif