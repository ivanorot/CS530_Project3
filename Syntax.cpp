#include "Syntax.h"

Syntax::Syntax() {}

bool Syntax::parseLine(string line){
    cout << line << "\t" << "\t";
    
    LexicalAnalyzer lex_analyzer;
    lex_analyzer.saveLexems(line);
    
    string temp = lex_analyzer.getNextToken();
    list<string> givenTokens;
    
    while (temp != ".") {
        //cout << "temp: " << temp << endl;
        givenTokens.push_back(temp);
        temp = lex_analyzer.getNextToken();
    }
    //cout << "givenToken size: " << givenTokens.size() << endl;
    if (givenTokens.empty() == false) {
        if (assignment(givenTokens)) {
            //cout << "true assignment statement above" << endl << endl;
            cout << "-- valid" << endl;
            return true;
        }
        else if (expression(givenTokens)) {
            //cout << "true expression statement above" << endl << endl;
            cout << "-- valid" << endl;
            return true;
        }
        else {
            //cout << "bad statement above" << endl << endl;
            cout << "-- invalid" << endl;
            return false;
        }
    }
}

bool Syntax::assignment(list<string> tokensList) {
    list<string> currentTokens = tokensList;
    bool flagAssignment = false;
    
    //cout << "check for assignment here" << endl;
    if (currentTokens.front() == "Id") {
        currentTokens.pop_front();
        //cout << "Id made it" << endl;
        
        if (currentTokens.front() == "Equal") {
            flagAssignment = true;
            currentTokens.pop_front();
            //cout << "Equal made it" << endl;
            
            if (currentTokens.back() == "terminal") {
                currentTokens.pop_back();
                //cout << "found terminal" << endl;
                
                if (expression(currentTokens)) {
                    //cout << "successful expression return" << endl;
                    return true;
                }
            }
        }
    }
    if (flagAssignment == true)
        //cout << "<Assignment> Failed" << endl;
    return false;
}

bool Syntax::expression(list<string> tokensList) {
    termTokens = tokensList;
    
    //cout << "check for expression here" << endl;
    if (term()) {
        //cout << "  successful term" << endl;
        if (extendedExp == true && termTokens.empty())
            return true;
        extendedExp = false;
        if ((termTokens.empty() == false) && termTokens.front() == "Op") {
            termTokens.pop_front();
            //cout << "Op made it" << endl;
            
            if (term()) {
                //cout << "  successful term" << endl;
                
                if (termTokens.empty()) return true;
                else if (termTokens.front() == "Op") {
                    termTokens.pop_front();
                   // cout << "Extended Op made it" << endl;
                    extendedExp = true;
                    return expression(termTokens);
                }
                return true;
            }
        }
    }
    return false;
}

bool Syntax::term() {
   // cout << "check for term here" << endl;
    if (termTokens.front() == "Id") {
       // cout << "  Id term" << endl;
        termTokens.pop_front();
        
        if (termTokens.empty()) return true;
//        else if (termTokens.front() == ")") {
//            //cout << "  close ) term" << endl;
//            termTokens.pop_front();
//            return true;
//        }
        return true;
    }
    else if (termTokens.front() == "(") {
        termTokens.pop_front();
        //cout << "  open ( term" << endl;
        if (expression(termTokens)) {

            if (termTokens.front() == ")") {
                termTokens.pop_front();
                //cout << "  open ( term" << endl;
                return true;
            }
        }
    }
    return false;
}

