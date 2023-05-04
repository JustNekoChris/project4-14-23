#include "Knight.hpp"
#include <iostream>
#include <cmath>
using namespace std;

Knight::Knight(char team)
{
    name = "Knight";
    this->team = team; 
}
bool Knight::MoveCheck(int ogRow, int ogCol, int tRow, int tCol, Chesspiece* playArea[][8]) 
{
    char teammate; 
    if(team == 'W')
        teammate = 'W';
    else
        teammate = 'B';

    if ((abs(tCol - ogCol) == 2 && abs(tRow - ogRow) == 1) || (abs(tCol - ogCol) == 1 && abs(tRow - ogRow) == 2))
    {
        if(playArea[tRow][tCol] == nullptr)
            {}
        else if (playArea[tRow][tCol]->getTeam() == teammate)
        {
            return false;
        }
        
        return true;     
    }
    return false;
}