//:Text.H

#include <fstream>
#include <string>

#ifndef Text_H
#define Text_H

class Text {
	std::string contents;
	bool success;
public:
	std::string fileName;
	std::string returnContents();
	bool readFile();
	Text() = default;
	Text (std::string instring) {
		fileName = instring;
		success = readFile();
	};
};

bool Text::readFile() {
	if(Text::fileName.find(".txt") == -1) { //append .txt to filename if missing

		Text::fileName = Text::fileName + ".txt";
    	}
	
	std::ifstream file(Text::fileName); //open file
	std::string str; //used to read words from file
	
	if(!file.fail()){
		while (file >> str) {//str stored whitespace separated words and advances file cursor until end of file
			Text::contents = Text::contents + str + " "; //appends str and a space to contents string
		}
		Text::success = 1;
		return 1;
	}
	else {
	Text::success = 0;
	return 0;
	}
}

std::string Text::returnContents(){
if (Text::success == 1) return Text::fileName + ": " + Text::contents;//returns contents with successful file reading--used to hide implementation of contents to prevent direct editing
else return "file " + Text::fileName + " does not exist."; // returns an error message if file did not open correctly.
}

#endif