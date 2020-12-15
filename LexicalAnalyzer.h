/************************************************
 * COURSE:          CS-530 Systems Programming
 * SECTION:         01 Synchronous TTh 1900-2015
 * PROGRAM #:       3
 * LAST MODIFIED:   14 December 2020
 * @author Ivan Orozco 82217656 cssc3012
 * @author Mariano Hernandez 820450001 cssc3062
 ************************************************/

/******************************************************************************
  * Program 03: LexicalAnalyzer.h
  *****************************************************************************
  * PROGRAM DESCRIPTION:
  * this header file includes type definitions (including function prototypes)
  * used for the LexicalAnalyzer
  *****************************************************************************/

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

    void checkFun(string temp);
public:
    LexicalAnalyzer();

    string getNextToken();
    void saveLexems(string inputstring);
    
};
#endif



