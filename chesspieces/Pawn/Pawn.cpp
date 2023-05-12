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
                
                if(playArea[ogRow + 1][tCol] == nullptr && playArea[tRow][tCol] == nullptr){
                    // notMoved = false;
                    cout << "Moved double" << endl; 

                    return true;
                } // Checks if there is nothing in the way and that the target is 

                
            }
        }
        if (ogRow + 1 == tRow && ogCol == tCol && playArea[tRow][tCol] == nullptr)
        {
            notMoved = false;
            cout << "Moved 1 up" << endl;
            return true;
        }
        if(playArea[tRow][tCol] != nullptr){
            if (ogRow + 1 == tRow && ogCol + 1 == tCol && playArea[tRow][tCol]->getTeam() == 'B')
            {
                notMoved = false;
                cout << "Moved diagonally (attack) upright" << endl;
                delete playArea[tRow][tCol];
                playArea[tRow][tCol] = nullptr;
                return true;
            }
            if (ogRow + 1  == tRow && ogCol - 1 == tCol && playArea[tRow][tCol]->getTeam() == 'B')
            {
                notMoved = false;
                cout << "Moved diagonally (attack) upleft" << endl;
                delete playArea[tRow][tCol];
                playArea[tRow][tCol] = nullptr;
                return true;
            }
        }
    }
    else
    {
        cout << "black piece" << endl;
        if (notMoved)
        {
            if ((ogRow - 2 == tRow) && ogCol == tCol)
            {
                if(playArea[ogRow - 1][tCol] == nullptr && playArea[tRow][tCol] == nullptr){
                    notMoved = false;
                    cout << "Moved double" << endl; 
                    return true;
                } // Checks if there is nothing in the way

                
            }
        }
        if (ogRow - 1 == tRow && ogCol == tCol)
        {
            notMoved = false;
            cout << "Moved 1 down" << endl;
            return true;
        }
        if(playArea[tRow][tCol] != nullptr){
            if (ogRow - 1 == tRow && ogCol - 1 == tCol && playArea[tRow][tCol]->getTeam() == 'W')
            {
                notMoved = false;
                cout << "Moved diagonally (attack) downleft" << endl;
                delete playArea[tRow][tCol];
                playArea[tRow][tCol] = nullptr;
                return true;
            }
            if (ogRow - 1  == tRow && ogCol + 1 == tCol && playArea[tRow][tCol]->getTeam() == 'W')
            {
                notMoved = false;
                cout << "Moved diagonally (attack) downright" << endl;
                delete playArea[tRow][tCol];
                playArea[tRow][tCol] = nullptr;
                return true;
            }
        }
    }
    return false;
}