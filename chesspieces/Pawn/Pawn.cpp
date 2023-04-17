#include "Pawn.hpp"
#include <iostream>

Pawn::Pawn(char team): Chesspiece()
{
    name = "Pawnn";
    this->team = team;
    notMoved = true;
}
bool Pawn::MoveCheck(int ogRow, int ogCol, int tRow, int tCol, Chesspiece*playArea[][8]) 
{
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
    }
    notMoved = false;
    return false;
}