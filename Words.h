// Rebecca Zipper, Midterm, 3/9/23

#pragma once //makes sure you cannot import this code twice.
#include<vector>
#include <string>
using namespace std;

class Words{
    private:
        vector<string> *words; //array list
        

    public:
        bool addExtraWord(string word);
        bool getRandomWord();

         //constructors, copy constructor, and deconstructor 
        Words();
        Words( const Words & other ); // make a copy in order to return something. 
        Words(const string & fileName);
        ~Words();
};
