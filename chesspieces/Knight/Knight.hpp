#ifndef KNIGHT_HPP
#define KNIGHT_HPP
#include "../Chesspiece.hpp"
#include "../Chesspiece.hpp"
#include "../../Board.hpp"

class Knight: public Chesspiece
{
    public:
        Knight(char team);
        bool MoveCheck(int ogRow, int ogCol, int tRow, int tCol, Chesspiece* playArea[][8]) override;
    protected:
        bool notMoved;
};
#endif 