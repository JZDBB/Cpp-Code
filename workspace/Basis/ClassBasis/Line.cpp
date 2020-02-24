#include "Line.h"
#include<iostream>
#include <math.h>
#include"Point.h"

using namespace std;

//组合类的构造函数
Line::Line(Point xp1, Point xp2):p1(xp1), p2(xp2) {
	cout << "Calling costructor of Line" << endl;
	double x = static_cast<double>(p1.getX() - p2.getX());
	double y = static_cast<double>(p1.getY() - p2.getY());
	len = sqrt(x*x + y * y);
}
// 组合类的拷贝函数
Line::Line(Line &l) :p1(l.p1), p2(l.p2), len(l.len) {
	cout << "Calling the copy cinstructor of line" << endl;
}

float Line::getLen() {
	return len;
}