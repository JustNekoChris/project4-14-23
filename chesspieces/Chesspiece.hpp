#ifndef CHESSPIECE_HPP
#define CHESSPIECE_HPP

#include <string>
class Chesspiece{
    public:
        Chesspiece();
        Chesspiece(char team, std::string name);
        void setTeam(char team);
        void setName(std:: string name);
        //The setterss could be 1 function ngl 

        std:: string getName()const{return name;}
        char getTeam()const{return team;}
        virtual bool MoveCheck(int ogRow, int ogCol, int tRow, int tCol, Chesspiece* playArea[][8]) = 0; 


    protected:
        char team; // B = black, W = white, N = neither (empty space);
        std::string name; // name of the piece (mostly going to be for debugging)
        bool isThreatened;


};

#endif //Chesspiece