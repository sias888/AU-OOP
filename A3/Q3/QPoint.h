//:QPoint.h v1.6

#ifndef QPOINT_H //include guards
#define QPOINT_H //include guards

#include <iostream>
#include <string>
#include <cmath> //inclusions

class Point {
	double x; //x-ccordinate of point
	double y; //y-coordinate of point.

	friend std::istream& operator>> (std::istream& is, Point& p); //allowing >> operator to use private point variables
	friend std::ostream& operator<< (std::ostream& os, Point& p); //allowing << operator to use private point variables
	friend Point operator+ (Point p1, Point p2); // allowing + operator to use private point values
	friend Point operator- (Point p1, Point p2); //allowing - operator to use private point values
	friend double length(Point p1, Point p2); //allowing length() function to use private point values
public:

	Point() = default; //default constructor 
	Point(double x_init_val, double y_init_val) { //main useful constructor; initialized with 2 double varialbes used for x and y vals of point.
		x = x_init_val;
		y = y_init_val;
	}

	std::string displayinfo(); //displays information about the point
	double X() {return x;} //used to access x
	double Y() {return y;} //used to access y
};


double length(Point p1, Point p2); //length declaration; calculates length between two points

std::istream& operator>> (std::istream& is, Point& p) { //take point coordinates from some stream
	is >> p.x >> p.y; // point first takes x then y variables from input stream
	if (!is) p = Point(); //if the input stream is invald, point becomes (0,0)
	return is; //return pointer to the instream
}

std::ostream& operator<< (std::ostream& os, Point& p) { //put point coordinates into some stream
	os << p.x << p.y; // outstream takes x coordinate first, then y coordinate.
	return os; //returns pointer to the outstream
}

Point operator+ (Point p1, Point p2) { // add x and y coordinates of two points
	Point p; //value to be returned. Initializes with default double values (0,0)
	p.x = p1.x + p2.x; //sets result of x-value sum to x-value of point to be returned
	p.y = p1.y + p2.y; //sets result of y-value sum to y-value of point to be returned
	return p; //returns point
}

Point operator- (Point p1, Point p2) { //subtract x and y coordinates from two points. Same structure as + operator
	Point p;
	p1.x = p1.x - p2.x;
	p1.y = p1.y - p2.y;
	return p;
}

inline double length(Point p1, Point p2){ //returns length between two points as a double. Length will always be positive.
	return std::sqrt(std::pow(p1.x - p2.x,2) + std::pow(p1.y - p2.y,2));
}

inline std::string Point::displayinfo() { //returns the x and y coordinates in bracket-notation as a string.
	return "(" + std::to_string(x) + "," + std::to_string(y) + ")";
}

#endif //inlude guards