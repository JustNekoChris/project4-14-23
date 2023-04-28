#include "King.hpp"
#include <iostream>
using namespace std;
King:: King(char team): Chesspiece(){
    this-> team = team;
    name = "Kingg";
}

bool King:: MoveCheck(int ogRow, int ogCol, int tRow, int tCol, Chesspiece* playArea[][8]) {
    char team, enemy;
    if(playArea[ogRow][ogCol]->getTeam() == 'W'){
        team = 'W';
        enemy = 'B';
    }
    else{ //Team black
        team = 'B';
        enemy = 'W';

    }
    if(tRow - ogRow == 1 && ogCol == tCol){
        cout << "Moved up" << endl;
        if(playArea[tRow][tCol] != nullptr){
            if(playArea[tRow][tCol]->getTeam() == enemy){
                delete playArea[tRow][tCol];
                playArea[tRow][tCol] = nullptr;
                return true;
                
            }
            //This means it was your team 
            return false;
        }
        else{
            return true; 
        }

    }
    else if(tRow - ogRow == -1 && ogCol == tCol){
        cout << "Moved Down" << endl;
        if(playArea[tRow][tCol] != nullptr){
            if(playArea[tRow][tCol]->getTeam() == enemy){
                return true;
                
            }
            //This means it was your team 
            return false;
        }
        else{
            return true; 
        }
    }
    else if (tCol - ogCol == 1 && ogRow == tRow){
        cout << "Moved right" << endl;
        if(playArea[tRow][tCol] != nullptr){
            if(playArea[tRow][tCol]->getTeam() == enemy){
                return true;
                
            }
            //This means it was your team 
            return false;
        }
        else{
            return true; 
        }
    }
    else if(tCol - ogCol == -1 && ogRow ==  tRow){
        cout << "Moved Left" << endl; 
        if(playArea[tRow][tCol] != nullptr){
            if(playArea[tRow][tCol]->getTeam() == enemy){
                return true;
                
            }
            //This means it was your team 
            return false;
        }
        else{
            return true; 
        }

    }
    else if (tCol == ogCol + 1 && tRow == ogRow + 1){
        cout << "Upright" << endl; 
        if(playArea[tRow][tCol] != nullptr){
            if(playArea[tRow][tCol]->getTeam() == enemy){
                return true;
                
            }
            //This means it was your team 
            return false;
        }
        else{
            return true; 
        }

    }
    else if( tRow == ogRow + 1 && tCol == ogCol - 1){
        cout << "Upleft" << endl; 
        if(playArea[tRow][tCol] != nullptr){
            if(playArea[tRow][tCol]->getTeam() == enemy){
                return true;
                
            }
            //This means it was your team 
            return false;
        }
        else{
            return true; 
        }
    }
    else if(tRow == ogRow - 1 && tCol == ogCol - 1){
        cout << "Down left" << endl;
        if(playArea[tRow][tCol] != nullptr){
            if(playArea[tRow][tCol]->getTeam() == enemy){
                return true;
                
            }
            //This means it was your team 
            return false;
        }
        else{
            return true; 
        }
    }
    else if(tRow == ogRow - 1 && tCol == ogCol + 1){
        cout << "Down right" << endl;
        if(playArea[tRow][tCol] != nullptr){
            if(playArea[tRow][tCol]->getTeam() == enemy){
                return true;
                
            }
            //This means it was your team 
            return false;
        }
        else{
            return true;
        }
    }
    return false;
}
