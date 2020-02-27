#include "Stack.h"
#include<assert.h>
#include<iostream>
using namespace std;

template<class T, int SIZE>
Stack<T,SIZE>::Stack():Top(-1)
{
}

template<class T, int SIZE>
Stack<T,SIZE>::~Stack()
{
}

template<class T, int SIZE>
bool Stack<T,SIZE>::stackEmpty()
{
	return Top == -1;
}

template<class T, int SIZE>
bool Stack<T, SIZE>::stackFull()
{
	return Top == SIZE - 1;
}

template<class T, int SIZE>
void Stack<T, SIZE>::clearStack()
{
	Top = -1;
}

template<class T, int SIZE>
int Stack<T, SIZE>::stackLength()
{
	return 0;
}

template<class T, int SIZE>
void Stack<T, SIZE>::push(const T & item)
{
	assert(!stackFull());
	list[++Top] = item;
}

template<class T, int SIZE>
T Stack<T, SIZE>::pop()
{
	assert(!stackEmpty());
	return list[Top--];
}

template<class T, int SIZE>
const T & Stack<T, SIZE>::peek() const
{
	// TODO: 在此处插入 return 语句
	assert(!stackEmpty());
	return list[Top];
}

template<class T, int SIZE>
void Stack<T, SIZE>::stackTranverse()
{
	int i = 0;
	for (i = 0; i < Top; i++) {
		cout << list[i];
	}
}


