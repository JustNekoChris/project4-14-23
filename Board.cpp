#include "Board.hpp"
#include "chesspieces/Chesspiece.hpp"
#include "chesspieces/Chesspiece.cpp"
#include "chesspieces/Pawn/Pawn.cpp"
#include "chesspieces/Pawn/Pawn.hpp"
#include "chesspieces/Rook/Rook.hpp"
#include "chesspieces/Rook/Rook.cpp"
#include "chesspieces/Bishop/Bishop.cpp"
#include "chesspieces/Bishop/Bishop.hpp"
#include "chesspieces/King/King.hpp"
#include "chesspieces/King/King.cpp"
#include "chesspieces/Knight/Knight.hpp"
#include "chesspieces/Knight/Knight.cpp"
#include "chesspieces/Queen/Queen.hpp"
#include "chesspieces/Queen/Queen.cpp"
#include <iostream>
using namespace std;

Board:: Board(){
    whiteTurn = true; 
    moves = 0; 

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            playArea[i][j] = nullptr; // empty address 
        }
    }
        // initialize all elements of the playArea array to nullptr
    // for (int i = 0; i < 8; i++) {
    //     for (int j = 0; j < 8; j++) {
    //         playArea[i][j] = nullptr;
    //     }
    // }

    // cout << "array of null ptrs made" << endl;
    //Its likely all the following code will be changed except for the initializing team names-> The rest will probably have to use the consttructors
    //From each of the specific piece classes-> Likely a lot of changes in the futur-> 
    playArea[0][4] = new King('W');
    playArea[7][4] = new King('B'); 
    for (int i = 0; i < 8; i++)
    {
        //playArea[0][i] = new Pawn('W');
        playArea[1][i] = new Pawn('W');


        // cout << "set first team" << endl;
    }

    // cout << "functions called";
    for (int i = 0; i < 8; i++)
    {
        // playArea[7][i] = new Pawn('B');
        playArea[6][i] = new Pawn('B');
    }        
    // cout << "created black pawns";
    //Like this will probably for sure be gone (but keeping the names all 5 letters i think is a good touch);

    //Rook
    playArea[0][0] = new Rook('W');
    playArea[0][7] = new Rook('W');
    playArea[7][0] = new Rook('B');
    playArea[7][7] = new Rook('B');

    // Bishop
    playArea[0][2] = new Bishop('W');
    playArea[0][5] = new Bishop('W');
    playArea[7][2] = new Bishop('B');
    playArea[7][5] = new Bishop('B');

    // Knight
    playArea[0][1] = new Knight('W');
    playArea[0][6] = new Knight('W');
    playArea[7][1] = new Knight('B');
    playArea[7][6] = new Knight('B');

    playArea[0][3] = new Queen('W');
    playArea[7][3] = new Queen('B');
    

    whiteAlive = true;
    blackAlive = true;
}


int Board:: turn(){
    if(whiteTurn){
        cout <<"It is White's turn" << endl;
    }
    else{
        cout << "It is Black's turn" << endl; 
    }
    int ogRow = 0, ogCol = 0;
    int tRow = 0, tCol = 0;

    bool notPicked = true;
    while(notPicked){
        ogRow = 0, ogCol = 0; 
        cout<< "Which piece would you like to move? Enter the x axis first(1-8)" << endl;
        while( (ogCol<1 || ogCol>8) && ogCol != 69){
            cin >> ogCol;
        }
        ogCol-=1;
        cout << "Enter the y axis now" << endl;
        while( ogRow<1 || ogRow>8 && ogRow != 69){
            cin >> ogRow;
        }
        ogRow-=1;
        if (ogRow == 68 || ogCol == 68) // will delete Board if written 69
        {
            return 69;
        }
        else if(playArea[ogRow][ogCol] != nullptr){
            notPicked = false; 
        }
        else
        {
            cout << "Not a piece, pick again" << endl;
        }
    }
    cout << "You have selected " << playArea[ogRow][ogCol]-> getName() << " on team " << playArea[ogRow][ogCol]-> getTeam() << endl;
    

    cout<< "Where would you like to move? Enter the x axis first (1-8)" << endl;
    while( tCol<1 || tCol>8){
        cin >> tCol;
    }
    tCol -=1;
    cout << "Enter the y axis now" << endl;
    while( tRow<1 || tRow>8){
        cin >> tRow;
    }
    tRow-=1;
    cout<< "You have chosen " << tCol+1 << "," << tRow+1 << endl; 

    //Here would be code that moves stuff around, checks if king is moving into wrong spot, handles captures, etc-> 
    //I imagine this function will be changed a LOT from what it is now-> 
    //Idea checklist:
    //Check if occupied by opponent or team piece(return false, might have to turn this into a bool function or something, or make one)
    
    //Check if valid move based on piece
    //USE THIS FOR QUICK DEBUGGING:
    // swapPiece( tRow, tCol, ogRow, ogCol);
    // swapTurn(); 

    // MAIN MOVECHECKING CODE
    if(playArea[ogRow][ogCol]-> MoveCheck(ogRow, ogCol, tRow, tCol, playArea)){
        //Destruction code
        delete playArea[tRow][tCol];
        playArea[tRow][tCol] = nullptr;
        swapPiece( tRow, tCol, ogRow, ogCol);
        cout << "ran swap" << endl;
        moves++;
        if(playArea[tRow][tCol]->getName() == "Pawnn"){
            checkPawnPromotion(); 
        }
        swapTurn();
    }
    else{
        cout << "Not valid move, please try again" << endl; 
    }

    // If empty, swap pieces
    // If occupied by enemy, make enemy default constructor again (or destroy it somehow), and then swap

    return 0;
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
            if(playArea[row][col] == nullptr){
                cout << "noname" << "\t\t";
            }
            else{
            cout << playArea[row][col]-> getTeam() << playArea[row][col]-> getName() << "\t\t";
            }
        }
        cout << endl << endl << endl << endl;
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
    Chesspiece* piece1 = playArea[ogRow][ogCol];
    Chesspiece* piece2 = playArea[tRow][tCol];
    swap(piece1, piece2);
    playArea[tRow][tCol] = piece2;
    //playArea[ogRow][ogCol] = piece1;
    playArea[ogRow][ogCol] = nullptr;
   
}
void Board:: checkPawnPromotion(){
    // char user;
    for (int i = 0; i < 8; i++)
    {   if(playArea[7][i] != nullptr){
            if(playArea[7][i]->getTeam() == 'W' && playArea[7][i]->getName() == "Pawnn"){
                delete playArea[7][i];
                playArea[7][i] = new Queen('W');
            }
        }
    }
    //This could be optimized very easily by passing in the team into a function after checking if it was white or black. 
    for (int i = 0; i < 8; i++)
    {   
        if(playArea[0][i] != nullptr){
            if(playArea[0][i]->getTeam() == 'B' && playArea[0][i]->getName() == "Pawnn"){
                delete playArea[0][i];
                playArea[0][i] = new Queen('B');
            }
        }
    }
    
}
bool Board:: gameOver(){
    bool tempWAlive = false, tempBAlive = false;
    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            if(playArea[row][col] != nullptr){
                if(playArea[row][col]->getName() == "Kingg"){
                    if(playArea[row][col]->getTeam() == 'W'){
                        tempWAlive = true;
                    }
                    else if(playArea[row][col]->getTeam() == 'B'){
                        tempBAlive = true;
                    }
                }
            }
        }
        
    }

    whiteAlive = tempWAlive;
    blackAlive = tempBAlive;
    if(whiteAlive == false || blackAlive == false){
        return true;
    }
    return false; 
}

void Board::deleter()
{
    for(int x = 0; x < 8; x++)
    {
        for(int y = 0; y < 8; y++)
        {
            if (playArea[y][x] == nullptr)
            {
                /* code */
            }
            else
            {
                delete playArea[y][x];
            }
            
        }
    }
    cout << "Deleted board :]" << endl;
}
// std::string Board::getPiece(int row, int col) const {
// }