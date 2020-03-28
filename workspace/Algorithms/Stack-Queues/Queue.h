#pragma once
#include<vector>
#include<queue>
using namespace std;

class MonotonicQueue {
public:
	// 在队尾添加元素 n
	void push(int n) {
		while (!Q.empty() && Q.back() < n) Q.pop_back();
		Q.push_back(n);
	}
	// 返回当前队列中的最大值
	int max() {
		return Q.front();
	}
	// 队头元素如果是 n，删除它
	void pop(int n) {
		if (!Q.empty() && Q.front() == n) Q.pop_front();
	}
private:
	deque<int> Q;// 双端队列 ——可以在队头队尾做push和pop
};

vector<int> maxSlidingWindow(vector<int>& nums, int k);