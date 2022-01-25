//:DVD.h
#include <string>
#include <iostream>

#ifndef DVD_H
#define DVD_H

//using namespace std;

class DVD {
public:
	std::string title, type, genre,
		    *title_p = &title;
	int copies, holds;
	double price;
	void print();
private:
	void replaceUnderscore(std::string*);
};

void DVD::print(){
	replaceUnderscore(title_p);
	std::cout << "Title: " << title << "|Type: " << type << "|Genre: " << genre << "|Copies: " << copies << "|Holds: " << holds<< "|Price: " << price << std::endl;
}

void DVD::replaceUnderscore(std::string* inString_p){
	std::string str = "_";
	std::string str2 = " ";
	std::size_t pos = inString_p->find(str);
	
	while(pos != std::string::npos){
		inString_p->replace(pos,str.length(),str2);
		pos = inString_p->find(str);
	}
}

#endif