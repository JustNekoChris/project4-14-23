#ifndef BOARD_HPP
#define BOARD_HPP
#include "chesspieces/Chesspiece.hpp"
class Board{
    public:
        Board();
        int turn();
        // bool sfmlturn(int tRow, int tCol, int ogRow, int ogCol);
        bool sfmlturn(int tRow, int tCol, int ogRow, int ogCol){
            if((whiteTurn && playArea[ogRow][ogCol]->getTeam() == 'W') || 
            !whiteTurn && playArea[ogRow][ogCol]->getTeam() == 'B'){
                if(playArea[ogRow][ogCol]-> MoveCheck(ogRow, ogCol, tRow, tCol, playArea)){
                    //Destruction code
                    if(playArea[tRow][tCol] != nullptr)
                        delete playArea[tRow][tCol];
                    playArea[tRow][tCol] = nullptr;
                    swapPiece( tRow, tCol, ogRow, ogCol);
                    moves++;
                    // if(playArea[tRow][tCol]->getName() == "Pawnn"){
                    //     // checkPawnPromotion(); 
                    // }
                    swapTurn();
                    return true; 
                }
            }
            return false;
        }
        void display();
        void swapTurn();
        void swapPiece(int tRow, int tCol ,int ogRow,int ogCol);
        int getMoves()const{return moves;}
        void checkPawnPromotion();
        bool gameOver();
        void deleter();
        bool getTurn()const{return whiteTurn;}
        Chesspiece* getPlayAreaElement(int row, int col) const{
            return playArea[row][col];
        }


    protected:
        //NOT A ISSUE ANYMORE: This gets around the error of creating objects with purely virtual functions.

        Chesspiece* playArea[8][8];
        bool whiteTurn;
    public:
        bool whiteAlive, blackAlive;
        int moves;
};

#endif 