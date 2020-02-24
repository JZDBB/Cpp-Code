#include<iostream>
//#include"Clock.h"
#include "Point.h"
#include"Line.h"
using namespace std;

// 引用传递
void swap(int &a, int &b) {
	int t = a;
	a = b;
	b = t;
}

// 函数重载
int SumOfSquare(int a, int b) {
	return a * a + b * b;
}

double SumOfSquare(double a, double b) {
	return a * a + b * b;
}

double max1(double x, double y) {// 浮点数比较方法
	if (abs(x - y) < 1e-10) return x;// 判断浮点数相等
	if (x >= y)
		return x;
	else
		return y;
}

// 复制构造函数
void fun1(Point p) {
	cout << p.getX() << endl;
}

Point fun2() {
	Point a;
	return a;
}

int main()
{
	cout << "Hello World!" << endl;

	// 引用传递
	/*int x = 5, y = 10;
	swap(x, y);
	cout << "x=" << x << "y=" << y << endl;*/

	// 函数重载
	/*int m, n;
	cout << "enter two integer: ";
	cin >> m >> n;
	cout << "Sum of square: " << SumOfSquare(m, n) << endl;
	double x, y;
	cout << "enter two number: ";
	cin >> x >> y;
	cout << "Sum of square: " << SumOfSquare(x, y) << endl;*/

	// 面向对象类
	//Clock c(0, 0, 0); //自动调用构造函数
	//c.showTime();

	// 复制构造函数
	/*Point a;
	Point b(a);
	cout << b.getX() << endl;
	fun1(b);
	b = fun2();
	cout << b.getX() << endl;*/

	// 组合类
	Point p1(1, 1), p2(4, 5);
	Line line(p1, p2);
	Line line2(line);
	cout << "line length: " <<line.getLen()<< endl;
	cout << "line2 length: " << line2.getLen() << endl;

	return 0;
}