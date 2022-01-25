//:DVD.cpp

/*
Title: DVD.cpp
Description: This program fills 10 DVD data types and prints out the information of all DVDs
Date: 2020-06-01
Author: Irteza Shamsi
Version: 2.3
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
	line - string - used in getline() function to transfer lines from file to buffer
	buffer - stringstream - used to effectively parse data and avoid bad data errors
	throwaway - string - throwaway string used to ignore excess data in buffer lines
	DVD::title - Public string - used to store title of a DVD.
	DVD::type - Public string - used to store type of DVD (Blu-Ray, Digital, DVD, etc.)
	DVD::genre - Public string - used to store genre of DVD (fiction, sci-fi, comedy, etc.)
	DVD::copies - Public int - used to store number of existing copies of a known DVD
	DVD::holds - Puiblic int - used to store number of holds on a known DVD
	DVD::price - Public double - renting price
*/

/*
TEST PLAN

Normal Case 1 (A_New_Hope Blu-Ray Sci-Fi 50 2 5.05...etc):
	>Title: A New Hope|Type: Blu-Ray|Genre: Sci-Fi|Copies: 50|Holds: 2|Price: 5.05
	>...
	>(until last entry or 10 DVDs have been printed)
	>
	> done.
Bad Data Case 1 (too many whitespace-separated strings in line 1):
	>Title: A New Hope|Type: Blu-Ray|Genre: Sci-Fi|Copies: 50|Holds: 2|Price: 5.05
	>...
	>(Until last entry or 10 DVDs have been printed)
	>
	> done.
Bad Data Case 2 (too few whitespace-separated strings in line 1):
	>(skip first line)
	>...
	>(Until last entry or 10 DVDs have been printed)
	>
	> done.
Bad Data Case 3 (Incorrect order of data in line 1 or presence of string where int should be for example...)
	>(skip bad-data line)
	>...
	>(Until last entry or 10 DVDs have been printed)
	>
	> done.
Bad Data Case 4 (more than 10 lines in sample):
	>Title: A New Hope|Type: Blu-Ray|Genre: Sci-Fi|Copies: 50|Holds: 2|Price: 5.05
	>...
	>(until 10th entry)
	>
	> done.


Discussion:

The program is designed to ignore bad data as much as possible. To do this, I insert the data line by line into a buffer stringstream using getline().
The buffer can then parse the data into the DVD objects using >> operators. Any excess elements in the line will be parsed into a throwaway string.
If the data in the line was ordered incorrectly or was not sufficient to fill the DVD object the program moves on to the next line and the DVD object
is not filled.

The elements of this DVD object are printed using the DVD::print() function, and the pointer is incremented by 1. A check is performed to see if the 
last elements of the array of DVDs has been reached to avoid any memory errors (ordinarily I would use Vector and skip this entirely but the assignment
specified exactly 10 DVD objects). The next line is then sent to the buffer, until all 10 DVDs have been filled.

If I were to forego the buffer entirely (as I did in earlier iterations) the loop responsible for filling the DVD array would not meet the required condition.
The entire array past a certain point would therefore stop being filled if the >> operator failed in the case of bad or incomplete data.
*/


#include "DVD.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main() {
	DVD list[10];
	DVD* d = list;
	ifstream file("example.txt");
	string line;

	while(getline(file, line))
	{
		stringstream buffer(line);
		while (buffer >> d->title >> d->type >> d->genre >> d->copies >> d->holds >> d->price)
		{
			string throwaway;
			buffer >> throwaway;
			d->print();
			d++;
		}
		if (d-1 >= &list[9]){break;}
	}
	cout<< endl << "done.";
return 0;
}

