//:DVD.cpp

/*
Title: DVD.cpp
Description: This program fills 10 DVD data types and prints out the information of all DVDs
Date: 2020-06-01
Author: Irteza Shamsi
Version: 1.5
*/

/*
DOCUMENTATION

Purpose: This program fills 10 DVD data types and prints out the information of all DVDs

Compile (assuming use of Cygwin): g++ -o DVD DVD.cpp
Execution (assuming use of Cygwin): ./DVD.exe

Classes: 
	DVD - used to store information about a DVD in a rental store

Functions:
	Public DVD::print - returns void - takes no arguments - prints out all values in DVD class
	Private DVD::replaceUnderscore - returns string - takes 1 string argument - replaces all "_" substrings in a string with " ".
Variables:
	list[10] - Array of DVD objects - used to store 10 DVD objects
	file - ifstream - serves as infile; used for opening and manipulation of file
	d - Pointer to DVD object - used to iterate through list.
	DVD::title - Public string - used to store title of a DVD.
	DVD::type - Public string - used to store type of DVD (Blu-Ray, Digital, DVD, etc.)
	DVD::genre - Public string - used to store genre of DVD (fiction, sci-fi, comedy, etc.)
	DVD::copies - Public int - used to store number of existing copies of a known DVD
	DVD::holds - Puiblic int - used to store number of holds on a known DVD
	DVD::price - Public double - renting price
*/

/*
TEST PLAN

Normal Case 1 (A_New_Hope Blu-Ray Sci-Fi 50 2 5.05
		...x10):
	>Title: A New Hope|Type: Blu-Ray|Genre: Sci-Fi|Copies: 50|Holds: 2|Price: 5.05
	>...
	>(until last entry)
	>
	> done.
Bad Data Case 1 (too many whitespace-separated strings in line 1):
	>Title: A New Hope|Type: Blu-Ray|Genre: Sci-Fi|Copies: 50|Holds: 2|Price: 5.05
	>
	> done.
Bad Data Case 2 (too few whitespace-separated strings in line):
	>
	>
	> done.
Bad Data Case 3 (more than 10 lines in sample):
	>Title: A New Hope|Type: Blu-Ray|Genre: Sci-Fi|Copies: 50|Holds: 2|Price: 5.05
	>...
	>(until last entry)
	>
	> done.
*/

#include "DVD.h"
#include <iostream>
#include <fstream>

using namespace std;

int main() {
	DVD list[10];
	DVD* d;
	d = list;
	ifstream file("example.txt");
	
	while(file >> d->title >> d->type >> d->genre >> d->copies >> d->holds >> d->price) 
	{
		d->print();
		if (d == &list[9]){break;}
		d++;
	}
	cout << endl << "done.";
return 0;
}

