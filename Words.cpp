// Rebecca Zipper, Midterm, 3/9/23
#include "Words.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// constructor
Words::Words(){
    words = new vector<string>();
    words->push_back(0);
};

// Copy Constructor 
Words::Words( const Words & other ){
    words = new vector<string>();
    for(int i=0; i<words->size(); i++){
        words->push_back(other.words->at(i));
    }
}; // make a copy in order to return something. 

//constructor to read in fileName
Words::Words(const string & fileName){
    words = new vector<string>();
    string line;
    ifstream myFile(fileName);

    if (myFile.is_open())
    {
        while (getline(myFile, line))
        {
            words->push_back(line);
        }
        myFile.close();
    }
    cout << "Done reading in file" << endl;
};

//deconstructor 
Words::~Words(){
    delete words;
};

/**
 * This function gets a random word from the words vector, and then checks if the user's guess is
 * correct. If the user's guess is correct, the letter is printed out. If the user's guess is
 * incorrect, the number of guesses left is decremented. If the number of guesses left is 0, the game
 * is lost. If the user guesses all the letters correctly, the game is won.
 * 
 * @return A boolean value.
 */
bool Words::getRandomWord(){
    int size = words->size(); //size of words
    int randomNum = 0; //not working

    string randomWord = ""; 
    randomNum = rand() % size; //gets a random number
    cout << randomNum << endl;
    randomWord = words->at(randomNum); //gets the random word from the words vector

    //booleans 
    bool found = false; //to check if a letter is found
    bool inGuess = false; //to check if a letter has been guessed

    char guess; //letter user inputs
    vector<char> guesses; //keeps track of the letter guesses

    string output; //helps format the correct letters

    int correct = 0; //helps with winning condition
    int numGuesses = 7; //number of guesses 


   

    for(char c:randomWord){ //initial printing of how many letters. Gets rid of spaces
        if(!isspace(c)){
            cout << "_ ";
        }
        
    }

    
    while(numGuesses !=0){ //checks if numGuesses is not 0, loosing condition 

        //user input 
        cout << "\nEnter guess: ";
        cin >> guess;

        //checks to see if the letter guessed has been guessed before. 
        for(int i=0; i<guesses.size(); i++){
            if(guesses.at(i) == guess){
                cout << "Already guessed" << endl;
                inGuess = true;
            }
        }

        //if the letter has not been guessed, it gets pushed into the guesses vector.
        if(!inGuess){
            guesses.push_back(guess);
        }
        


        for(char c:randomWord){ 
            //if the current letter is the guess
            if(c == guess){
                output+=c; //add the letter to the string output
                found = true; //flag 
            }
            //formatting for output 
            if (find(guesses.begin(), guesses.end(), c) != guesses.end()) {
                cout << c << " "; //puts correct letters where they should be.
            }
            else if(!isspace(c)){ //if current letter isn't a space and isn't correct
                cout << "_ ";
            }
           
        }

        //if the letter isn't found, numGuesses is decremented
        if(!found){
            numGuesses--;
            cout << "\nNumber of Guesses Left: " << numGuesses << endl;
        }

        //reset
        correct = 0;
        found = false;

        // checks winning conditions
        for(char c:randomWord){ //win! 
            if (find(guesses.begin(), guesses.end(), c) != guesses.end()) {
                correct++;
            }
        }
        // if the number of correct letters is the word length of the word, then the game is won.
        if(correct == randomWord.length()){ 
            cout << "\nGame Won" << endl;
            return true;
        }

    }
    return false;
}

/**
 * This function checks if the word is too long, if it exists, or if it has a space. If it passes all
 * of these tests, it adds the word to the vector.
 * 
 * @param word the word to be added to the vector
 * 
 * @return a boolean value.
 */
bool Words::addExtraWord(string word){
    //checks if the word length is too long 
    if(word.length() > 10){
        cout << "Word is too long" << endl;
        return false;
    }
    else{
        for(int i=0; i<words->size(); i++){
            //checks if the word exists or has a space.
            if(word == words->at(i) || isspace(word[i])) {
                cout << "Word Exists or has a space" << endl;
                return false;
            }
        }
        //otherwise, add the word to the words vector 
        words->push_back(word);
        return true;
    }
    
    return false;

}