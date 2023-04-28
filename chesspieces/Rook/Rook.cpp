#include "Rook.hpp"
#include <iostream> 
using namespace std; 
Rook::Rook(char team)
{
    name = "Rook";
    this->team = team; 
}
bool Rook::MoveCheck(int ogRow, int ogCol, int tRow, int tCol, Chesspiece* playArea[][8])
{
    char teammate, enemy;
    if (team == 'W')
        { 
            teammate = 'W';
            enemy = 'B';
        }
    else // black piece
        {
            teammate = 'B';
            enemy = 'W';
        }
        if((tRow - ogRow >= 0) && (tCol - ogCol == 0))
        {
            for(int yT = ogRow + 1; yT < tRow ;yT++) // moves up
            {
                if(playArea[yT][tCol] != nullptr){ // Checks if there is a pieace nullptr are the empty spots on the board 
                cout << "Something in the way" << endl; 
                
                    return false; // If there are no pieaces and then this will continue to be true
                }
            }
            if(playArea[tRow][tCol] != nullptr && playArea[tRow][tCol]->getTeam() == teammate)//checks if there is a white pieace in the way
                {
                    cout << "There is a white peice in the way\n";
                    return false; // checks if there are white team pieaces
                }

            else if (playArea[tRow][tCol] != nullptr && playArea[tRow][tCol]->getTeam() == enemy ) // checks if there are no
            {                                                                                   //spaces and if there is a 
                                                                                                // black pieace remove
                    // remove piece
                    delete playArea[tRow][tCol];
                    playArea[tRow][tCol] = nullptr;// after removing the black pieace we place the rook in that spot
                    std:: cout << "deleted the peice the balck pieace and replaced the pieace with the white rook\n" << endl;
                    return true;
            }
            else 
            {
                cout << "freely moved the pieace - up \n" << endl;
                return true;
            }      
        }
        
        else if((tRow - ogRow <= 0) && (tCol - ogCol == 0))
        {
            for(int yT = ogRow - 1; yT > tRow ;yT--) // moves down
            {
                if(playArea[yT][tCol] != nullptr){ // Checks if there is a pieace nullptr are the empty spots on the board 
                cout << "Something in the way" << endl; 
                
                    return false; // If there are no pieaces and then this will continue to be true
                }
            }
            if(playArea[tRow][tCol] != nullptr && playArea[tRow][tCol]->getTeam() == teammate)//checks if there is a white pieace in the way
                {
                    cout << "There is a white peice in the way\n";
                    return false; // checks if there are white team pieaces
                }

            else if (playArea[tRow][tCol] != nullptr && playArea[tRow][tCol]->getTeam() == enemy ) // checks if there are no
            {                                                                                   //spaces and if there is a 
                                                                                                // black pieace remove
                    // remove piece
                    delete playArea[tRow][tCol];
                    playArea[tRow][tCol] = nullptr;// after removing the black pieace we place the rook in that spot
                    cout << "deleted the peice the balck pieace and replaced the pieace with the white rook\n" << endl;
                    return true;
            }
            else
            {
                cout << "freely moved the pieace - down \n" << endl;
                return true;
            }      
        }
        

        else if((tRow - ogRow == 0) && (tCol - ogCol >= 0))
        {
            for(int yT = ogCol + 1; yT < tCol ;yT++)// moves to the right
            {
                if(playArea[tRow][yT] != nullptr){ // Checks if there is a pieace nullptr are the empty spots on the board 
                cout << "Something in the way" << endl; 
                
                    return false; // If there are no p1ieaces and then this will continue to be true
                }
            }
            if(playArea[tRow][tCol] != nullptr && playArea[tRow][tCol]->getTeam() == teammate)//checks if there is a white pieace in the way
                {
                    cout << "There is a white peice in the way\n";
                    return false; // checks if there are white team pieaces
                }

            else if (playArea[tRow][tCol] != nullptr && playArea[tRow][tCol]->getTeam() == enemy) // checks if there are no
            {                                                                                   //spaces and if there is a 
                                                                                                // black pieace remove
                    // remove piece
                    delete playArea[tRow][tCol];
                    playArea[tRow][tCol] = nullptr;// after removing the black pieace we place the rook in that spot
                    cout << "deleted the peice the balck pieace and replaced the pieace with the white rook\n" << endl;
                    return true;
            }
            else
            {
                // playArea[tRow][tCol] = this;
                cout << "freely moved the pieace - right \n" << endl;
                return true;
            }      
        }   
        
        else if((tRow - ogRow == 0) && (tCol - ogCol <= 0))
        {
            for(int yT = ogCol - 1; yT > tCol ;yT--)// moves to the left
            {
                if(playArea[tRow][yT] != nullptr){ // Checks if there is a pieace nullptr are the empty spots on the board 
                cout << "Something in the way" << endl; 
                
                    return false; // If there are no pieaces and then this will continue to be true
                }
            }
            if(playArea[tRow][tCol] != nullptr && playArea[tRow][tCol]->getTeam() == teammate)//checks if there is a white pieace in the way
                {
                    cout << "There is a white peice in the way\n";
                    return false; // checks if there are white team pieaces
                }

            else if (playArea[tRow][tCol] != nullptr && playArea[tRow][tCol]->getTeam() == enemy) // checks if there are no
            {                                                                                   //spaces and if there is a 
                                                                                                // black pieace remove
                    // remove piece
                    delete playArea[tRow][tCol];
                   playArea[tRow][tCol] = nullptr;// after removing the black pieace we place the rook in that spot
                    cout << "deleted the peice the balck pieace and replaced the pieace with the white rook\n" << endl;
                    return true;
            }
            else
            {
                cout << "freely moved the pieace - left\n" << endl;
                return true;
            }      
        }  
        
    return false; 
}