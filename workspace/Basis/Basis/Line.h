#pragma once
#include"Point.h"
class Line {
private:
	Point p1, p2;
	float len;

public:
	float getLen();
	Line(Point a, Point b);
	Line(Line &l);
};

