#include <iostream>
#include "Board.hpp"
using namespace std;

int main(){ 
    cout << "hi " << endl;
    // Chesspiece test;
    // cout << test.getName() << endl; 
    Board game;
    while(game.getMoves() < 50){
        // cout << "predisplay" << endl;
        game.display();
        // cout << "post display" << endl; 
        game.turn();
      
    }
    
    cout <<"Good Game!";
    cout << "Testing out the source control that vscode has. Nice job team!";
    return 0; 
}