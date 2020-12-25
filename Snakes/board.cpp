#include <cstddef> 
#include <random>
#include "board.h"
#include "snake.h"


void Board::put_seed(std::vector<BodyPart>& parts) {
    
    
    this->seed_x = rand() % board_width;
    this->seed_y = rand() % board_height;

}




