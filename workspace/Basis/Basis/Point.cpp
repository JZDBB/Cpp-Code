#include "Point.h"
#include<iostream>
using namespace std;
Point::Point(){}
Point::Point(int px, int py):x(px),y(py){}
Point::Point(Point &p)
{
	x = p.x;
	y = p.y;
	cout << "Calling copy constructor" << endl;
}


Point::~Point()
{
}

int Point::getX() {
	return x;
}

int Point::getY() {
	return y;
}