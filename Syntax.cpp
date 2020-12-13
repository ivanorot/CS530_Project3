#include "Syntax.h"

Syntax::Syntax() {}

bool Syntax::parseLine(string line){
    LexicalAnalyzer lex_analyzer;
    lex_analyzer.saveLexems(line);
    
    string temp = lex_analyzer.getNextToken();
    list<string> givenTokens;
    
    while (temp != ".") {
        cout << "temp: " << temp << endl;
        givenTokens.push_back(temp);
        temp = lex_analyzer.getNextToken();
    }
    if (assignment(givenTokens)) {
        cout << "true assignment above" << endl;
        return true;
    }
    else if (expression(givenTokens)) {
        cout << "true expression above" << endl;
        return true;
    }
    else
        return false;
}

bool Syntax::assignment(list<string> tokensList) {
    if (tokensList.front() == "Id") {
        tokensList.pop_front();
        
        if (tokensList.front() == "Equal") {
            tokensList.pop_front();
            
            if (tokensList.back() == "terminal") {
                tokensList.pop_back();
                
                if (expression(tokensList))
                    return true;
            }
        }
    }
    else return false;
}

bool Syntax::expression(list<string> tokensList) {
    if (tokensList.front() == "Id") {
        tokensList.pop_front();
        
        if (tokensList.front() == "Op") {
            tokensList.pop_front();
            
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
