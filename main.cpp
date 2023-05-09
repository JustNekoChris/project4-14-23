#include <iostream>
#include "Board.hpp"
#include <vector>
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
    if (!font.loadFromFile("src/Poppins/Poppins-Thin.ttf")){
        std::cout << "Error on getting fonts" << endl;
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
        std:: cout << "Load failed" << endl;
        system("pause");
    }
    //Moving chessboard to the proper spot;
    sf::Sprite board_sprite;
    board_sprite.setPosition(100,100);
    board_sprite.setTexture(background);

    //Chess pieces sprite
    sf::Texture pieces_texture;
    if(!pieces_texture.loadFromFile("src/images/Chess_Pieces_Sprite.png")){
        std:: cout << "Loading pieces failed" << endl;
        system("pause");
    }
    pieces_texture.setSmooth(true);
    sf::Sprite w_king;
    w_king.setTexture(pieces_texture);
    w_king.setTextureRect(sf::IntRect(0,0, 128,128));
    w_king.setScale(0.78125f, 0.78125f);
    w_king.setPosition(100,100);
    sf::Sprite w_queen;
    w_queen.setTexture(pieces_texture);
    w_queen.setTextureRect(sf::IntRect(120,0,128,128));
    w_queen.setScale(0.78125f, 0.78125f);
    w_queen.setPosition(200, 100);
    vector<sf::Sprite> w_bishops;
    for (int i = 0; i < 2; i++)
    {
        sf:: Sprite bishop_temp;
        bishop_temp.setTexture(pieces_texture);
        bishop_temp.setTextureRect(sf::IntRect(256,0,128,128));
        bishop_temp.setScale(0.78125f, 0.78125f);
        w_bishops.push_back

    }
    vector<sf::Sprite> w_knights;
    for(int i = 0; i < 2; i++){
        sf:: Sprite tempKnight;
        tempKnight.setTexture(pieces_texture);
        tempKnight.setTextureRect(sf::IntRect(384,0,128,128));
        tempKnight.setScale(0.78125f, 0.78125f);

    }
    sf::Sprite w_rooks;
    for (int i = 0; i < 2; i++)
    {
        sf:: Sprite temprook;
        temprook.setTexture(pieces_texture);
        temprook.setTextureRect(sf::IntRect(512,0,128,128));
        temprook.setScale(0.78125f, 0.78125f);
    }
    
    sf::Sprite w_pawn;
    w_pawn.setTexture(pieces_texture);
    w_pawn.setTextureRect(sf::IntRect(640,0,128,128));
    w_pawn.setScale(0.78125f, 0.78125f);
    w_pawn.setPosition(600, 100);



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
            std:: cout << "Congratulations, Black won in " << game.moves << " turns!" << endl;
        }
        else if(game.whiteAlive && game.gameOver()){
            std:: cout << "Congratulations, White won in " << game.moves << " turns!" << endl;
        }
        else if(game.moves >= 50 && game.gameOver()){
            std:: cout << "Game ends because of the 50 move rule. Tie!" << endl;

        }

            //Render window

        window.clear();
        window.draw(rect);
        window.draw(board_sprite);
        window.draw(text);
        window.draw(w_king);
        window.draw(w_queen);
        window.draw(w_bishop);
        window.draw(w_knight);
        window.draw(w_rook);
        window.draw(w_pawn);
        window.display();

    }
    game.deleter();
    std:: cout << "Game ended!";
    return 0;
}

void createsprite(Board game){
    int wpawnc = 0, wrookc= 0, wknitc = 0, wbishoc = 0;
    int bpawnc = 0, brookc = 0, bknitc = 0;
    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            Chesspiece* temp = game.getPlayAreaElement(row, col);
            if(){
                w_pawn.setPosition(((col+1) * 100) , ((row+1) * 100));
            }
        }
        
    }
    
}
