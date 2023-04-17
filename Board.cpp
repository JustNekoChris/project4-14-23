#include "Board.hpp"
#include "chesspieces/Chesspiece.hpp"
#include "chesspieces/Chesspiece.cpp"
#include "chesspieces/Pawn/Pawn.cpp"
#include "chesspieces/Pawn/Pawn.hpp"
#include <iostream>
using namespace std;

Board:: Board(){
    whiteTurn = true; 
    moves = 0; 

    // for (int i = 0; i < 8; i++)
    // {
    //     for (int j = 0; j < 8; j++)
    //     {
    //         playArea[i][j] = Chesspiece(); 
    //     }
        
    // }
        // initialize all elements of the playArea array to nullptr
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            playArea[i][j] = nullptr;
        }
    }

    // cout << "array of null ptrs made" << endl;
    //Its likely all the following code will be changed except for the initializing team names-> The rest will probably have to use the consttructors
    //From each of the specific piece classes-> Likely a lot of changes in the futur-> 

    for (int i = 0; i < 8; i++)
    {
        playArea[0][i] = new Pawn('W');
        playArea[1][i] = new Pawn('W');

        // cout << "set first team" << endl;
    }

    // cout << "functions called";
    for (int i = 0; i < 8; i++)
    {
        playArea[7][i] = new Pawn('B');
        playArea[6][i] = new Pawn('B');
    }        
    // cout << "created black pawns";
    //Like this will probably for sure be gone (but keeping the names all 5 letters i think is a good touch);
    // playArea[0][0]-> setName("Rookk");
    // playArea[7][0]-> setName("Rookk");
    // playArea[0][1]-> setName("Knite");
    // playArea[7][1]-> setName("Knite");
    // playArea[0][2]-> setName("Bihop");
    // playArea[7][2]-> setName("Bihop");
    // playArea[0][3]-> setName("Queen");
    // playArea[7][3]-> setName("Queen");
    // playArea[0][4]-> setName("Kingg");
    // playArea[7][4]-> setName("Kingg");
    // playArea[0][5]-> setName("Bihop");
    // playArea[7][5]-> setName("Bihop");
    // playArea[0][6]-> setName("Knite");
    // playArea[7][6]-> setName("Knite");
    // playArea[0][7]-> setName("Rookk");
    // playArea[7][7]-> setName("Rookk"); 
}
void Board:: turn(){
    if(whiteTurn){
        cout <<"It is White's turn" << endl;
    }
    else{
        cout << "It is Black's turn" << endl; 
    }
    int ogRow = 0, ogCol = 0;
    int x = 0,y = 0;


    cout<< "Which piece would you like to move? Enter the x axis first(1-8)" << endl;
    while( ogRow<1 || ogRow>8){
        cin >> ogRow;
    }
    ogRow-=1;
    cout << "Enter the y axis now" << endl;
    while( ogCol<1 || ogCol>8){
        cin >> ogCol;
    }
    ogCol-=1;
    

    cout << "You have selected " << playArea[ogCol][ogRow]-> getName() << " on team " << playArea[ogCol][ogRow]-> getTeam() << endl;
    

    cout<< "Where would you like to move? Enter the x axis first (1-8)" << endl;
    while( x<1 || x>8){
        cin >> x;
    }
    x -=1;
    cout << "Enter the y axis now" << endl;
    while( y<1 || y>8){
        cin >> y;
    }
    y-=1;
    cout<< "You have chosen " << x+1 << "," << y+1 << endl; 
    swapPiece( x, y, ogRow, ogCol);
    cout << "ran swap" << endl;
    //Here would be code that moves stuff around, checks if king is moving into wrong spot, handles captures, etc-> 
    //I imagine this function will be changed a LOT from what it is now-> 
    //Idea checklist:
    //Check if occupied by opponent or team piece(return false, might have to turn this into a bool function or something, or make one)
    //Check if valid move based on piece
    // If empty, swap pieces
    // If occupied by enemy, make enemy default constructor again (or destroy it somehow), and then swap
    
    moves++;
    swapTurn();

    
}
void Board:: swapTurn(){
    //Might not change much either
    if(whiteTurn){
        whiteTurn = false;
    }
    else{
        whiteTurn = true;
    }
}
void Board:: display(){
    //This display code I dont imagine changing much
    for (int row = 7; row >=0; row--)
    {   
        cout << row + 1 <<"    "; 
        for (int col = 0; col <8; col++)
        {
            // cout << "deepest layer of loop" << endl; 
            if(playArea[row][col] == nullptr){
                cout << "nonam" << "\t\t";
            }
            else{
            cout << playArea[row][col]-> getTeam() << playArea[row][col]-> getName() << "\t\t";
            }
        }
        cout << endl << endl;
    }
    cout << "    ";
    for (int i = 0; i < 8; i++)
    {
        cout << "  " << i+1<< "  " << "\t\t";
    }
    cout << endl;
}
void Board :: swapPiece(int tRow,int tCol,int ogRow,int ogCol)
{
    Chesspiece* piece1 = playArea[ogCol][ogRow];
    Chesspiece* piece2 = playArea[tCol][tRow];
    swap(piece1, piece2);
    playArea[ogCol][ogRow] = piece1;
    playArea[tCol][tRow] = piece2;
   
}