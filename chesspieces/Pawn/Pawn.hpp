#ifndef PAWN_HPP
#define PAWN_HPP
#include "../Chesspiece.hpp"
#include "../Chesspiece.hpp"
#include "../../Board.hpp"
class Pawn: public Chesspiece
{
    public:
        Pawn(char team);
        bool MoveCheck(int ogRow, int ogCol, int tRow, int tCol, Chesspiece* playArea[][8]) override;
    protected:
        bool notMoved; 


};
#endif