//:main.cpp

/*
Title: main.cpp
Description: This program records time to complete filling and multiplying two double-arrays.
Date: 2020-06-20
Author: Irteza Shamsi
Version: 1.0
*/

/*
DOCUMENTATION

Purpose: This program records time to complete filling and multiplying two double-arrays.

Compile: g++ -o main main.cpp
Execute: ./main

Classes: none
Functions: func() - returns void - takes no args - creates two arrays filled with doubles and multiplies the entries
Variables:
	init_t - const time_t - records time of program initialization
	end_t - time_t - records time after func() has been completed
*/

/*
TEST PLAN

Normal Case:
	>...(print out all multiplied double values_
	>...
	>...
	>elapsed time: (end_t - init_t) seconds

Discussion: 

This program performes the above calculation and records the time it takes to perform the calculation. It then prints out
the elapsed time. On average, the elapsed time was 3 seconds.
*/


#include <iostream>
#include <ctime>

void func ();

int main() {
	const std::time_t init_t = std::time(NULL);
	std::time_t end_t;

	func();

	std::time(&end_t);
	std::cout << std::endl << "elapsed time: " << end_t - init_t << " seconds";

}

void func () {

	double arr1[10000];
	double arr2[10000];

	for (int i=0; i < 10000; i++) {
		arr1[i] = i + 100;
		arr2[i] = 10099 - i;
	}

	for (int i = 0; i < 10000; i++) {
		std::cout << arr1[i] * arr2[i] << std::endl;
	}
}