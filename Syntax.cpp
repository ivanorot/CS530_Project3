/************************************************
 * COURSE:          CS-530 Systems Programming
 * SECTION:         01 Synchronous TTh 1900-2015
 * PROGRAM #:       3
 * LAST MODIFIED:   14 December 2020
 * @author Ivan Orozco 82217656 cssc3012
 * @author Mariano Hernandez 820450001 cssc3062
 ************************************************/

/******************************************************************************
  * Program 03: Syntax.cpp
  *****************************************************************************
  * PROGRAM DESCRIPTION:
  * Verifies an assignment or expression statment to be valid based on the 
  * following BNF:
  *
  * <assignment> ::= <id> = <expression> ;
  * <expression> ::= <term> <op> <term> {<op> <term>}
  * <term> ::= <id> | ( <expression> )
  *****************************************************************************/

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
        /* <assignment> */
        if (assignment(givenTokens)) {
            //cout << "true assignment statement above" << endl << endl;
            cout << "-- valid Statement" << endl;
            return true;
        }
        /* <expression> */
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
    /* <id> */
    if (currentTokens.front() == "Id") {
        currentTokens.pop_front();
        //cout << "Id made it" << endl;
        
        /* = */
        if (currentTokens.front() == "Equal") {
            flagAssignment = true;
            currentTokens.pop_front();
            //cout << "Equal made it" << endl;
            
            /* ; */
            if (currentTokens.back() == "terminal") {
                terminalflag = false;
                currentTokens.pop_back();
                //cout << "found terminal" << endl;
                
                /* <expression> */
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
    /* <term> */
    if (term()) {
        //cout << "  successful term" << endl;
        if (extendedExp == true && termTokens.empty())
            return true;
        extendedExp = false;
        
        /* <op> */
        if ((termTokens.empty() == false) && termTokens.front() == "Op") {
            termTokens.pop_front();
            //cout << "Op made it" << endl;
            
            /* <term> */
            if (term()) {
                //cout << "  successful term" << endl;
                
                if (termTokens.empty()) return true;
                /* {<op> <term>> */
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
    /* <id> */
    bool parenthesisflag = false;;
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
    
    /* (<expression>) */
    else if ((termTokens.empty() == false) && termTokens.front() == "(") {
        termTokens.pop_front();
        parenthesisflag = true;
        //cout << "  open ( term" << endl;
        if (expression(termTokens)) {
            parenthesisflag = false;
          

            if ((termTokens.empty() == false) && termTokens.front() == ")") {
                termTokens.pop_front();
                //cout << "  open ( term" << endl;
                return true;
            }
           
            cout << endl << "---Expected a ')'";
        }
        if (parenthesisflag) {
            cout << endl << "---<exp>" << "\t" << "\t" << " failed";
        }
    }
    cout <<endl<< "---<term>" << "\t" << "\t" << " failed";
    return false;
}

