//: WordCounter.cpp

/*
Title: WordCounter.cpp
Description: Counts the number of words in a text file
Date: 2020-05-21
Author: Irteza Shamsi
Version: 2.1
*/

/*
DOCUMENTATION

Purpose: This program opens a file and counts the whitespace-separated words in that file.

Compile (assuming use of Cygwin): g++ -o WordCounter WordCounter.cpp
Execution (assuming use of Cygwin): ./WordCounter.exe

Classes: none

Variables:
	wordCount - int - used to store number of words in a text file
	fileName - string - used to store name of text file to be read
	file - ifstream - serves as infile; used for opening and manipulation of file
	word - string - placeholder for string class. Used for file to check if there is a input of string class

*/

/*
TEST PLAN

Normal Case 1 (String with .txt):
	>Please enter file name: example.txt
	>There are 11 words in example.txt

Normal Case 2 (string without .txt):
	>Please enter file name: example
	>There are 11 words in example.txt

Bad Data Case 1 (file does not exist):
	>Please enter file name: DoesNotExist
	>Error opening file.

*/

#include <iostream> // Stream Declarations
#include <fstream>
#include <string>


int main()
{
    string fileName; 
    int wordCount = 0;
    ifstream file;

    //Request and obtain fileName
    cout << "please type in the file name: ";
    cin >> fileName;

    //Add .txt to file name if not already present
    if(fileName.find(".txt") == -1) {
	fileName = fileName + ".txt";
    }
    
    file.open(fileName); //Open file
    

    if(!file.fail()){ //Check if file exists

   	string word;
   	
	// Increase wordCount by 1 each time file recognizes whitespace-separated word until there are no words left in file
  	while( file >> word){

        wordCount++;

   	}
    
   	cout << '\n' << "There are "<< wordCount << " words in "<< fileName << "."; // display number of words to user

     }
     else { cout << '\n' << "Error opening file.";} // Display badcase output

    file.close(); // close file
   
    return 0;
}