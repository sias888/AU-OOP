//:main.cpp

/*
Title: main.cpp
Description: uses defined Shape and Point classes to create a circle, triangle, and square, and display information
	     about each shape.
Date: 2020-06-28
Author: Irteza Shamsi
Version: 2.5
*/

/*
DOCUMENTATION

Purpose: create various shapes and display information about each shape

Compile: g++ -o main main.cpp QShape.h QPoint.h
	 OR make (using makefile)
Execute: ./main

Classes:
	Point - Point(), Point(double, double) - takes two double inputs from user which serve as x and y coordinates describing a point on a 2D cartesian plane
	Shape - Shape() - Parent class which serves as a template for child classes which represent types of shapes
	Circle - Circle(), Circle(Point, double) - takes a Point and a double which serve as the centre and radius of a circle
	Triangle - Triangle(), Triangle(Point, Point, Point) - takes 3 Points to form a traingle
	Square - Square, Square(Point, Point, Point, Point) - takes 4 points to form a square
Functions:
	public string Point::displayinfo() - outputs information about a point as a string
	public double Point::X() - returns private x coordinate
	public double Point::Y() - returns private y coordinate
	double length(Point, Point) - calculates distance between two ppints. Declared and defined in QPoint.h as non-member function
	istream& operator>> (istream&, Point&) - friend function of Point class. overloaded >> operator. Takes point coordinates from some stream
	ostream& operator<< (ostream&, Point&) - friend function of Point class. overloaded << operator. Put point coordinates into some stream
	Point operator+ (Point, Point) - friend function of Point class. overloaded + operator. add x and y coordinates of two points
	Point operator- (Point, Point) - friend function of Point class. overloaded - operator. subtract x and y coordinates of two points.

	public void Shape::display() - prints information about a shape
	public double Shape::Area() - template Area function
	public double Shape::Perimeter() - template perimeter function

	public double Circle::Area() - calculates Area of circle and defines area_val
	public double Circle::Perimeter() - Calculates perimeter of circle and defines peri_val

	public double Triangle::Area() - calculates Area of triangle and defines area_val
	public double Triangle::Perimeter() - Calculates perimeter of triangle and defines peri_val
	private void Triangle::boundaryHelper() - used to calculate boundary points of shape
	private bool Triangle::passCheck(Point, Point, Point) - function used to check whether triangle can exist using given points

	public double Square::Area() - calculates Area of square and defines area_val
	public double Square::Perimeter() - Calculates perimeter of square and defines peri_val
	private void Square::boundaryHelper() - used to calculate and order boundary points of shape
	private bool Square::passCheck(Point, Point, Point, Point) - function used to check whether square can exist using given points
Variables:
	private Point::x - double - value representing x coordinate of point
	private Point::y - double - value representing y coordinate of point

	protected Shape::name - string - name of shape
	protected Shape::p1 - Point - top left point of boundary box of shape
	protected Shape::p2 - Point - top right point of boundary box of shape
	protected Shape::p3 - Point - bottom left point of boundary box of shape
	protected Shape::p4 - Point - botoom right point of boundary box of shape
	protected Shape::area_val - double - area value of shape
	protected Shape::peri_val - double - perimeter value of shape
	
	private Circle::centre - Point - value representing coordinates of centre of cricle as a Point
	private Circle::radius - double - value representing the radius of the circle
	
	private Triangle::vertex1 - Point - one of the three points of triangle
	private Triangle::vertex2 - Point - one of the three points of triangle
	private Triangle::vertex3 - Point - one of the three points of triangle

	private Square::vertex1 - Point - one of the four points of square
	private Square::vertex2 - Point - one of the four points of square
	private Square::vertex3 - Point - one of the four points of square
	private Square::vertex4 - Point - one of the four points of square

	c - Circle - circle object
	t - Triangle - triangle object
	s - Square - square object
	s2 - Square - square object used for testing purposes.
*/


/*
TEST PLAN

Normal Case (all points are valid and form shapes correctly)
	>Name: Circle
	>Area: 1661.9
	>Perimeter: 144.513
	>Bounding Points: (-10.000000,30.000000) (20.000000,30.000000) (-10.000000,-10.000000) (20.000000,-10.000000)
	>
	>(and so on for the other shapes)

Bad Coordinates Case 1 (Circle values are invalid)
	>Error! Radius of a circle cannot be 0 (and/or: "Error! All side lengths of a square must be equal." for square, and/or "Error! A triangle must have 3 sides." for triangle)
	>
	>Name: N/A
	>Area: -1
	>Perimeter: -1
	>Bounding Points:  (0.000000,0.000000) (0.000000,0.000000) (0.000000,0.000000) (0.000000,0.000000)
	>
	>(Print rest of shape info normally, assuming good inputs)

*/

#include "QShape.h"

int main() {
	Circle c(Point(0,0), 23);
	Triangle t(Point(-10,-10), Point(20,-10), Point(-10,30)); //A traingle with sides 10, 20, 30 is impossible to exist as sides 1 and 2 cannot add up to side 3 in a triangle.	
	Square s(Point(-1, -1), Point(24, 24), Point(24, -1), Point(-1, 24));
	Square s2(Point(0,0), Point(-1,1), Point(0,2), Point(1,1));

	c.display();
	t.display();
	s.display();
	s2.display();
}