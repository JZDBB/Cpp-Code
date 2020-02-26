#include "IntNum.h"
#include<iostream>
using namespace std;

IntNum::IntNum(){}
IntNum::IntNum(int x = 0):xptr(new int(x))
{
	cout << "Constructor..." << endl;
}

IntNum::IntNum(const IntNum& n): xptr(new int(*n.xptr)){
	cout << "Copy Constructor..." << endl;
}
IntNum::IntNum(IntNum && n) : xptr(n.xptr){
	n.xptr = nullptr;
  // &&是右值引用——即将消亡
	cout << "Move Constructor..." << endl;
}


IntNum::~IntNum()
{
	cout << "Deconstructor..." << endl;
}

int IntNum::getInt() {
	return *xptr;
}
