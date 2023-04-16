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
void Chesspiece:: setTeam(char team){
    this->team = team; 
}
void Chesspiece:: setName(std:: string name){
    this->name = name;
}