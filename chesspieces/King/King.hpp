#ifndef KING_HPP
#define KING_HPP
#include "../Chesspiece.hpp"
#include "../Chesspiece.hpp"
#include "../../Board.hpp"
class King : public Chesspiece
{
    public:
        King(char team);
        bool MoveCheck(int ogRow, int ogCol, int tRow, int tCol, Chesspiece* playArea[][8]) override;
    protected:
        bool notMoved;
        //Might Not Need this variable
        bool alive;
};
#endif