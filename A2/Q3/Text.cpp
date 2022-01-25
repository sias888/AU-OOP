//:Text.cpp

/*
Title: Text.cpp
Description: uses Text class defined in Text.h to print contents of
	     a text file.
Date: 2020-06-24
Author: Irteza Shamsi
Version: 1.5
*/

/*
DOCUMENTATION

Purpose: print text from text file using Text class to hide implementation

Compile: g++ -o Text Text.cpp Text.h
Execution: ./Text

Classes:
	Text - text(), text(string) - takes a textfile name from user and prints out the text in the file

Functions:
	private bool Text::readFile() - appends text from input file into contents string. Returns 1 if successful, 0 if failed.
	public string Text::returnContents() - returns contents string if reading is successful. Returns error message if not.

Variables:
	Text::contents - private string - contains contents of textfile
	Text::success - public bool - is set to return value of Text::readFile()
	Text::fileName - public string - name of file to be opened
*/

/*
TEST PLAN

Normal Case (input file = example.txt)
	>starting...
	>example.txt: (contents from file, words separated with spaces)

Normal Case 2 (input file = example)
	>starting...
	>example.txt: (contents from file, words separated with spaces)

Bad Data Case (input file does not exist)
	>starting....
	>file does not exist

Discussion: This program tests two instances of Text--one version with standard initialization
	    and the other initialized with a string. The implementation of Text is mostly hidden,
	    the contents of the file cannot be directly changed and the success of reading the file
	    cannot be directly changed either. The readFile() function is public for users who choose
	    to init without a string--if init with a string was the only option, I would have made 
	    readFile private as well. Calling the function displayContents() will make the object
	    check the readFile success state automatically, so the cpp file does not need to perform
	    the if/else checks either.
*/

#include "Text.h"
#include <iostream>

int main () {
	std::cout << "starting..." << std::endl;

	Text text("example.txt"); //initialization of text using pre-written example textfile
	
	std::cout << std::endl << text.returnContents() << std::endl; //display contents of file
	
	Text text2;
	text2.fileName = "E";
	text2.readFile();
	
	std::cout << std::endl << text2.returnContents() << std::endl;

}