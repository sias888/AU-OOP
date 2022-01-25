//: LineCounter.cpp

/*
Title: LineReader.cpp
Description: Reads a text file line-by-line
Date: 2020-05-21
Author: Irteza Shamsi
Version: 2.3
*/

/*
DOCUMENTATION

Purpose: This program uses a text file to fill 100 strings.

Compile (assuming use of Cygwin): g++ -o LineCounter LineCounter.cpp
Execute (assuming use of Cygwin): ./LineCounter

Classes: none

Variables:
	fileName - string - used to store name of text file to be read
	file - ifstream - infile used to get lines from and open chosen file
	line - string - object of string class used to store lines from infile
	throwaway - string - throwaway string used to ignore user input until [enter] is pressed

*/

/*
TEST PLAN

Normal Case (file exists):
	>please type in the file name: example
	>*file line 1 here*
	>*file line 2 here*
	>...

Bad Case (file doesnt exist):
	>please type in the file name here: DoesNotExist
	>File DoesNotExist does not exist.
*/

#include <iostream> // Stream Declarations
#include <fstream>
#include <string>
using namespace std;

int main() {
	
	string fileName;
	extern ifstream file;
	//string str;
	string lines[100];

	// Request and obtain filename
	cout << "please type in the file name: ";
	cin >> fileName;

	//Add '.txt' to filename if not already present
	if(fileName.find(".txt") == -1) {

		fileName = fileName + ".txt";
    	}
	
	// Open File
	ifstream file = fileName;

	if(!file.fail()){

		//while(getline(file, line)){
		for (int i = 0; i < 100; i++) {
			getline(file, lines[i]);
			cout << "line " << i + 1 << ": " << lines[i] << endl;
		}
	}
	else{cout << "File " << fileName<< " does not exist.";}

	return 0;
}