#pragma once
#ifndef POINT_H_
#define POINT_H_

class Point {
private:
	int x, y;
public:
	Point();
	Point(int x, int y);
	~Point();
	int getx();
	int gety();
	void move(int nx, int ny);
};


#endif // !POINT_H_
