#include "Queen.hpp"
#include <cmath>
#include <iostream>
using namespace std;

Queen::Queen(char team)
{
    name = "Queen";
    this->team = team; 
}

bool Queen::MoveCheck(int ogRow, int ogCol, int tRow, int tCol, Chesspiece* playArea[][8])
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
    else if((abs(tRow - ogRow) == 0 && abs(tCol - ogCol) != 0) || (abs(tRow - ogRow) != 0 && abs(tCol - ogCol) == 0))
    {
        int difX = tCol - ogCol, difY = tRow - ogRow;
        if(difX > 0 && difY == 0) // Check right
        {
            int num = abs(difX);
            for(int i = 1; i <= num; i++)
            {
                if(playArea[ogRow][ogCol + i] == nullptr)
                {}
                else if(playArea[ogRow][ogCol + i]->getTeam() == team || (playArea[ogRow][ogCol + i]->getTeam() == other && i != num))
                {
                    return false;
                }                
            }
            return true;
        }
        else if((difX < 0 && difY == 0)) // Check left
        {
            int num = abs(difX);
            for(int i = 1; i <= num; i++)
            {
                if(playArea[ogRow][ogCol - i] == nullptr)
                {}
                else if(playArea[ogRow][ogCol - i]->getTeam() == team || (playArea[ogRow][ogCol - i]->getTeam() == other && i != num))
                {
                    return false;
                }        
            }
            return true;
        }
        else if((difX == 0 && difY > 0)) // Check up 
        {
            int num = abs(difY);
            for(int i = 1; i <= num; i++)
            {
                if(playArea[ogRow + i][ogCol] == nullptr)
                {}
                else if(playArea[ogRow + i][ogCol]->getTeam() == team || (playArea[ogRow + i][ogCol]->getTeam() == other && i != num))
                {
                    return false;
                }                
            }
            return true;
        }
        else if((difX == 0 && difY < 0)) // Check down 
        {
            int num = abs(difY);
            for(int i = 1; i <= num; i++)
            {
                if(playArea[ogRow - i][ogCol] == nullptr)
                {}
                else if(playArea[ogRow - i][ogCol]->getTeam() == team || (playArea[ogRow - i][ogCol]->getTeam() == other && i != num))
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
    {
        return false;
    }
}