// Rebecca Zipper, Midterm, 3/9/23

#include "Player.h"
#include <iostream>
#include <string>
using namespace std;

int winScore = 0;
int loseScore = 0;

//constructor 
Player::Player(){
    winScore = 0;
    loseScore = 0;
}

//setters 
void Player::setWinScore(){
    this->winScore=winScore+1;
}

void Player::setLoseScore(){
    this->loseScore=loseScore+1;
}

//getter
void Player::getScore(){
    cout << "\nPlayer " << winScore << endl;
    cout << "Win Score: " << winScore << endl;
    cout << "Lose Score: " << loseScore << endl;
}