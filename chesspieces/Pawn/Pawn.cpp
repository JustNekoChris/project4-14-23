#include "Pawn.hpp"
#include <iostream>
using namespace std;
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
                notMoved = false;
                cout << "Moved double" << endl; 
                return true;
                
            }
        }
        if (ogRow + 1 == tRow && ogCol == tCol)
        {
            notMoved = false;
            cout << "Moved 1 up";
            return true;
        }
        if (ogCol + 1 == tRow && ogCol + 1 == tCol)
        {
            notMoved = false;
            cout << "Moved diagonally";
            return true;
        }
    }
    else
    {
        cout << "black piece";
    }
    cout << "No condition met";
    return false;
}