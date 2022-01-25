//:QShape.h
#ifndef QShape_H //include guards
#define QShape_H //include guards

#include "QPoint.h"
#include <iostream>
#include <limits>
#include <cmath>
#include <stdexcept>
#include <exception> //include declarations

class Shape { //Mother class shape. Serves as a template for daughter classes
protected:
	std::string name = "N/A"; //name of shape. changes depending on what child class access this variable.
	Point p1,p2,p3,p4; //points defining bounding box
	double area_val = -1; //area value initialized as -1 
	double peri_val = -1; //perimeter value initialized as -1
public:
	double Area(); // calculates area
	double Perimeter(); // calculates perimeter
	void display(); //displays information about shape
	
	Shape() = default; //defualt constructor
	virtual ~Shape() = default; //default destructor
};

void Shape::display () { //Prints name, area, perimeter, and bounding points of shape
	std::cout << std::endl << "Name: " << name << std::endl << "Area: " << area_val << std::endl
	<< "Perimeter: " << peri_val << std::endl << "Bounding Points: " << p1.displayinfo()
	<< " " << p2.displayinfo() << " " << p3.displayinfo() << " " << p4.displayinfo() << std::endl;
}

class Circle :public Shape { //daughter class circle
	Point centre; //unique aspects of circle. centre is a Point while radius is a double
	double radius;
public:
	double Area(); 
	double Perimeter();

	Circle() = default; //default constructor
	Circle(Point centre_init_val, double radius_init_val) { //initialize Circle object with radius and centre values
		try { //error catching used to prevent termination of program if incorrect/bad data is used to init circle
			if (radius_init_val == 0) //checks if value used to initialize radius of circle is zero
				throw std::runtime_error("Error! Radius of a circle cannot be 0."); //error message
			
			centre = centre_init_val;
			radius = radius_init_val;

			name = "Circle";

			p1 = centre + Point(-radius, radius); //sets bounding point values
			p2 = centre + Point(radius, radius);
			p3 = centre + Point(-radius,-radius);
			p4 = centre + Point(radius,-radius);

			area_val = Area(); //sets Shape's area_val and peri_val to return vals of Area() and Perimeter()
			peri_val = Perimeter();
		}
		catch(std::exception const& exc){ //prevents initialization of Circle object and prints error message instead.
			std::cerr << std::endl << exc.what() << std::endl;
		}
	}
};

double Circle::Area() { //calculates area of circle using pi*radius^2 formula
	return 3.141592653589793238463 * radius * radius;
}

double Circle::Perimeter() { //calculates perimeter of circle using 2*pi*radius formula
	return 3.141592653589793238463 * 2 * radius;
}

class Triangle:public Shape { //daughter class Triangle
	Point vertex1, vertex2, vertex3; //three points of triangle
	void boundaryHelper(); //function used to help calculate boundary points
	bool passCheck(Point, Point, Point); //function used to check whether triangle can exist
public:
	double Area();
	double Perimeter();

	Triangle() = default; //default constructor
	Triangle(Point v1, Point v2, Point v3) { // initialize triangle object with 3 point values
		try { // tries to init triangle using 3 points. Prints error message if points are invalid
			if (!passCheck(v1, v2, v3)) // returns false if the sum of the two smaller sides is less than or equal to the larger side of the triangle
				throw std::runtime_error("Error! A triangle must have 3 sides."); //error message
					
			vertex1 = v1;
			vertex2 = v2;
			vertex3 = v3;

			name = "Triangle";
		
			boundaryHelper(); //sets boudary points

			area_val = Area();
			peri_val = Perimeter();
		}
		catch(std::exception const& exc){
			std::cerr << std::endl << exc.what() << std::endl; //print error message and prevent initialization of triangle object if passCheck returns fail state
		}
	}
};

bool Triangle::passCheck(Point v1, Point v2, Point v3) { // used to check if valid triangle is formed using points given
	double s_len = std::numeric_limits<double>::max(); // initialize smallest side of triangle as max_double value
	double m_len = std::numeric_limits<double>::max(); // initialize medium side of triangle as max_double value
	double l_len = -std::numeric_limits<double>::max(); // initialize largest side of triangle as -max_double value.
	
	s_len = length(v1,v2) < s_len ? length(v1,v2) : s_len; // Calculate lengths between all three points. s_len is set to the smallest of these lengths.
	s_len = length(v1,v3) < s_len ? length(v1,v3) : s_len;
	s_len = length(v3,v2) < s_len ? length(v3,v2) : s_len;

	l_len = length(v1,v2) > l_len ? length(v1,v2) : l_len; // Calulcate lengths between all three points. l_len is set to the largest of the these lengths.
	l_len = length(v1,v3) > l_len ? length(v1,v3) : l_len;
	l_len = length(v3,v2) > l_len ? length(v3,v2) : l_len;

	m_len = (length(v1,v2) != s_len && length(v1,v2) != l_len) ? length(v1,v2) : m_len; // m_len is set to the last remaining side length
	m_len = (length(v1,v3) != s_len && length(v1,v3) != l_len) ? length(v1,v3) : m_len;
	m_len = (length(v3,v2) != s_len && length(v3,v2) != l_len) ? length(v3,v2) : m_len;

	if ((s_len + m_len) <= l_len) return 0; //return false if the sum of the two smaller sides are less than or equal to the large length
	else return 1; //return true otherwise
}

void Triangle::boundaryHelper() { //used to determine boundary points using 3 triangle points
	double smallx = std::numeric_limits<double>::max(), smally = std::numeric_limits<double>::max(); // set smallest x and y coordinates of boundary box to maximum double value
	double bigx = -std::numeric_limits<double>::max(), bigy = -std::numeric_limits<double>::max(); //set largest x and y coordinates of boundary box to minimum double value
	
	smallx = vertex1.X() < smallx ? vertex1.X() : smallx; // checks all X values of the three verticies. smallx is set to the least of the three.
	smallx = vertex2.X() < smallx ? vertex2.X() : smallx;
	smallx = vertex3.X() < smallx ? vertex3.X() : smallx;

	smally = vertex1.Y() < smally ? vertex1.Y() : smally; //checks all Y values of the three vertecies. smally is set to the least of the three.
	smally = vertex2.Y() < smally ? vertex2.Y() : smally;
	smally = vertex3.Y() < smally ? vertex3.Y() : smally;

	bigx = vertex1.X() > bigx ? vertex1.X() : bigx; // checks all x values. bigx is set to the largest.
	bigx = vertex2.X() > bigx ? vertex2.X() : bigx;
	bigx = vertex3.X() > bigx ? vertex3.X() : bigx;

	bigy = vertex1.Y() > bigy ? vertex1.Y() : bigy; //checks all y values. bigy is set to the largets.
	bigy = vertex2.Y() > bigy ? vertex2.Y() : bigy;
	bigy = vertex3.Y() > bigy ? vertex3.Y() : bigy;

	p1 = Point(smallx,bigy); //top left boundary box point is set to (smallx,bigy)
	p2 = Point(bigx,bigy); //top right bounding box point is set to (bigx,bigy)
	p3 = Point(smallx,smally); //bottom left if set to (smallx, smally)
	p4 = Point(bigx,smally); //bottom right is set to (bigx, smally)
}

double Triangle::Area() { //area calculation of triangle using heron's forumula
	double p = 0.5*Perimeter(); 
	double a = length(vertex1, vertex2);
	double b = length(vertex1, vertex3);
	double c = length(vertex2, vertex3);

	return sqrt(p*(p-a)*(p-b)*(p-c));
}

double Triangle::Perimeter() { //returns sum of 3 side lengths
	int l1, l2, l3;

	l1 = length(vertex1, vertex2);
	l2 = length(vertex2, vertex3);
	l3 = length(vertex1, vertex3);

	return l1 + l2 + l3;
}

class Square : public Shape{ //daughter class Square
	Point vertex1, vertex2, vertex3, vertex4; //4 points of square
	void boundaryHelper(); // used to calculate (and order) the bounding box of the shape
	bool passCheck(Point, Point, Point, Point); //checks whether points given form a sqaure
public:
	double Area();
	double Perimeter();

	Square() = default;
	Square(Point v1, Point v2, Point v3, Point v4) { //initialize using 4 points. the points can be given in any order--the checks allow for this (which was harder to implement than it first seemed)
		try {	//tried creating instance of square object. Fails if points do not form a square. error message is printed and object is not created			
			if (!passCheck(v1,v2,v3,v4)) 
				throw std::runtime_error("Error! All side lengths of a square must be equal.");
			
			vertex1 = v1;
			vertex2 = v2;
			vertex3 = v3;
			vertex4 = v4;

			name = "Square";
		
			boundaryHelper(); // assigns bounding box points in order 

			area_val = Area();
			peri_val = Perimeter();
		}
		catch (std::exception const& exc){
			std::cerr << std::endl << exc.what() << std::endl; //display error message if needed
		}
	}
};

bool Square::passCheck(Point v1, Point v2, Point v3, Point v4) {//desinged to return true if points form square.
	bool b = 0; //return value.
	Point pointArr[4] = {v1,v2,v3,v4}; //array of all 4 points.
	double s_len = std::numeric_limits<double>::max(), l_len = -std::numeric_limits<double>::max(); //s_len is the smallest length in a square, or the side length.
	//l_len is the largest length; the length of the diagonal. s_len is intended to be reduced later, so it is initialized as max double value.
	//l_len is set to the smallest double length as it will increase depending on how long the diagonals of the square are.
	int s_count = 0, l_count = 0; //these count how many s_len and l_len are found in the square
	//Simpler methods to determine symmetry cannot be used as the order the points were given in (left to right, random order, etc.) is unknown.

	for (int i = 0; i < 4; i++) { //iterate through array of points from first to last
		for (int j = 3; j > -1; j--) { //iterate through array of points from last to first
			s_len = length(pointArr[i], pointArr[j]) < s_len && i != j? length(pointArr[i], pointArr[j]) : s_len; //length between two points is calculated.
			// if the calculated length is smaller than the current s-len value, s_len is set to the calculated length
			l_len = length(pointArr[i], pointArr[j]) > l_len && i != j? length(pointArr[i], pointArr[j]) : l_len; //length between two points is calculated.
			//if the calculated length is larger than the current l_len value, l_len is set to the calculated length
		} 
	}
	//the above calculates all the possible lengths between two unique points. the smallest of these lengths is set to s_len and the largest is set to l_len.
	//the following nested loop counts the number of s_len and l_len that can be found when iterating between all lengths
	for (int i = 0; i < 4 ; i++) {
		for (int j = 3; j > -1; j--) {
			s_count = length(pointArr[i], pointArr[j]) == s_len ? s_count + 1 : s_count; //increment s_count by 1 if the given length is equal to s_len value
			l_count = length(pointArr[i], pointArr[j]) == l_len ? l_count + 1 : l_count; //increment l_count by 1 if the given length is equal to l_len value
		} 
	}
	//in any given square, there must be 2 identical diagonals and 4 identical side lengths.
	//if the given points form a square, the largest length that could possibly be formed is the diagonal of the square.
	//the smallest length possible is the side length.
	//therefore, counting the number of "smallest lengths" and "largest lengths" formed by four given points will determine whether the shape formed is a square.
	//this method accounts for all angles of rotation the square could have, and eliminates the possibility that the "square" is really a rhombus. 
	
	b = s_count == 8 && l_count == 4 && s_len != l_len ? 1 : 0;//if s_count is 8 and l_count is 4, and if s_len and l_len are not equal (possible if all 4 points are the same point), set b to 1.

	return b;
}

void Square::boundaryHelper() { //this function assigns the values of the boundary box points

	double smallx = std::numeric_limits<double>::max(), smally = std::numeric_limits<double>::max(); //smallest x and y values are given max double values
	double bigx = -std::numeric_limits<double>::max(), bigy = -std::numeric_limits<double>::max(); //largest x and y values are given min double values
	
	smallx = vertex1.X() < smallx ? vertex1.X() : smallx; //set smallx to smallest x coordinate of all the given points
	smallx = vertex2.X() < smallx ? vertex2.X() : smallx;
	smallx = vertex3.X() < smallx ? vertex3.X() : smallx;
	smallx = vertex4.X() < smallx ? vertex4.X() : smallx;

	smally = vertex1.Y() < smally ? vertex1.Y() : smally; //set smally to smallest y coordinate of all the given points
	smally = vertex2.Y() < smally ? vertex2.Y() : smally;
	smally = vertex3.Y() < smally ? vertex3.Y() : smally;
	smally = vertex4.Y() < smally ? vertex4.Y() : smally;	

	bigx = vertex1.X() > bigx ? vertex1.X() : bigx; //set bigx to largest x coordinate of given points
	bigx = vertex2.X() > bigx ? vertex2.X() : bigx;
	bigx = vertex3.X() > bigx ? vertex3.X() : bigx;
	bigx = vertex4.X() > bigx ? vertex4.X() : bigx;	

	bigy = vertex1.Y() > bigy ? vertex1.Y() : bigy; //set bigy to largest y coordinate of given points
	bigy = vertex2.Y() > bigy ? vertex2.Y() : bigy;
	bigy = vertex3.Y() > bigy ? vertex3.Y() : bigy;
	bigy = vertex4.Y() > bigy ? vertex4.Y() : bigy;

	p1 = Point(smallx,bigy); //boundary box point 1 (top left point) is set to (smallx,bigy)
	p2 = Point(bigx,bigy); // top right point is given value
	p3 = Point(smallx,smally); //bottom left point is given value
	p4 = Point(bigx,smally); // bottom right point is given value
}

double Square::Area() {//calculate area of square
	if (length(vertex1,vertex2) <= length(vertex1,vertex3)) //the smallest line between two given points in a square is the side length.
	//checks size returned between two lengths and determines the smaller length. returns the square of the smaller length.
		return pow(length(vertex2, vertex1),2);
	else return pow(length(vertex1,vertex3),2);
}

double Square::Perimeter() { //calculate perimeter of square
	if (length(vertex1,vertex2) <= length(vertex1,vertex3)) //the smallest line between two given points in a square is the side length
	//checks size returned between two lengths are determines the smaller length. returns the smaller length multiplied by 4.
		return 4*length(vertex2,vertex1);
	else return 4*length(vertex1,vertex3);
}

#endif //include guards