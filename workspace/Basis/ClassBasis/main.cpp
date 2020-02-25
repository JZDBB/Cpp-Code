#include<iostream>
//#include"Clock.h"
#include "Point.h"
#include"Line.h"
#include"COMPUTER.h"
#include"CPU.h"
#include"RAM.h"
#include"CDROM.h"
using namespace std;


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
	/*Point p1(1, 1), p2(4, 5);
	Line line(p1, p2);
	Line line2(line);
	cout << "line length: " <<line.getLen()<< endl;
	cout << "line2 length: " << line2.getLen() << endl;*/

	// 组合例子
	//CPU a(P6, 300, 2.8);
	//a.run(); a.stop();
	//cout << "*****************\n";
	//RAM b(DDR3, 1600, 8);
	//b.run(); b.stop();
	//cout << "*****************\n";
	//CDROM c(SATA, external, 23);
	//c.run(); c.stop();
	//cout << "*****************\n";
	//COMPUTER com(a, b, c, 1080, 512);
	//com.Run(); com.Stop();
	//cout << "*****************\n";


	// 静态成员
	Point::showCount();
	Point a(4, 5);
	cout << "Point A:" << a.getX() << "," << a.getY() << endl;
	Point::showCount();

	Point b(a);
	cout << "Point B" << b.getX() << "," << b.getY() << endl;
	Point::showCount();

	return 0;
}