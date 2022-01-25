//:DisplayHen.cpp

/*
Title: DisplayHen.cpp
Description: uses Hen, Nest, and Egg classes defines in Hen.h to create instances of each class in heap memory
	     calls a display() function from each function, then removes each instance from memory.
Date: 2020-06-24
Author: Irteza Shamsi
Version: 2.1
*/

/*
DOCUMENTATION

Purpose: display information about nested Hen, Nest, and Egg objects.

Compile: g++ -o DisplayHen DisplayHen.cpp Hen.h
Execution: ./DisplayHen

Classes:
	Hen - contains display() function that prints information about Hen and initializes Nest class.
	Nest - contains display() function that prints information about Nest and initializes Egg class.
	Egg - contains display() function that prints information about Egg class.

Functions:
	public void Hen::display() - prints "Hello I am a hen!"
	public void Hen::Nest::display() - prints "Hello I am a nest!"
	public void Hen::Nest::Egg::display() - prints "Hello I am an egg!"

Variables:
	h - Hen* - pointer to Hen object refernced from heap memory
	n - Nest* - pointer to Nest object referenced from heap memory
	e - Egg* - pointer to egg object referenced from heap memory
*/

/*
TEST PLAN

Normal Case:
	>Hello I am a hen!"
	>Hello I am a nest!"
	>Hello I am an egg!
	>
	>ok
*/

#include "HenC.H"

int main() {
	Hen* h = new Hen;
	Hen::Nest* n = new Hen::Nest;
	Hen::Nest::Egg* e = new Hen::Nest::Egg;

	h->display();
	n->display();
	e->display();

	delete e;
	delete n;
	delete h;
	std::cout << '\n' << "ok"; 
}