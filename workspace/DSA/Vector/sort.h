#pragma once
#include<vector>
using namespace std;

template <typename T>
void bubbleSort(vector<T> &V) { // 蛮力版
	int lo = 0, hi = V.size();
	T temp;
	while (lo < --hi) {
		for (int i = lo; i < hi; i++) {
			if (V[i] > V[i + 1]) {
				temp = V[i];
				V[i] = V[i + 1];
				V[i + 1] = temp;
			}	
		}
	}
}

template <typename T>
void bubbleSort1(vector<T> &V) { // 跳跃版
	int lo = 0, hi = V.size();
	for (int last = --hi; lo < hi; hi = last)
		for (int i = last = lo; i < hi; i++)
			if (V[i] > V[i + 1]) //若逆序，则
				swap(V[last = i], V[i + 1]); //经交换使局部有序
}
