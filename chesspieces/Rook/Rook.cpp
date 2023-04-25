#include "Rook.hpp"
#include <iostream> 

Rook::Rook(char team)
{
    name = "Rook";
    this->team = team; 
}
bool Rook::MoveCheck(int ogRow, int ogCol, int tRow, int tCol, Chesspiece* playArea[][8])
{
    if (team == 'W')
        {
            for(int yT = ogRow + 1; yT < tRow ;yT++)
            {
                if(playArea[yT][tCol] != nullptr) // Checks if there is a pieace nullptr are the empty spots on the board 
                    return false; // If there are no pieaces and then this will continue to be true
            }
            if(playArea[tRow][tCol] != nullptr && playArea[tRow][tCol]->getTeam() == 'W')
                return false; // checks if there are white team pieaces
            else if (playArea[tRow][tCol] != nullptr && playArea[tRow][tCol]->getTeam() == 'B' ) // checks if there are no
            {                                                                                   //spaces and if there is a 
                                                                                                // black pieace remove
                    // remove piece
                    delete playArea[tRow][tCol];
                    playArea[tRow][tCol] = this;// after removing the black pieace we place the rook in that spot
                    return true;
            }
            else
            {
                playArea[tRow][tCol] = this;
                return true;
            }      
            
        }
    else 
    {
        return false;
    }

      
}