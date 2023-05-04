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
    //Text
    sf::Font font;
    if (!font.loadFromFile("src/Poppins/Poppins-Thin.ttf"))
    {
        cout << "Error on getting fonts" << endl;
        system("pause");
    }
    sf::Text text("Welcome to chess.", font, 30);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);
    text.setPosition(50, 25);
    //Background
    sf::RectangleShape rect(sf::Vector2f(1000, 1000)); // create a rectangle shape with dimensions 1000x1000
    sf::Color color1(64, 64, 64); // dark grey color
    sf:: Color black(0,0,0);
    sf:: Color white(255,255,255);
    
    sf::Color color2(192, 192, 192); // dark white color
    rect.setFillColor(color1);
    //Chessboard sprite
    bool turn;
    sf::Texture background; 
    if(!background.loadFromFile("src/images/Chess_Board.png")){
        cout << "Load failed" << endl;
        system("pause");
    }

    //Moving chessboard to the proper spot;
    sf::Sprite board_sprite;
    board_sprite.setPosition(100,100);
    board_sprite.setTexture(background);
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

                if(turn){
                    rect.setFillColor(color1);
                    text.setFillColor(white);
                    turn = false;
                }
                else{
                    rect.setFillColor(color2);
                    text.setFillColor(black);
                    turn = true; 
                }
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
        window.draw(rect);
        window.draw(board_sprite);
        window.draw(text);
        window.display();

    }
    game.deleter();
    cout << "Game ended!";
    return 0;
}