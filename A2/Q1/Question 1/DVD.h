//:DVD.h
#include <string>
#include <iostream>

#ifndef DVD_H
#define DVD_H

class DVD
{
public:
	std::string title, type, genre;
	int copies, holds;
	double price;
	void print();
private:
	std::string replaceUnderscore(std::string);
};

void DVD::print()
{
	title = replaceUnderscore(title);
	std::cout << "Title: " << title << "|Type: " << type << "|Genre: " << genre << "|Copies: " << copies << "|Holds: " << holds<< "|Price: " << price << std::endl;
}

std::string DVD::replaceUnderscore(std::string inString)
{

	std::string str = "_";
	std::string str2 = " ";
	std::size_t pos = inString.find(str);
	
	while(pos != std::string::npos)
	{
		inString.replace(pos,str.length(),str2);
		pos = inString.find(str);
	}

	return inString;
}

#endif