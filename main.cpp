/************************************************
 * COURSE:          CS-530 Systems Programming
 * SECTION:         01 Synchronous TTh 1900-2015
 * PROGRAM #:       3
 * LAST MODIFIED:   14 December 2020
 * @author Ivan Orozco 82217656 cssc3012
 * @author Mariano Hernandez 820450001 cssc3062
 ************************************************/

/******************************************************************************
  * Program 03: main.cpp
  *****************************************************************************
  * PROGRAM DESCRIPTION:
  * Starting point for the statement parsing program, where the files are to be
  * read and parsed
  *****************************************************************************/

#include <fstream>

#include "Syntax.h"

int main(int argc, char* argv[]) {
    cout << "CS-530: Systems Programming\n";
    cout << "Program 3: Statement Parser Program\n";
    cout << "@author Ivan Orozco 82217656 cssc3012\n";
    cout << "@author Mariano Hernandez 820450001 cssc3062\n\n";
    

    // if (argc != 2) {
    //     cout << "Incorrect number of arguemnts\n";
    //     cerr << "Correct usage: dis <filename>\n";
    //     return 1;    
    // }
    
    Syntax syntax_analyzer;
    ifstream file("testing.txt");
    string inputLine;
    
    if (!file.is_open()) {
        cout << "Error with file\n";
        cerr << "Check to make sure file exists within current directory\n";
    }
    
    while (file.good()) {
        getline(file, inputLine);
        //cout << inputLine << endl;
        syntax_analyzer.parseLine(inputLine);
    }
    file.close();
    
    return 0;
}
