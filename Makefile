# COURSE:          CS-530 Systems Programming
# SECTION:         01 Synchronous TTh 1900-2015
# PROGRAM #:       3
# LAST MODIFIED:   14 December 2020
# @author Ivan Orozco 822171656 cssc3012
# @author Mariano Hernandez 820450001 cssc3062

parser: main.o Syntax.o LexicalAnalyzer.o 
	g++ main.o Syntax.o LexicalAnalyzer.o  -o parser

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

Syntax.o: Syntax.cpp
	g++ -std=c++11 -c Syntax.cpp

LexicalAnalyzer.o: LexicalAnalyzer.cpp
	g++ -std=c++11 -c LexicalAnalyzer.cpp

clean:
	rm *.o parser

