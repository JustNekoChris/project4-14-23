#include <iostream>
#include "Board.hpp"
using namespace std;

int main(){ 
    Board game;
    while(game.getMoves() < 50 && (!(game.gameOver()))){
        game.display();
        game.turn();
    }
    game.display();
    if(game.blackAlive){
        cout << "Congratulations, Black won in " << game.moves << " turns!" << endl;
    }
    else if(game.whiteAlive){
        cout << "Congratulations, White won in " << game.moves << " turns!" << endl;
    }
    else if(game.moves >= 50){
        cout << "Game ends because of the 50 move rule. Tie!" << endl;

    }
    cout <<"Good Game!";

    return 0; 
}