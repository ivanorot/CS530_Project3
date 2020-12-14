#ifndef SYNTAX_H
#define SYNTAX_H

#include "LexicalAnalyzer.h"

class Syntax {
private:
    
    
public:
    list<string> termTokens;
    bool extendedExp = false;
    Syntax();

    bool parseLine(string line);
    bool assignment(list<string> tokensList);
    bool expression(list<string> tokensList);
    bool term();
};
#endif
