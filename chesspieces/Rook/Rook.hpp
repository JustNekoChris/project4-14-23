#ifndef ROOK_HPP
#define ROOK_HPP
#include "../Chesspiece.hpp"
#include "../Chesspiece.hpp"
#include "../../Board.hpp"


class Rook: public Chesspiece
{
    public:
        Rook(char team);
        bool MoveCheck(int ogRow, int ogCol, int tRow, int tCol, Chesspiece* playArea[][8]) override;
    protected:
        bool notMoved; 

};

#endif 