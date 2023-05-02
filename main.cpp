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
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}