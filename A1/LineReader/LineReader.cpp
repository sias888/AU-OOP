//: LineReader.cpp

/*
TItle: LineReader.cpp
Description: Reads a text file line-by-line
Date: 2020-05-21
Author: Irteza Shamsi
Version: 1.0
*/

/*
DOCUMENTATION

Purpose: This program opens a text file and reads it line-by-line, waiting for user to press enter after each line ends.

Compile (assuming use of Cygwin): g++ -o LineReader LineReader.cpp
Execute (assuming use of Cygwin): ./LineReader

Classes: none

Variables:

*/

/*
TEST PLAN

*/

#include <iostream> // Stream Declarations
#include <fstream>
#include <string>
using namespace std;

int main() {
	
	string fileName;
	// Request and obtain filename
	cout << "please type in the file name: ";
	cin >> fileName;

	//Add '.txt' to filename if not already present
	if(fileName.find(".txt") == -1) {

		fileName = fileName + ".txt";
    	}
	
	
	ifstream file(fileName);

	if(file){
		char line[256];
		while (file.getline(line, 256)){
			cin.ignore();
			cout << line;
		}
	}
	else{cout << "File " << fileName<< " does not exist";}

	return 0;
}