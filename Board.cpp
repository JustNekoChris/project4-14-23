#include "Board.hpp"
#include "chesspieces/Chesspiece.hpp"
#include "chesspieces/Chesspiece.cpp"
#include "chesspieces/Pawn/Pawn.cpp"
#include "chesspieces/Pawn/Pawn.hpp"
#include "chesspieces/Rook/Rook.hpp"
#include "chesspieces/Rook/Rook.cpp"
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

    for (int i = 0; i < 8; i++)
    {
        //playArea[0][i] = new Pawn('W');
        playArea[1][i] = new Rook('W');

        // cout << "set first team" << endl;
    }

    // cout << "functions called";
    for (int i = 0; i < 8; i++)
    {
        playArea[7][i] = new Pawn('B');
        playArea[6][i] = new Rook('B');
    }        
    // cout << "created black pawns";
    //Like this will probably for sure be gone (but keeping the names all 5 letters i think is a good touch);
    playArea[0][0] = new Rook('W');
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
    int tRow = 0, tCol = 0;

    bool notPicked = true;
    while(notPicked){
        ogRow = 0, ogCol = 0; 
        cout<< "Which piece would you like to move? Enter the x axis first(1-8)" << endl;
        while( ogCol<1 || ogCol>8){
            cin >> ogCol;
        }
        ogCol-=1;
        cout << "Enter the y axis now" << endl;
        while( ogRow<1 || ogRow>8){
            cin >> ogRow;
        }
        ogRow-=1;
        if(playArea[ogRow][ogCol] != nullptr){
            notPicked = false; 
        }
        else{
            cout << "Not a piece, pick again";
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
    Chesspiece* piece1 = playArea[ogRow][ogCol];
    Chesspiece* piece2 = playArea[tRow][tCol];
    swap(piece1, piece2);
    playArea[tRow][tCol] = piece2;
    playArea[ogRow][ogCol] = piece1;
   
}
void Board:: checkPawnPromotion(){
    char user;
    for (int i = 0; i < 8; i++)
    {   if(playArea[7][i] != nullptr){
            if(playArea[7][i]->getTeam() == 'W' && playArea[7][i]->getName() == "Pawnn"){
                cout << "Your pawn can promote!" << endl;
                cout << "What would you like to promote to: " << endl; 
                cout << "Q - Queen, B - Bishop, K- Knight, R- Rook" << endl;
                cin >> user;
                user = toupper(user);
                while(user != 'Q' && user!= 'B' && user != 'K' && user!= 'R'){
                    cout << "Not valid, please try again" << endl;
                    cin >> user;
                }
                delete playArea[7][i];
                //TO DO: Implement these as the classes get finished.
                if(user == 'Q'){
                    playArea[7][i] = nullptr;
                }
                if(user == 'B'){
                    playArea[7][i] = nullptr;
                }
                if(user == 'K'){
                    playArea[7][i] = nullptr;
                }
                if(user == 'R'){
                    playArea[7][i] = new Rook('W');
                }
            }
        }
    }
    //This could be optimized very easily by passing in the team into a function after checking if it was white or black. 
    for (int i = 0; i < 8; i++)
    {   
        if(playArea[0][i] != nullptr){
            if(playArea[0][i]->getTeam() == 'B' && playArea[0][i]->getName() == "Pawnn"){
                cout << "Your pawn can promote!" << endl;
                cout << "What would you like to promote to: " << endl; 
                cout << "Q - Queen, B - Bishop, K- Knight, R- Rook" << endl;
                cin >> user;
                user = toupper(user);
                while(user != 'Q' && user!= 'B' && user != 'K' && user!= 'R'){
                    cout << "Not valid, please try again" << endl;
                    cin >> user;
                }
                delete playArea[0][i];
                //TO DO: Implement these as the classes get finished.
                if(user == 'Q'){
                    playArea[0][i] = nullptr;
                }
                if(user == 'B'){
                    playArea[0][i] = nullptr;
                }
                if(user == 'K'){
                    playArea[0][i] = nullptr;
                }
                if(user == 'R'){
                    playArea[0][i] = new Rook('B');
                }
            }
        }
    }
    
}