#include "ArrayOfPoint.h"
#include<iostream>
#include <assert.h>
using namespace std;

ArrayOfPoint::ArrayOfPoint(int size) :size(size) { points = new Point[size]; }
ArrayOfPoint::~ArrayOfPoint() { cout << "Deleting ..."; delete[] points; }
Point& ArrayOfPoint::element(int index) {
	assert(index >= 0 && index < size);// 判断下标不能越界
	return points[index];// 返回一个引用才能对该对象进行操作，如果是返回值则无法操作。引用是左值能够进行操作
}
