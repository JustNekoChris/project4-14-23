#ifndef BOARD_HPP
#define BOARD_HPP
#include "chesspieces/Chesspiece.hpp"
class Board{
    public:
        Board();
        void turn();
        void display();
        void swapTurn();
        void swapPiece(int tRow, int tCol ,int ogRow,int ogCol);
        int getMoves()const{return moves;}

    protected:
        //Chesspiece playArea[8][8];
        //This gets around the error of creating objects with purely virtual functions. 
        Chesspiece* playArea[8][8];
        bool whiteTurn;
        int moves;
};

#endif 