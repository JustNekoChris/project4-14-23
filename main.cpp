#include <iostream>
#include "Board.hpp"
#include <SFML/Graphics.hpp>

using namespace std;

// int main(){ 
//     Board game;
//     while(game.getMoves() < 50 && (!(game.gameOver()))){
//         game.display();
//         game.turn();
//     }
//     game.display();
//     if(game.blackAlive){
//         cout << "Congratulations, Black won in " << game.moves << " turns!" << endl;
//     }
//     else if(game.whiteAlive){
//         cout << "Congratulations, White won in " << game.moves << " turns!" << endl;
//     }
//     else if(game.moves >= 50){
//         cout << "Game ends because of the 50 move rule. Tie!" << endl;

//     }
//     cout <<"Good Game!";

//     return 0; 
// }

int main()
{
    Board game;
    //Window
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Minimalistic Chess", sf:: Style:: Default);
    sf::Event event;
    //Game Loop
    while (window.isOpen())
    {
        //Check user Input
        while (window.pollEvent(event))
        {
            switch(event.type){
            case sf::Event::Closed:
                window.close();
                break; 
            case sf::Event::MouseButtonPressed:
                break;
                
            }
            
        }
        //Game Updates 
        if (game.getMoves() < 50 && (!(game.gameOver()))){
            // game.turn();
        }
        game.display();
        if(game.blackAlive && game.gameOver()){
            cout << "Congratulations, Black won in " << game.moves << " turns!" << endl;
        }
        else if(game.whiteAlive && game.gameOver()){
            cout << "Congratulations, White won in " << game.moves << " turns!" << endl;
        }
        else if(game.moves >= 50 && game.gameOver()){
            cout << "Game ends because of the 50 move rule. Tie!" << endl;

        }

        //Render window
        window.clear();
        window.display();
    }
    return 0;
}