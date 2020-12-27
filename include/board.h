#ifndef _BOARD_H
#define _BOARD_H

#include "snake.h"

class Board {
    
    public:
    inline size_t get_board_width();
    inline size_t get_board_height();

    inline size_t get_seed_x();
    inline size_t get_seed_y();

    Board(size_t width, size_t height):
        board_width(width), board_height(height) {}
    
    void put_seed(std::vector<BodyPart>& parts);

    protected:
    size_t board_width;
    size_t board_height;
    size_t seed_x;
    size_t seed_y;

};


size_t Board::get_board_width() {
   return board_width; 
}

size_t Board::get_board_height() {
    return board_height;
}

size_t Board::get_seed_x() {
    return seed_x;
}

size_t Board::get_seed_y() {
    return seed_y;
}
#endif
