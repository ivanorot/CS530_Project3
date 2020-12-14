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
    cout << "givenToken size: " << givenTokens.size() << endl;
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
    bool flagAssignment = false;
    
    cout << "check for assignment here" << endl;
    if (currentTokens.front() == "Id") {
        currentTokens.pop_front();
        cout << "Id made it" << endl;
        
        if (currentTokens.front() == "Equal") {
            flagAssignment = true;
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
    if (flagAssignment == true)
        cout << "<Assignment> Failed" << endl;
    return false;
}

bool Syntax::expression(list<string> tokensList) {
    termTokens = tokensList;
    //list<string> currentTokens = tokensList;
    
    cout << "check for expression here" << endl;
    cout << "Staring num termTokens in expr: " << termTokens.size() << endl;
    if (term()) {
        cout << "  term successful check" << endl;
        cout << "Current termTokens: " << termTokens.size() << endl;
        if (termTokens.empty()) {
            //cout << "successful expression return" << endl;
            return true;
        }
        
        if (termTokens.front() == "Op") {
            termTokens.pop_front();
            cout << "Op made it" << endl;
            
            if (termTokens.empty())
                return false; // may need to change to false
            else
                return expression(termTokens);
        }
    }
    return false;
}


bool Syntax::term() {
    cout << "check for term here" << endl;
    if (termTokens.front() == "Id") {
        cout << "  Id term" << endl;
        termTokens.pop_front();
        
        if (termTokens.front() == ")") {
            cout << "  close ) term" << endl;
            termTokens.pop_front();
            return true;
        }
        return true;
    }
    else if (termTokens.front() == "(") {
        termTokens.pop_front();
        cout << "  open ( term" << endl;
        expression(termTokens);
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
