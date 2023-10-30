// Rebecca Zipper, Midterm, 3/9/23

#include "Player.h"
#include "Words.h"
#include <iostream>
#include <cctype>
#include <string>
using namespace std;

void menu(){
    cout << "\nMenu" << endl;
    cout << "1. Play" << endl;
    cout << "2. Score" << endl;
    cout << "3. Add Word" << endl;
    cout << "4. Exit" << endl;
    cout << "\nEnter choice: ";
}

int main(){
    Player p1;
    Words game("words.txt");

    int choice = 0;
    string word = "";
    menu();
    cin >> choice;

    while(choice != 4){
         switch(choice){
            case 1: //play hangman. if getRandomWord returns true then it adds 1 to WinScore
                if(game.getRandomWord()){
                    p1.setWinScore();
                }
                else{
                    p1.setLoseScore();
                }
                break;

            case 2: //gets player's score
                p1.getScore();
                break;

            case 3: //allows user to add new words to play with.
                while(word != "salir"){
                    cout << "Enter Word to be added (type salir to exit): ";
                    cin >> word;
                    game.addExtraWord(word);
                }
                break;

            default: 
                break;
        }
        menu();
        choice = 0;
        cin >> choice;
    } 
   
    return 0;
}

