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
    vector<sf::Sprite> w_bishops;
    vector<sf::Sprite> w_knights;
    vector <sf::Sprite> w_rooks;
    vector <sf::Sprite> w_pawns;

    vector<sf::Sprite> b_bishops;
    vector<sf::Sprite> b_knights;
    vector <sf::Sprite> b_rooks;
    vector<sf::Sprite> b_pawns;
void createsprite(Board game);
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
    for (int i = 0; i < 2; i++)
    {
        sf:: Sprite bishop_temp;
        bishop_temp.setTexture(pieces_texture);
        bishop_temp.setTextureRect(sf::IntRect(256,0,128,128));
        bishop_temp.setScale(0.78125f, 0.78125f);
        w_bishops.push_back(bishop_temp);

    }
    for(int i = 0; i < 2; i++){
        sf:: Sprite tempKnight;
        tempKnight.setTexture(pieces_texture);
        tempKnight.setTextureRect(sf::IntRect(384,0,128,128));
        tempKnight.setScale(0.78125f, 0.78125f);
        w_knights.push_back(tempKnight);
    }
    for (int i = 0; i < 2; i++)
    {
        sf:: Sprite temprook;
        temprook.setTexture(pieces_texture);
        temprook.setTextureRect(sf::IntRect(512,0,128,128));
        temprook.setScale(0.78125f, 0.78125f);
        w_rooks.push_back(temprook); 
    }
    for (int i = 0; i < 8; i++)
    {
        sf:: Sprite temppawn;
        temppawn.setTexture(pieces_texture);
        temppawn.setTextureRect(sf::IntRect(640,0,128,128));
        temppawn.setScale(0.78125f, 0.78125f);
        w_pawns.push_back(temppawn);
        
    }

    //Black pieces
    for (int i = 0; i < 2; i++)
    {
        sf:: Sprite bishop_temp;
        bishop_temp.setTexture(pieces_texture);
        bishop_temp.setTextureRect(sf::IntRect(256,128,128,128));
        bishop_temp.setScale(0.78125f, 0.78125f);
        b_bishops.push_back(bishop_temp);

    }
    for(int i = 0; i < 2; i++){
        sf:: Sprite tempKnight;
        tempKnight.setTexture(pieces_texture);
        tempKnight.setTextureRect(sf::IntRect(384,128,128,128));
        tempKnight.setScale(0.78125f, 0.78125f);
        b_knights.push_back(tempKnight);
    }
    for (int i = 0; i < 2; i++)
    {
        sf:: Sprite temprook;
        temprook.setTexture(pieces_texture);
        temprook.setTextureRect(sf::IntRect(512,128,128,128));
        temprook.setScale(0.78125f, 0.78125f);
        b_rooks.push_back(temprook); 
    }
    
    for (int i = 0; i < 8; i++)
    {
        sf:: Sprite temppawn;
        temppawn.setTexture(pieces_texture);
        temppawn.setTextureRect(sf::IntRect(640,128,128,128));
        temppawn.setScale(0.78125f, 0.78125f);
        b_pawns.push_back(temppawn); 
    }
    if(w_pawns.empty()){
        system("pause");
    }

    sf::Sprite w_king;
    w_king.setTexture(pieces_texture);
    w_king.setTextureRect(sf::IntRect(0,0, 128,128));
    w_king.setScale(0.78125f, 0.78125f);
    w_king.setPosition(500,800);
    sf::Sprite w_queen;
    w_queen.setTexture(pieces_texture);
    w_queen.setTextureRect(sf::IntRect(128,0,128,128));
    w_queen.setScale(0.78125f, 0.78125f);
    w_queen.setPosition(400,800);
    sf::Sprite b_king;
    b_king.setTexture(pieces_texture);
    b_king.setTextureRect(sf::IntRect(0,128, 128,128));
    b_king.setScale(0.78125f, 0.78125f);
    b_king.setPosition(500, 100);
    sf::Sprite b_queen;
    b_queen.setTexture(pieces_texture);
    b_queen.setTextureRect(sf::IntRect(128,128,128,128));
    b_queen.setScale(0.78125f, 0.78125f);
    b_queen.setPosition(400,100);
    



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
        window.draw(b_king);
        window.draw(b_queen);

        w_pawns[0].setPosition(700,700);
        window.draw(w_pawns[0]);
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
            if(temp->getName() == "Pawnn" && temp->getTeam() == 'W'){
                w_pawns[wpawnc].setPosition(((col+1) * 100) , ((row+1) * 100));
                wpawnc +=1;
            }
        }
        
    }
    
}