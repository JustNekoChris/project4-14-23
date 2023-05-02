#ifndef QUEEN_HPP
#define QUEEN_HPP
#include "../Chesspiece.hpp"
#include "../Chesspiece.hpp"
#include "../../Board.hpp"
class Queen : public Chesspiece
{
    public:
        Queen(char team);
        bool MoveCheck(int ogRow, int ogCol, int tRow, int tCol, Chesspiece* playArea[][8]) override;
    protected:
};
#endif 