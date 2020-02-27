#pragma once
template <class T, int SIZE=50>
class Stack
{
public:
	Stack();
	~Stack();
	bool stackEmpty();//判空
	bool stackFull();//判满
	void clearStack();//清空
	int stackLength();//长度
	void push(const T &item);//压栈
	T pop();//出栈
	const T &peek() const;//读取栈顶
	void stackTranverse();//遍历栈

private:
	T list[SIZE];//栈指针
	int Size;//栈容量
	int Top;//栈顶
};