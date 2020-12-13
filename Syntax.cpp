#include "Syntax.h"

Syntax::Syntax() {}

void Syntax::parseLine(string line){
    LexicalAnalyzer = lex_analyzer;
    lex_analyzer.saveLexems(line);
    
    string temp = lex_analyzer.getNextToken();
    list<string> givenTokens;
    
    while (temp != ".") {
        givenTokens.push_back(temp);
        temp = lex_analyzer.getNextToken();
    }
    if (assignment(givenTokens))
        return true;
    else if (expression(givenTokens))
        return true;
    else
        return false;
}

bool Syntax::assignment(list<string> tokensList) {
    if (tokensList.pop_front() == "Id") {
        if (tokensList.pop_fron() == "Equal") {
            if (tokensList.pop_back() == "terminal") {
                if (expression(tokensList))
                    return true
            }
        }
    }
    else return false;
}

bool Syntax::expression(list<string> tokensList) {
    if (tokensList.pop_front() == "Id") {
        if (tokensList.pop_fron() == "Op") {
            if (tokensList.empty())
                return true;
            else
                expression(tokensList);
        }
    }
    else return false;
}

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
