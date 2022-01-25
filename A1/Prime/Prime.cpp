//: Prime.cpp

/*
Title: Prime.cpp
Descprion: Lists all prime numbers from 1 to 10000
Date: 2020-05-27
Author: Irteza Shamsi
Version: 2.0
*/

/*
DOCUMNETATION

Purpose: This program will display all the prime numbers from 1 to 10000

Compile: g++ -o Prime Prime.cpp
Execute: ./Prime

Classes: none

Variables: 
	prime - bool - condition that is true when number is prime and false when not prime
	primeList - vector<prime> - vector of all prime numbers
*/

/*
TEST PLAN

Normal Case:
	>2, 3, 5...9973

*/

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {

	bool prime = false;
	vector<int> primeList;

	primeList.push_back(2); // adding first two known prime numbers to list
	primeList.push_back(3);

	for (int i = 4; i <= 10000; i++){ // iterating through all numbers between 3 (last known prime number) and 10000

		for (int j = 0; primeList[j] <= ceil(sqrt(i)); j++){ //iterating through all known prime numbers until square root of current number i is reached
			if (i % primeList[j] == 0) { // if remainder is zero, current number i has a factor, and is therefore not prime. Set prime to false and break loop.
				prime = false;
				break;
			}
			else prime = true;
		}
		
		if (prime == true) {
			primeList.push_back(i); // add current number i to list of known primes
		}
	}

	for (int k = 0; k < primeList.size() - 1; k++) { // cout list of primes until second-last entry
		cout << primeList[k] << ", ";
	}
	cout << primeList.back(); //cout last prime number
}	