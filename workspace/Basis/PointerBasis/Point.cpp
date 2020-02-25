#include "Point.h"
#include<iostream>
using namespace std;

Point::Point() :x(0), y(0) { cout << "Defuat Constructor called.\n"; }
Point::Point(int x, int y) :x(x), y(y) { cout << "Constructor called.\n"; };
Point::~Point() { cout << "Destructor called.\n"; }
int Point::getx() { return x; };
int Point::gety() { return y; };
void Point::move(int nx, int ny) { x = nx; y = ny; }
