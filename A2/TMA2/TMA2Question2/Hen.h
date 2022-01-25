//Hen.h

#include <iostream>

#ifndef Hen_H
#define Hen_H

class Hen {
public:
	void display();
	class Nest;
};

class Hen::Nest {
public:
	void display();
	class Egg;
};

class Hen::Nest::Egg {
public:
	Egg() = default;
	void display();
};

void Hen::display() {
	std::cout << "Hello I am a hen!" << '\n';
}

void Hen::Nest::display() {
	std::cout << "Hello I am a nest!" << '\n';
}

void Hen::Nest::Egg::display() {
	std::cout << "Hello I am an egg!" << '\n';
}

#endif