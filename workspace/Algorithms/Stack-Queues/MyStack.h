#pragma once
#include<queue>
using namespace std;

class MyStack
{
public:
	/** Initialize your data structure here. */
	MyStack() {

	}

	/** Push element x onto stack. */
	void push(int x) {
		pushs.push(x);
	};

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		int m = pushs.back();
		for (int i = 0; i < pushs.size(); i++) {
			pops.push(pushs.front());
			pushs.pop();
		}
		pushs.pop();
		pop2push();
		return m;
	};

	/** Get the top element. */
	int top() {
		return pushs.back();
	};

	/** Returns whether the stack is empty. */
	bool empty() {
		return pushs.empty();
	};
	
private:
	queue<int> pushs, pops;
	void pop2push() {
		while (!pops.empty()) {
			pushs.push(pops.front());
			pops.pop();
		}
	};
};

