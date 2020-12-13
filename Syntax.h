#ifndef SYNTAX_H
#define SYNTAX_H

#include "LexicalAnalyzer.h"

class Syntax {
private:
    //LexicalAnalyzer lexical;

public:
    //constructor (lexical analyzer as parameter)
    Syntax();

    void parseLine(string line);
    bool assignment(list<string> tokensList);
    bool expression(list<string> tokensList);
};
#endif

/*
* 
* 

bool assignment(){
check if next token is id


check if next token is =


check if next token is exp


check if next tokent is ;

}

bool expression(){

check id

check for op

check for id

return true



[ id, op , id, .
st
}

bool checkif(string token, string check){

if (token == check)

*/

