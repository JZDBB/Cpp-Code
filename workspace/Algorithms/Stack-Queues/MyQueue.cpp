#include "MyQueue.h"

MyQueue::MyQueue()
{

}

void MyQueue::push(int x)
{
	pushs.push(x);
}

int MyQueue::pop()
{
	push2pop();
	int m = pops.top();
	pops.pop();
	pop2push();
	return m;
}

int MyQueue::peek()
{
	push2pop();
	int m = pops.top();
	pop2push();
	return m;
}

bool MyQueue::empty()
{
	return pushs.empty();
}

void MyQueue::push2pop()
{
	while (!pushs.empty()) {
		pops.push(pushs.top());
		pushs.pop();
	}
}
void MyQueue::pop2push()
{
	while (!pops.empty()) {
		pushs.push(pops.top());
		pops.pop();
	}
}

MyQueue::~MyQueue()
{
}
