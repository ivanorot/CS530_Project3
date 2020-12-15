/************************************************
 * COURSE:          CS-530 Systems Programming
 * SECTION:         01 Synchronous TTh 1900-2015
 * PROGRAM #:       3
 * LAST MODIFIED:   14 December 2020
 * @author Ivan Orozco 82217656 cssc3012
 * @author Mariano Hernandez 820450001 cssc3062
 ************************************************/

/******************************************************************************
  * Program 03: Syntax.h
  *****************************************************************************
  * PROGRAM DESCRIPTION:
  * this header file includes type definitions (including function prototypes)
  * used for the Syntax
  *****************************************************************************/

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
