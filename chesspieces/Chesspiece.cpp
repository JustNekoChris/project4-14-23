#include "Chesspiece.hpp"
#include <iostream>


Chesspiece:: Chesspiece(){
    team = 'N';
    name = "nonam";
    isThreatened = false;


}
Chesspiece:: Chesspiece(char team, std::string name){
    this-> team = team;
    this-> name = name;
    isThreatened = false;
}
void Chesspiece:: setInfo(char team, std::string name){
    this->team = team; 
    this->name = name;
}
struct Point
{
    int x;
    int y;
};
void Chesspiece:: setPosX(int x){
    posX = x;
}
void Chesspiece:: setPosY(int y){
    posY = y;
}