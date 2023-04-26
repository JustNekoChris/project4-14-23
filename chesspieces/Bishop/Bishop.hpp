#ifndef BISHOP_HPP
#define BISHOP_HPP
#include "../Chesspiece.hpp"
#include "../Chesspiece.hpp"
#include "../../Board.hpp"

class Bishop : public Chesspiece
{
    public:
        Bishop(char team);
        bool MoveCheck(int ogRow, int ogCol, int tRow, int tCol, Chesspiece* playArea[][8]) override;
    protected:

};
#endif