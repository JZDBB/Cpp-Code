#include<iostream>
using namespace std;

#include"vector.h"

// 基本ok，还需完善出来冒泡和归并意外的排序以及遍历函数

int main() {

	// 向量
	Vector<int> arr;
	int a[20] = { 1, 4, 3, 4, 5, 12, 7, 15, 11, 14 };
	for (int i = 0; i < 10; i++) {
		arr.insert(a[i]);
	}
	cout << "empty? " << arr.empty() << endl;
	cout << "find 12: " << arr.find(12) << endl;
	cout << "remove index 3: " << arr.remove(3) << endl;
	arr.sort();
	cout << arr.search(4) << endl;





	return 0;
}
