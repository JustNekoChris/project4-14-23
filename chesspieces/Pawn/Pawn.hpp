#ifndef PAWN_HPP
#define PAWN_HPP
#include "../Chesspiece.hpp"
#include "../Chesspiece.hpp"
#include "../../Board.hpp"
class Pawn: public Chesspiece
{
    public:
        Pawn(char team);

        bool MoveCheck(int ogRow, int ogCol, int tRow, int tCol, Chesspiece* playArea[][8]) override{
            if (team == 'W')
            {
                if (notMoved)
                {
                    if ((ogRow + 2 == tRow) && ogCol == tCol)
                    {
                        return true;
                    }
                }
                if (ogRow + 1 == tRow && ogCol == tCol)
                {
                    return true;
                }
                if (ogCol + 1 == tRow && ogCol + 1 == tCol)
                {
                    return true;
                }
            }
            else
            {
                int woo = 0; 
            }
            notMoved = false;
            return false;
        }

    protected:
        bool notMoved; 


};
#endif