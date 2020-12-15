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
            cout << "-- valid Statement" << endl;
            return true;
        }
        else if (expression(givenTokens)) {
            //cout << "true expression statement above" << endl << endl;
            cout << "-- valid Statement" << endl;
            return true;
        }
        else {
            //cout << "bad statement above" << endl << endl;
            //cout << "-- invalid" << endl;
            cout << endl<<endl;
            return false;
        }
    }
}

bool Syntax::assignment(list<string> tokensList) {
    list<string> currentTokens = tokensList;
    bool flagAssignment = false;
    bool terminalflag = true;
    
    //cout << "check for assignment here" << endl;
    if (currentTokens.front() == "Id") {
        currentTokens.pop_front();
        //cout << "Id made it" << endl;
        
        if (currentTokens.front() == "Equal") {
            flagAssignment = true;
            currentTokens.pop_front();
            //cout << "Equal made it" << endl;
            
            if (currentTokens.back() == "terminal") {
                terminalflag = false;
                currentTokens.pop_back();
                //cout << "found terminal" << endl;
                
                if (expression(currentTokens)) {
                    //cout << "successful expression return" << endl;
                    return true;
                }
            }
            if (terminalflag) {
                cout << endl << "---Expected a ';'";
            }
        }
    }
    if (flagAssignment == true)
        cout <<endl<<"---<Assgmnt>"<<"\t"<< "\t" << " failed";
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
                else if ((termTokens.empty() == false) && termTokens.front() == "Op") {
                    termTokens.pop_front();
                   // cout << "Extended Op made it" << endl;
                    extendedExp = true;
                    return expression(termTokens);
                }
                return true;
            }


            cout << endl << "---<exp>" << "\t" << "\t" << " failed";
        }
        
    }
    return false;
}

bool Syntax::term() {
   // cout << "check for term here" << endl;
    if ((termTokens.empty() == false)&&termTokens.front() == "Id") {
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
    else if ((termTokens.empty() == false) && termTokens.front() == "(") {
        termTokens.pop_front();
        //cout << "  open ( term" << endl;
        if (expression(termTokens)) {

            if ((termTokens.empty() == false) && termTokens.front() == ")") {
                termTokens.pop_front();
                //cout << "  open ( term" << endl;
                return true;
            }
            cout << endl <<"---Expected a ')'";

        }
        
    }
    cout <<endl<< "---<term>" << "\t" << "\t" << " failed";
    return false;
}

