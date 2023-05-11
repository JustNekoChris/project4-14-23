#include <iostream>
#include "Board.hpp"
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;
vector<sf::Sprite> w_bishops;
vector<sf::Sprite> w_knights;
vector <sf::Sprite> w_rooks;
vector <sf::Sprite> w_pawns;

vector<sf::Sprite> b_bishops;
vector<sf::Sprite> b_knights;
vector <sf::Sprite> b_rooks;
vector<sf::Sprite> b_pawns;
int ogRow = -1, ogCol = -1, tRow = -1, tCol = -1; 
bool click2coord(Board game, int mousePositionx, int mousePositiony);

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
                if (event.mouseButton.button == sf::Mouse::Left){
                    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                
                    // Check if the mouse click is within a certain area col, row.
                    // Chesspiece* lol = game.getPlayAreaElement(0,0);
                    // if(lol != nullptr){
                    //     cout << "the pointer wasn't empty";
                    //     system("pause");
                    // }

                    if(click2coord(game, mousePosition.x, mousePosition.y)){
                        system("pause");
                    }
                    //1, 8  

                }
                break;
                
            }
            

            
        }
        if(game.getTurn()){
            // turn = false;
            rect.setFillColor(color2);
            text.setFillColor(black);
        }
        else{
            rect.setFillColor(color1);
            text.setFillColor(white);
            // turn = true; 
        }
        //Game Updates 
        if (game.getMoves() < 50 && (!(game.gameOver()))){
            // game.turn();
        }
        game.display();

        //Win Conditions;
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
        int wpawnc = 0, wrookc= 0, wknitc = 0, wbishoc = 0;
        int bpawnc = 0, brookc = 0, bknitc = 0, bbishoc = 0;
        for (int row = 0; row < 8; row++)
        {
            for (int col = 0; col < 8; col++)
            {
                Chesspiece* temp = game.getPlayAreaElement(row, col);
                if(temp != nullptr){
                    if(temp->getName() == "Pawnn" && temp->getTeam() == 'W'){
                        w_pawns[wpawnc].setPosition(((col+1) * 100) , ((8-row) * 100));
                        wpawnc +=1;
                        window.draw(w_pawns[wpawnc-1]);
                    }
                    else if(temp->getName() == "Rook" && temp->getTeam() == 'W'){
                        w_rooks[wrookc].setPosition(((col+1) * 100) , ((8-row) * 100));
                        wrookc+=1;
                        window.draw(w_rooks[wrookc-1]);
                    }
                    else if(temp->getName() == "Kingg" && temp->getTeam() == 'W'){
                        w_king.setPosition(((col+1) * 100) , ((8-row) * 100));
                        window.draw(w_king);
                    }
                    else if(temp->getName() == "Queen" && temp->getTeam() == 'W'){
                        w_queen.setPosition(((col+1) * 100) , ((8-row) * 100));
                        window.draw(w_queen);
                    }
                    else if(temp->getName() == "Bishop" && temp->getTeam() == 'W'){
                        w_bishops[wbishoc].setPosition(((col+1) * 100) , ((8-row) * 100));
                        wbishoc+=1;
                        window.draw(w_bishops[wbishoc-1]);
                    }
                    else if(temp->getName() == "Knight" && temp->getTeam() == 'W'){
                        w_knights[wknitc].setPosition(((col+1) * 100) , ((8-row) * 100));
                        wknitc+=1;
                        window.draw(w_knights[wknitc-1]);
                    }

                    //Black pieces
                    if(temp->getName() == "Pawnn" && temp->getTeam() == 'B'){
                        b_pawns[bpawnc].setPosition(((col+1) * 100) , ((8-row) * 100));
                        bpawnc +=1;
                        window.draw(b_pawns[bpawnc-1]);
                    }
                    else if(temp->getName() == "Rook" && temp->getTeam() == 'B'){
                        b_rooks[brookc].setPosition(((col+1) * 100) , ((8-row) * 100));
                        brookc+=1;
                        window.draw(b_rooks[brookc-1]);
                    }
                    else if(temp->getName() == "Kingg" && temp->getTeam() == 'B'){
                        b_king.setPosition(((col+1) * 100) , ((8-row) * 100));
                        window.draw(b_king);
                    }
                    else if(temp->getName() == "Queen" && temp->getTeam() == 'B'){
                        b_queen.setPosition(((col+1) * 100) , ((8-row) * 100));
                        window.draw(b_queen);
                    }
                    else if(temp->getName() == "Bishop" && temp->getTeam() == 'B'){
                        b_bishops[bbishoc].setPosition(((col+1) * 100) , ((8-row) * 100));
                        bbishoc+=1;
                        window.draw(b_bishops[bbishoc-1]);
                    }
                    else if(temp->getName() == "Knight" && temp->getTeam() == 'B'){
                        b_knights[bknitc].setPosition(((col+1) * 100) , ((8-row) * 100));
                        bknitc+=1;
                        window.draw(b_knights[bknitc-1]);
                    }
                }
            }
        }
        window.draw(b_king);
        window.draw(b_queen);

        window.display();

    }
    game.deleter();
    std:: cout << "Game ended!";
    return 0;
}
bool click2coord(Board game, int mousePositionx, int mousePositiony){

    //The first Row (within game logic),
    for (int col = 1; col <= 8; ++col) {
        if (mousePositionx >= col * 100 && mousePositionx <= (col + 1) * 100 &&
            mousePositiony >= 800 && mousePositiony <= 900) {
            if (ogRow == -1 && ogCol == -1) {
                if (game.getPlayAreaElement(0, col-1) != nullptr) {
                    // Chesspiece* = game.getPlayAreaElement()
                    ogRow = 0;
                    ogCol = col - 1;
                    return true;
                }
            } else if (tRow == -1 && tCol == -1) {
                tRow = 0;
                tCol = col - 1;
            }
        }
    } 
    //2nd row
    for (int col = 1; col <= 8; ++col) {
        if (mousePositionx >= col * 100 && mousePositionx <= (col + 1) * 100 &&
            mousePositiony >= 700 && mousePositiony <= 800) {
            if (ogRow == -1 && ogCol == -1) {
                if (game.getPlayAreaElement(1, col-1) != nullptr) {
                    ogRow = 1;
                    ogCol = col - 1;
                    return true;
                }
            } else if (tRow == -1 && tCol == -1) {
                tRow = 1;
                tCol = col-1;
            }
        }
    } 
    //3rd row 
    for (int col = 1; col <= 8; ++col) {
        if (mousePositionx >= col * 100 && mousePositionx <= (col + 1) * 100 &&
            mousePositiony >= 600 && mousePositiony <= 700) {
            if (ogRow == -1 && ogCol == -1) {
                if (game.getPlayAreaElement(2, col-1) != nullptr) {
                    ogRow = 2;
                    ogCol = col-1;
                    return true;
                }
            } else if (tRow == -1 && tCol == -1) {
                tRow = 2;
                tCol = col-1;
            }
        }
    } 
    //4th row
    for (int col = 1; col <= 8; ++col) {
        if (mousePositionx >= col * 100 && mousePositionx <= (col + 1) * 100 &&
            mousePositiony >= 500 && mousePositiony <= 600) {
            if (ogRow == -1 && ogCol == -1) {
                if (game.getPlayAreaElement(3, col-1) != nullptr) {
                    ogRow = 3;
                    ogCol = col-1;
                    return true;
                }
            } else if (tRow == -1 && tCol == -1) {
                tRow = 3;
                tCol = col-1;
            }
        }
    } 
    //5th row
    for (int col = 1; col <= 8; ++col) {
        if (mousePositionx >= col * 100 && mousePositionx <= (col + 1) * 100 &&
            mousePositiony >= 400 && mousePositiony <= 500) {
            if (ogRow == -1 && ogCol == -1) {
                if (game.getPlayAreaElement(4, col-1) != nullptr) {
                    ogRow = 4;
                    ogCol = col-1;
                    return true;
                }
            } else if (tRow == -1 && tCol == -1) {
                tRow = 4;
                tCol = col-1;
            }
        }
    } 
    //6th row
    for (int col = 1; col <= 8; ++col) {
        if (mousePositionx >= col * 100 && mousePositionx <= (col + 1) * 100 &&
            mousePositiony >= 300 && mousePositiony <= 400) {
            if (ogRow == -1 && ogCol == -1) {
                if (game.getPlayAreaElement(5, col-1) != nullptr) {
                    ogRow = 5;
                    ogCol = col;
                    return true;
                }
            } else if (tRow == -1 && tCol == -1) {
                tRow = 5;
                tCol = col-1;
            }
        }
    } 
    //7th row
    for (int col = 1; col <= 8; ++col) {
        if (mousePositionx >= col * 100 && mousePositionx <= (col + 1) * 100 &&
            mousePositiony >= 200 && mousePositiony <= 300) {
            if (ogRow == -1 && ogCol == -1) {
                if (game.getPlayAreaElement(6, col-1) != nullptr) {
                    ogRow = 6;
                    ogCol = col-1;
                    return true;
                }
            } else if (tRow == -1 && tCol == -1) {
                tRow = 6;
                tCol = col-1;
            }
        }
    } 
    //8th
    for (int col = 1; col <= 8; ++col) {
        if (mousePositionx >= col * 100 && mousePositionx <= (col + 1) * 100 &&
            mousePositiony >= 100 && mousePositiony <= 200) {
            if (ogRow == -1 && ogCol == -1) {
                if (game.getPlayAreaElement(7, col-1) != nullptr) {
                    ogRow = 7;
                    ogCol = col-1;
                    return true;
                }
            } else if (tRow == -1 && tCol == -1) {
                tRow = 7;
                tCol = col-1;
            }
        }
    } 

    return false; 

}