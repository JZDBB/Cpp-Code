#pragma once
#include"Point.h"
class ArrayOfPoint {
public:
	ArrayOfPoint(int size);
	ArrayOfPoint(const ArrayOfPoint& pointsArray);
	~ArrayOfPoint();
	Point& element(int index);
private:
	int size;
	Point *points;
};

