#pragma once
#include<stack>
using namespace std;

class MyQueue
{

public:
	/** Initialize your data structure here. */
	MyQueue();
	~MyQueue();

	/** Push element x to the back of queue. */
	void push(int x);

	/** Removes the element from in front of queue and returns that element. */
	int pop();

	/** Get the front element. */
	int peek();
	/** Returns whether the queue is empty. */
	bool empty();

private:
	stack<int> pushs, pops;
	int len;

	void push2pop();
	void pop2push();
};

