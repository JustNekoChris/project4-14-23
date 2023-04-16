#ifndef BOARD_HPP
#define BOARD_HPP
#include "chesspieces/Chesspiece.hpp"
class Board{
    public:
        Board();
        void turn();
        void display();
        void swapTurn();

        int getMoves()const{return moves;}

    protected:
        Chesspiece playArea[8][8];
        bool whiteTurn;
        int moves;
};

#endif 