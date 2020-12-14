#include "LexicalAnalyzer.h"


LexicalAnalyzer::LexicalAnalyzer() {
}

void LexicalAnalyzer::saveLexems(string inputstring) {
    int length = inputstring.length();
    int counter;
    string temp;
    bool flag;
    for (int i = 0; i < length; i++) {
        if (inputstring[i] == ' ' || checkIfTerminal2(inputstring[i])) {
            checkFun(temp);
            temp.clear();
            if (checkIfTerminal(inputstring[i])) {
                tokens.push_back("terminal");
            }
            else if (checkIfLeftParenthesis(inputstring[i])) {
                tokens.push_back("(");
            }
            else if (checkIfRightParenthesis(inputstring[i])) {
                tokens.push_back(")");
            }

        }
        else {
            temp += inputstring[i];
        }
    }
    if (temp.length() > 0) {
        checkFun(temp);
    }
    tokens.push_back(".");
}

void LexicalAnalyzer::checkFun(string temp) {

        if (checkIfId(temp) == true) {
            tokens.push_back("Id");
        }
        else if (checkIfEqual(temp) == true) {
            tokens.push_back("Equal");
        }

        else if (checkIfOp(temp) == true) {
            tokens.push_back("Op");
        }
        else if (temp.length() > 0) {
            tokens.push_back("~Not a valid token");
        }

 }

string LexicalAnalyzer::getNextToken() {
    if (tokens.empty() == false) {
        int size = tokens.size();
        string temp;
        if (size > 0) {
            temp += tokens.front();
            tokens.pop_front();
            return temp;
        }
        else {
            return ",";
        }
    }
};

/*/
void LexicalAnalyzer::expandArray() {
    string* temp;
    string* temp2;
    if (lexCount > (size - 5)) {
        temp = new string[size + 10];
        temp2 = new string[size + 10];
        for (int i = 0; i < size; i++) {
            temp[i] = lexems[i];
            temp2[i] = tokens[i];
        }
        lexems = temp;
        tokens = temp2;
    }
}
*/

bool LexicalAnalyzer::checkIfId(string id) {
    int length = id.length();
    int ascii;
    ascii = id[0];
    if (checkIfChar(ascii) == false) {
        return false;
    }
    for (int i = 0; i < length; i++) {
        ascii = id[i];
        if ((checkIfNum(ascii) == false) && (checkIfChar(ascii) == false)) {
            return false;
        }
    }
    return true;

}

bool LexicalAnalyzer::checkIfChar(int ascii) {
    if (ascii < 48 || (ascii > 57 && ascii < 97) || (ascii > 122)) {
        return false;
    }
    return true;
}

bool LexicalAnalyzer::checkIfNum(int ascii) {
    if (ascii < 48 || ascii > 57) {
        return false;
    }
    return true;
}


//+ - * / %
bool LexicalAnalyzer::checkIfOp(string op) {
    if (op=="+"||op=="-"||op == "*" || op=="/" || op=="%") {
			return true;
    }
    return false;
}

//;
bool LexicalAnalyzer::checkIfTerminal2(char terminal) {
    
    if (terminal == ';' || (terminal == '(') || (terminal == ')')) {
        return true;
    }
    return false;
}

bool LexicalAnalyzer::checkIfTerminal(char terminal) {

    if (terminal == ';') {
        return true;
    }
    return false;
}

//=
bool LexicalAnalyzer::checkIfEqual(string equal) {
    if (equal == "=") {
        return true;
    }
    return false;
}

bool LexicalAnalyzer::checkIfLeftParenthesis(char par) {
    if (par == '(') {
        return true;
    }
    return false;
}

bool LexicalAnalyzer::checkIfRightParenthesis(char par) {
    if (par == ')') {
        return true;
    }
    return false;
}
