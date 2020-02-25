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
	static void showCount();
private:
	int x, y;
	static int count;
};

