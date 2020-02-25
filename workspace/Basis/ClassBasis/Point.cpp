#include "Point.h"
#include<iostream>
using namespace std;

int Point::count = 0; // 静态成员需要初始化
Point::Point() { count++; }
Point::Point(int px, int py) :x(px), y(py) { count++; }
Point::Point(Point &p)
{
	x = p.x;
	y = p.y;
	cout << "Calling copy constructor" << endl;
	count++;
}


Point::~Point()
{
	count--;
}

int Point::getX() {
	return x;
}

int Point::getY() {
	return y;
}

void Point::showCount() {
	cout << "Objectcount = " << count << endl;
}