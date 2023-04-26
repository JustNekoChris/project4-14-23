#include "Bishop.hpp"
#include <cmath>

Bishop::Bishop(char team)
{
    name = "Bishop";
    this->team = team; 
}

bool Bishop::MoveCheck(int ogRow, int ogCol, int tRow, int tCol, Chesspiece* playArea[][8])
{
    if(playArea[ogCol][ogRow]->getTeam() == 'W')
    {
        char team = 'W';
    }
    else
    {
        char team = 'B';
    }

    if(abs(tRow - ogRow) == abs(tCol - ogCol))
    {
        int difX = tCol - ogCol, difY = tRow- ogRow;
        if(difX > 0 && difY > 0) // Check up right
        {
            int num = abs(difX);
            for(int i = 0; i < num; i++)
            {
                if(playArea[ogCol + i][ogRow + i] == nullptr)
                {}
                else if(playArea[ogCol + i][ogRow + i]->getTeam() == team)
                {
                    return false;
                }                
            }
            return true;
        }
        else if((difX < 0 && difY > 0)) // Check up left
        {
            int num = abs(difX);
            for(int i = 0; i < num; i++)
            {
                if(playArea[ogCol - i][ogRow + i] == nullptr)
                {}
                else if(playArea[ogCol - i][ogRow + i]->getTeam() == team)
                {
                    return false;
                }                
            }
            return true;
        }
        else if((difX < 0 && difY < 0)) // Check down left
        {
            int num = abs(difX);
            for(int i = 0; i < num; i++)
            {
                if(playArea[ogCol - i][ogRow - i] == nullptr)
                {}
                else if(playArea[ogCol - i][ogRow - i]->getTeam() == team)
                {
                    return false;
                }                
            }
            return true;
        }
        else if((difX > 0 && difY < 0)) // Check down right
        {
            int num = abs(difX);
            for(int i = 0; i < num; i++)
            {
                if(playArea[ogCol + i][ogRow - i] == nullptr)
                {}
                else if(playArea[ogCol + i][ogRow - i]->getTeam() == team)
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