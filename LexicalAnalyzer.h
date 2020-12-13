#ifndef LEXICALANALYZER_H
#define LEXICALANALYZER_H

#include <iostream>
#include <string>
#include <list>
using namespace std;

class LexicalAnalyzer {
private:

    list<string> tokens;


    //functions
    bool checkIfId(string id);
    bool checkIfChar(int ascii);
    bool checkIfNum(int ascii);
    bool checkIfOp(string op);
    bool checkIfTerminal2(char terminal);
    bool checkIfTerminal(char terminal);
    bool checkIfEqual(string equal);

    bool checkIfLeftParenthesis(char par);
    bool checkIfRightParenthesis(char par);

public:
    LexicalAnalyzer();

    string getNextToken();
    void saveLexems(string inputstring);
    
};
#endif



