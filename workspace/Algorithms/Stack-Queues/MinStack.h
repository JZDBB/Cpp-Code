#pragma once
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

// 155. ×îÐ¡Õ»¡ª¡ªË«Õ»ÅäºÏ
class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {
		
	}

	void push(int x) {
		if (min.empty()) min.push(x);
		else min.push(x < min.top() ? x : min.top());
		s.push(x);
	}

	void pop() {
		min.pop();
		s.pop();
	}

	int top() {
		return s.top();
	}

	int getMin() {
		return min.top();
	}
private:
	stack<int> s, min;
};
