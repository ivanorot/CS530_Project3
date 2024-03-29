## COURSE:          CS-530 Systems Programming
## SECTION:         01 Synchronous TTh 1900-2015
## PROGRAM #:       3
## LAST MODIFIED:   14 December 2020
## @author Ivan Orozco 822171656 cssc3012
## @author Mariano Hernandez 820450001 cssc3062


***
## Overview

This is a parser program called `parser`, that uses a BNF grammer to recognize
whether an assignment or expression statement is either valid or invalid. The
methodology to determine the grammer is explained more in the "Design Process"
section.

**IMPORTANT for Grading Purposes**<br />
note to the grader: please specify which .txt file is to be read as the second
command line arguement and make sure to include it inside the ./a3 directory;
otherwise, our testing file will run as explained in the following.

To run the program...

>start up a terminal and open the directory where the source code is stored,
>as shown in the "Directories/Files" section:
>
>                cd ./a3
>
>build the executable program:
>
>                make
>
>run the executable (use the optional \<filetoparse>.txt if you are using
>your own file and also make sure to include in the ./a3 directory; otherwise,
>when running `parser` alone, it will use our *testing.txt* file):
>
>                parser [<filetoparse>.txt]

upon execution, the program will output to the console each line that was read
from the incoming file then determine and output, right after the line that was
read, whether it is valid or where each part of the statement failed. If it is
an invalid statment, it will also output a list errors found in the statement.


***
## Design Process

The BNF grammer used for this assignment is following:

`<assignment> ::= <id> = <expression> ;`
    
`<expression> ::= <term> <op> <term> {<op> <term>}`
    
`<term> ::= <id> | ( <expression> )`
    
`<id> ::= <char> | <id><char> | <id><digit>`
    
`<char> ::= a|b|c|d|e|f|g|h|i|j|k|l|m|n|o|p|q|r|s|t|u|v|w|x|y|z|A|B|C|D|E|F|G|H|I|J|K|L|M|N|O|P|Q|R|S|T|U|V|W|X|Y|Z`
            
`<digit> ::= 1|2|3|4|5|6|7|8|9`
    
`<op> ::= +|-|*|/|%`
    
***
## Lessons Learned

- The project became an easier task once we wrote a BNF to base our work on.
  Each BNF definition was translated into a method in our parser, and each
  method had its own error message, which also made it easier to debug our project.
- Another technique we practiced was the of recursive functions to facilitate
  the BNF grammer

***
## Directories/Files

### ./a3

This directory contains any source code files, executables, and a Makefile to
run the program; plus information regarding the program.

>- *Makefile*
    - set of directives that tell `make` how to compile and link the program

>- *main.cpp*
    - starting point of the program opens and reads the file to be parsed

>- *LexicalAnalyzer.h*
    - this header file includes type definitions (including function
      prototypes) used for the LexicalAnalyzer

>- *LexicalAnalyzer.cpp*
    - source code for the basic LexicalAnalyzer

>- *Syntax.h*
    - this header file includes type definitions (including function
      prototypes) used for the Syntax

>- *Syntax.cpp*
    - source code for the basic Syntax

>- *testing.txt*
    - statements used for testing

>- *README.md* (this file)
    - details the information of this program

