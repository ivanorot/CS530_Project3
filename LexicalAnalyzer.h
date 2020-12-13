#ifndef LEXICALANALYZER_H
#define LEXICALANALYZER_H

#include <iostream>
#include <string>
using namespace std;

class LexicalAnalyzer {
private:
    string *lexems;
    string *tokens;
    int lexCount;
    int size;

public:
    LexicalAnalyzer() {
        lexCount = 0;
        lexems = new string[10];
        tokens = new string[10];
        size = 10;
    }

    void saveLexems(string inputstring);
    void expandArray();
    bool checkIfId(string id);
    bool checkIfChar(int ascii);
    bool checkIfNum(int ascii);
    bool checkIfOp(int ascii);
    bool checkIfTerminal(int ascii);
    bool checkIfEqual(int ascii);
};
#endif
