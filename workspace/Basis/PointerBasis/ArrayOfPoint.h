#pragma once
#include"Point.h"
class ArrayOfPoint {
public:
	ArrayOfPoint(int size);
	~ArrayOfPoint();
	Point& element(int index);
private:
	int size;
	Point *points;
};

