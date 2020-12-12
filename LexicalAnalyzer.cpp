#include <iostream>
#include <string>
using namespace std;

class LexicalAnalyzer {
private:
	string *lexems;
	string *tokens;
	int lexCount;
	int size;

public:
	LexicalAnalyzer() {
		lexCount = 0;
		lexems = new string[10];
		tokens = new string[10];
		size = 10;
	}

	void saveLexems(string inputstring) {
		int length = inputstring.length();
		int counter;
		string temp;
		bool flag;
		for (int i = 0; i < length; i++) {
			if (inputstring[i] != ' ' || checkIfTerminal(inputstring[i])) {

			}


		}



	}
	void expandArray() {
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

	bool checkIfId(string id) {
		int length = id.length();
		int ascii;
		ascii = id[0];
		if (checkIfChar(ascii) == false) {
			return false;
		}
		for (int i = 0; i < length; i++) {
			ascii = id[i];
			if (ascii < 48 || ascii > 57) {

			}

		}


	}

	bool checkIfChar(int ascii) {
		if (ascii < 48 || (ascii > 57 && ascii < 97) || (ascii > 122)) {
			return false;
		}
		return true;
	}

	bool checkIfNum(int ascii) {
		if (ascii < 48 || ascii > 57) {
			return false;
		}
		return true;
	}


	//+ - * / %
	bool checkIfOp(int ascii) {
		if (ascii==42||ascii==43||ascii == 45 || ascii == 47 || ascii == 37) {
			return true;
		}
		return false;
	}

	bool checkIfTerminal(int ascii) {
		if (ascii == 59) {
			return true;
		}
		return false;
	}

	bool checkIfEqual(int ascii) {
		if (ascii == 61) {
			return true;
		}
		return false;
	}



};