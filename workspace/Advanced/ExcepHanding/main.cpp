#include <iostream>
using namespace std;

int divide(int x, int y) {
	if (y == 0)
		throw x;
	return x / y;
}

//给出三角形三边长，计算三角形面积
double area(double a, double b, double c) {
	//判断三角形边长是否为正
	if (a <= 0 || b <= 0 || c <= 0)
		throw invalid_argument("the side length should be positive");
	//判断三边长是否满足三角不等式
	if (a + b <= c || b + c <= a || c + a <= b)
		throw invalid_argument("the side length should fit the triangle inequality");
	//由Heron公式计算三角形面积
	double s = (a + b + c) / 2;
	return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main() {

	// 异常处理
	/*try {
		cout << "5 / 2 = " << divide(5, 2) << endl;
		cout << "8 / 0 = " << divide(8, 0) << endl;
	}
	catch (int e) {
		cout << e << " is divided by zero!" << endl;
	}
	cout << "That is ok." << endl;*/

	// 异常处理的构造和析构

	double a, b, c;	//三角形三边长
	cout << "Please input the side lengths of a triangle: ";
	cin >> a >> b >> c;

	try {
		double s = area(a, b, c);	//尝试计算三角形面积
		cout << "Area: " << s << endl;
	}
	catch (exception &e) {
		cout << "Error: " << e.what() << endl;
	}

	return 0;
}