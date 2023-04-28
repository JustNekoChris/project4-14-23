#include "Bishop.hpp"
#include <cmath>
#include <iostream>
using namespace std;

Bishop::Bishop(char team)
{
    name = "Bishop";
    this->team = team; 
}

bool Bishop::MoveCheck(int ogRow, int ogCol, int tRow, int tCol, Chesspiece* playArea[][8])
{
    char team, other;
    if(playArea[ogRow][ogCol]->getTeam() == 'W')
    {
        team = 'W'; 
        other = 'B';
    }
    else
    {
        team = 'B';
        other = 'W';
    }

    if(abs(tRow - ogRow) == abs(tCol - ogCol))
    {
        int difX = tCol - ogCol, difY = tRow- ogRow;
        if(difX > 0 && difY > 0) // Check up right
        {
            int num = abs(difX);
            for(int i = 1; i <= num; i++)
            {
                if(playArea[ogRow + i][ogCol + i] == nullptr)
                {}
                else if(playArea[ogRow + i][ogCol + i]->getTeam() == team || (playArea[ogRow + i][ogCol + i]->getTeam() == other && i != num))
                {
                    return false;
                }                
            }
            return true;
        }
        else if((difX < 0 && difY > 0)) // Check up left
        {
            int num = abs(difX);
            for(int i = 1; i <= num; i++)
            {
                if(playArea[ogRow + i][ogCol - i] == nullptr)
                {}
                else if(playArea[ogRow + i][ogCol - i]->getTeam() == team || (playArea[ogRow + i][ogCol - i]->getTeam() == other && i != num))
                {
                    return false;
                }        
            }
            return true;
        }
        else if((difX < 0 && difY < 0)) // Check down left
        {
            int num = abs(difX);
            for(int i = 1; i <= num; i++)
            {
                if(playArea[ogRow - i][ogCol - i] == nullptr)
                {}
                else if(playArea[ogRow - i][ogCol - i]->getTeam() == team || (playArea[ogRow - i][ogCol - i]->getTeam() == other && i != num))
                {
                    return false;
                }                
            }
            return true;
        }
        else if((difX > 0 && difY < 0)) // Check down right
        {
            int num = abs(difX);
            for(int i = 1; i <= num; i++)
            {
                if(playArea[ogRow - i][ogCol + i] == nullptr)
                {}
                else if(playArea[ogRow - i][ogCol + i]->getTeam() == team || (playArea[ogRow - i][ogCol + i]->getTeam() == other && i != num))
                {
                    return false;
                }                
            }
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}