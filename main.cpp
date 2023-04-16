#include <iostream>
#include "Board.hpp"
using namespace std;

int main(){ 
    cout << "hi " << endl;
    // Chesspiece test;
    // cout << test.getName() << endl; 
    Board game;
    while(game.getMoves() < 50){
        game.display();
        game.turn();
    }

    cout << "Testing out the source control that vscode has. Nice job team!";
    return 0; 
}