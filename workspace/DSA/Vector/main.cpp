#include<iostream>
#include<vector>
#include<stack>
using namespace std;

#include"search.h"
#include"sort.h"


int main() {

	// 向量
	vector<int> arr;
	int index;
	int a[20] = { 1, 4, 3, 4, 5, 12, 7, 15, 11, 14 };
	arr.insert(arr.begin(), a, a + 9);

	// 冒泡排序
	bubbleSort1(arr);
	
	// 二分查找
	index = Bisearch(arr, 6, 0, 9);



	// Stack 应用——进制转换
	/*stack<int> S;
	int re, num = 2013;
	while (num) {
		re = num % 2;
		num = num / 2;
		S.push(re);
	}
	while (!S.empty()) {
		cout << S.top();
		S.pop();
	}*/



	return 0;
}
