#pragma once
class Point
{
public:
	int getX();
	int getY();
	Point();
	Point(int px, int py);
	Point(Point &p);
	~Point();
private:
	int x, y;
};

