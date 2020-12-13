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
        cout << "true assignment statement above" << endl << endl;
        return true;
    }
    else if (expression(givenTokens)) {
        cout << "true expression statement above" << endl << endl;
        return true;
    }
    else {
        cout << "bad statement above" << endl << endl;
        return false;
    }
}

bool Syntax::assignment(list<string> tokensList) {
    list<string> currentTokens = tokensList;
    
    cout << "assignment here" << endl;
    if (currentTokens.front() == "Id") {
        currentTokens.pop_front();
        cout << "Id made it" << endl;
        if (currentTokens.front() == "Equal") {
            currentTokens.pop_front();
            cout << "Equal made it" << endl;
            if (currentTokens.back() == "terminal") {
                currentTokens.pop_back();
                cout << "found terminal" << endl;
                if (expression(currentTokens)) {
                    cout << "successful assignment return" << endl;
                    return true;
                }
            }
        }
    }
    return false;
}

bool Syntax::expression(list<string> tokensList) {
    list<string> currentTokens = tokensList;
    
    cout << "expression here" << endl;
    if (currentTokens.front() == "Id") {
        currentTokens.pop_front();
        cout << "Id made it" << endl;
        cout << "Current Tokens empty?: " << currentTokens.empty() << endl;
        if (currentTokens.empty()) {
            cout << "successful expression return" << endl;
            return true;
        }
        
        if (currentTokens.front() == "Op") {
            currentTokens.pop_front();
            cout << "Op made it" << endl;
            
            if (currentTokens.empty())
                return true;
            else
                return expression(currentTokens);
        }
    }
    return false;
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
