#ifndef SYNTAX_H
#define SYNTAX_H

#include "LexicalAnalyzer.h"

class Syntax {
private:
    LexicalAnalyzer lexical;

public:
    //constructor (lexical analyzer as parameter)
    Syntax();

    void readline(string line);
    bool assignment(list<string> tokens);
    bool expression(list<string> tokens);
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

}

bool checkif(string token, string check){

if (token == check)

*/

